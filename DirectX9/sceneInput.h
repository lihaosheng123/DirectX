/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@sceneInput.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/05
* input���͑S����
********************************************************************************/
#ifndef _SCENEINPUT_H_
#define _SCENEINPUT_H_
/*------------------------------------------------------------------------------
|	�C���N���[�h�t�@�C��
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
|	�}�N����`
------------------------------------------------------------------------------*/
#define	NUM_KEY_MAX			( 256 )		//�L�[�̍ő吔
#define	WAIT_COUNT_REPEAT	( 20 )		//���s�[�g�J�n�܂ł̑҂�����

class CSceneInput  
{
public:
	CSceneInput();
	~CSceneInput();
	HRESULT Init (HINSTANCE hInstance,HWND hWnd,BOOL bWindow);		// ����������
	void Uninit(void);		// �I������
	void Update(void);		//�X�V����
	void Draw(void);
	LPDIRECTINPUT8 GetpInput( void );
	bool	GetKeyboardPress( int key );
	bool	GetKeyboardTrigger( int key );
	bool	GetKeyboardRelease( int key );
	bool	GetKeyboardRepeat( int key );
private:
	LPDIRECTINPUT8 m_pInput;					//IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	BYTE					m_KeyState[ NUM_KEY_MAX ];				//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE					m_KeyStateTrigger[ NUM_KEY_MAX ];		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE					m_KeyStateRelease[ NUM_KEY_MAX ];		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	BYTE					m_KeyStateRepeat[ NUM_KEY_MAX ];		//�L�[�{�[�h�̏�Ԃ��󂯎�郏�[�N
	int						m_KeyStateRepeatCnt[ NUM_KEY_MAX ];		//�L�[�{�[�h�̃��s�[�g�J�E���^
	BYTE					KeyStateOld[ NUM_KEY_MAX ];
	LPDIRECTINPUTDEVICE8	m_pDevKeyboard	;					//IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�L�[�{�[�h)
};
#endif
