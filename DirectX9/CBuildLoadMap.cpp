/********************************************************************************
* �t�@�C�����@CBuildLoadMap.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�̐��l�ǂݍ��݂̊Ǘ�
********************************************************************************/

/*******************************************************************************
�C���N���[�h�錾
*******************************************************************************/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include "main.h"
#include "scene3D.h"
#include "manager.h"
#include "scene.h"
#include "CBuildLoadMap.h"

//------------------------------------------------------------------------------
//	�֐���:	CBuildLoadMap::CBuildLoadMap
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CBuildLoadMap::CBuildLoadMap()
{


}

//------------------------------------------------------------------------------
//	�֐���:	CBuildLoadMap::~CBuildLoadMap
//	����:	�Ȃ�
//	�߂�l:	
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CBuildLoadMap::~CBuildLoadMap()
{

}

/*******************************************************************************
�֐����F	void CBuildLoadMap::Init
�߂�l�F	void
�����F		void
�����F		CBuildLoadMap�̏���������
*******************************************************************************/
void CBuildLoadMap::Init(void)
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CGameWall_001 *m_GameWall_001 = BuildManager->GetGameWall_001();
	CGameWall_002 *m_GameWall_002 = BuildManager->GetGameWall_002();
	CGameEnemy_001 *m_GameEnemy_001 = BuildManager->GetGameEnemy_001();
	CGameEnemy_002 *m_GameEnemy_002 = BuildManager->GetGameEnemy_002();
	CGameCeiling *m_GameCeiling = BuildManager->GetGameCeiling();
	CGameDoor *m_GameDoor = BuildManager->GetGameDoor();
	CGamePoint *m_GamePoint = BuildManager->GetGamePoint();
	//�ǂݍ��݂̐��̏�����
	m_Wall001_num = 0;
	m_Wall002_num = 0;
	m_Enemy001_num = 0;
	m_Enemy002_num = 0;
	m_Point_num = 0;
	m_Ceiling_num = 0;
	m_Door_num = 0;

	//�e�X�g�p�ǂݍ���
	if (access("data\\SCRIPT\\WALL\\wall_01_Map01.txt", 0) == 0)
	{
		LoadTest("data\\SCRIPT\\WALL\\wall_01_Map01.txt", hInstance, hWnd);
	}

	//��001�̓ǂݍ���
	if (access("data\\SCRIPT\\WALL\\wall_01_Map01.txt", 0) == 0)
	{
		LoadWall_001("data\\SCRIPT\\WALL\\wall_01_Map01.txt", hInstance, hWnd);
	}

	//��002�̓ǂݍ���
	if (access("data\\SCRIPT\\WALL\\wall_02_Map01.txt", 0) == 0)
	{
		LoadWall_002("data\\SCRIPT\\WALL\\wall_02_Map01.txt", hInstance, hWnd);
	}

	//�G001�̓ǂݍ���
	if (access("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", 0) == 0)
	{
		LoadEnemy_001("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", hInstance, hWnd);
	}

	//�G002�̓ǂݍ���
	if (access("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", 0) == 0)
	{
		LoadEnemy_002("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", hInstance, hWnd);
	}

	//�V��̓ǂݍ���
	if (access("data\\SCRIPT\\CEILING\\ceiling_Map01.txt", 0) == 0)
	{
		LoadCeiling("data\\SCRIPT\\CEILING\\ceiling_Map01.txt", hInstance, hWnd);
	}

	//�h�A���f���̓ǂݍ���
	if (access("data\\SCRIPT\\PROP\\Door_Map01.txt", 0) == 0)
	{
		LoadDoor("data\\SCRIPT\\PROP\\Door_Map01.txt", hInstance, hWnd);
	}

	//�������f���̓ǂݍ���
	if (access("data\\SCRIPT\\PROP\\point_Map01.txt", 0) == 0)
	{
		LoadPoint("data\\SCRIPT\\PROP\\point_Map01.txt", hInstance, hWnd);
	}

	//�v���C���[�ŏ��ʒu�̓ǂݍ���
	if (access("data\\SCRIPT\\ANOTHER\\start_Map01.txt", 0) == 0)
	{
		LoadStart("data\\SCRIPT\\ANOTHER\\start_Map01.txt", hInstance, hWnd);
	}

	//�Q�[���I���ʒu�̓ǂݍ���
	if (access("data\\SCRIPT\\ANOTHER\\end_Map01.txt", 0) == 0)
	{
		LoadEnd("data\\SCRIPT\\ANOTHER\\end_Map01.txt", hInstance, hWnd);
	}

	//���[�����������̃��f���̓ǂݍ���
	if (access("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", 0) == 0)
	{
		LoadRobot("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", hInstance, hWnd);
	}

}

/*******************************************************************************
�֐����F	void CBuildLoadMap::Uninit
�߂�l�F	void
�����F		void
�����F		CBuildLoadMap�̏I������
*******************************************************************************/
void CBuildLoadMap::Uninit(void)
{

}

