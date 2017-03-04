/********************************************************************************
* �t�@�C�����@BuildSetMap.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�̕`��Ǘ�
********************************************************************************/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "scene3D.h"
#include "manager.h"
#include "scene.h"
#include "BuildSetMap.h"
/*******************************************************************************
�}�N����`
*******************************************************************************/

//------------------------------------------------------------------------------
//	�֐���:	BuildSetMap::BuildSetMap
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
BuildSetMap::BuildSetMap()
{



}

//------------------------------------------------------------------------------
//	�֐���:	BuildSetMap::~BuildSetMap
//	����:	�Ȃ�
//	�߂�l:	
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
BuildSetMap::~BuildSetMap()
{

}

/*******************************************************************************
�֐����F	void BuildSetMap::Init
�߂�l�F	�Ȃ�
�����F		void
�����F		BuildSetMap�̏���������
**********	*********************************************************************/
void BuildSetMap::Init(void)
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
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	//��001�̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Wall001_num; i++)
	{
		m_GameWall_001->SetGameWall_001(m_BuildLoadMap->m_Pos_Wall_001[i], m_BuildLoadMap->m_Rot_Wall_001[i]);
	}
	//��002�̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Wall002_num; i++)
	{
		m_GameWall_002->SetGameWall_002(m_BuildLoadMap->m_Pos_Wall_002[i], m_BuildLoadMap->m_Rot_Wall_002[i]);
	}
	//�V��̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Ceiling_num; i++)
	{
		m_GameCeiling->SetGameCeiling(m_BuildLoadMap->m_Pos_Ceiling[i]);
	}
	//�G001�̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Enemy001_num; i++)
	{
		m_GameEnemy_001->SetGameEnemy_001(m_BuildLoadMap->m_Pos_Enemy_001[i], m_BuildLoadMap->m_Rot_Enemy_001[i]);
	}
	//�G002�̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Enemy002_num; i++)
	{
		m_GameEnemy_002->SetGameEnemy_002(m_BuildLoadMap->m_Pos_Enemy_002[i], m_BuildLoadMap->m_Rot_Enemy_002[i]);
	}
	//�h�A���f���̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Door_num; i++)
	{
		m_GameDoor->SetGameDoor(m_BuildLoadMap->m_Pos_Door[i], m_BuildLoadMap->m_Rot_Door[i]);
	}
	//�������f���̕`��z�u
	for (int i = 0; i < m_BuildLoadMap->m_Point_num; i++)
	{
		m_GamePoint->SetGamePoint(m_BuildLoadMap->m_Pos_Point[i]);
	}
}

/*******************************************************************************
�֐����F	void BuildSetMap::Uninit
�߂�l�F	void
�����F		void
�����F		BuildSetMap�̏I������
*******************************************************************************/
void BuildSetMap::Uninit(void)
{

}

/*******************************************************************************
�֐����F	void BuildSetMap::Update
�߂�l�F	void
�����F		void
�����F		BuildSetMap�̍X�V����
*******************************************************************************/
void BuildSetMap::Update()
{


}

/*******************************************************************************
�֐����F	void BuildSetMap::Draw
�߂�l�F	void
�����F		void
�����F		BuildSetMap�̕`�揈��
*******************************************************************************/
void BuildSetMap::Draw(void)
{

}

