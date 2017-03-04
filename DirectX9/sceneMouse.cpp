/********************************************************************************
* �^�C�g���@GM 01
* �t�@�C�����@sceneMouse.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/23
* �}�E�X���͑S����
********************************************************************************/
/*------------------------------------------------------------------------------
|	�C���N���[�h�t�@�C��
------------------------------------------------------------------------------*/
#include "main.h"
#include "manager.h"
#include "dinput.h"
#include "sceneInput.h"
#include "sceneMouse.h"
#include "scene2D.h"

#define	TEXTURE_MOUSE_FILE		"data\\TEXTURE\\mouse.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

#define	NUM_PATTERN			(32)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X		(8.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y		(4.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X		(1.0f / TEXTURE_PATTERN_X)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y		(1.0f / TEXTURE_PATTERN_Y)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN	(3)						// �A�j���[�V�����̐؂�ւ��Ԋu
//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CSceneMouse::CSceneMouse()
{
	m_pTexture = NULL;
	m_pVtxBuffer  = NULL;	//���_�p�b�t�@�ւ̃|�C���^
	m_MouseInput = NULL;					//IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	g_pDevMouse = NULL;					//IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�}�E�X)
	for(int cntMouse = 0;cntMouse < NUM_KEY_MAX ;cntMouse++)
	{
		g_MouseStateTrigger[ cntMouse ] = 0 ;		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
		g_MouseStateRelease[ cntMouse ] = 0 ;		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
		g_MouseStateRepeat[ cntMouse ] = 0 ;		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
		g_MouseStateRepeatCnt[ cntMouse ] = 0 ;	//�}�E�X�̃��s�[�g�J�E���^
	}
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CSceneMouse::~CSceneMouse()
{

}

/*------------------------------------------------------------------------------
|	�}�E�X�̏���������
------------------------------------------------------------------------------*/
HRESULT CSceneMouse::Init( HINSTANCE hInstance, HWND hWnd )
{
	if( m_MouseInput == NULL )
	{
		//DirectInput�I�u�W�F�N�g�̍쐬
		if( FAILED(
			DirectInput8Create
			(
				hInstance,
				DIRECTINPUT_VERSION,
				IID_IDirectInput8,
				( void** )&m_MouseInput,
				NULL
			) ) )
		{
			MessageBox( hWnd, "DirectInput8�I�u�W�F�N�g�̍쐬(�}�E�X�p)�ł��܂���ł����B", "�x���I", MB_ICONWARNING );
			return E_FAIL;
		}
	}


	if( FAILED( m_MouseInput -> CreateDevice( GUID_SysMouse, &g_pDevMouse, NULL ) ) )
	{//�f�o�C�X�I�u�W�F�N�g���쐬
		MessageBox( hWnd, "�}�E�X������܂���I", "�x���I", MB_ICONWARNING );
		return E_FAIL;	
	}

	if( g_pDevMouse != NULL )
	{
		if( FAILED( g_pDevMouse -> SetDataFormat( &c_dfDIMouse ) ) )												//�f�[�^�t�H�[�}�b�g�̐ݒ�
		{//�f�[�^�t�H�[�}�b�g��ݒ�
			MessageBox( hWnd, "�}�E�X�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING );
			return E_FAIL;
		}

		//�������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
		if( FAILED( g_pDevMouse -> SetCooperativeLevel( hWnd, ( DISCL_EXCLUSIVE | DISCL_FOREGROUND ) ) ) )		//�������[�h�̐ݒ�
		{
			MessageBox( hWnd, "�}�E�X�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING );
			return E_FAIL;
		}

		//�����[�h��ݒ�i���Βl���[�h�ɐݒ�j
		DIPROPDWORD diprop;
		diprop.diph.dwSize			= sizeof( diprop );
		diprop.diph.dwHeaderSize	= sizeof( diprop.diph );
		diprop.diph.dwObj			= 0;
		diprop.diph.dwHow			= DIPH_DEVICE;
		diprop.dwData				= DIPROPAXISMODE_REL;	//���Βl���[�h�Őݒ�i��΃��[�h��DIPROPAXISMODE_ABS�j

		if( FAILED( g_pDevMouse -> SetProperty( DIPROP_AXISMODE, &diprop.diph ) ) )
		{
			MessageBox( hWnd, "�����[�h�̐ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING );
			return E_FAIL;
		}
		
		//�}�E�X�\���̂̏�����
		SetRect( &g_Mouse.moveRect, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );		//�}�E�X�J�[�\���̓����͈�
		g_Mouse.x = SCREEN_CENTER_X;											//�}�E�X�J�[�\���̂w���W��������
		g_Mouse.y = SCREEN_CENTER_Y;											//�}�E�X�J�[�\���̂x���W��������
		g_Mouse	.moveAdd = 3;													//�}�E�X�J�[�\���̈ړ��ʂ�ݒ�
		g_MouseState.lX = 0;
		g_MouseState.lY = 0;
		g_MouseState.lZ = 0;
		nCount = 0;			// �J�E���^
		nPattern = 0;		// �p�^�[��No.	
		//���͐���J�n	
		g_pDevMouse -> Acquire();

	}
	/*�}�E�X�̕`��J�n*/

	m_Position =  D3DXVECTOR3(0.0f,0.0f,0.0f);	// ���_���W
	m_Rotation=  D3DXVECTOR3(0.0f,0.0f,0.0f);	// ��]
	m_height = 40.0f;		//����
	m_width = 40.0f;		//����
	nCount = 0;			// �J�E���^
	nPattern = 0;		// �p�^�[��No.
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
								TEXTURE_MOUSE_FILE,		// �t�@�C���̖��O
								&m_pTexture);	// �ǂݍ��ރ������[

	 //�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
    if(FAILED(device->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * 1,	// ���_�f�[�^�p�Ɋm�ۂ���o�b�t�@�T�C�Y(�o�C�g�P��)
												D3DUSAGE_WRITEONLY,						// ���_�o�b�t�@�̎g�p�@
												FVF_VERTEX_2D,							// �g�p���钸�_�t�H�[�}�b�g
												D3DPOOL_MANAGED,						// ���\�[�X�̃o�b�t�@��ێ����郁�����N���X���w��
												&m_pVtxBuffer,						// ���_�o�b�t�@�C���^�[�t�F�[�X�ւ̃|�C���^
												NULL)))									// NULL�ɐݒ�
	{
        return E_FAIL;
	}

	{//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_2D *pVtx;

		// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

		for(int nCntScene = 0; nCntScene < 1; nCntScene++, pVtx += 4)
		{
			// ���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y - m_height/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y - m_height/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y + m_height/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y + m_height/2, 0.0f);

			// rhw�̐ݒ�
			pVtx[0].rhw =
			pVtx[1].rhw =
			pVtx[2].rhw =
			pVtx[3].rhw = 1.0f;

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// �e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(TEXTURE_SIZE_X, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, TEXTURE_SIZE_Y);
			pVtx[3].tex = D3DXVECTOR2(TEXTURE_SIZE_X, TEXTURE_SIZE_Y);
		}

		// ���_�f�[�^���A�����b�N����
		m_pVtxBuffer->Unlock();
	}
	return S_OK;
}

/*------------------------------------------------------------------------------
|	�}�E�X�̏I������
------------------------------------------------------------------------------*/
void CSceneMouse::Uninit( void )
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
	RELEASE(g_pDevMouse);
}
/*------------------------------------------------------------------------------
|	�}�E�X�̕`�揈��
------------------------------------------------------------------------------*/
void CSceneMouse::Draw( void )
{

	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();


	// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h
	device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	device->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	device->SetTexture(0, m_pTexture);
	device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	// �u�����h���Z����
	device->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�X�e�B�l�[�V�����J���[�̎w��

	// �|���S���̕`��
	device->DrawPrimitive( D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
							 0 ,								// �`�悷��ŏ��̒��_
							2 );										// �`�悷��v���~�e�B�u��
	//device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHATESTENABLE, FALSE );			// �f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_ALWAYS );			// �f�t�H���g�ɖ߂��B

	// �ʏ�u�����h
	device->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��

}
/*------------------------------------------------------------------------------
|	�}�E�X�̍X�V����
------------------------------------------------------------------------------*/
void CSceneMouse::Update( void )
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CField *meshField = game -> GetField();
	CCamera *m_Camera = game->GetCCamera();
	CSceneInput *m_Input = manager->GetInput();

	if (g_pDevMouse != NULL)
	{
		BYTE MouseStateOld[NUM_KEY_MAX];

		//�O��̃f�[�^��ۑ�
		memcpy(MouseStateOld, g_MouseState.rgbButtons, NUM_KEY_MAX);

		if (SUCCEEDED(g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE), &g_MouseState)))
		{//�f�o�C�X����f�[�^���擾
				//�}�E�X�̈ړ����X�V
		//	g_Mouse.x += (g_MouseState.lX * g_Mouse.moveAdd);
		//	g_Mouse.y += (g_MouseState.lY * g_Mouse.moveAdd);

			//��ʊO�`�F�b�N
			if (g_Mouse.x < g_Mouse.moveRect.left)
			{
				g_Mouse.x = g_Mouse.moveRect.left;
			}
			if (g_Mouse.x > g_Mouse.moveRect.right)
			{
				g_Mouse.x = g_Mouse.moveRect.right;
			}
			if (g_Mouse.y < g_Mouse.moveRect.top)
			{
				g_Mouse.y = g_Mouse.moveRect.top;
			}
			if (g_Mouse.y > g_Mouse.moveRect.bottom)
			{
				g_Mouse.y = g_Mouse.moveRect.bottom;
			}

			for (int nCntMouse = 0; nCntMouse < NUM_KEY_MAX; nCntMouse++)
			{//�f�o�C�X����f�[�^���擾
				g_MouseStateTrigger[nCntMouse] = (MouseStateOld[nCntMouse] ^ g_MouseState.rgbButtons[nCntMouse]) & g_MouseState.rgbButtons[nCntMouse];
				g_MouseStateRelease[nCntMouse] = (MouseStateOld[nCntMouse] ^ g_MouseState.rgbButtons[nCntMouse]) & ~g_MouseState.rgbButtons[nCntMouse];
				g_MouseStateRepeat[nCntMouse] = g_MouseStateTrigger[nCntMouse];

				if (g_MouseState.rgbButtons[nCntMouse])
				{
					g_MouseStateRepeatCnt[nCntMouse]++;
					if (g_MouseStateRepeatCnt[nCntMouse] >= WAIT_COUNT_REPEAT)
					{
						g_MouseStateRepeat[nCntMouse] = g_MouseState.rgbButtons[nCntMouse];
					}
				}
				else
				{
					g_MouseStateRepeatCnt[nCntMouse] = 0;
					g_MouseStateRepeat[nCntMouse] = 0;
				}
			}
		}
		else
		{
			//�}�E�X�ւ̃A�N�Z�X�����擾
			g_pDevMouse->Acquire();
		}
	}
	SetMouse(g_Mouse.x,g_Mouse.y);
	
}