/*******************************************************************************
�֐����F	void CBuildLoadMap::Update
�߂�l�F	void
�����F		void
�����F		CBuildLoadMap�̍X�V����
*******************************************************************************/
void CBuildLoadMap::Update()
{


}

/*******************************************************************************
�֐����F	void CBuildLoadMap::Draw
�߂�l�F	void
�����F		void
�����F		CBuildLoadMap�̕`�揈��
*******************************************************************************/
void CBuildLoadMap::Draw(void)
{

}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadWall_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Wall001)
*******************************************************************************/
void CBuildLoadMap::LoadWall_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;

	// �t�@�C���Ǎ�
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾���邬�傤
			//������̔�r
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			else if (strcmp(aStr, "rot") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);

				m_Pos_Wall_001[i].x = fPosX[i];
				m_Pos_Wall_001[i].y = fPosY[i];
				m_Pos_Wall_001[i].z = fPosZ[i];

				m_Rot_Wall_001[i].x = fRotX[i];
				m_Rot_Wall_001[i].y = fRotY[i];
				m_Rot_Wall_001[i].z = fRotZ[i];
				i++;
				m_Wall001_num = i - 1;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadWall_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Wall002)
*******************************************************************************/
void CBuildLoadMap::LoadWall_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;
	// �t�@�C���Ǎ�
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{

				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			else if (strcmp(aStr, "rot") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);

				m_Pos_Wall_002[i].x = fPosX[i];
				m_Pos_Wall_002[i].y = fPosY[i];
				m_Pos_Wall_002[i].z = fPosZ[i];

				m_Rot_Wall_002[i].x = fRotX[i];
				m_Rot_Wall_002[i].y = fRotY[i];
				m_Rot_Wall_002[i].z = fRotZ[i];
				i++;
				m_Wall002_num = i - 1;
			}
		}
	}

	fclose(pFile);

}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadEnemy_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Enemy001)
*******************************************************************************/
void CBuildLoadMap::LoadEnemy_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fPos_To[i].x = 0.0f;
		fPos_To[i].y = 0.0f;
		fPos_To[i].z = 0.0f;
	}
	i = 0;
	// �t�@�C���Ǎ�
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			if (strcmp(aStr, "rot") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);
			}
			else if (strcmp(aStr, "Trail") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fPos_To[i].x, &fPos_To[i].y, &fPos_To[i].z);
				m_Pos_Enemy_001[i].x = fPosX[i];
				m_Pos_Enemy_001[i].y = fPosY[i];
				m_Pos_Enemy_001[i].z = fPosZ[i];

				m_Rot_Enemy_001[i].x = fRotX[i];
				m_Rot_Enemy_001[i].y = fRotY[i];
				m_Rot_Enemy_001[i].z = fRotZ[i];
				//�G001�̋O��
				m_Pos_To_Enemy_001[i].x = fPos_To[i].x;
				m_Pos_To_Enemy_001[i].y = fPos_To[i].y;
				m_Pos_To_Enemy_001[i].z = fPos_To[i].z;
				i++;
				m_Enemy001_num = i - 1;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadEnemy_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Enemy002)
*******************************************************************************/
void CBuildLoadMap::LoadEnemy_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fPos_To[i].x = 0.0f;
		fPos_To[i].y = 0.0f;
		fPos_To[i].z = 0.0f;
	}
	i = 0;
	// �t�@�C���Ǎ�

	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			if (strcmp(aStr, "rot") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);
			}
			else if (strcmp(aStr, "Trail") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fPos_To[i].x, &fPos_To[i].y, &fPos_To[i].z);
				m_Pos_Enemy_002[i].x = fPosX[i];
				m_Pos_Enemy_002[i].y = fPosY[i];
				m_Pos_Enemy_002[i].z = fPosZ[i];

				m_Rot_Enemy_002[i].x = fRotX[i];
				m_Rot_Enemy_002[i].y = fRotY[i];
				m_Rot_Enemy_002[i].z = fRotZ[i];
				//�G002�̋O��
				m_Pos_To_Enemy_002[i].x = fPos_To[i].x;
				m_Pos_To_Enemy_002[i].y = fPos_To[i].y;
				m_Pos_To_Enemy_002[i].z = fPos_To[i].z;
				i++;
				m_Enemy002_num = i - 1;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadCeiling(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Ceiling)
