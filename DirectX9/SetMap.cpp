/********************************************************************************
* �t�@�C�����@SetMap.cpp
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
#include "SetMap.h"
/*******************************************************************************
�}�N����`
*******************************************************************************/

//------------------------------------------------------------------------------
//	�֐���:	SetMap::SetMap
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
SetMap::SetMap()
{
	m_GameWall_001 = NULL;
	m_GameWall_002 = NULL;
	m_GameEnemy_001 = NULL;
	m_GameEnemy_002;
	m_GameCeiling = NULL;
	m_GameDoor = NULL;
	m_GamePoint = NULL;
}

//------------------------------------------------------------------------------
//	�֐���:	SetMap::~SetMap
//	����:	�Ȃ�
//	�߂�l:	
//	����:	�R���X�g���N�^
//------------------------------------------------------------------------------
SetMap::~SetMap()
{

}

/*******************************************************************************
�֐����F	HRESULT SetMap::Init
�߂�l�F	HRESULT
�����F		void
�����F		SetMap�̏���������
**********	*********************************************************************/
void SetMap::Init(void)
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CGameWall_001 *m_GameWall_001 = game->GetGameWall_001();
	CGameWall_002 *m_GameWall_002 = game->GetGameWall_002();
	CGameEnemy_001 *m_GameEnemy_001 = game->GetGameEnemy_001();
	CGameEnemy_002 *m_GameEnemy_002 = game->GetGameEnemy_002();
	CGameCeiling *m_GameCeiling = game->GetGameCeiling();
	CGameDoor *m_GameDoor = game->GetGameDoor();
	CGamePoint *m_GamePoint = game->GetGamePoint();
	for (int i = 0; i < m_LoadMap->m_Wall001_num; i++)
	{
		m_GameWall_001->SetGameWall_001(m_LoadMap->m_Pos_Wall_001[i], m_LoadMap->m_Rot_Wall_001[i]);
	}
	for (int i = 0; i < m_LoadMap->m_Wall002_num; i++)
	{
		m_GameWall_002->SetGameWall_002(m_LoadMap->m_Pos_Wall_002[i], m_LoadMap->m_Rot_Wall_002[i]);
	}
	for (int i = 0; i < m_LoadMap->m_Ceiling_num; i++)
	{
		m_GameCeiling->SetGameCeiling(m_LoadMap->m_Pos_Ceiling[i]);
	}
	for (int i = 0; i < m_LoadMap->m_Enemy001_num; i++)
	{
		m_GameEnemy_001->SetGameEnemy_001(m_LoadMap->m_Pos_Enemy_001[i], m_LoadMap->m_Rot_Enemy_001[i]);
	}

	for (int i = 0; i < m_LoadMap->m_Enemy002_num; i++)
	{
		m_GameEnemy_002->SetGameEnemy_002(m_LoadMap->m_Pos_Enemy_002[i], m_LoadMap->m_Rot_Enemy_002[i]);
	}
	for (int i = 0; i < m_LoadMap->m_Door_num; i++)
	{
		m_GameDoor->SetGameDoor(m_LoadMap->m_Pos_Door[i], m_LoadMap->m_Rot_Door[i]);
	}
	for (int i = 0; i < m_LoadMap->m_Point_num; i++)
	{
		m_GamePoint->SetGamePoint(m_LoadMap->m_Pos_Point[i]);
	}
}

/*******************************************************************************
�֐����F	void SetMap::Uninit
�߂�l�F	void
�����F		void
�����F		SetMap�̏I������
*******************************************************************************/
void SetMap::Uninit(void)
{
	m_GameWall_001 = NULL;
	m_GameWall_002 = NULL;
	m_GameEnemy_001 = NULL;
	m_GameEnemy_002;
	m_GameCeiling = NULL;
	m_GameDoor = NULL;
	m_GamePoint = NULL;
}

/*******************************************************************************
�֐����F	void SetMap::Update
�߂�l�F	void
�����F		void
�����F		SetMap�̍X�V����
*******************************************************************************/
void SetMap::Update()
{


}

/*******************************************************************************
�֐����F	void SetMap::Draw
�߂�l�F	void
�����F		void
�����F		SetMap�̕`�揈��
*******************************************************************************/
void SetMap::Draw(void)
{

}

