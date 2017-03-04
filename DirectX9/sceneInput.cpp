/********************************************************************************
* �^�C�g���@GM 01
* �t�@�C�����@sceneInput.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/05
* input���͑S����
********************************************************************************/
/*------------------------------------------------------------------------------
|	�C���N���[�h�t�@�C��
------------------------------------------------------------------------------*/

#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "sceneInput.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CSceneInput::CSceneInput()
{
	m_pInput = NULL;					//IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	m_pDevKeyboard	 = NULL;					//IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�L�[�{�[�h)
	for(int cntInput = 0;cntInput < NUM_KEY_MAX ;cntInput++)
	{
		m_KeyState[ cntInput ] = 0;				//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
		m_KeyStateTrigger[ cntInput ] = 0;		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
		m_KeyStateRelease[ cntInput ] = 0;		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
		m_KeyStateRepeat[ cntInput ] = 0;		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
		m_KeyStateRepeatCnt[ cntInput ] = 0;		//�L�[�{�[�h�̃��s�[�g�J�E���^
		KeyStateOld[ cntInput ] = 0;
	}

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CSceneInput::~CSceneInput()
{

}
//================================================================================================================================================================================================
// Init�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
HRESULT CSceneInput ::Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow)
{
	if( m_pInput == NULL )
	{
		//DirectInput�I�u�W�F�N�g�̍쐬
		if( FAILED(
			DirectInput8Create
			(
				hInstance,
				DIRECTINPUT_VERSION,
				IID_IDirectInput8,
				( void** )&m_pInput,
				NULL
			) ) )
		{
			MessageBox( hWnd, "DirectInput8�I�u�W�F�N�g�̍쐬(�L�[�{�[�h�p)�ł��܂���ł����B", "�x���I", MB_ICONWARNING );
			return E_FAIL;
		}
	}

	if( FAILED( m_pInput -> CreateDevice( GUID_SysKeyboard, &m_pDevKeyboard, NULL ) ) )
	{//�f�o�C�X�I�u�W�F�N�g���쐬
		MessageBox( hWnd, "�L�[�{�[�h������܂���I", "�x���I", MB_ICONWARNING);
		return E_FAIL;
	}

	if( m_pDevKeyboard != NULL )
	{
		if( FAILED( m_pDevKeyboard -> SetDataFormat( &c_dfDIKeyboard ) ) )											//�f�[�^�t�H�[�}�b�g�̐ݒ�
		{//�f�[�^�t�H�[�}�b�g��ݒ�
			MessageBox(hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
			return E_FAIL;
		}

		//�������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
		if( FAILED( m_pDevKeyboard -> SetCooperativeLevel( hWnd, ( DISCL_FOREGROUND | DISCL_NONEXCLUSIVE ) ) ) )	//�������[�h�̐ݒ�
		{
			MessageBox(hWnd, "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
			return E_FAIL;
		}

		//���͐���J�n
		m_pDevKeyboard -> Acquire();
	}
	
	return S_OK;
}
//================================================================================================================================================================================================
// Uninit�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CSceneInput ::Uninit( void )
{
	RELEASE(m_pDevKeyboard);
	RELEASE(m_pInput);
}
//================================================================================================================================================================================================
// Update�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CSceneInput ::Update( void )
{
	if( m_pDevKeyboard != NULL )
	{

		//�O��̃f�[�^��ۑ�
		memcpy( KeyStateOld, m_KeyState, NUM_KEY_MAX );

		if( SUCCEEDED( m_pDevKeyboard -> GetDeviceState( sizeof( m_KeyState ),m_KeyState ) ) )
		{//�f�o�C�X����f�[�^���擾
			for( int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++ )
			{
				m_KeyStateTrigger[ nCntKey ] = ( KeyStateOld[nCntKey] ^ m_KeyState[ nCntKey ] ) & m_KeyState[ nCntKey ];
				m_KeyStateRelease[ nCntKey ] = ( KeyStateOld[nCntKey] ^ m_KeyState[ nCntKey ] ) & ~m_KeyState[ nCntKey ];
				m_KeyStateRepeat[ nCntKey ]  = m_KeyStateTrigger[nCntKey];

				if( m_KeyState[ nCntKey ] )
				{
					m_KeyStateRepeatCnt[ nCntKey ]++;
					if( m_KeyStateRepeatCnt[ nCntKey ] >= WAIT_COUNT_REPEAT )
					{
						m_KeyStateRepeat[ nCntKey ] = m_KeyState[ nCntKey ];
					}
				}
				else
				{
					m_KeyStateRepeatCnt[ nCntKey ] = 0;
					m_KeyStateRepeat[ nCntKey ] = 0;
				}
			}
		}
		else
		{
			//�L�[�{�[�h�ւ̃A�N�Z�X�����擾
			m_pDevKeyboard -> Acquire();
		}
	}
}
//================================================================================================================================================================================================
// Draw�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CSceneInput ::Draw( void )
{

}
/*------------------------------------------------------------------------------
|	�C���^�[�t�F�[�X�ւ̃|�C���^���擾
------------------------------------------------------------------------------*/
LPDIRECTINPUT8 CSceneInput ::GetpInput( void )
{
	return m_pInput;
}
/*------------------------------------------------------------------------------
|	�L�[�{�[�h�̃v���X��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneInput ::GetKeyboardPress( int nKey )
{
	return ( m_KeyState[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�L�[�{�[�h�̃g���K�[��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneInput ::GetKeyboardTrigger( int nKey )
{
	return ( m_KeyStateTrigger[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�L�[�{�[�h�̃����[�X��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneInput ::GetKeyboardRelease( int nKey )
{
	return ( m_KeyStateRelease[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�L�[�{�[�h�̃��s�[�g��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneInput ::GetKeyboardRepeat( int nKey )
{
	return ( m_KeyStateRepeat[ nKey ] & 0x80 ) ? true : false;
}