/*------------------------------------------------------------------------------
|	�}�E�X�̃v���X��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneMouse::GetMousePress( int nKey )
{
	return ( g_MouseState.rgbButtons[ nKey ] & 0x80) ? true : false;
}

/*------------------------------------------------------------------------------
|	�}�E�X�̃g���K�[��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneMouse::GetMouseTrigger( int nKey )
{
	return ( g_MouseStateTrigger[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�}�E�X�̃����[�X��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneMouse::GetMouseRelease( int nKey )
{
	return ( g_MouseStateRelease[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�}�E�X�̃��s�[�g��Ԃ��擾
------------------------------------------------------------------------------*/
bool CSceneMouse::GetMouseRepeat( int nKey )
{
	return ( g_MouseStateRepeat[ nKey ] & 0x80 ) ? true : false;
}

/*------------------------------------------------------------------------------
|	�}�E�X���擾
------------------------------------------------------------------------------*/
MSTATE *CSceneMouse::GetMouseState( void )
{
	return &g_Mouse;
}
void CSceneMouse::SetMouse(int x,int y)
{
	m_Position.x = (float)x;
	m_Position.y = (float)y;

	//���_�o�b�t�@�̒��g�𖄂߂�
	VERTEX_2D *pVtx;
	// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

	nCount++;
	if((nCount % INTERVAL_PATTERN) == 0)
		{// �A�j���[�V�����؂�ւ�
			nPattern++;
			if(nPattern >= NUM_PATTERN )
			{// �A�j���[�V�����p�^�[�����I��
				nCount = 0;
				nPattern = 0;
			}
	pVtx[0].tex = D3DXVECTOR2(nPattern * TEXTURE_SIZE_X, nPattern * TEXTURE_SIZE_Y);
	pVtx[1].tex = D3DXVECTOR2((nPattern + 1) * TEXTURE_SIZE_X, nPattern * TEXTURE_SIZE_Y);
	pVtx[2].tex = D3DXVECTOR2(nPattern * TEXTURE_SIZE_X,(nPattern + 1) * TEXTURE_SIZE_Y);
	pVtx[3].tex = D3DXVECTOR2((nPattern + 1) * TEXTURE_SIZE_X, (nPattern + 1) * TEXTURE_SIZE_Y);
		}
	// ���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y - m_height/2, 0.0f);
	pVtx[1].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y - m_height/2, 0.0f);
	pVtx[2].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y + m_height/2, 0.0f);
	pVtx[3].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y + m_height/2, 0.0f);

	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffer->Unlock();
}

