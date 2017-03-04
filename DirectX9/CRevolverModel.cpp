/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@CRevolverModel.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
���X�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "Camera.h"
#include "sceneX.h"
#include "manager.h"
#include "scene.h"
#include "CRevolverModel.h"
#include "sceneMouse.h"
#include "score.h"
//=============================================================================
// �N���X�R���X�g���N�^
//=============================	================================================
CRevolverModel::CRevolverModel()
{
	m_BuffMat = NULL;             // ���_�o�b�t�@�ւ̃|�C���^
	m_Mesh = NULL;                  // ���b�V���̏��
	m_nNumMat = NULL;                     // �}�e���A����x
	m_pTexture = NULL;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CRevolverModel::~CRevolverModel()
{

}

//================================================================================================================================================================================================
// Init�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
HRESULT CRevolverModel::Init(LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	D3DXCreateTextureFromFile(device, "data\\TEXTURE\\??.png", &m_pTexture);// �e�N�X�`���ǂݍ���
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
	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ���_���W
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ��]
	m_scl = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	return S_OK;
}

//================================================================================================================================================================================================
// Uninit�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CRevolverModel::Uninit(void)
{
	//RELEASE(m_pTexture);
	RELEASE(m_BuffMat);
	RELEASE(m_Mesh);
}

//================================================================================================================================================================================================
// Update�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CRevolverModel::Update(void)
{

}

//================================================================================
//================================================================================================================
// Draw�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CRevolverModel::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	if (m_Parent != NULL)
	{
		parentMatrix = m_Parent->GetWorldMatrix();

	}
	else
	{
		device->GetTransform(D3DTS_WORLD, &parentMatrix);
	}

	// ���݂̃}�e���A�������擾����B
	device->GetMaterial(&matDef);

	//�����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
	device->SetRenderState(D3DRS_ZENABLE, TRUE);
	device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V
															//�����_�[�X�e�[�g�̐ݒ�i�A���t�@�e�X�g�j
	device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);				// �A���t�@�l�𔻒肵�āA�Y���̃s�N�Z����`�悷��悤�ɂ���B
	device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);			// ���̒l���A���t�@�l���傫����Ε`�悷��B
	device->SetRenderState(D3DRS_ALPHAREF, 200);						// �A���t�@�l�B0�œ����ȕ����B


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

	//���f���`��

	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &parentMatrix);
	// ���[���h�}�g���b�N�X��ݒ�
	device->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// �L���X�g�ϊ�
	pMat = (D3DXMATERIAL*)m_BuffMat->GetBufferPointer();


	for (int nCntMat = 0; nCntMat < (int)m_nNumMat; nCntMat++)
	{
		// �}�e���A���̐ݒ�
		device->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		device->SetTexture(0, m_pTexture);

		// ���b�V���̕`��
		m_Mesh->DrawSubset(nCntMat);
	}
	// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
	device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
																	// ���C�g�_��
	device->SetRenderState(D3DRS_LIGHTING, TRUE);
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	// �}�e���A���������ɖ߂��B�߂��Ȃ��Ǝ��ɕ`�悳���}�e���A�������������Ȃ�B
	device->SetMaterial(&matDef);

}

D3DXMATRIX CRevolverModel::GetWorldMatrix(void)
{
	return m_mtxWorld;
}
void CRevolverModel::SetParent(CRevolverModel *Parent)
{
	m_Parent = Parent;
}
void CRevolverModel::SetPosition(D3DXVECTOR3 Position)
{
	m_Position = Position;
}
void CRevolverModel::SetRotation(D3DXVECTOR3 Rotation)
{
	m_Rotation = Rotation;
}
CRevolverModel* CRevolverModel::Create(LPCSTR TEXTURE_FILE)
{
	CRevolverModel *sceneX;
	sceneX = new CRevolverModel;
	sceneX->Init(TEXTURE_FILE);
	return sceneX;
}
