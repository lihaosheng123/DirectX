/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@m_Buildaxis.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
meshfield�̕`��p
********************************************************************************/
#include "main.h"
#include "CBuildManager.h"
#include "renderer.h"
#include "scene.h"
#include "Caxis.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
Caxis::Caxis()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
Caxis::~Caxis()
{

}
Caxis* Caxis::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	Caxis *m_Buildaxis;
	m_Buildaxis = new Caxis;
	m_Buildaxis->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_Buildaxis;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT0
//=============================================================================
HRESULT Caxis::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();

	m_Position = pos;	// ���_���W
	m_Rotation = rot;	// ��]

	m_height = height;
	m_width = width;

	m_scl = D3DXVECTOR3(1.0f, 1.0f, 1.0f);	//�g��k���p

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);

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

	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(-m_width/2, 0.0f, m_height/2);	// ���_���W
	pVtx[1].pos = D3DXVECTOR3(m_width/2, 0.0f, m_height/2);
	pVtx[2].pos = D3DXVECTOR3(-m_width/2, 0.0f, -m_height/2);
	pVtx[3].pos = D3DXVECTOR3(m_width/2, 0.0f, -m_height/2);


	// ���_�F�ݒ�
	pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 50);
	pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 50);
	pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 50);
	pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 50);


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
void Caxis::Draw(void)
{

	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CBuildCamera *m_Camera = BuildManager->GetBuildCamera();
	//�}�g���b�N�X�̓J����������
	//m_Matrix.View = m_Camera->m_mtxView;

	// �r���[�}�g���b�N�X���擾
	device->GetTransform(D3DTS_VIEW, &m_Matrix.View);

	// ���C�g�����B
	device->SetRenderState(D3DRS_LIGHTING, FALSE);

	// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
	device->SetRenderState(D3DRS_ZENABLE, TRUE);
	device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V

	device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	// ���_�t�H�[�}�b�g�̐ݒ�
	device->SetFVF(FVF_VERTEX_3D);

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_Matrix.World);

	// �X�P�[���𔽉f
	D3DXMatrixScaling(&m_Matrix.Scl, m_scl.x, m_scl.y, m_scl.z);
	D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Scl);

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll(&m_Matrix.Rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Rot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&m_Matrix.Trans, m_Position.x, m_Position.y, m_Position.z);
	D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Trans);

	// ���[���h�}�g���b�N�X��ݒ�
	device->SetTransform(D3DTS_WORLD, &m_Matrix.World);

	// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����B
	device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

	// �e�N�X�`���̐ݒ�
	device->SetTexture(0, m_pTexture);

	// �|���S���̕`��
	device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�O�p�`�BTRIANGLESTRIP�l�p�BTRIANGLEFAN�~�B
		(0 * 4),								// �`�悷��ŏ��̒��_
		2);										// �`�悷��v���~�e�B�u��

	//�����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
	device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
	// ���C�g�_��
	device->SetRenderState(D3DRS_LIGHTING, TRUE);
	//�w�ʂ̎O�p�`���J�����O�A�X�e���V�����[�h��L���ɂ���
	device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F3D�̍X�V����
//  �߂�l�@�F
//=============================================================================
void Caxis::Update(void)
{


}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCaxis�̏I������
//  �߂�l�@�F
//=============================================================================
void Caxis::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
