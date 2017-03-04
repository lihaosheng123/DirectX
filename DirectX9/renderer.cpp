/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@renderer.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#include "renderer.h"

CRenderer *renderer;
//�O���[�o���ϐ�
//=============================================================================
// D3D����
//=============================================================================
CRenderer::CRenderer(void)
{
	m_pD3D = NULL;		//Direct3D�I�u�W�F�N�g�ւ̃|�C���^
	m_pD3DDevice = NULL;	//Direct3D�f�o�C�X�ւ̃|�C���^
	m_pFont = NULL;		//�t�H���g�ւ̃|�C���^
}

//=============================================================================
// D3D�j��
//=============================================================================
CRenderer::~CRenderer(void)
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�FD3D�̕K�v�R�[�h
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CRenderer:: Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow)
{

	D3DPRESENT_PARAMETERS d3dpp;
	D3DDISPLAYMODE d3ddm;
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);	//Direct3D�I�u�W�F�N�g�̊���
	if(m_pD3D == NULL)
	{
		return E_FAIL;
	}
	if(FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&d3ddm)))	//�f�B�X�v���C���[�h�i��ʉ𑜓x�j
	{
		return E_FAIL;
	}
	ZeroMemory(&d3dpp,sizeof(d3dpp));
	d3dpp.BackBufferWidth = SCREEN_WIDTH;		//size
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;		//size
	d3dpp.BackBufferFormat = d3ddm.Format;	//�o�[�N�o�b�t�@�`��
	d3dpp.BackBufferCount = 1;	//�o�[�N�o�b�t�@��
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;	//�e�b�O�X�o�b�t�@�ƃX�e���V���o�t�@�̐���
	//d3dpp.AutoDepthStencilFormat = D3DFMT_D16;	//	16�r�b�g�Ŏg�p(�X�e���V���o�b�t�@�g�p���Ȃ�)
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8; //�X�e���V���o�b�t�@�g�p // 24�r�b�gZ�o�b�t�@8�r�b�g�X�e���V���o�b�t�@�쐬
	d3dpp.Windowed = bWindow;
//	d3dpp.Windowed = false;		//�S���
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;

  //  d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
  ////d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
  //  d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	if(FAILED(m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,	//�`��
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,	//���_����
		&d3dpp,
		&m_pD3DDevice)))	//Direce 3D�f�o�C�X�̐���	

	{
		if(FAILED(m_pD3D->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&d3dpp,
			&m_pD3DDevice)))	//Direce 3D�f�o�C�X�̐���
		{
			if(FAILED(m_pD3D->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_REF,
				hWnd,
				D3DCREATE_HARDWARE_VERTEXPROCESSING,
				&d3dpp,
				&m_pD3DDevice)))	//Direce 3D�f�o�C�X�̐���
			{
				return E_FAIL;
			}
		}
	}

	/* �����_�[�X�e�[�g �ݒ� */
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);					// �J�����O���s��Ȃ�
	m_pD3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);							// Z�o�b�t�@���g�p

	m_pD3DDevice -> SetRenderState( D3DRS_BLENDOP, D3DBLEND_ZERO );          // �J�����O�ݒ�
	m_pD3DDevice -> SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );          // �A���t�@�ݒ�
	m_pD3DDevice -> SetRenderState( D3DRS_SRCBLEND, D3DBLEND_SRCALPHA );     // �\�[�X�u�����h�ݒ�
	m_pD3DDevice -> SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA ); // �f�B�X�g�u�����h�ݒ�

	/* �T���v���[�X�e�[�g �ݒ� */
	m_pD3DDevice -> SetSamplerState( 0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP );
	m_pD3DDevice -> SetSamplerState( 0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP );
	m_pD3DDevice -> SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
	m_pD3DDevice -> SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );

	// �e�N�X�`���[�X�e�[�W�p�����[�^�̂̐ݒ�
	m_pD3DDevice ->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pD3DDevice ->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pD3DDevice ->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	m_pD3DDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE );
	m_pD3DDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	m_pD3DDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	//�f�o�b�O���\���p�t�H���g��ݒ�
#ifdef _DEBUG

	//����������
	D3DXCreateFont(m_pD3DDevice,18,0,0,0,FALSE,
			SHIFTJIS_CHARSET,
			OUT_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH,
			"Terminal",
			&m_pFont);

#endif


	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FD3D�I������
//  �߂�l�@�Fvoid
//=============================================================================
void CRenderer:: Uninit (void)
{
	RELEASE(m_pD3D);
	RELEASE(m_pD3DDevice);
	//�f�o�b�O���\���p�t�H���g��ݒ�
#ifdef _DEBUG
	RELEASE(m_pFont);
#endif

}
//=============================================================================
//  �֐����@�FBegin
//  �@�\�T�v�FD3D��ʕ`��p
//  �߂�l�@�Fvoid
//=============================================================================
void CRenderer:: Begin (void)
{
	/*�X�e���V���o�b�t�@�g�p���Ȃ��̏ꍇ*/
	//m_pD3DDevice->Clear(0,NULL,
	//(D3DCLEAR_TARGET|
	//D3DCLEAR_ZBUFFER),
	//D3DCOLOR_RGBA(135, 206, 235,255),	//R,G,B,�����x
	//1.0f,0);	//��ʂ̃N���A


	/*�X�e���V���o�b�t�@�g�p����̏ꍇ*/
	m_pD3DDevice->Clear(0,NULL,
	(D3DCLEAR_TARGET|		//�o�b�N�o�b�t�@
	D3DCLEAR_ZBUFFER|		//z�o�b�t�@
	D3DCLEAR_STENCIL),//�X�e���V���o�b�t�@
	D3DCOLOR_RGBA(255, 255, 255, 255),	//R,G,B,�����x
	1.0f,0);	//��ʂ̃N���A

	m_pD3DDevice->BeginScene();	//�`��J�n

}
//=============================================================================
//  �֐����@�FEnd
//  �@�\�T�v�FD3D��ʕ`��p
//  �߂�l�@�Fvoid
//=============================================================================
void CRenderer:: End (void)
{
	m_pD3DDevice->EndScene();	//�`��I��
	m_pD3DDevice->Present(NULL,NULL,NULL,NULL);	//�o�b�N�o�b�t�@���f�B�X�v���C�ɕ\��
}

//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�FD3D�X�V����
//  �߂�l�@�Fvoid
//=============================================================================
void CRenderer:: Update(void)
{

}
//=============================================================================
//  �֐����@�FLPDIRECT3DDEVICE9 GetDevice(void)
//  �@�\�T�v�F����cpp�g�����߂ɂ̖߂�l
//  �߂�l�@�FLPDIRECT3DDEVICE9
//=============================================================================
LPDIRECT3DDEVICE9 CRenderer::GetDevice(void)
{
	return m_pD3DDevice;
}
/*******************************************************************************
* �֐���: DrawFPS
*******************************************************************************/
void CRenderer::DrawFPS( void )
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	char aStr[ 256 ];

	wsprintf( &aStr[ 0 ], "FPS:%d\n", g_nCountFPS );

	//�e�L�X�g�`��
	m_pFont -> DrawText( NULL, &aStr[ 0 ], -1, &rect, DT_RIGHT,  D3DCOLOR_RGBA( 255, 255, 255, 255 ) );
}