//
// �X�N���[�����W�����[���h���W�ɕϊ�
D3DXVECTOR3* CSceneMouse::CalcScreenToWorld(D3DXVECTOR3* pout,
											int Sx,  // �X�N���[��X���W
											int Sy,  // �X�N���[��Y���W
											float fZ,  // �ˉe��Ԃł�Z�l�i0�`1�j
											int Screen_w,
											int Screen_h,
											D3DXMATRIX* View,
											D3DXMATRIX* Prj
)
{
	// �e�s��̋t�s����Z�o
	D3DXMATRIX InvView, InvPrj, VP, InvViewport;
	D3DXMatrixInverse( &InvView, NULL, View );
	D3DXMatrixInverse( &InvPrj, NULL, Prj );
	D3DXMatrixIdentity( &VP );
	VP._11 = Screen_w/2.0f; VP._22 = -Screen_h/2.0f;
	VP._41 = Screen_w/2.0f; VP._42 = Screen_h/2.0f;
	D3DXMatrixInverse( &InvViewport, NULL, &VP );

	// �t�ϊ�
	D3DXMATRIX tmp = InvViewport * InvPrj * InvView;
	D3DXVec3TransformCoord( pout, &D3DXVECTOR3((float)Sx,(float)Sy,(float)fZ), &tmp );

	return pout;
}

