///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitle_R_Model.cpp
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Title_R_Model�`��
//********************************************************************************/
#include "main.h"
#include "manager.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CTitle_R_Model.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CTitle_R_Model::CTitle_R_Model()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_Mesh = NULL;

	m_BuffMat = NULL;

	m_Rot = true;

	m_flag = false;

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CTitle_R_Model::~CTitle_R_Model()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CTitle_R_Model::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();

	CEffect *m_Effect = game->GetEffect();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	////////////
	D3DXCreateTextureFromFile(device, "data\\TEXTURE\\titlemodel.jpg", &m_pTexture);// �e�N�X�`���ǂݍ���
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

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CTitle_R_Model::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_BuffMat);
	RELEASE(m_Mesh);
}
//------------------------------------------------------------------------------
//	�֐���:	void CTitle_R_Model::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CTitle_R_Model::Draw(void)
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
//	�֐���:	void CTitle_R_Model::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CTitle_R_Model::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CTitle *Title = (CTitle*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();
	
	if (m_Rotation.x <= -0.35f)
	{
		m_Rot = true;
	}
	else if (m_Rotation.x >= 0.35f)
	{
		m_Rot = false;
	}
	if (m_Rot == false)
	{
		m_Rotation.x -= 0.0025f;
	}
	if (m_Rot == true)
	{
		m_Rotation.x += 0.0025f;
	}
	if (m_flag == true)
	{
		m_Rotation.x -= 0.0375f;
	}
	if (m_Rotation.x <= -1.57f)
	{
		m_Rotation.x = -1.57f;
	}
	if (m_Rotation.x >= 1.57f)
	{
		m_Rotation.x = 1.57f;
	}
	if (m_time >= 60*5)
	{
		m_flag = true;
		m_time = 0;
	}
	else
	{
		m_time++;
	}

}
CTitle_R_Model* CTitle_R_Model::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CTitle_R_Model *Title_R_Model;
	Title_R_Model = new CTitle_R_Model;
	Title_R_Model->Init(pos, rot, height, width, TEXTURE_FILE);
	return Title_R_Model;
}