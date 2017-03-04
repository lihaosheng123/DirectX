/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@manager.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/09
*
********************************************************************************/

#include "manager.h"

CMode* CManager::m_Mode;

CManager::MODE CManager::m_OldMode;
CManager::MODE CManager::m_NewMode;

int CManager::m_FadeMode;
int CManager::m_FadeCount;
int CManager::m_ModeDelay;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CManager::CManager( void )
{
	m_Build = false;
	m_MouseDraw = false;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CManager::~CManager()
{
}

//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F�v���S���̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CManager ::Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow)
{
	m_Renderer = new CRenderer;
	m_Renderer->Init(hInstance,hWnd,bWindow);

	m_Input = new CSceneInput;
	m_Input->Init(hInstance,hWnd,bWindow);

	m_Fade = new CFade();
	m_Fade->Init();
	
	m_FadeMode = 0;
	m_FadeCount = 34;


	m_Mode = new CTitle();
	m_Mode->Init();

	m_Mouse = new CSceneMouse;
	m_Mouse->Init(hInstance,hWnd);

	m_OldMode = MODE_TITLE;
	m_NewMode = MODE_TITLE;

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FD3D�I������
//  �߂�l�@�Fvoid
//=============================================================================
void CManager :: Uninit (void)
{


	m_Input->Uninit();
	delete m_Input;

	m_Mouse->Uninit();
	delete m_Mouse;

	m_Fade->Uninit();
	delete m_Fade;


	if( m_Mode )
	{
		//�������[���
		m_Mode->Uninit();
		delete m_Mode;
		m_Mode = NULL;
	}


	if( m_Renderer )
	{
		m_Renderer->Uninit();
		delete m_Renderer;
		m_Renderer = NULL;
	}



}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�FD3D��ʕ`��p
//  �߂�l�@�Fvoid
//=============================================================================
void CManager:: Draw (void)
{
	/* �`��J�n �֐� */
	m_Renderer->Begin();
	m_Mode->Draw();
	if (m_FadeMode != 0)
	{
		m_Fade->Draw();
	}
	if (m_MouseDraw == true)
	{
		m_Mouse->Draw();
	}
	/* �`��I�� �֐� */
	m_Renderer->End();


}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�FD3D��ʕ`��p
//  �߂�l�@�Fvoid
//=============================================================================
void CManager:: Update (void)

{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	CSceneInput *m_Input = manager -> GetInput();
	//if(m_Input->GetKeyboardPress( DIK_F1 ))
	//{
	//	device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);		//����������̏ꍇ
	//}
	//else 
	//{
	//	device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	//}
	m_Input->Update();
	m_Mode->Update();
	m_Renderer->Update();
	m_Mouse->Update();
	m_Fade->Update();


	if( m_FadeMode == 1)
	{
		m_FadeCount++;

		if( m_FadeCount > 34 )
		{
			m_FadeCount = 34;
			//�������[���
			m_Mode->Uninit();
		
 			switch( m_NewMode )
			{
				case MODE_TITLE:
					m_Mode = new CTitle();
					break;

				case MODE_GAME:
					m_Mode = new CGame();
					break;

				case MODE_BUILD:
					m_Mode = new CBuildManager();
					break;

				case MODE_RESULT:
					m_Mode = new CResult();
					break;
			}

			m_Mode->Init();

			m_OldMode = m_NewMode;


			m_FadeMode = -1;
		}
	}
	else if( m_FadeMode == -1 )
	{
		m_FadeCount--;

		if( m_FadeCount < 0 )
		{
			m_FadeCount = 0;
				
			m_FadeMode = 0;
		}
	}


}
void CManager::SetMode(MODE Mode)
{

	m_NewMode = Mode;


	m_FadeMode = 1;
	m_FadeCount = 0;
}
CMode* CManager::GetMode(void)
{
	 return m_Mode; 
}
//�߂�l�@�FCRenderer*
CRenderer* CManager::GetRenderer ( void )
{
	return m_Renderer;
}
CSceneInput* CManager::GetInput ( void )
{
	return m_Input;
}
CSceneMouse* CManager::GetMouse ( void )
{
	return m_Mouse;
}
