/********************************************************************************
* �t�@�C�����@CBuildMap.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�Ǘ��A�ǂݍ��݁A�t�@�C���쐬
********************************************************************************/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "scene3D.h"
#include "manager.h"
#include "scene.h"
#include "CBuildMap.h"
/*******************************************************************************
�}�N����`
*******************************************************************************/

//------------------------------------------------------------------------------
//	�֐���:	CBuildMap::CBuildMap
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CBuildMap::CBuildMap()
{
	//�f�[�^�̓ǂݍ��ݏ�����
	PosX = 0;
	PosY = 0;
	PosZ = 0;
	RotX = 0;
	RotY = 0;
	RotZ = 0;
	m_Trail_PosX = 0;
	m_Trail_PosY = 0;
	m_Trail_PosZ = 0;

	/*���X�g�\���̃��f���`��(�m�ۗp)*/
	//�G001�`��p
	p_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_001);
	//�G002�`��p
	p_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
	//�h�A���f���`��p
	p_Door[0] = CDoor::Create(D3DXVECTOR3(0.f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
	//�������f���`��p
	p_Point[0] = CPoint::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_POINT);
	//Build�p(start)�`��p
	p_Start[0] = CStart::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_START);
	//Build�p(end)�`��p
	p_End[0] = CEnd::Create(D3DXVECTOR3(0.0f, 7000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, "NULL");
	//Build�p(robot)�`��p
	p_Robot[0] = CRobot::Create(D3DXVECTOR3(0.0f, 5000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ROBOT);
}

//------------------------------------------------------------------------------
//	�֐���:	CBuildMap::~CBuildMap
//	����:	�Ȃ�
//	�߂�l:	
//	����:	�R���X�g���N�^
//------------------------------------	------------------------------------------
CBuildMap::~CBuildMap()
{

}

/*******************************************************************************
�֐����F	HRESULT CBuildMap::Init
�߂�l�F	HRESULT
�����F		void
�����F		CBuildMap�̏���������
**********	*********************************************************************/
void CBuildMap::Init(void)
{
	CManager *manager = GetManager();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildMap *m_BuildMap = BuildManager->GetBuildMap();
	CSceneInput *m_Input = manager->GetInput();
	CSceneMouse *m_Mouse = manager->GetMouse();
	CRenderer *renderer = manager->GetRenderer();
	CBuildMenu_Wall *m_BuildMenu_Wall = BuildManager->GetBuildMenu_Wall();
	CBuildMenu_Enemy *m_BuildMenu_Enemy = BuildManager->GetBuildMenu_Enemy();
	CWall_001 *m_Wall_001 = BuildManager->GetBuildWall_001(0);
	CWall_002 *m_Wall_002 = BuildManager->GetBuildWall_002(0);
	CEnemy_001 *m_Enemy_001 = BuildManager->GetEnemy_001(0);
	CEnemy_002 *m_Enemy_002 = BuildManager->GetEnemy_002(0);
	CBuildMenu *m_BuildMenu = BuildManager->GetBuildMenu();
	CBuildLight *m_BuildLight = BuildManager->GetBuildLight();
	CCeiling *m_Ceiling = BuildManager->GetCeiling(0);
	CDoor *m_Door = BuildManager->GetDoor();
	CPoint *m_Point = BuildManager->GetPoint();
	CStart *m_Start = BuildManager->GetStart();
	CEnd *m_End = BuildManager->GetEnd();
	CRobot *m_Robot = BuildManager->GetRobot();

	//�g�p���Ȃ��̏ꍇ�A������FALSE
	m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
	m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
	m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
	m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
	m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
	m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
	m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
	m_Start->m_type = m_Start->START_BUILDING_FALSE;
	m_End->m_type = m_End->END_BUILDING_FALSE;
	m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;
}

/*******************************************************************************
�֐����F	void CBuildMap::Uninit
�߂�l�F	void
�����F		void
�����F		CBuildMap�̏I������
*******************************************************************************/
void CBuildMap::Uninit(void)
{

}

/*******************************************************************************
�֐����F	void CBuildMap::Update
�߂�l�F	void
�����F		void
�����F		CBuildMap�̍X�V����
*******************************************************************************/
void CBuildMap::Update(HINSTANCE hInstance, HWND hWnd)
{
	CManager *manager = GetManager();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildMap *m_BuildMap = BuildManager->GetBuildMap();
	CSceneInput *m_Input = manager->GetInput();
	CSceneMouse *m_Mouse = manager->GetMouse();
	CRenderer *renderer = manager->GetRenderer();
	CBuildMenu_Wall *m_BuildMenu_Wall = BuildManager->GetBuildMenu_Wall();
	CBuildMenu_Enemy *m_BuildMenu_Enemy = BuildManager->GetBuildMenu_Enemy();
	CWall_001 *m_Wall_001 = BuildManager->GetBuildWall_001(0);
	CWall_002 *m_Wall_002 = BuildManager->GetBuildWall_002(0);
	CEnemy_001 *m_Enemy_001 = BuildManager->GetEnemy_001(0);
	CEnemy_002 *m_Enemy_002 = BuildManager->GetEnemy_002(0);
	CBuildMenu *m_BuildMenu = BuildManager->GetBuildMenu();
	CBuildLight *m_BuildLight = BuildManager->GetBuildLight();
	CTrail *m_Trail = BuildManager->GetBuildTrail();
	CCeiling *m_Ceiling = BuildManager->GetCeiling(0);
	CDoor *m_Door = BuildManager->GetDoor();
	CBuildMenu_Prop *m_BuildMenu_Prop = BuildManager->GetBuildMenu_Prop();
	CPoint *m_Point = BuildManager->GetPoint();
	CStart *m_Start = BuildManager->GetStart();
	CBuildMenu_Another *m_BuildMenu_Another = BuildManager->GetBuildMenu_Another();
	CEnd *m_End = BuildManager->GetEnd();
	CRobot *m_Robot = BuildManager->GetRobot();

	/*�Љ�robot�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_ANOTHER
	//Another Menu��Menu:BUILD_MENU_ANOTHER_PRESENT
	if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ANOTHER && m_BuildMenu_Another->m_type == m_BuildMenu_Another->BUILD_MENU_ANOTHER_PRESENT)
	{
		//���̈ȊO�̃��m�S��FALSE
		m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
		m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
		m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
		m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
		m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
		m_Start->m_type = m_Start->START_BUILDING_FALSE;
		m_End->m_type = m_End->END_BUILDING_FALSE;
		//�uI�v�{�^���������A
		//��ԁFROBOT_BUILDING_FRONT�i���j
		if (m_Robot->m_type != m_Robot->ROBOT_BUILDING_FRONT && m_Input->GetKeyboardTrigger(DIK_I))
		{
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_FRONT;
		}
		//	�}�E�X�̍��{�^������
		if (m_Robot->m_type == m_Robot->ROBOT_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�ƌ������|�C���^����n��
			p_Robot[0]->m_Position = m_Robot->m_Position;
			p_Robot[0]->m_Rotation = m_Robot->m_Rotation;

			//�f�[�^�̕ۑ�
			PosX = (int)p_Robot[i]->m_Position.x;
			PosY = (int)p_Robot[i]->m_Position.y;
			PosZ = (int)p_Robot[i]->m_Position.z;
			RotX = p_Robot[i]->m_Rotation.x;
			RotY = p_Robot[i]->m_Rotation.y;
			RotZ = p_Robot[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}

		//�uK�v�{�^���������A
		//��ԁFROBOT_BUILDING_BACK�i���j
		if (m_Robot->m_type != m_Robot->ROBOT_BUILDING_BACK &&m_Input->GetKeyboardTrigger(DIK_K))
		{
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_BACK;
		}

		//	�}�E�X�̍��{�^������
		if (m_Robot->m_type == m_Robot->ROBOT_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�ƌ������|�C���^����n��
			p_Robot[0]->m_Position = m_Robot->m_Position;
			p_Robot[0]->m_Rotation = m_Robot->m_Rotation;

			//�f�[�^�̕ۑ�
			PosX = (int)p_Robot[i]->m_Position.x;
			PosY = (int)p_Robot[i]->m_Position.y;
			PosZ = (int)p_Robot[i]->m_Position.z;
			RotX = p_Robot[i]->m_Rotation.x;
			RotY = p_Robot[i]->m_Rotation.y;
			RotZ = p_Robot[i]->m_Rotation.z;


			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}

		//�uJ�v�{�^���������A
		//��ԁFROBOT_BUILDING_LEFT�i���j
		if (m_Robot->m_type != m_Robot->ROBOT_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
		{
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_LEFT;
		}

		//	�}�E�X�̍��{�^������
		if (m_Robot->m_type == m_Robot->ROBOT_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�ƌ������|�C���^����n��
			p_Robot[0]->m_Position = m_Robot->m_Position;
			p_Robot[0]->m_Rotation = m_Robot->m_Rotation;
			//�f�[�^�̕ۑ�
			PosX = (int)p_Robot[i]->m_Position.x;
			PosY = (int)p_Robot[i]->m_Position.y;
			PosZ = (int)p_Robot[i]->m_Position.z;
			RotX = p_Robot[i]->m_Rotation.x;
			RotY = p_Robot[i]->m_Rotation.y;
			RotZ = p_Robot[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}

		//�uL�v�{�^���������A
		//��ԁFROBOT_BUILDING_RIGHT�i���j
		if (m_Robot->m_type != m_Robot->ROBOT_BUILDING_RIGHT && m_Input->GetKeyboardTrigger(DIK_L))
		{
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_RIGHT;
		}

		//	�}�E�X�̍��{�^������
		if (m_Robot->m_type == m_Robot->ROBOT_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�ƌ������|�C���^����n��
			p_Robot[0]->m_Position = m_Robot->m_Position;
			p_Robot[0]->m_Rotation = m_Robot->m_Rotation;
			//�f�[�^�̕ۑ�
			PosX = (int)p_Robot[i]->m_Position.x;
			PosY = (int)p_Robot[i]->m_Position.y;
			PosZ = (int)p_Robot[i]->m_Position.z;
			RotX = p_Robot[i]->m_Rotation.x;
			RotY = p_Robot[i]->m_Rotation.y;
			RotZ = p_Robot[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}
	}
	/*�Љ�robot�̏����I��*/

	/*start�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_ANOTHER
	//Another Menu��Menu:BUILD_MENU_ANOTHER_START
	if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ANOTHER && m_BuildMenu_Another->m_type == m_BuildMenu_Another->BUILD_MENU_ANOTHER_START)
	{
		//���̈ȊO�̃��m�S��FALSE
		m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
		m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
		m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
		m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
		m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
		m_Start->m_type = m_Start->START_BUILDING_TRUE;
		m_End->m_type = m_End->END_BUILDING_FALSE;
		m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;

		//	�}�E�X�̍��{�^������(���������Ȃ�)
		if (m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�̃|�C���^����n��
			p_Start[0]->m_Position = m_Start->m_Position;
			//�f�[�^�̕ۑ�
			PosX = (int)p_Start[i]->m_Position.x;
			PosY = (int)p_Start[i]->m_Position.y;
			PosZ = (int)p_Start[i]->m_Position.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\start_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\n", PosX, PosY, PosZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}
	}
	/*start�̏����I��*/

	/*end�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_ANOTHER
	//Another Menu��Menu:BUILD_MENU_ANOTHER_END
	if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ANOTHER && m_BuildMenu_Another->m_type == m_BuildMenu_Another->BUILD_MENU_ANOTHER_END)
	{
		//���̈ȊO�̃��m�S��FALSE
		m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
		m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
		m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
		m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
		m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
		m_Start->m_type = m_Start->START_BUILDING_FALSE;
		m_End->m_type = m_End->END_BUILDING_TRUE;
		m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;
		//	�}�E�X�̍��{�^������(���������Ȃ�)
		if (m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�ʒu�̃|�C���^����n��
			p_End[0]->m_Position = m_End->m_Position;
			//�f�[�^�̕ۑ�
			PosX = (int)p_End[i]->m_Position.x;
			PosY = (int)p_End[i]->m_Position.y;
			PosZ = (int)p_End[i]->m_Position.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\ANOTHER\\end_Map01.txt", "w+");//�uw+�v�Ƃ͏������݂Ɠǂݍ��� �ɂ���i�㏑���j
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\n", PosX, PosY, PosZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}
	}
	/*end�̏����I��*/

	/*point�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_PROP
	//Another Menu��Menu:BUILD_MENU_PROP_POINT
	if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_PROP && m_BuildMenu_Prop->m_type == m_BuildMenu_Prop->BUILD_MENU_PROP_POINT)
	{
		//���̈ȊO�̃��m�S��FALSE
		m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
		m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
		m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
		m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
		m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		m_Point->m_type = m_Point->POINT_BUILDING_TRUE;
		m_Start->m_type = m_Start->START_BUILDING_FALSE;
		m_End->m_type = m_End->END_BUILDING_FALSE;
		m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;
		//	�}�E�X�̍��{�^������(���������Ȃ�)
		if (m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Point[0] = CPoint::Create(D3DXVECTOR3((int)m_Point->m_Position.x, (int)m_Point->m_Position.y, (int)m_Point->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_POINT);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Point[i]->m_Position.x;
			PosY = (int)p_Point[i]->m_Position.y;
			PosZ = (int)p_Point[i]->m_Position.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\PROP\\point_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\n", PosX, PosY, PosZ);
			// �t�@�C���N���[�Y
			fclose(pFile);
		}
	}
	/*point�̏����I��*/

	/*door�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_PROP
	//Another Menu��Menu:BUILD_MENU_PROP_DOOR
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_PROP && m_BuildMenu_Prop->m_type == m_BuildMenu_Prop->BUILD_MENU_PROP_DOOR)
		{
			//���̈ȊO�̃��m�S��FALSE
			m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
			m_Trail->m_type = m_Trail->TRAIL_BUILDING_FALSE;
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
			m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
			m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
			m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
			m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
			m_Start->m_type = m_Start->START_BUILDING_FALSE;
			m_End->m_type = m_End->END_BUILDING_FALSE;

			//�uI�v�{�^���������A
			//��ԁFDOOR_BUILDING_FRONT�i���j
		if (m_Door->m_type != m_Door->DOOR_BUILDING_FRONT &&m_Input->GetKeyboardTrigger(DIK_I))
		{
			m_Door->m_type = m_Door->DOOR_BUILDING_FRONT;
		}
		//	�}�E�X�̍��{�^������
		if (m_Door->m_type == m_Door->DOOR_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Door[0] = CDoor::Create(D3DXVECTOR3((int)m_Door->m_Position.x, (int)m_Door->m_Position.y, (int)m_Door->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Door[i]->m_Position.x;
			PosY = (int)p_Door[i]->m_Position.y;
			PosZ = (int)p_Door[i]->m_Position.z;
			RotX = p_Door[i]->m_Rotation.x;
			RotY = p_Door[i]->m_Rotation.y;
			RotZ = p_Door[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\PROP\\Door_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);
		}
		//�uK�v�{�^���������A
		//��ԁFDOOR_BUILDING_BACK�i���j
		if (m_Door->m_type != m_Door->DOOR_BUILDING_BACK && m_Input->GetKeyboardTrigger(DIK_K))
		{
			m_Door->m_type = m_Door->DOOR_BUILDING_BACK;
		}
		//	�}�E�X�̍��{�^������
		if (m_Door->m_type == m_Door->DOOR_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Door[0] = CDoor::Create(D3DXVECTOR3((int)m_Door->m_Position.x, (int)m_Door->m_Position.y, (int)m_Door->m_Position.z), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Door[i]->m_Position.x;
			PosY = (int)p_Door[i]->m_Position.y;
			PosZ = (int)p_Door[i]->m_Position.z;
			RotX = p_Door[i]->m_Rotation.x;
			RotY = p_Door[i]->m_Rotation.y;
			RotZ = p_Door[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\PROP\\Door_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}

		//�uJ�v�{�^���������A
		//��ԁFDOOR_BUILDING_LEFT�i���j
		if (m_Door->m_type != m_Door->DOOR_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
		{
			m_Door->m_type = m_Door->DOOR_BUILDING_LEFT;
		}
		//	�}�E�X�̍��{�^������
		if (m_Door->m_type == m_Door->DOOR_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Door[0] = CDoor::Create(D3DXVECTOR3((int)m_Door->m_Position.x, (int)m_Door->m_Position.y, (int)m_Door->m_Position.z), D3DXVECTOR3(0.0f, -1.57f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Door[i]->m_Position.x;
			PosY = (int)p_Door[i]->m_Position.y;
			PosZ = (int)p_Door[i]->m_Position.z;	
			RotX = p_Door[i]->m_Rotation.x;
			RotY = p_Door[i]->m_Rotation.y;
			RotZ = p_Door[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\PROP\\Door_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

		}

		//�uL�v�{�^���������A
		//��ԁFDOOR_BUILDING_RIGHT�i���j
		if (m_Door->m_type != m_Door->DOOR_BUILDING_RIGHT &&m_Input->GetKeyboardTrigger(DIK_L))
		{
			m_Door->m_type = m_Door->DOOR_BUILDING_RIGHT;
		}
		//	�}�E�X�̍��{�^������
		if (m_Door->m_type == m_Door->DOOR_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Door[0] = CDoor::Create(D3DXVECTOR3((int)m_Door->m_Position.x, (int)m_Door->m_Position.y, (int)m_Door->m_Position.z), D3DXVECTOR3(0.0f, 1.57f, 0.0f), 0.0f, 0.0f, MODEL_DOOR);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Door[i]->m_Position.x;
			PosY = (int)p_Door[i]->m_Position.y;
			PosZ = (int)p_Door[i]->m_Position.z;
			RotX = p_Door[i]->m_Rotation.x;
			RotY = p_Door[i]->m_Rotation.y;
			RotZ = p_Door[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\PROP\\Door_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);
		}
	}
	/*door�̏����I��*/


	/*�V��̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_CEILING
	//ceiling Menu��Menu:NULL
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_CEILING)
		{
			//���̈ȊO�̃��m�S��FALSE
			m_Trail->m_type = m_Trail->TRAIL_BUILDING_FALSE;
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
			m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
			m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
			m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
			m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_TRUE;
			m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
			m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
			m_Start->m_type = m_Start->START_BUILDING_FALSE;
			m_End->m_type = m_End->END_BUILDING_FALSE;
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;
			//	�}�E�X�̍��{�^������
			if (m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Ceiling[0] = CCeiling::Create(D3DXVECTOR3((int)m_Ceiling->m_Position.x, (int)m_Ceiling->m_Position.y, (int)m_Ceiling->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_CEILING_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Ceiling[i]->m_Position.x;
				PosY = (int)p_Ceiling[i]->m_Position.y;
				PosZ = (int)p_Ceiling[i]->m_Position.z;


				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\CEILING\\ceiling_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
				// �����o��
				fprintf_s(pFile, "pos = %d %d %d\n", PosX, PosY, PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*�V��̏����I��*/

	/*��001�̏����J�n*/
	//��������:
	//Menu:BUILD_MENU_WALL
	//�� Menu��Menu:BUILD_MENU_WALL_01
	if ( m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_WALL  && m_BuildMenu_Wall->m_type == m_BuildMenu_Wall->BUILD_MENU_WALL_01)
	{
		//���̈ȊO�̃��m�S��FALSE
		m_Trail->m_type = m_Trail->TRAIL_BUILDING_FALSE;
		m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
		m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
		m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
		m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
		m_Start->m_type = m_Start->START_BUILDING_FALSE;
		m_End->m_type = m_End->END_BUILDING_FALSE;
		m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;

		//�uI�v�{�^���������A
		//��ԁFWALL_001_BUILDING_FRONT�i���j
		if (m_Wall_001->m_type != m_Wall_001->WALL_001_BUILDING_FRONT &&m_Input->GetKeyboardTrigger(DIK_I))
		{
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FRONT;
		}

		//	�}�E�X�̍��{�^������
		if (m_Wall_001->m_type == m_Wall_001->WALL_001_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//�`�悷��
			p_Wall_001[0] = CWall_001::Create(D3DXVECTOR3((int)m_Wall_001->m_Position.x, (int)m_Wall_001->m_Position.y, (int)m_Wall_001->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_001_FILE);
			//�f�[�^�̕ۑ�
			PosX = (int)p_Wall_001[i]->m_Position.x;
			PosY = (int)p_Wall_001[i]->m_Position.y;
			PosZ = (int)p_Wall_001[i]->m_Position.z;
			RotX = p_Wall_001[i]->m_Rotation.x;
			RotY = p_Wall_001[i]->m_Rotation.y;
			RotZ = p_Wall_001[i]->m_Rotation.z;

			FILE *pFile;
			// �t�@�C���I�[�v��
			pFile = fopen("data\\SCRIPT\\WALL\\wall_01_Map01.txt","a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
			// �����o��
			fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
			// �t�@�C���N���[�Y
			fclose(pFile);

			}

			//�uK�v�{�^���������A
			//��ԁFWALL_001_BUILDING_BACK�i���j
			if (m_Wall_001->m_type != m_Wall_001->WALL_001_BUILDING_BACK &&m_Input->GetKeyboardTrigger(DIK_K))
			{
				m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_BACK;
			}

			//	�}�E�X�̍��{�^������
			if (m_Wall_001->m_type == m_Wall_001->WALL_001_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_001[0] = CWall_001::Create(D3DXVECTOR3((int)m_Wall_001->m_Position.x, (int)m_Wall_001->m_Position.y, (int)m_Wall_001->m_Position.z), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_001_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_001[i]->m_Position.x;
				PosY = (int)p_Wall_001[i]->m_Position.y;
				PosZ = (int)p_Wall_001[i]->m_Position.z;
				RotX = p_Wall_001[i]->m_Rotation.x;
				RotY = p_Wall_001[i]->m_Rotation.y;
				RotZ = p_Wall_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
				// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}


			//�uJ�v�{�^���������A
			//��ԁFWALL_001_BUILDING_LEFT�i���j
			if (m_Wall_001->m_type != m_Wall_001->WALL_001_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
			{
				m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_LEFT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Wall_001->m_type == m_Wall_001->WALL_001_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_001[0] = CWall_001::Create(D3DXVECTOR3((int)m_Wall_001->m_Position.x, (int)m_Wall_001->m_Position.y, (int)m_Wall_001->m_Position.z), D3DXVECTOR3(0.0f, -1.57f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_001_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_001[i]->m_Position.x;
				PosY = (int)p_Wall_001[i]->m_Position.y;
				PosZ = (int)p_Wall_001[i]->m_Position.z;
				RotX = p_Wall_001[i]->m_Rotation.x;
				RotY = p_Wall_001[i]->m_Rotation.y;
				RotZ = p_Wall_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
				// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}

			//�uL�v�{�^���������A
			//��ԁFWALL_001_BUILDING_RIGHT�i���j
			if (m_Wall_001->m_type != m_Wall_001->WALL_001_BUILDING_RIGHT &&m_Input->GetKeyboardTrigger(DIK_L))
			{
				m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_RIGHT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Wall_001->m_type == m_Wall_001->WALL_001_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_001[0] = CWall_001::Create(D3DXVECTOR3((int)m_Wall_001->m_Position.x, (int)m_Wall_001->m_Position.y, (int)m_Wall_001->m_Position.z), D3DXVECTOR3(0.0f, 1.57f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_001_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_001[i]->m_Position.x;
				PosY = (int)p_Wall_001[i]->m_Position.y;
				PosZ = (int)p_Wall_001[i]->m_Position.z;
				RotX = p_Wall_001[i]->m_Rotation.x;
				RotY = p_Wall_001[i]->m_Rotation.y;
				RotZ = p_Wall_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
				// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*��001�̏����I��*/
		/*��002�̏����J�n*/
		//��������:
		//Menu:BUILD_MENU_WALL
		//�� Menu��Menu:BUILD_MENU_WALL_02
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_WALL  && m_BuildMenu_Wall->m_type == m_BuildMenu_Wall->BUILD_MENU_WALL_02)
		{
			//���̈ȊO�̃��m�S��FALSE
			m_Trail->m_type = m_Trail->TRAIL_BUILDING_FALSE;
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
			m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
			m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
			m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
			m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
			m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
			m_Start->m_type = m_Start->START_BUILDING_FALSE;
			m_End->m_type = m_End->END_BUILDING_FALSE;
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;

			//�uI�v�{�^���������A
			//��ԁFWALL_002_BUILDING_FRONT�i���j
			if (m_Wall_002->m_type != m_Wall_002->WALL_002_BUILDING_FRONT &&m_Input->GetKeyboardTrigger(DIK_I))
			{
				m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FRONT;
			}

			//	�}�E�X�̍��{�^������
			if (m_Wall_002->m_type == m_Wall_002->WALL_002_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_002[0] = CWall_002::Create(D3DXVECTOR3((int)m_Wall_002->m_Position.x, (int)m_Wall_002->m_Position.y, (int)m_Wall_002->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_002_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_002[i]->m_Position.x;
				PosY = (int)p_Wall_002[i]->m_Position.y;
				PosZ = (int)p_Wall_002[i]->m_Position.z;
				RotX = p_Wall_002[i]->m_Rotation.x;
				RotY = p_Wall_002[i]->m_Rotation.y;
				RotZ = p_Wall_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}

			//�uK�v�{�^���������A
			//��ԁFWALL_002_BUILDING_BACK�i���j
			if (m_Wall_002->m_type != m_Wall_002->WALL_002_BUILDING_BACK &&m_Input->GetKeyboardTrigger(DIK_K))
			{
				m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_BACK;
			}

			//	�}�E�X�̍��{�^������
			if (m_Wall_002->m_type == m_Wall_002->WALL_002_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_002[0] = CWall_002::Create(D3DXVECTOR3((int)m_Wall_002->m_Position.x, (int)m_Wall_002->m_Position.y, (int)m_Wall_002->m_Position.z), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_002_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_002[i]->m_Position.x;
				PosY = (int)p_Wall_002[i]->m_Position.y;
				PosZ = (int)p_Wall_002[i]->m_Position.z;
				RotX = p_Wall_002[i]->m_Rotation.x;
				RotY = p_Wall_002[i]->m_Rotation.y;
				RotZ = p_Wall_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}


			//�uJ�v�{�^���������A
			//��ԁFWALL_002_BUILDING_LEFT�i���j
			if (m_Wall_002->m_type != m_Wall_002->WALL_002_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
			{
				m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_LEFT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Wall_002->m_type == m_Wall_002->WALL_002_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_002[0] = CWall_002::Create(D3DXVECTOR3((int)m_Wall_002->m_Position.x, (int)m_Wall_002->m_Position.y, (int)m_Wall_002->m_Position.z), D3DXVECTOR3(0.0f, -1.57f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_002_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_002[i]->m_Position.x;
				PosY = (int)p_Wall_002[i]->m_Position.y;
				PosZ = (int)p_Wall_002[i]->m_Position.z;
				RotX = p_Wall_002[i]->m_Rotation.x;
				RotY = p_Wall_002[i]->m_Rotation.y;
				RotZ = p_Wall_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}

			//�uL�v�{�^���������A
			//��ԁFWALL_002_BUILDING_RIGHT�i���j
			if (m_Wall_002->m_type != m_Wall_002->WALL_002_BUILDING_RIGHT &&m_Input->GetKeyboardTrigger(DIK_L))
			{
				m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_RIGHT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Wall_002->m_type == m_Wall_002->WALL_002_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Wall_002[0] = CWall_002::Create(D3DXVECTOR3((int)m_Wall_002->m_Position.x, (int)m_Wall_002->m_Position.y, (int)m_Wall_002->m_Position.z), D3DXVECTOR3(0.0f, 1.57f, 0.0f), 200.0f, 200.0f, TEXTURE_WALL_002_FILE);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Wall_002[i]->m_Position.x;
				PosY = (int)p_Wall_002[i]->m_Position.y;
				PosZ = (int)p_Wall_002[i]->m_Position.z;
				RotX = p_Wall_002[i]->m_Rotation.x;
				RotY = p_Wall_002[i]->m_Rotation.y;
				RotZ = p_Wall_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\WALL\\wall_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*��002�̏����I��*/

		/*�G001�̏����J�n*/
		//��������:
		//Menu:BUILD_MENU_ENEMY
		//�G Menu��Menu:BUILD_MENU_ENEMY_01
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ENEMY  && m_BuildMenu_Enemy->m_type == m_BuildMenu_Enemy->BUILD_MENU_ENEMY_01)
		{
			//���̈ȊO�̃��m�S��FALSE
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
			m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
			m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FALSE;
			m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
			m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
			m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
			m_Start->m_type = m_Start->START_BUILDING_FALSE;
			m_End->m_type = m_End->END_BUILDING_FALSE;
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;

			//�uI�v�{�^���������A
			//��ԁFENEMY_001_BUILDING_FRONT�i���j
			if (m_Enemy_001->m_type != m_Enemy_001->ENEMY_001_BUILDING_FRONT &&m_Input->GetKeyboardTrigger(DIK_I))
			{
				m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FRONT;
				//��ԁFTRAIL_BUILDING_FRONT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_FRONT;

			}

			//	�}�E�X�̍��{�^������
			if (m_Enemy_001->m_type == m_Enemy_001->ENEMY_001_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3((int)m_Enemy_001->m_Position.x, (int)m_Enemy_001->m_Position.y, (int)m_Enemy_001->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 200.0f, 200.0f, MODEL_ENEMY_001);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_001[i]->m_Position.x;
				PosY = (int)p_Enemy_001[i]->m_Position.y;
				PosZ = (int)p_Enemy_001[i]->m_Position.z;
				RotX = p_Enemy_001[i]->m_Rotation.x;
				RotY = p_Enemy_001[i]->m_Rotation.y;
				RotZ = p_Enemy_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}

			//�uK�v�{�^���������A
			//��ԁFENEMY_001_BUILDING_BACK�i���j
			if (m_Enemy_001->m_type != m_Enemy_001->ENEMY_001_BUILDING_BACK &&m_Input->GetKeyboardTrigger(DIK_K))
			{
				m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_BACK;
				//��ԁFTRAIL_BUILDING_BACK�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_BACK;
			}

			//	�}�E�X�̍��{�^������
			if (m_Enemy_001->m_type == m_Enemy_001->ENEMY_001_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3((int)m_Enemy_001->m_Position.x, (int)m_Enemy_001->m_Position.y, (int)m_Enemy_001->m_Position.z), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 200.0f, 200.0f, MODEL_ENEMY_001);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_001[i]->m_Position.x;
				PosY = (int)p_Enemy_001[i]->m_Position.y;
				PosZ = (int)p_Enemy_001[i]->m_Position.z;
				RotX = p_Enemy_001[i]->m_Rotation.x;
				RotY = p_Enemy_001[i]->m_Rotation.y;
				RotZ = p_Enemy_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}


			//�uJ�v�{�^���������A
			//��ԁFENEMY_001_BUILDING_LEFT�i���j
			if (m_Enemy_001->m_type != m_Enemy_001->ENEMY_001_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
			{
				m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_LEFT;
				//��ԁFTRAIL_BUILDING_LEFT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_LEFT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Enemy_001->m_type == m_Enemy_001->ENEMY_001_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3((int)m_Enemy_001->m_Position.x, (int)m_Enemy_001->m_Position.y, (int)m_Enemy_001->m_Position.z), D3DXVECTOR3(0.0f, -1.57f, 0.0f), 200.0f, 200.0f, MODEL_ENEMY_001);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_001[i]->m_Position.x;
				PosY = (int)p_Enemy_001[i]->m_Position.y;
				PosZ = (int)p_Enemy_001[i]->m_Position.z;
				RotX = p_Enemy_001[i]->m_Rotation.x;
				RotY = p_Enemy_001[i]->m_Rotation.y;
				RotZ = p_Enemy_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}

			//�uL�v�{�^���������A
			//��ԁFENEMY_001_BUILDING_RIGHT�i���j
			if (m_Enemy_001->m_type != m_Enemy_001->ENEMY_001_BUILDING_RIGHT &&m_Input->GetKeyboardTrigger(DIK_L))
			{
				m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_RIGHT;
				//��ԁFTRAIL_BUILDING_RIGHT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_RIGHT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Enemy_001->m_type == m_Enemy_001->ENEMY_001_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_001[0] = CEnemy_001::Create(D3DXVECTOR3((int)m_Enemy_001->m_Position.x, (int)m_Enemy_001->m_Position.y, (int)m_Enemy_001->m_Position.z), D3DXVECTOR3(0.0f, 1.57f, 0.0f), 200.0f, 200.0f, MODEL_ENEMY_001);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_001[i]->m_Position.x;
				PosY = (int)p_Enemy_001[i]->m_Position.y;
				PosZ = (int)p_Enemy_001[i]->m_Position.z;
				RotX = p_Enemy_001[i]->m_Rotation.x;
				RotY = p_Enemy_001[i]->m_Rotation.y;
				RotZ = p_Enemy_001[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*�G001�̏����I��*/

		/*�G002�̏����J�n*/
		//��������:
		//Menu:BUILD_MENU_ENEMY
		//�G Menu��Menu:BUILD_MENU_ENEMY_02
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ENEMY  && m_BuildMenu_Enemy->m_type == m_BuildMenu_Enemy->BUILD_MENU_ENEMY_02)
		{
			//���̈ȊO�̃��m�S��FALSE
			m_Enemy_001->m_type = m_Enemy_001->ENEMY_001_BUILDING_FALSE;
			m_Wall_001->m_type = m_Wall_001->WALL_001_BUILDING_FALSE;
			m_Wall_002->m_type = m_Wall_002->WALL_002_BUILDING_FALSE;
			m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
			m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
			m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
			m_Start->m_type = m_Start->START_BUILDING_FALSE;
			m_End->m_type = m_End->END_BUILDING_FALSE;
			m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;

			//�uI�v�{�^���������A
			//��ԁFENEMY_002_BUILDING_FRONT�i���j
			if (m_Enemy_002->m_type != m_Enemy_002->ENEMY_002_BUILDING_FRONT &&m_Input->GetKeyboardTrigger(DIK_I))
			{
				m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_FRONT;
				//��ԁFTRAIL_BUILDING_FRONT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_FRONT;
			}

			//	�}�E�X�̍��{�^������
			if (m_Enemy_002->m_type == m_Enemy_002->ENEMY_002_BUILDING_FRONT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3((int)m_Enemy_002->m_Position.x, (int)m_Enemy_002->m_Position.y, (int)m_Enemy_002->m_Position.z), D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_002[i]->m_Position.x;
				PosY = (int)p_Enemy_002[i]->m_Position.y;
				PosZ = (int)p_Enemy_002[i]->m_Position.z;
				RotX = p_Enemy_002[i]->m_Rotation.x;
				RotY = p_Enemy_002[i]->m_Rotation.y;
				RotZ = p_Enemy_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}

			//�uK�v�{�^���������A
			//��ԁFENEMY_002_BUILDING_BACK�i���j
			if (m_Enemy_002->m_type != m_Enemy_002->ENEMY_002_BUILDING_BACK &&m_Input->GetKeyboardTrigger(DIK_K))
			{
				m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_BACK;
				//��ԁFTRAIL_BUILDING_BACK�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_BACK;
			}

			//	�}�E�X�̍��{�^������
			if (m_Enemy_002->m_type == m_Enemy_002->ENEMY_002_BUILDING_BACK && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3((int)m_Enemy_002->m_Position.x, (int)m_Enemy_002->m_Position.y, (int)m_Enemy_002->m_Position.z), D3DXVECTOR3(0.0f, 3.14f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_002[i]->m_Position.x;
				PosY = (int)p_Enemy_002[i]->m_Position.y;
				PosZ = (int)p_Enemy_002[i]->m_Position.z;
				RotX = p_Enemy_002[i]->m_Rotation.x;
				RotY = p_Enemy_002[i]->m_Rotation.y;
				RotZ = p_Enemy_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}


			//�uJ�v�{�^���������A
			//��ԁFENEMY_002_BUILDING_LEFT�i���j
			if (m_Enemy_002->m_type != m_Enemy_002->ENEMY_002_BUILDING_LEFT &&m_Input->GetKeyboardTrigger(DIK_J))
			{
				m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_LEFT;
				//��ԁFTRAIL_BUILDING_LEFT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_LEFT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Enemy_002->m_type == m_Enemy_002->ENEMY_002_BUILDING_LEFT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3((int)m_Enemy_002->m_Position.x, (int)m_Enemy_002->m_Position.y, (int)m_Enemy_002->m_Position.z), D3DXVECTOR3(0.0f, -1.57f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_002[i]->m_Position.x;
				PosY = (int)p_Enemy_002[i]->m_Position.y;
				PosZ = (int)p_Enemy_002[i]->m_Position.z;
				RotX = p_Enemy_002[i]->m_Rotation.x;
				RotY = p_Enemy_002[i]->m_Rotation.y;
				RotZ = p_Enemy_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\wall_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}

			//�uL�v�{�^���������A
			//��ԁFENEMY_002_BUILDING_RIGHT�i���j
			if (m_Enemy_002->m_type != m_Enemy_002->ENEMY_002_BUILDING_RIGHT &&m_Input->GetKeyboardTrigger(DIK_L))
			{
				m_Enemy_002->m_type = m_Enemy_002->ENEMY_002_BUILDING_RIGHT;
				//��ԁFTRAIL_BUILDING_RIGHT�i���j�O��
				m_Trail->m_type = m_Trail->TRAIL_BUILDING_RIGHT;
			}
			//	�}�E�X�̍��{�^������
			if (m_Enemy_002->m_type == m_Enemy_002->ENEMY_002_BUILDING_RIGHT && m_Mouse->GetMouseTrigger(DIM_LEFT))
			{
				//�`�悷��
				p_Enemy_002[0] = CEnemy_002::Create(D3DXVECTOR3((int)m_Enemy_002->m_Position.x, (int)m_Enemy_002->m_Position.y, (int)m_Enemy_002->m_Position.z), D3DXVECTOR3(0.0f, 1.57f, 0.0f), 0.0f, 0.0f, MODEL_ENEMY_002);
				//�f�[�^�̕ۑ�
				PosX = (int)p_Enemy_002[i]->m_Position.x;
				PosY = (int)p_Enemy_002[i]->m_Position.y;
				PosZ = (int)p_Enemy_002[i]->m_Position.z;
				RotX = p_Enemy_002[i]->m_Rotation.x;
				RotY = p_Enemy_002[i]->m_Rotation.y;
				RotZ = p_Enemy_002[i]->m_Rotation.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���
																			// �����o��
				fprintf_s(pFile, "pos = %d %d %d\nrot = %.2f %.2f %.2f\n", PosX, PosY, PosZ, RotX, RotY, RotZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*�G002�̏����I��*/

		/*�G001�O�Ղ̏����J�n*/
		//��������:
		//Menu:BUILD_MENU_ENEMY
		//�G Menu��Menu:BUILD_MENU_ENEMY_01
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ENEMY && m_BuildMenu_Enemy->m_type == m_BuildMenu_Enemy->BUILD_MENU_ENEMY_01 && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//��ԁFTRAIL_BUILDING_FRONT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_FRONT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_001[i]->m_Position.x;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_001[i]->m_Position.z + m_Trail->Check;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
				// �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}
			//��ԁFTRAIL_BUILDING_BACK�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_BACK)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_001[i]->m_Position.x;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_001[i]->m_Position.z - m_Trail->Check;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
				// �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}

			//��ԁFTRAIL_BUILDING_LEFT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_LEFT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_001[i]->m_Position.x - m_Trail->Check;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_001[i]->m_Position.z ;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
				// �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
			//��ԁFTRAIL_BUILDING_RIGHT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_RIGHT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_001[i]->m_Position.x + m_Trail->Check;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_001[i]->m_Position.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
				// �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*�G001�O�Ղ̏����I��*/

		/*�G002�O�Ղ̏����J�n*/
		//��������:
		//Menu:BUILD_MENU_ENEMY
		//�G Menu��Menu:BUILD_MENU_ENEMY_02
		if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_ENEMY && m_BuildMenu_Enemy->m_type == m_BuildMenu_Enemy->BUILD_MENU_ENEMY_02 && m_Mouse->GetMouseTrigger(DIM_LEFT))
		{
			//��ԁFTRAIL_BUILDING_FRONT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_FRONT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_002[i]->m_Position.x;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_002[i]->m_Position.z + m_Trail->Check;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
																			  // �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}
			//��ԁFTRAIL_BUILDING_BACK�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_BACK)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_002[i]->m_Position.x;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_002[i]->m_Position.z - m_Trail->Check;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
																			  // �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);

			}

			//��ԁFTRAIL_BUILDING_LEFT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_LEFT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_002[i]->m_Position.x - m_Trail->Check;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_002[i]->m_Position.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
																			  // �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
			//��ԁFTRAIL_BUILDING_RIGHT�i���j
			if (m_Trail->m_type == m_Trail->TRAIL_BUILDING_RIGHT)
			{
				//�`�悷��
				p_Trail[0] = CTrail::Create(D3DXVECTOR3((int)m_Trail->m_Position.x, (int)m_Trail->m_Position.y, (int)m_Trail->m_Position.z), D3DXVECTOR3(m_Trail->m_Rotation.x, m_Trail->m_Rotation.y, m_Trail->m_Rotation.z), m_Trail->Check, m_Trail->m_width, TEXTURE_TRAIL_FILE);
				//�f�[�^�̕ۑ�
				m_Trail_PosX = (int)p_Enemy_002[i]->m_Position.x + m_Trail->Check;
				m_Trail_PosY = 0;
				m_Trail_PosZ = (int)p_Enemy_002[i]->m_Position.z;

				FILE *pFile;
				// �t�@�C���I�[�v��
				pFile = fopen("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", "a");//�ua�v�Ƃ͍Ō�ɒǉ��������݂���(pos��rot��)
																			  // �����o��
				fprintf_s(pFile, "Trail = %d %d %d\n", m_Trail_PosX, m_Trail_PosY, m_Trail_PosZ);
				// �t�@�C���N���[�Y
				fclose(pFile);
			}
		}
		/*�G002�O�Ղ̏����I��*/
		//�d��
		//if (m_BuildMenu->m_type == m_BuildMenu->BUILD_MENU_LIGHT)
		//{
		//	m_Ceiling->m_type = m_Ceiling->CEILING_BUILDING_FALSE;
		//	m_Door->m_type = m_Door->DOOR_BUILDING_FALSE;
		//	m_Point->m_type = m_Point->POINT_BUILDING_FALSE;
		//	m_Start->m_type = m_Start->START_BUILDING_FALSE;
		//	m_End->m_type = m_End->END_BUILDING_FALSE;
		//	m_Robot->m_type = m_Robot->ROBOT_BUILDING_FALSE;
		//	if (m_Mouse->GetMouseTrigger(DIM_LEFT))
		//	{
		//		p_Light[0] = CBuildLight::Create(D3DXVECTOR3((int)m_BuildLight->m_Position.x, (int)m_BuildLight->m_Position.y, (int)m_BuildLight->m_Position.z));
		//		PosX = m_BuildLight->m_Position.x;
		//		PosY = m_BuildLight->m_Position.y;
		//		PosZ = m_BuildLight->m_Position.z;
		//		// �t�@�C���I�[�v��
		//		pFile = fopen("data\\SCRIPT\\LIGHT\\light.txt", "a");
		//		// �����o��
		//		fprintf_s(pFile, "pos = %d %d %d\n", PosX, PosY, PosZ);
		//		// �t�@�C���N���[�Y
		//		fclose(pFile);
		//	}

		//}
		////�ǂݍ��݂̓��e�������܂�
		//if (m_Input->GetKeyboardTrigger(DIK_C))
		//{
		//	// �t�@�C���I�[�v��
		//	pFile = fopen(FILE_SCRIPT_MAP_WALL_01, "w");
		//	// �t�@�C���N���[�Y
		//	fclose(pFile);

		//	// �t�@�C���I�[�v��
		//	pFile = fopen(FILE_SCRIPT_MAP_WALL_02, "w");
		//	// �t�@�C���N���[�Y
		//	fclose(pFile);
		//}

}

/*******************************************************************************
�֐����F	void CBuildMap::Draw
�߂�l�F	void
�����F		void
�����F		CBuildMap�̕`�揈��
*******************************************************************************/
void CBuildMap::Draw(void)
{

}