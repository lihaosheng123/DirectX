/********************************************************************************
* �^�C�g���@
* �t�@�C�����@m_BuildCeiling.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
�V��̕`��p
********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "CCeiling.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CCeiling::CCeiling()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	m_use = true;

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CCeiling::~CCeiling()
{

}
CCeiling* CCeiling::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CCeiling *m_BuildCeiling;
	m_BuildCeiling = new CCeiling;
	m_BuildCeiling->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_BuildCeiling;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT0
//=============================================================================
HRESULT CCeiling::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();

	m_Position = pos;	// ���_���W
	m_Rotation = rot;	// ��]

	m_height = height;
	m_width = width;


	m_scl.x = 1.0f;
	m_scl.y = 1.0f;
	m_scl.z = 1.0f;

	m_Changge = 600;
	//���_�o�b�t�@�̐���	
	if (FAILED(device->CreateVertexBuffer(
		sizeof(VERTEX_3D) * 1 * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffer,
		NULL
	)))
	{
		return E_FAIL;
	}
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);

	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(-m_width / 2, 0.0f, m_height/2);	// ���_���W
	pVtx[1].pos = D3DXVECTOR3(m_width / 2, 0.0f, m_height/2);
	pVtx[2].pos = D3DXVECTOR3(-m_width / 2, 0.0f, -m_height/2);
	pVtx[3].pos = D3DXVECTOR3(m_width / 2, 0.0f, -m_height/2);

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


	/* ���_��� �J�M���� */
	m_pVtxBuffer->Unlock();
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CCeiling::Draw(void)
{
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�

	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	if (m_use == true)
	{
		// �r���[�}�g���b�N�X���擾
		device->GetTransform(D3DTS_VIEW, &mtxView);

		// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
		device->SetRenderState(D3DRS_LIGHTING, FALSE);

		// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
		device->SetRenderState(D3DRS_ZENABLE, TRUE);
		device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
		device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V

		device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		// ���_�t�H�[�}�b�g�̐ݒ�
		device->SetFVF(FVF_VERTEX_3D);

		// ���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxWorld);



		// �X�P�[���𔽉f
		D3DXMatrixScaling(&mtxScl, m_scl.x, m_scl.y, m_scl.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScl);

		// ��]�𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		// �ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, m_Position.x, m_Position.y, m_Position.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		// ���[���h�}�g���b�N�X��ݒ�
		device->SetTransform(D3DTS_WORLD, &m_mtxWorld);

		// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
		device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																				// �e�N�X�`���̐ݒ�
		device->SetTexture(0, m_pTexture);

		// �|���S���̕`��
		device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
			(0 * 4),								// �`�悷��ŏ��̒��_
			2);										// �`�悷��v���~�e�B�u��

													// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
		device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
		device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
																		// ���C�g�_��
		device->SetRenderState(D3DRS_LIGHTING, TRUE);
		device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	}
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F3D�̍X�V����
//  �߂�l�@�F
//=============================================================================
void CCeiling::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CBuildCamera *m_BuildCamera = BuildManager->GetBuildCamera();
	CCeiling *m_Ceiling = BuildManager->GetCeiling(0);
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	m_NumCheck.x = (int)(m_BuildCamera->m_3DPos.x) - (int)(m_BuildCamera->m_3DPos.x) % 50;
	m_NumCheck.z = (int)(m_BuildCamera->m_3DPos.z) - (int)(m_BuildCamera->m_3DPos.z) % 50;
	m_NumCheck.y = 0 + m_Changge;
	if (m_Input->GetKeyboardTrigger(DIK_U))
	{
		m_Changge += 50;
	}

	if (m_Input->GetKeyboardTrigger(DIK_O))
	{
		m_Changge -= 50;
	}
	if (m_NumCheck.y <= 0.0)
	{
		m_NumCheck.y = 2.0f;
	}
	switch (m_type)
	{
	case CCeiling::CEILING_NORMAL:
		break;
	case CCeiling::CEILING_BUILDING_TRUE:
		m_Ceiling->m_Position.x = (int)m_NumCheck.x;	// ���_���W
		m_Ceiling->m_Position.z = (int)m_NumCheck.z;
		m_Ceiling->m_Position.y = (int)m_NumCheck.y;

		//�t�B�[���h���_�o�b�t�@�̏�����
		VERTEX_3D *pVtx;

		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

		pVtx[0].pos = D3DXVECTOR3(-m_width / 2, 0.0f, m_height / 2);	// ���_���W
		pVtx[1].pos = D3DXVECTOR3(m_width / 2, 0.0f, m_height / 2);
		pVtx[2].pos = D3DXVECTOR3(-m_width / 2, 0.0f, -m_height / 2);
		pVtx[3].pos = D3DXVECTOR3(m_width / 2, 0.0f, -m_height / 2);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 100);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 100);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 100);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 100);

		/* ���_��� �J�M���� */
		m_pVtxBuffer->Unlock();
		break;
	case CCeiling::CEILING_BUILDING_FALSE:
		m_Ceiling->m_Position.x = 5000.0f;	// ���_���W
		m_Ceiling->m_Position.z = 5000.0f;
		m_Ceiling->m_Position.y = 5000.0f;

		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

		pVtx[0].pos = D3DXVECTOR3(-m_width / 2, 0.0f, m_height / 2);	// ���_���W
		pVtx[1].pos = D3DXVECTOR3(m_width / 2, 0.0f, m_height / 2);
		pVtx[2].pos = D3DXVECTOR3(-m_width / 2, 0.0f, -m_height / 2);
		pVtx[3].pos = D3DXVECTOR3(m_width / 2, 0.0f, -m_height / 2);

		/* ���_��� �J�M���� */
		m_pVtxBuffer->Unlock();
		break;
	case CCeiling::CEILING_MAX:
		break;
	default:
		break;
	}
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCCeiling�̏I������
//  �߂�l�@�F
//=============================================================================
void CCeiling::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}