/********************************************************************************
* �t�@�C�����@CLoadMap.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�Ǘ�
********************************************************************************/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include "main.h"
#include "scene3D.h"
#include "manager.h"
#include "scene.h"
#include "CLoadMap.h"
/*******************************************************************************
�}�N����`
*******************************************************************************/

//------------------------------------------------------------------------------
//	�֐���:	CLoadMap::CLoadMap
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CLoadMap::CLoadMap()
{


}

//------------------------------------------------------------------------------
//	�֐���:	CLoadMap::~CLoadMap
//	����:	�Ȃ�
//	�߂�l:	
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
CLoadMap::~CLoadMap()
{

}

/*******************************************************************************
�֐����F	HRESULT CLoadMap::Init
�߂�l�F	HRESULT
�����F		void
�����F		CLoadMap�̏���������
**********	*********************************************************************/
void CLoadMap::Init(void)
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CGameWall_001 *m_GameWall_001 = game->GetGameWall_001();
	CGameWall_002 *m_GameWall_002 = game->GetGameWall_002();
	CGameEnemy_001 *m_GameEnemy_001 = game->GetGameEnemy_001();
	CGameEnemy_002 *m_GameEnemy_002 = game->GetGameEnemy_002();
	CGameCeiling *m_GameCeiling = game->GetGameCeiling();
	CGameDoor *m_GameDoor = game->GetGameDoor();
	CGamePoint *m_GamePoint = game->GetGamePoint();
	m_Test_num = 0;
	m_Wall001_num = 0;
	m_Wall002_num = 0;
	m_Enemy001_num = 0;
	m_Enemy002_num = 0;
	m_Point_num = 0;
	m_Ceiling_num = 0;
	m_Door_num = 0;

		if (access("data\\SCRIPT\\WALL\\wall_01_Map01.txt", 0) == 0)
		{
			LoadWall_001("data\\SCRIPT\\WALL\\wall_01_Map01.txt", hInstance, hWnd);
		}
		if (access("data\\SCRIPT\\WALL\\wall_02_Map01.txt", 0) == 0)
		{
			LoadWall_002("data\\SCRIPT\\WALL\\wall_02_Map01.txt", hInstance, hWnd);
		}
			if (access("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", 0) == 0)
			{
				LoadEnemy_001("data\\SCRIPT\\ENEMY\\enemy_01_Map01.txt", hInstance, hWnd);
			}
			if (access("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", 0) == 0)
			{
				LoadEnemy_002("data\\SCRIPT\\ENEMY\\enemy_02_Map01.txt", hInstance, hWnd);
			}

			if (access("data\\SCRIPT\\CEILING\\ceiling_Map01.txt", 0) == 0)
			{
				LoadCeiling("data\\SCRIPT\\CEILING\\ceiling_Map01.txt", hInstance, hWnd);
			}
			if (access("data\\SCRIPT\\PROP\\Door_Map01.txt", 0) == 0)
			{
				LoadDoor("data\\SCRIPT\\PROP\\Door_Map01.txt", hInstance, hWnd);
			}

			if (access("data\\SCRIPT\\PROP\\point_Map01.txt", 0) == 0)
			{
				LoadPoint("data\\SCRIPT\\PROP\\point_Map01.txt", hInstance, hWnd);
			}

			if (access("data\\SCRIPT\\ANOTHER\\start_Map01.txt", 0) == 0)
			{
				LoadStart("data\\SCRIPT\\ANOTHER\\start_Map01.txt", hInstance, hWnd);
			}

			if (access("data\\SCRIPT\\ANOTHER\\end_Map01.txt", 0) == 0)
			{
				LoadEnd("data\\SCRIPT\\ANOTHER\\end_Map01.txt", hInstance, hWnd);
			}
			if (access("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", 0) == 0)
			{
				LoadRobot("data\\SCRIPT\\ANOTHER\\Robot_Map01.txt", hInstance, hWnd);
			}
	now_Point = m_Point_num;
}

/*******************************************************************************
�֐����F	void CLoadMap::Uninit
�߂�l�F	void
�����F		void
�����F		CLoadMap�̏I������
*******************************************************************************/
void CLoadMap::Uninit(void)
{

}