// XZ���ʂƃX�N���[�����W�̌�_�Z�o�֐�
D3DXVECTOR3* CSceneMouse::CalcScreenToXZ(D3DXVECTOR3* pout,int Sx,int Sy,int Screen_w,int Screen_h,D3DXMATRIX* View,D3DXMATRIX* Prj)
{
	D3DXVECTOR3 nearpos;
	D3DXVECTOR3 farpos;
	D3DXVECTOR3 ray;
	CalcScreenToWorld( &nearpos, Sx, Sy, 0.0f, Screen_w, Screen_h, View, Prj );
	CalcScreenToWorld( &farpos, Sx, Sy, 1.0f, Screen_w, Screen_h, View, Prj );
	ray = farpos - nearpos;
	D3DXVec3Normalize( &ray, &ray );

	// ���Ƃ̌������N���Ă���ꍇ�͌�_��
	// �N���Ă��Ȃ��ꍇ�͉����̕ǂƂ̌�_���o��
	if( ray.y <= 0 )
	{
	// ����_
	float Lray = D3DXVec3Dot( &ray, &D3DXVECTOR3(0,1,0) );
	float LP0 = D3DXVec3Dot( &(-nearpos), &D3DXVECTOR3(0,1,0) );
	*pout = nearpos + (LP0/Lray)*ray;
	}
	else 
	{
		*pout = farpos;
	}

	return pout;
}
