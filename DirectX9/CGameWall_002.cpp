/********************************************************************************
* �^�C�g���@
* �t�@�C�����@CGameWall_002.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2017/01/12

********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "CGameWall_002.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CGameWall_002::CGameWall_002()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CGameWall_002::~CGameWall_002()
{

}
CGameWall_002* CGameWall_002::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CGameWall_002 *m_GameWall_002;
	m_GameWall_002 = new CGameWall_002;
	m_GameWall_002->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_GameWall_002;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CGameWall_002::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
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
		//���_�o�b�t�@�̐���
		if (FAILED(device->CreateVertexBuffer(
			sizeof(VERTEX_3D) * m_LoadMap->m_Wall002_num * 4,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&m_pVtxBuffer,
			NULL
		)))
		{
			return E_FAIL;
		}
		m_width = width;
		m_height = height;
		D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);

		//�t�B�[���h���_�o�b�t�@�̏�����
		VERTEX_3D *pVtx;

		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
		for (int i = 0; i < m_LoadMap->m_Wall002_num; i++, pVtx += 4)
		{
			pVtx[0].pos = D3DXVECTOR3(-m_width / 2, m_height, 0.0f);	// ���_���W
			pVtx[1].pos = D3DXVECTOR3(m_width / 2, m_height, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(-m_width / 2, 0.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_width / 2, 0.0f, 0.0f);

			// ���_�F�ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


			//UV�ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);



			// ���W�ϊ��ςݒ��_�ݒ�
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		}
		/* ���_��� �J�M���� */
		m_pVtxBuffer->Unlock();
		m_warp = 15;
	}

	if (manager->m_Build == true)
	{
		//���_�o�b�t�@�̐���
		if (FAILED(device->CreateVertexBuffer(
			sizeof(VERTEX_3D) * m_BuildLoadMap->m_Wall002_num * 4,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_3D,
			D3DPOOL_MANAGED,
			&m_pVtxBuffer,
			NULL
		)))
		{
			return E_FAIL;
		}
		m_width = width;
		m_height = height;
		D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);

		//�t�B�[���h���_�o�b�t�@�̏�����
		VERTEX_3D *pVtx;

		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
		for (int i = 0; i < m_BuildLoadMap->m_Wall002_num; i++, pVtx += 4)
		{
			pVtx[0].pos = D3DXVECTOR3(-m_width / 2, m_height, 0.0f);	// ���_���W
			pVtx[1].pos = D3DXVECTOR3(m_width / 2, m_height, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(-m_width / 2, 0.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_width / 2, 0.0f, 0.0f);

			// ���_�F�ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


			//UV�ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);



			// ���W�ϊ��ςݒ��_�ݒ�
			pVtx[0].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[1].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[2].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
			pVtx[3].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		}
		/* ���_��� �J�M���� */
		m_pVtxBuffer->Unlock();
		m_warp = 5;
	}
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CGameWall_002::Draw(void)
{
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�

	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Wall002_num; i++)
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

				// �r���[�}�g���b�N�X���擾
				device->GetTransform(D3DTS_VIEW, &m_data[i].Matrix.View);

				// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
				device->SetRenderState(D3DRS_LIGHTING, FALSE);

				// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
				device->SetRenderState(D3DRS_ZENABLE, TRUE);
				device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V

				device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
				// ���_�t�H�[�}�b�g�̐ݒ�
				device->SetFVF(FVF_VERTEX_3D);


				// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
				device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																						// �e�N�X�`���̐ݒ�
				device->SetTexture(0, m_pTexture);

				// �|���S���̕`��
				device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
					(i * 4),								// �`�悷��ŏ��̒��_
					2);										// �`�悷��v���~�e�B�u��

				device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

				device->SetRenderState(D3DRS_LIGHTING, TRUE);
				device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
			}
		}
	}

	if (manager->m_Build == true)
	{
		for (int i = 0; i < m_BuildLoadMap->m_Wall002_num; i++)
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

				// �r���[�}�g���b�N�X���擾
				device->GetTransform(D3DTS_VIEW, &m_data[i].Matrix.View);

				// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
				device->SetRenderState(D3DRS_LIGHTING, FALSE);

				// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
				device->SetRenderState(D3DRS_ZENABLE, TRUE);
				device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V

				device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
				// ���_�t�H�[�}�b�g�̐ݒ�
				device->SetFVF(FVF_VERTEX_3D);


				// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
				device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																						// �e�N�X�`���̐ݒ�
				device->SetTexture(0, m_pTexture);

				// �|���S���̕`��
				device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
					(i * 4),								// �`�悷��ŏ��̒��_
					2);										// �`�悷��v���~�e�B�u��

				device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
				device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

				device->SetRenderState(D3DRS_LIGHTING, TRUE);
				device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
			}
		}
	}
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F3D�̍X�V����
//  �߂�l�@�F
//=============================================================================
void CGameWall_002::Update(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CPlayer *m_Player = game->GetPlayer();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Wall002_num; i++)
		{
			if (m_data[i].m_bUse == true && m_data[i].m_Position.y <100.0f)
			{
				if (m_Player->m_OldPos.x <= (m_data[i].m_Position.x + m_warp) &&
					m_Player->m_OldPos.x >= (m_data[i].m_Position.x - m_warp) &&
					(m_data[i].m_Position.z + 100.0f + m_warp) >= m_Player->m_OldPos.z &&
					m_Player->m_OldPos.z >= (m_data[i].m_Position.z - 100.0f - m_warp) &&
					(m_data[i].m_Rotation.y == -1.57f))
				{
					m_Player->m_OldPos.x = (m_data[i].m_Position.x + m_warp);
				}

				if (m_Player->m_OldPos.x >= (m_data[i].m_Position.x - m_warp) &&
					m_Player->m_OldPos.x <= (m_data[i].m_Position.x + m_warp) &&
					(m_data[i].m_Position.z + 100.0f + m_warp) >= m_Player->m_OldPos.z &&
					m_Player->m_OldPos.z >= (m_data[i].m_Position.z - 100.0f - m_warp) &&
					(m_data[i].m_Rotation.y == 1.57f))
				{
					m_Player->m_OldPos.x = (m_data[i].m_Position.x - m_warp);
				}

				if (m_Player->m_OldPos.z >= (m_data[i].m_Position.z - m_warp) &&
					m_Player->m_OldPos.z <= (m_data[i].m_Position.z + m_warp) &&
					(m_data[i].m_Position.x + 100.0f + m_warp) >= m_Player->m_OldPos.x &&
					m_Player->m_OldPos.x >= (m_data[i].m_Position.x - 100.0f - m_warp) &&
					(m_data[i].m_Rotation.y == 0.0f))
				{

					m_Player->m_OldPos.z = (m_data[i].m_Position.z - m_warp);
				}


				if (m_Player->m_OldPos.z <= (m_data[i].m_Position.z + m_warp) &&
					m_Player->m_OldPos.z >= (m_data[i].m_Position.z - m_warp) &&
					(m_data[i].m_Position.x + 100.0f + m_warp) >= m_Player->m_OldPos.x &&
					m_Player->m_OldPos.x >= (m_data[i].m_Position.x - 100.0f - m_warp) &&
					(m_data[i].m_Rotation.y == 3.14f))
				{
					m_Player->m_OldPos.z = (m_data[i].m_Position.z + m_warp);
				}

			}
		}
	}
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCGameWall_002�̏I������
//  �߂�l�@�F
//=============================================================================
void CGameWall_002::Uninit(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CLoadMap *m_LoadMap = game->GetLoadMap();

			RELEASE(m_pTexture);
			RELEASE(m_pVtxBuffer);

}
void CGameWall_002::SetGameWall_002(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CBuildLoadMap *m_BuildLoadMap = BuildManager->GetBuildLoadMap();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	if (manager->m_Build == false)
	{
		for (int i = 0; i < m_LoadMap->m_Wall002_num; i++)
		{
			if (m_data[i].m_bUse == false)
			{
				m_data[i].m_Position = pos;
				m_data[i].m_Rotation = rot;
				m_data[i].m_bUse = true;
				break;
			}
		}
	}

	if (manager->m_Build == true)
	{
		for (int i = 0; i < m_BuildLoadMap->m_Wall002_num; i++)
		{
			if (m_data[i].m_bUse == false)
			{
				m_data[i].m_Position = pos;
				m_data[i].m_Rotation = rot;
				m_data[i].m_bUse = true;
				break;
			}
		}
	}
}