*******************************************************************************/
void CBuildLoadMap::LoadCeiling(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;
	// �t�@�C���Ǎ�

	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{

				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
				m_Pos_Ceiling[i].x = fPosX[i];
				m_Pos_Ceiling[i].y = fPosY[i];
				m_Pos_Ceiling[i].z = fPosZ[i];
				i++;
				m_Ceiling_num = i - 1;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadDoor(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Door)
*******************************************************************************/
void CBuildLoadMap::LoadDoor(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000;
		fPosY[i] = 5000;
		fPosZ[i] = 5000;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			else if (strcmp(aStr, "rot") == 0)
			{

				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);

				m_Pos_Door[i].x = fPosX[i];
				m_Pos_Door[i].y = fPosY[i];
				m_Pos_Door[i].z = fPosZ[i];

				m_Rot_Door[i].x = fRotX[i];
				m_Rot_Door[i].y = fRotY[i];
				m_Rot_Door[i].z = fRotZ[i];
				i++;
				m_Door_num = i - 1;
			}
		}
	}
	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadPoint(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Point)
*******************************************************************************/
void CBuildLoadMap::LoadPoint(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000;
		fPosY[i] = 5000;
		fPosZ[i] = 5000;
	}

	i = 0;
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
				m_Pos_Point[i].x = fPosX[i];
				m_Pos_Point[i].y = fPosY[i];
				m_Pos_Point[i].z = fPosZ[i];
				i++;
				m_Point_num = i - 1;
			}

		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadStart(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Start)
*******************************************************************************/
void CBuildLoadMap::LoadStart(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < 1; i++)
	{
		fPosX[i] = 5000;
		fPosY[i] = 5000;
		fPosZ[i] = 5000;
	}

	i = 0;
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
 				m_Pos_Start[i].x = fPosX[i];
				m_Pos_Start[i].y = fPosY[i];
				m_Pos_Start[i].z = fPosZ[i];
			}

		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadEnd(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(End)
*******************************************************************************/
void CBuildLoadMap::LoadEnd(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < 1; i++)
	{
		fPosX[i] = 5000;
		fPosY[i] = 5000;
		fPosZ[i] = 5000;
	}

	i = 0;
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
				m_Pos_End[i].x = fPosX[i];
				m_Pos_End[i].y = fPosY[i];
				m_Pos_End[i].z = fPosZ[i];
			}

		}
	}

	fclose(pFile);
}



/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadTest(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Test�p)
*******************************************************************************/
void CBuildLoadMap::LoadTest(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < MAX_WALL; i++)
	{
		fPosX[i] = 5000.0f;
		fPosY[i] = 5000.0f;
		fPosZ[i] = 5000.0f;
	}
	for (int i = 0; i < MAX_WALL; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;
	// �t�@�C���Ǎ�

	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{

				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			else if (strcmp(aStr, "rot") == 0)
			{
				CManager *manager = GetManager();
				CGame *game = (CGame*)CManager::GetMode();
				CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();

				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);

				m_Pos_Test[i].x = fPosX[i];
				m_Pos_Test[i].y = fPosY[i];
				m_Pos_Test[i].z = fPosZ[i];

				m_Rot_Test[i].x = fRotX[i];
				m_Rot_Test[i].y = fRotY[i];
				m_Rot_Test[i].z = fRotZ[i];
				i++;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CBuildLoadMap::LoadRobot(const char *fileName, HINSTANCE hInstance, HWND hWnd)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Robot)
*******************************************************************************/
void CBuildLoadMap::LoadRobot(const char *fileName, HINSTANCE hInstance, HWND hWnd)
{
	// �ϐ��̏�����
	ZeroMemory(aStr, sizeof(aStr));
	ZeroMemory(aStr, sizeof(aData));

	for (int i = 0; i < 1; i++)
	{
		fPosX[i] = 5000;
		fPosY[i] = 5000;
		fPosZ[i] = 5000;
	}
	for (int i = 0; i < 1; i++)
	{
		fRotX[i] = 0;
		fRotY[i] = 0;
		fRotZ[i] = 0;
	}
	i = 0;
	if ((fopen_s(&pFile, fileName, "r")) == NULL)
	{

	}
	// �I�������܂ŃX�N���v�g���̒T��
	if (pFile)
	{
		while (!feof(pFile))
		{
			fscanf_s(pFile, "%s", aStr, sizeof(aStr)); // �s�f�[�^���擾����
			if (strcmp(aStr, "pos") == 0)
			{
				// ���W���
				fscanf_s(pFile, "%s %d %d %d", aData, sizeof(aData), &fPosX[i], &fPosY[i], &fPosZ[i]);
			}
			else if (strcmp(aStr, "rot") == 0)
			{

				// ���W���
				fscanf_s(pFile, "%s %f %f %f", aData, sizeof(aData), &fRotX[i], &fRotY[i], &fRotZ[i]);

				m_Pos_Robot[i].x = fPosX[i];
				m_Pos_Robot[i].y = fPosY[i];
				m_Pos_Robot[i].z = fPosZ[i];

				m_Rot_Robot[i].x = fRotX[i];
				m_Rot_Robot[i].y = fRotY[i];
				m_Rot_Robot[i].z = fRotZ[i];
			}
		}
	}
	fclose(pFile);
}