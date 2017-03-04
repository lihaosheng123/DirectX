#include "main.h"
#include "manager.h"
#include "CColumnar.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CColumnar::CColumnar()
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	CLoadMap *m_LoadMap = game->GetLoadMap();
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^

	m_bUse = true;
	m_bMove = false;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CColumnar::~CColumnar()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CColumnar::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CLoadMap *m_LoadMap = game->GetLoadMap();
		m_Position = pos;	// ���_���W
		m_Rotation = rot;	// ��]
		m_height = height;
		m_width = width;
		m_scl.x = 1.0f;		//�n�ʂ�X�̃X�P�[��������
		m_scl.y = 1.0f;		//�n�ʂ�Y�̃X�P�[��������
		m_scl.z = 1.0f;		//�n�ʂ�Z�̃X�P�[��������
		Point_num = m_LoadMap->m_Point_num;
	//���_�o�b�t�@�̐���
	if (FAILED(device->CreateVertexBuffer(
		sizeof(VERTEX_3D) * 66,
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

		for (int i = 0; i < 33; i++)
		{
			pVtx->pos.x = cosf(PI / 16.0f * i) * m_width;
			pVtx->pos.y = m_height;
			pVtx->pos.z = sinf(PI / 16.0f * i) * m_width;

			pVtx->tex = D3DXVECTOR2(i / 16.0f, 0.0f);

			pVtx->col = D3DCOLOR_RGBA(100, 255, 255, 255);

			pVtx++;


			pVtx->pos.x = cosf(PI / 16.0f * i) * m_width;
			pVtx->pos.y = -height;
			pVtx->pos.z = sinf(PI / 16.0f * i) * m_width;

			pVtx->tex = D3DXVECTOR2(i / 16.0f, 1.0f);

			pVtx->col = D3DCOLOR_RGBA(100, 255, 255, 255);

			pVtx++;

		}
	
	/* ���_��� �J�M���� */
	m_pVtxBuffer->Unlock();
	m_Life = 8;

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CColumnar::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
//------------------------------------------------------------------------------
//	�֐���:	void CColumnar::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CColumnar::Draw(void)
{

	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CCamera *m_Camera = game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

		if (m_bUse == true)
		{
			// �r���[�}�g���b�N�X���擾
			device->GetTransform(D3DTS_VIEW, &m_Matrix.View);

			// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
			device->SetRenderState(D3DRS_LIGHTING, FALSE);

			// �u�����h���Z����
		//	device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
		//	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�X�e�B�l�[�V�����J���[�̎w��
			device->SetFVF(FVF_VERTEX_3D);

			// ���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&m_Matrix.World);


			// �X�P�[���𔽉f
			D3DXMatrixScaling(&m_Matrix.Scl, m_scl.x, m_scl.y, m_scl.z);
			D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Scl);

			// ��]�𔽉f
			D3DXMatrixRotationYawPitchRoll(&m_Matrix.Rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
			D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Rot);

			// �ʒu�𔽉f
			D3DXMatrixTranslation(&m_Matrix.Trans, m_Position.x, m_Position.y, m_Position.z);
			D3DXMatrixMultiply(&m_Matrix.World, &m_Matrix.World, &m_Matrix.Trans);

			// ���[���h�}�g���b�N�X��ݒ�
			device->SetTransform(D3DTS_WORLD, &m_Matrix.World);

			// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
			device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																					// �e�N�X�`���̐ݒ�
			device->SetTexture(0, NULL);


			// �|���S���̕`��
			device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
				(0 * 4),								// �`�悷��ŏ��̒��_
				64);										// �`�悷��v���~�e�B�u��

															// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
		//	device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
		//	device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

																			// ���C�g�_��
			device->SetRenderState(D3DRS_LIGHTING, TRUE);
		}

}
//------------------------------------------------------------------------------
//	�֐���:	void CColumnar::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CColumnar::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CScore *m_Score = game->GetScore();
	CHpScore *m_HpScore = game->GetHpScore();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CPlayer *m_Player = game->GetPlayer();
	CGlass *m_Glass = game->GetGlass();
		if (m_Life < 0)
		{
			m_Life = 0;
			m_bMove = true;
			
		}
		if (m_bMove == true)
		{
			m_Position.y -= 0.98f;
			m_Rotation.x -= 0.0125f;
		}
		if (m_Position.y < 20.0f && m_bUse == true)
		{
			m_Position.y = 20.0f;
			m_bUse = false;
			m_HpScore->AddScore(1);
			m_LoadMap->now_Point -=1;
			m_Player->m_Power += 25;
		}
		if (m_Rotation.x <= -1.57f)
		{
			m_Rotation.x = -1.57f;
		}
}
CColumnar* CColumnar::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CColumnar *Columnar;
	Columnar = new CColumnar;
	Columnar->Init(pos, rot, height, width, TEXTURE_FILE);
	return Columnar;
}