/*******************************************************************************
�֐����F	void CLoadMap::Update
�߂�l�F	void
�����F		void
�����F		CLoadMap�̍X�V����
*******************************************************************************/
void CLoadMap::Update()
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CGameWall_001 *m_GameWall_001 = game->GetGameWall_001();
	CGameWall_002 *m_GameWall_002 = game->GetGameWall_002();
	CGameEnemy_001 *m_GameEnemy_001 = game->GetGameEnemy_001();
	CGameEnemy_002 *m_GameEnemy_002 = game->GetGameEnemy_002();

}

/*******************************************************************************
�֐����F	void CLoadMap::Draw
�߂�l�F	void
�����F		void
�����F		CLoadMap�̕`�揈��
*******************************************************************************/
void CLoadMap::Draw(void)
{

}

/*******************************************************************************
�֐����F	void CLoadMap::LoadScript(const char *filezName)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Wall)
*******************************************************************************/
void CLoadMap::LoadWall_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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

				m_Pos_Wall_001[i].x = fPosX[i];
				m_Pos_Wall_001[i].y = fPosY[i];
				m_Pos_Wall_001[i].z = fPosZ[i];

				m_Rot_Wall_001[i].x = fRotX[i];
				m_Rot_Wall_001[i].y = fRotY[i];
				m_Rot_Wall_001[i].z = fRotZ[i];
				i++;
				m_Wall001_num = i-1;
			}
		}
	}

	fclose(pFile);
}

/*******************************************************************************
�֐����F	void CLoadMap::LoadScript(const char *filezName)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Wall)
*******************************************************************************/
void CLoadMap::LoadWall_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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

				m_Pos_Wall_002[i].x = fPosX[i];
				m_Pos_Wall_002[i].y = fPosY[i];
				m_Pos_Wall_002[i].z = fPosZ[i];

				m_Rot_Wall_002[i].x = fRotX[i];
				m_Rot_Wall_002[i].y = fRotY[i];
				m_Rot_Wall_002[i].z = fRotZ[i];
				i++;
				m_Wall002_num = i-1;
			}
		}
	}

	fclose(pFile);
}
void CLoadMap::LoadEnemy_001(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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

					m_Pos_To_Enemy_001[i].x = fPos_To[i].x;
					m_Pos_To_Enemy_001[i].y = fPos_To[i].y;
					m_Pos_To_Enemy_001[i].z = fPos_To[i].z;
					i++;
					m_Enemy001_num = i-1;
			}
		}
	}

	fclose(pFile);
}

void CLoadMap::LoadEnemy_002(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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

				m_Pos_To_Enemy_002[i].x = fPos_To[i].x;
				m_Pos_To_Enemy_002[i].y = fPos_To[i].y;
				m_Pos_To_Enemy_002[i].z = fPos_To[i].z;
				i++;
				m_Enemy002_num = i-1;
			}
		}
	}

	fclose(pFile);
}
/*******************************************************************************
�֐����F	void CLoadMap::LoadCeiling(const char *filezName)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Ceiling)
*******************************************************************************/
void CLoadMap::LoadCeiling(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
				m_Ceiling_num = i-1;
			}
		}
	}

	fclose(pFile);
}

void CLoadMap::LoadDoor(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
				m_Door_num = i-1;
			}
		}
	}
	fclose(pFile);
}

void CLoadMap::LoadPoint(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
				m_Point_num = i-1;
			}
		
		}
	}

	fclose(pFile);
}

void CLoadMap::LoadStart(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
void CLoadMap::LoadEnd(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
�֐����F	void CBuildLoadMap::LoadScript(const char *filezName)
�߂�l�F	void
�����F		�}�b�v�̏����ݒ�̓Ǎ�(Wall)
*******************************************************************************/
void CLoadMap::LoadTest(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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
				m_Test_num = i - 1;
			}
		}
	}

	fclose(pFile);
}

void CLoadMap::LoadRobot(const char *fileName, HINSTANCE hInstance, HWND hWnd)
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
		//	MessageBox(hWnd, "�}�b�v.txt������܂���I", "�x���I",  MB_ICONWARNING);
		//return ;
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

				m_Pos_GameRobot[i].x = fPosX[i];
				m_Pos_GameRobot[i].y = fPosY[i];
				m_Pos_GameRobot[i].z = fPosZ[i];

				m_Rot_GameRobot[i].x = fRotX[i];
				m_Rot_GameRobot[i].y = fRotY[i];
				m_Rot_GameRobot[i].z = fRotZ[i];
			}
		}
	}
	fclose(pFile);
}