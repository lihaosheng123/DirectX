///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGamePoint.cpp
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GamePoint�`��
//********************************************************************************/
#include "main.h"
#include "manager.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CGamePoint.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CGamePoint::CGamePoint()
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	CLoadMap *m_LoadMap = game->GetLoadMap();

	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^

	m_Mesh = NULL;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CGamePoint::~CGamePoint()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CGamePoint::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	CLoadMap *m_LoadMap = game->GetLoadMap();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	D3DXCreateTextureFromFile(device, "data\\TEXTURE\\point.png", &m_pTexture);// �e�N�X�`���ǂݍ���
																			  // X�t�@�C���̓ǂݍ���
	if (FAILED(D3DXLoadMeshFromX(TEXTURE_FILE,
		D3DXMESH_SYSTEMMEM,				// �m�ۂ���o�b�t�@�̃T�C�Y�i�o�C�g�P�ʁj�B
		device,
		NULL,
		&m_BuffMat,		// �}�e���A�����
		NULL,
		&m_nNumMat,			// �}�e���A����
		&m_Mesh)))		// ���b�V�����
	{
		return E_FAIL;
	}
	m_Flag = false;
	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CGamePoint::Uninit(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CLoadMap *m_LoadMap = game->GetLoadMap();

			RELEASE(m_pTexture);
			RELEASE(m_BuffMat);
			RELEASE(m_Mesh);

}
//------------------------------------------------------------------------------
//	�֐���:	void CGamePoint::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CGamePoint::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Point_num; i++)
		{
			if (m_data[i].m_bUse == true)
			{
				// ���[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&m_data[i].Matrix.World);


				// �X�P�[���𔽉f
				D3DXMatrixScaling(&m_data[i].Matrix.Scl, m_data[i].m_scl.x, m_data[i].m_scl.y, m_data[i].m_scl.z);
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Scl);

				// ��]�𔽉f
				D3DXMatrixRotationYawPitchRoll(&m_data[i].Matrix.Rot, m_data[i].m_Rotation.y, m_data[i].m_Rotation.x, m_data[i].m_Rotation.z);	// y,x,z
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Rot);

				// �ʒu�𔽉f
				D3DXMatrixTranslation(&m_data[i].Matrix.Trans, m_data[i].m_Position.x, m_data[i].m_Position.y, m_data[i].m_Position.z);
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Trans);

				// ���[���h�}�g���b�N�X��ݒ�
				device->SetTransform(D3DTS_WORLD, &m_data[i].Matrix.World);
				D3DXMATERIAL *pMat;		// �}�e���A�����
				D3DMATERIAL9 matDef;	// �f�t�H���g�̃}�e���A���B���̃}�e���A���̏���ޔ������邽�߂̕ϐ��B


										// ���݂̃}�e���A�������擾����B
				device->GetMaterial(&matDef);
				// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
				device->SetRenderState(D3DRS_ZENABLE, TRUE);
				device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V
																		// �����_�[�X�e�[�g�̐ݒ�i�A���t�@�e�X�g�j


																		//���f���ɖ���ɂȂ�
				device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
				device->SetRenderState(D3DRS_SPECULARENABLE, true);

				// �L���X�g�ϊ�
				pMat = (D3DXMATERIAL*)m_BuffMat->GetBufferPointer();

				for (int nCntMat = 0; nCntMat < (int)m_nNumMat; nCntMat++)
				{
					// �}�e���A���̐ݒ�
					device->SetMaterial(&pMat[nCntMat].MatD3D);

					// �e�N�X�`���̐ݒ�
					device->SetTexture(0, m_pTexture);
					// ���b�V���̕`��
					m_Mesh->DrawSubset(nCntMat);
				}
				// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
																				// �}�e���A���������ɖ߂��B�߂��Ȃ��Ǝ��ɕ`�悳���}�e���A�������������Ȃ�B�ԐF�̂܂܁A�Ƃ��B
				device->SetMaterial(&matDef);
			}
		}
	}

	if (manager->m_Build == true)
	{
		for (int i = 0; i < m_BuildLoadMap->m_Point_num; i++)
		{
			if (m_data[i].m_bUse == true)
			{
				// ���[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&m_data[i].Matrix.World);


				// �X�P�[���𔽉f
				D3DXMatrixScaling(&m_data[i].Matrix.Scl, m_data[i].m_scl.x, m_data[i].m_scl.y, m_data[i].m_scl.z);
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Scl);

				// ��]�𔽉f
				D3DXMatrixRotationYawPitchRoll(&m_data[i].Matrix.Rot, m_data[i].m_Rotation.y, m_data[i].m_Rotation.x, m_data[i].m_Rotation.z);	// y,x,z
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Rot);

				// �ʒu�𔽉f
				D3DXMatrixTranslation(&m_data[i].Matrix.Trans, m_data[i].m_Position.x, m_data[i].m_Position.y, m_data[i].m_Position.z);
				D3DXMatrixMultiply(&m_data[i].Matrix.World, &m_data[i].Matrix.World, &m_data[i].Matrix.Trans);

				// ���[���h�}�g���b�N�X��ݒ�
				device->SetTransform(D3DTS_WORLD, &m_data[i].Matrix.World);
				D3DXMATERIAL *pMat;		// �}�e���A�����
				D3DMATERIAL9 matDef;	// �f�t�H���g�̃}�e���A���B���̃}�e���A���̏���ޔ������邽�߂̕ϐ��B


										// ���݂̃}�e���A�������擾����B
				device->GetMaterial(&matDef);
				// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
				device->SetRenderState(D3DRS_ZENABLE, TRUE);
				device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V
																		// �����_�[�X�e�[�g�̐ݒ�i�A���t�@�e�X�g�j


																		//���f���ɖ���ɂȂ�
				device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
				device->SetRenderState(D3DRS_SPECULARENABLE, true);

				// �L���X�g�ϊ�
				pMat = (D3DXMATERIAL*)m_BuffMat->GetBufferPointer();

				for (int nCntMat = 0; nCntMat < (int)m_nNumMat; nCntMat++)
				{
					// �}�e���A���̐ݒ�
					device->SetMaterial(&pMat[nCntMat].MatD3D);

					// �e�N�X�`���̐ݒ�
					device->SetTexture(0, m_pTexture);
					// ���b�V���̕`��
					m_Mesh->DrawSubset(nCntMat);
				}
				// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
																				// �}�e���A���������ɖ߂��B�߂��Ȃ��Ǝ��ɕ`�悳���}�e���A�������������Ȃ�B�ԐF�̂܂܁A�Ƃ��B
				device->SetMaterial(&matDef);
			}
		}
	}

}
//------------------------------------------------------------------------------
//	�֐���:	void CGamePoint::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CGamePoint::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CRenderer *renderer = manager->GetRenderer();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildCamera *m_BuildCamera = BuildManager->GetBuildCamera();
	CBuildMenu_Wall *m_BuildMenu_Wall = BuildManager->GetBuildMenu_Wall();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CEnemy_Bullet_Up *m_Enemy_Bullet_Up = game->GetEnemy_Bullet_Up();
	CEnemy_Bullet_Down *m_Enemy_Bullet_Down = game->GetEnemy_Bullet_Down();
	CEnemy_Bullet_Left *m_Enemy_Bullet_Left = game->GetEnemy_Bullet_Left();
	CEnemy_Bullet_Right *m_Enemy_Bullet_Right = game->GetEnemy_Bullet_Right();
	CPlayer *m_Player = game->GetPlayer();
	CScore *m_Score = game->GetScore();
	CEnemy_Effect *m_Enemy_Effect = game->GetEnemy_Effect();

	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Point_num; i++)
		{
			if (m_data[i].m_bUse == true)
			{
			CColumnar *m_Columnar = game->GetColumnar(i);
				if (m_Columnar->m_bMove == false)
				{
					m_Columnar->m_Position.x = m_data[i].m_Position.x;
					m_Columnar->m_Position.y = m_data[i].m_Position.y + 100.0f;
					m_Columnar->m_Position.z = m_data[i].m_Position.z;
				}
			}
		}


	}
}
CGamePoint* CGamePoint::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CGamePoint *GamePoint;
	GamePoint = new CGamePoint;
	GamePoint->Init( pos,  rot,  height,  width, TEXTURE_FILE);
	return GamePoint;
}
void CGamePoint::SetGamePoint(D3DXVECTOR3 pos)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Point_num; i++)
		{
			if (m_data[i].m_bUse == false)
			{
				m_data[i].m_Position = pos;
				m_data[i].m_bUse = true;
				break;
			}
		}
	}

	if (manager->m_Build == true)
	{
		for (int i = 0; i < m_BuildLoadMap->m_Point_num; i++)
		{
			if (m_data[i].m_bUse == false)
			{
				m_data[i].m_Position = pos;
				m_data[i].m_bUse = true;
				break;
			}
		}
	}
}
CGamePoint_data* CGamePoint::Get(int Index)
{
	return &m_data[Index];
}
float  CGamePoint::Length(D3DXVECTOR3 *Vector)
{
	float len = sqrtf(Vector->x * Vector->x +
		Vector->y * Vector->y +
		Vector->z * Vector->z);

	return len;

}