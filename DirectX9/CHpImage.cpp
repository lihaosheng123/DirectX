/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@scene2D.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/25
2D�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "scene2D.h"
#include "CHpImage.h"

//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CHpImage::CHpImage()
{
	m_pTexture = NULL;
	m_pVtxBuffer = NULL;	//���_�p�b�t�@�ւ̃|�C���^

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CHpImage::~CHpImage()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F�v���S���̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CHpImage::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();


	m_Position = D3DXVECTOR3(pos.x, pos.y, pos.z);	// ���_���W
	m_Rotation = D3DXVECTOR3(rot.x, rot.y, rot.z);	// ��]

	m_height = height;
	m_width = width;
	m_r = 0;
	m_b = 255;
	m_Alpha = false;
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
		TEXTURE_FILE,		// �t�@�C���̖��O
		&m_pTexture);	// �ǂݍ��ރ������[

						//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
	if (FAILED(device->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,	// ���_�f�[�^�p�Ɋm�ۂ���o�b�t�@�T�C�Y(�o�C�g�P��)
		D3DUSAGE_WRITEONLY,						// ���_�o�b�t�@�̎g�p�@
		FVF_VERTEX_2D,							// �g�p���钸�_�t�H�[�}�b�g
		D3DPOOL_MANAGED,						// ���\�[�X�̃o�b�t�@��ێ����郁�����N���X���w��
		&m_pVtxBuffer,						// ���_�o�b�t�@�C���^�[�t�F�[�X�ւ̃|�C���^
		NULL)))									// NULL�ɐݒ�
	{
		return E_FAIL;
	}
	{//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_2D *pVtx;

		// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);


		// ���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y - m_height / 2, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y - m_height / 2, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y + m_height / 2, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y + m_height / 2, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw =
			pVtx[1].rhw =
			pVtx[2].rhw =
			pVtx[3].rhw = 1.0f;

		// ���_�J���[�̐ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(0, 0, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(0, 0, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(0, 0, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(0, 0, 255, 255);

		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
	}
	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffer->Unlock();

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CHpImage::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F�v���S���̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CHpImage::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	// ���_�F�t�H�[�}�b�g
	device->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	device->SetTexture(0, m_pTexture);

	// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h����
	device->SetStreamSource(
		0,
		m_pVtxBuffer,
		0,
		sizeof(VERTEX_2D)
	);

	// �t�F�[�h�̕`��ݒ���e
	device->DrawPrimitive(
		D3DPT_TRIANGLESTRIP,		// �v���~�e�B�u�̎��
		0,		// �ŏ��̒��_�̃C���f�b�N�X
		2			// �`�悷��v���~�e�B�u��
	);

}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F�v���S���̍X�V����	
//  �߂�l�@�F
//=============================================================================
void CHpImage::Update(void)
{
	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CPlayer *m_Player = game->GetPlayer();
	if (m_Player->m_Dead == false && m_Player->m_HP > 0)
	{
		{//���_�o�b�t�@�̒��g�𖄂߂�
			VERTEX_2D *pVtx;

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
			pVtx[0].col = D3DCOLOR_RGBA(m_r, 0, m_b, 255);
			pVtx[1].col = D3DCOLOR_RGBA(m_r, 0, m_b, 255);
			pVtx[2].col = D3DCOLOR_RGBA(m_r, 0, m_b, 255);
			pVtx[3].col = D3DCOLOR_RGBA(m_r, 0, m_b, 255);

			if (m_r >= 255)
			{
				m_r = 255;
			}

			if (m_b <= 0)
			{
				m_b = 0;
			}
			if (m_Alpha == true)
			{
				m_r += 5;
				m_b -= 5;
				m_Alpha = false;
			}
			// �e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
		}
		// ���_�f�[�^���A�����b�N����
		m_pVtxBuffer->Unlock();
	}
}

CHpImage* CHpImage::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CHpImage *m_HpImage;
	m_HpImage = new CHpImage;
	m_HpImage->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_HpImage;
}