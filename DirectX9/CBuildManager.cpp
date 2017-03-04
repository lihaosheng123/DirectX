/********************************************************************************
* �^�C�g���@CBUILDMANAGER
* �t�@�C�����@CBuildManager.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/12/19
*Build�̃}�l�W���[
********************************************************************************/
#include "CBuildManager.h"
//------------------------------------------------------------------------------
//	�֐���:	CBuildManager::CBuildManager
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CBuildManager::CBuildManager()
{
	CManager *manager = GetManager();
	//Build���[�h�I��
	manager->m_Build = true;
	//�}�E�X�`��I��
	manager->m_MouseDraw = true;
}

//------------------------------------------------------------------------------
//	�֐���:	CBuildManager::~CBuildManager
//	����:	�Ȃ�
//	�߂�l:	CBuildManager
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CBuildManager::~CBuildManager()
{
}

//------------------------------------------------------------------------------
//	�֐���:	void CBuildManager::Init
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	����������
//------------------------------------------------------------------------------
void CBuildManager::Init(void)
{
	//���C�g�N���X�̃C���X�^���X�Ə�����
	m_Light = new CBuildLight;
	m_Light->Init(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//�J�����N���X�̃C���X�^���X�Ə�����
	m_BuildCamera = new CBuildCamera;
	m_BuildCamera->Init();

	//�}�b�v�̓ǂݍ��݃N���X�̃C���X�^���X�Ə�����
	m_BuildLoadMap = new CBuildLoadMap;
	m_BuildLoadMap->Init();
	/*���X�g�\���`��J�n*/
	//�V��`��p
	m_GameCeiling = CGameCeiling::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_CEILING_FILE);
	//��001�`��p
	m_GameWall_001 = CGameWall_001::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, GAME_TEXTURE_WALL_001_FILE);
	//��002�`��p
	m_GameWall_002 = CGameWall_002::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, GAME_TEXTURE_WALL_002_FILE);
	//�G001�`��p
	m_GameEnemy_001 = CGameEnemy_001::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_001);
	//�G002�`��p
	m_GameEnemy_002 = CGameEnemy_002::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
	//�h�A���f���`��p
	m_GameDoor = CGameDoor::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
	//�������f���`��p
	m_GamePoint = CGamePoint::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_POINT);
	//�t�B�[���h�`��p
	m_Field = CField::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 100.0f, 100.0f, MESHFIELD_TEXTURE_FILE00);
	//���W�n�`��p
	m_axis = Caxis::Create(D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 7000.0f, 7000.0f, TEXTURE_AXIS_FILE);
	//2DMEnu(main)�`��p
	m_BuildMenu = CBuildMenu::Create(D3DXVECTOR3(50.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 60.0f, 90.0f, "NULL");
	//2DMEnu(wall)�`��p
	m_BuildMenu_Wall = CBuildMenu_Wall::Create(D3DXVECTOR3(130.0f, 50.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 50.0f, 50.0f, "NULL");
	//2DMEnu(enemy)�`��p
	m_BuildMenu_Enemy = CBuildMenu_Enemy::Create(D3DXVECTOR3(130.0f, 130.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 60.0f, 60.0f, "NULL");
	//2DMEnu(prop)�`��p
	m_BuildMenu_Prop  = CBuildMenu_Prop::Create(D3DXVECTOR3(150.0f, 370.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 60.0f, 100.0f, "NULL");
	//2DMEnu(another)�`��p
	m_BuildMenu_Another = CBuildMenu_Another::Create(D3DXVECTOR3(150.0f, 450.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 60.0f, 100.0f, "NULL");
	//Build�p(wall001)�`��p
	m_Wall_001[0] = CWall_001::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_001_FILE);
	//Build�p(wall002)�`��p
	m_Wall_002[0] = CWall_002::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_002_FILE);
	//Build�p(enemy001)�`��p
	m_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_001);
	//Build�p(enemy002)�`��p
	m_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
	//Build�p(ceiling(�V���))�`��p
	m_Ceiling[0] = CCeiling::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_CEILING_FILE);
	//Build�p(Trail(�G�̋O��))�`��p
	m_Trail = CTrail::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 70.0f, 30.0f, TEXTURE_TRAIL_FILE);
	//Build�p(door)�`��p
	m_Door = CDoor::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
	//Build�p(point)�`��p
	m_Point = CPoint::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_POINT);
	//Build�p(start)�`��p
	m_Start = CStart::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_START);
	//Build�p(end)�`��p
	m_End = CEnd::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, "NULL");
	//Build�p(robot)�`��p
	m_Robot = CRobot::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ROBOT);
	//Build�p(BuildImage)�`��p
	m_BuildImage = CBuildImage::Create(D3DXVECTOR3(1120.0f, 60.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 120.0f, 300.0f, TEXTURE_BUILDIMAGE_FILE);
	/*���X�g�\���`��I��*/
	//���݂���̃f�[�^���͂̃C���X�^���X�Ə�����
	m_BuildSetMap = new BuildSetMap;
	m_BuildSetMap->Init();

	//�}�b�N�̍쐬�Ɠ��̓C���X�^���X�Ə�����
	m_BuildMap = new CBuildMap;
	m_BuildMap->Init();


}

