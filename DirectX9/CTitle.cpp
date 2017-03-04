/********************************************************************************
* �^�C�g���@TITLE
* �t�@�C�����@CTitle.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
TITLE�̃��[�h����
********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene2D.h"
#include "sceneInput.h"
#include "CTitle.h"
//------------------------------------------------------------------------------
//	�֐���:	CTitle::CTitle
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CTitle::CTitle()
{
	CManager *manager = GetManager();
	manager->m_MouseDraw = false;
}

//------------------------------------------------------------------------------
//	�֐���:	CTitle::~CTitle
//	����:	�Ȃ�
//	�߂�l:	CTitle
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CTitle::~CTitle()
{
}

//------------------------------------------------------------------------------
//	�֐���:	void CTitle::Init
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	����������
//------------------------------------------------------------------------------
void CTitle::Init(void)
{
	m_Light = new CTitleLight;
	m_Light->Init();

	m_Camera = new CTitleCamera;
	m_Camera->Init();
	m_TitleSkyBox = CTitleSkyBox::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, "NULL");
	m_Field = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 100.0f, 100.0f, MESHFIELD_TEXTURE_FILE00);
	m_TitleModel = CTitleModel::Create(D3DXVECTOR3(0.0f, 0.0f, 500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_TITLE);
	m_Title_R_Model = CTitle_R_Model::Create(D3DXVECTOR3(0.0f, 0.0f, 500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_R);
	m_TitleRobot = CTitleRobot::Create(D3DXVECTOR3(300.0f, 0.0f, 300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_TITLE_MODEL);
	m_TitleMenu = CTitleMenu::Create(D3DXVECTOR3(100.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 150.0f, "NULL");
	m_TitleMark = CTitleMark::Create(D3DXVECTOR3(100.0f, 500.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 70.0f, 170.0f, TEXTURE_TITLEMARK);
	m_TitleImage = CTitleImage::Create(D3DXVECTOR3(SCREEN_CENTER_X, 170.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), SCREEN_HEIGHT / 5, SCREEN_WIDTH / 1.5, TEXTURE_TITLEIMAGE_FILE);

}

//------------------------------------------------------------------------------
//	�֐���:	void CTitle::Uninit
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�I������
//------------------------------------------------------------------------------
void CTitle::Uninit(void)
{
	m_Camera->Uninit();
	delete m_Camera;

	delete m_Light;
	CScene::UninitAll();
}

//------------------------------------------------------------------------------
//	�֐���:	void CTitle::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�X�V����

//------------------------------------------------------------------------------
void CTitle::Update(void)
{
	CManager *manager = GetManager();
	CSceneInput *m_Input = manager -> GetInput();
	CTitle *Title = (CTitle*)CManager::GetMode();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildMap *m_BuildMap = BuildManager->GetBuildMap();
	CTitleMark *m_TitleMark = Title->GetTitleMark();
	m_Camera->Update();

	CScene::UpdateAll();


	if (m_TitleMark->m_type == m_TitleMark->TITLE_MENU_BUILD && m_Input->GetKeyboardTrigger(DIK_RETURN))
	{
		CManager::SetMode(CManager::MODE_BUILD);
	}


	if (m_TitleMark->m_type == m_TitleMark->TITLE_MENU_START && m_Input->GetKeyboardTrigger(DIK_RETURN))
	{
		CManager::SetMode(CManager::MODE_GAME);
	}
	if (m_TitleMark->m_type == m_TitleMark->TITLE_MENU_END && m_Input->GetKeyboardTrigger(DIK_RETURN))
	{
		exit(0);
	}

}

//------------------------------------------------------------------------------
//	�֐���:	void CTitle::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CTitle::Draw(void)
{
	CScene::DrawAll();

}

CTitleMark* CTitle::GetTitleMark(void)
{
	return m_TitleMark;
}
CTitleMenu* CTitle::GetTitleMenu(void)
{
	return m_TitleMenu;
}
CTitle_R_Model* CTitle::GetTitle_R_Model(void)
{
	return m_Title_R_Model;
}