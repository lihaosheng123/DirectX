///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitleRobot.cpp
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* TitleRobot�`��
//********************************************************************************/
#include "main.h"
#include "manager.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CTitleRobot.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CTitleRobot::CTitleRobot()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_Mesh = NULL;

	m_BuffMat = NULL;
	m_bMove = true;
	m_flag = true;
	m_rot = false;
	m_Backrot = false;
	m_newMove = false;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CTitleRobot::~CTitleRobot()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CTitleRobot::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();

	CEffect *m_Effect = game->GetEffect();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

																					// X�t�@�C���̓ǂݍ���
	if (FAILED(D3DXLoadMeshFromX(TEXTURE_FILE,
		D3DXMESH_SYSTEMMEM,				// �m�ۂ���o�b�t�@�̃T�C�Y�i�o�C�g�P�ʁj�B�Q�[���ɂ���ĉ����_�Ȃ̂��ς��B����͎l�p������S�B
		device,
		NULL,
		&m_BuffMat,		// �}�e���A�����
		NULL,
		&m_nNumMat,			// �}�e���A����
		&m_Mesh)))		// ���b�V�����
	{
		return E_FAIL;
	}
	// ���f���̏����ݒ�
	m_Position = D3DXVECTOR3(pos.x, pos.y, pos.z);	// ���_���W
	m_Rotation = D3DXVECTOR3(rot.x, rot.y, rot.z);	// ��]

	m_scl = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	m_wait = 0;
	m_Time = 0;
	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CTitleRobot::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_BuffMat);
	RELEASE(m_Mesh);
}
//------------------------------------------------------------------------------
//	�֐���:	void CTitleRobot::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CTitleRobot::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
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

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	// �X�P�[���𔽉f
	D3DXMatrixScaling(&mtxScl, m_scl.x, m_scl.y, m_scl.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z);	// y,x,z
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);



	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);



	// ���[���h�}�g���b�N�X��ݒ�
	device->SetTransform(D3DTS_WORLD, &m_mtxWorld);

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
//------------------------------------------------------------------------------
//	�֐���:	void CTitleRobot::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CTitleRobot::Update(void)
{
	CManager *manager = GetManager();
	CTitle *Title = (CTitle*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();
	CTitle_R_Model *m_Title_R_Model = Title->GetTitle_R_Model();
	if (m_flag == true)
	{
		if (m_Position.x >= 300.0f)
		{
			m_bMove = true;
		}
		else if (m_Position.x <= -300.0f)
		{
			m_bMove = false;
		}
		if (m_bMove == true)
		{
			m_Position.x -= 1.0f;
		}
		else if (m_bMove == false)
		{
			m_Position.x += 1.0f;
		}
	}
	if (m_Title_R_Model->m_Rotation.x == -1.57f &&m_Position.x == m_Title_R_Model->m_Position.x)
	{
		m_flag = false;
	}
	if (m_flag == false)
	{
		if (m_wait >= 60)
		{
			m_rot = true;
			m_wait = 0;
		}
		else
		{
			m_wait++;
		}
		if (m_rot == true)
		{
			m_Rotation.y -= 0.0125f;
			if (m_Rotation.y <= -3.14f)
			{
				m_Rotation.y = -3.14f;
				if (m_wait >= 60)
				{
					m_Backrot = true;
					m_Time = 0;
				}
				else
				{
					m_Time++;
				}
			}
		}
		if (m_Backrot == true)
			{
				m_rot = false;
				m_Rotation.y += 0.0125f;
				if (m_Rotation.y >= 0.0f)
				{
					m_Rotation.y = 0.0f;
					m_Position.z += 0.25f;
					m_Title_R_Model->m_Rotation.x += 0.0375f;
					if (m_Position.z >= 450.0f)
					{
						m_Position.z  = 450.0f;
						m_newMove = true;
					}

				}
				if (m_Title_R_Model->m_Rotation.x >= 1.57f)
					{
						m_Title_R_Model->m_Rotation.x = 1.57f;
					
					}

			}
		if (m_newMove == true)
		{
			if (m_Position.x >= 300.0f)
			{
				m_bMove = true;
			}
			else if (m_Position.x <= -300.0f)
			{
				m_bMove = false;
			}
			if (m_bMove == true)
			{
				m_Position.x -= 1.0f;
			}
			else if (m_bMove == false)
			{
				m_Position.x += 1.0f;
			}
		}
	}

}
CTitleRobot* CTitleRobot::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CTitleRobot *TitleRobot;
	TitleRobot = new CTitleRobot;
	TitleRobot->Init(pos, rot, height, width, TEXTURE_FILE);
	return TitleRobot;
}