//------------------------------------------------------------------------------
//	�֐���:	void CBuildManager::Uninit
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�I������
//------------------------------------------------------------------------------
void CBuildManager::Uninit(void)
{
	//�J�����N���X�̍폜
	m_BuildCamera->Uninit();
	delete m_BuildCamera;

	//���C�g�N���X�̍폜
	delete m_Light;

	//�}�b�N�̍쐬�Ɠ��̓N���X�̍폜
	m_BuildMap->Uninit();
	delete m_BuildMap;

	//�}�b�v�̓ǂݍ��݃N���X�̍폜
	m_BuildLoadMap->Uninit();
	delete m_BuildLoadMap;

	//���݂���̃f�[�^���̓N���X�̍폜
	delete m_BuildSetMap;

	/*���X�g�\���̍폜*/
	CScene::UninitAll();



}

//------------------------------------------------------------------------------
//	�֐���:	void CBuildManager::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�X�V����

//------------------------------------------------------------------------------
void CBuildManager::Update(void)
{
	CManager *manager = GetManager();
	CSceneInput *m_Input = manager->GetInput();

	//���C�g�N���X�̍X�V
	m_Light->Update();

	//�J�����N���X�̍X�V
	m_BuildCamera->Update();

	//�}�b�v�̓ǂݍ��݃N���X�̍X�V
	m_BuildLoadMap->Update();

	/*���X�g�\���̍X�V*/
	CScene::UpdateAll();

	//�}�b�N�̍쐬�Ɠ��̓N���X�̍X�V
	m_BuildMap->Update(hInstance,hWnd);
}

//------------------------------------------------------------------------------
//	�֐���:	void CBuildManager::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CBuildManager::Draw(void)
{
	/*���X�g�\���̕`��*/
	CScene::DrawAll();
	
}
CBuildLoadMap* CBuildManager::GetBuildLoadMap(void)
{
	return m_BuildLoadMap;
}
CBuildCamera* CBuildManager::GetBuildCamera(void)
{
	return m_BuildCamera;
}
CBuildMap* CBuildManager::GetBuildMap(void)
{
	return m_BuildMap;
}
CBuildLight* CBuildManager::GetBuildLight(void)
{
	return m_Light;
}
CBuildMenu_Wall* CBuildManager::GetBuildMenu_Wall(void)
{
	return m_BuildMenu_Wall;
}
CBuildMenu_Enemy* CBuildManager::GetBuildMenu_Enemy(void)
{
	return m_BuildMenu_Enemy;
}
CBuildMenu* CBuildManager::GetBuildMenu(void)
{
	return m_BuildMenu;
}
CEnemy_001* CBuildManager::GetEnemy_001(int Index)
{
	return m_Enemy_001[Index];
}
CEnemy_002* CBuildManager::GetEnemy_002(int Index)
{
	return m_Enemy_002[Index];
}
CWall_001* CBuildManager::GetBuildWall_001(int Index)
{
	return m_Wall_001[Index];
}
CWall_002* CBuildManager::GetBuildWall_002(int Index)
{
	return m_Wall_002[Index];
}
CTrail* CBuildManager::GetBuildTrail(void)
{
	return m_Trail;
}
CGameWall_001* CBuildManager::GetGameWall_001(void)
{
	return m_GameWall_001;
}
CGameWall_002* CBuildManager::GetGameWall_002(void)
{
	return m_GameWall_002;
}
CGameEnemy_001* CBuildManager::GetGameEnemy_001(void)
{
	return m_GameEnemy_001;
}
CGameEnemy_002* CBuildManager::GetGameEnemy_002(void)
{
	return m_GameEnemy_002;
}
CCeiling* CBuildManager::GetCeiling(int Index)
{
	return m_Ceiling[Index];
}
CGameCeiling* CBuildManager::GetGameCeiling(void)
{
	return m_GameCeiling;
}
CGameDoor* CBuildManager::GetGameDoor(void)
{
	return m_GameDoor;
}
CDoor* CBuildManager::GetDoor(void)
{
	return m_Door;
}
CBuildMenu_Prop* CBuildManager::GetBuildMenu_Prop(void)
{
	return m_BuildMenu_Prop;
}
CPoint* CBuildManager::GetPoint(void)
{
	return m_Point;
}
CStart* CBuildManager::GetStart(void)
{
	return m_Start;
}
CEnd* CBuildManager::GetEnd(void)
{
	return m_End;
}
CGamePoint* CBuildManager::GetGamePoint(void)
{
	return m_GamePoint;
}
CBuildMenu_Another* CBuildManager::GetBuildMenu_Another(void)
{
	return m_BuildMenu_Another;
}
CRobot* CBuildManager::GetRobot(void)
{
	return m_Robot;
}