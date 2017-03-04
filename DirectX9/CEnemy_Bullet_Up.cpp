/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@m_Enemy_Bullet_Up.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
meshfield�̕`��p
********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "bullet.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CEnemy_Bullet_Up::CEnemy_Bullet_Up()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	for (int i = 0; i<ENEMY_BULLET_UP_MAX; i++)
	{
		m_Enemy_Bullet_Up[i].m_bUse = false;
		m_Enemy_Bullet_Up[i].m_OneCheck = false;
	}
	m_Num = 6;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CEnemy_Bullet_Up::~CEnemy_Bullet_Up()
{


}
CEnemy_Bullet_Up* CEnemy_Bullet_Up::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CEnemy_Bullet_Up *m_Enemy_Bullet_Up;
	m_Enemy_Bullet_Up = new CEnemy_Bullet_Up;
	m_Enemy_Bullet_Up->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_Enemy_Bullet_Up;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CEnemy_Bullet_Up::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{

	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	//���_�o�b�t�@�̐���
	if (FAILED(device->CreateVertexBuffer(
		sizeof(VERTEX_3D) * ENEMY_BULLET_UP_MAX * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffer,
		NULL
	)))
	{
		return E_FAIL;
	}
	for (int i = 0; i < ENEMY_BULLET_UP_MAX; i++)
	{
		m_Enemy_Bullet_Up[i].m_Position = pos;	// ���_���W
		m_Enemy_Bullet_Up[i].m_Rotation = rot;	// ��]
		m_Enemy_Bullet_Up[i].m_height = height;
		m_Enemy_Bullet_Up[i].m_width = width;

		m_Enemy_Bullet_Up[i].m_Life = 200;


		m_Enemy_Bullet_Up[i].m_scl.x = 1.0f;
		m_Enemy_Bullet_Up[i].m_scl.y = 1.0f;
		m_Enemy_Bullet_Up[i].m_scl.z = 1.0f;


		//�e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);
	}
	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
	for (int i = 0; i < ENEMY_BULLET_UP_MAX; i++, pVtx += 4)
	{
		pVtx[0].pos = D3DXVECTOR3(-m_Enemy_Bullet_Up[i].m_width / 2, m_Enemy_Bullet_Up[i].m_height, 0.0f);	// ���_���W
		pVtx[1].pos = D3DXVECTOR3(m_Enemy_Bullet_Up[i].m_width / 2, m_Enemy_Bullet_Up[i].m_height, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-m_Enemy_Bullet_Up[i].m_width / 2, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_Enemy_Bullet_Up[i].m_width / 2, 0.0f, 0.0f);

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
	cnt = 0;
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CEnemy_Bullet_Up::Draw(void)
{

	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CCamera *m_Camera = game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	for (int i = 0; i < ENEMY_BULLET_UP_MAX; i++)
	{
		if (m_Enemy_Bullet_Up[i].m_bUse == true)
		{
			// �r���[�}�g���b�N�X���擾
			device->GetTransform(D3DTS_VIEW, &m_Enemy_Bullet_Up[i].m_Matrix.View);

			// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
			device->SetRenderState(D3DRS_LIGHTING, FALSE);

			// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
			device->SetRenderState(D3DRS_ZENABLE, TRUE);
			device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
			device->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);		//z�l�̍X�V
																	// �����_�[�X�e�[�g�̐ݒ�i�A���t�@�e�X�g�j
			device->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);				// �A���t�@�l�𔻒肵�āA�Y���̃s�N�Z����`�悷��悤�ɂ���B
			device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);			// ���̒l���A���t�@�l���傫����Ε`�悷��B
			device->SetRenderState(D3DRS_ALPHAREF, 200);						// �A���t�@�l�B0�œ����ȕ����B
																				// ���_�t�H�[�}�b�g�̐ݒ�
			device->SetFVF(FVF_VERTEX_3D);

			// ���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&m_Enemy_Bullet_Up[i].m_Matrix.World);

			// �r���[�}�g���b�N�X�̋t�s������߂�B
			D3DXMatrixInverse(&m_Enemy_Bullet_Up[i].m_Matrix.World, NULL, &m_Enemy_Bullet_Up[i].m_Matrix.View);

			m_Enemy_Bullet_Up[i].m_Matrix.World._41 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A
			m_Enemy_Bullet_Up[i].m_Matrix.World._42 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A
			m_Enemy_Bullet_Up[i].m_Matrix.World._43 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A

													// �X�P�[���𔽉f
			D3DXMatrixScaling(&m_Enemy_Bullet_Up[i].m_Matrix.Scl, m_Enemy_Bullet_Up[i].m_scl.x, m_Enemy_Bullet_Up[i].m_scl.y, m_Enemy_Bullet_Up[i].m_scl.z);
			D3DXMatrixMultiply(&m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.Scl);

			// ��]�𔽉f
			D3DXMatrixRotationYawPitchRoll(&m_Enemy_Bullet_Up[i].m_Matrix.Rot, m_Enemy_Bullet_Up[i].m_Rotation.y, m_Enemy_Bullet_Up[i].m_Rotation.x, m_Enemy_Bullet_Up[i].m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
			D3DXMatrixMultiply(&m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.Rot);

			// �ʒu�𔽉f
			D3DXMatrixTranslation(&m_Enemy_Bullet_Up[i].m_Matrix.Trans, m_Enemy_Bullet_Up[i].m_Position.x, m_Enemy_Bullet_Up[i].m_Position.y, m_Enemy_Bullet_Up[i].m_Position.z);
			D3DXMatrixMultiply(&m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.World, &m_Enemy_Bullet_Up[i].m_Matrix.Trans);

			// ���[���h�}�g���b�N�X��ݒ�
			device->SetTransform(D3DTS_WORLD, &m_Enemy_Bullet_Up[i].m_Matrix.World);

			// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
			device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																					// �e�N�X�`���̐ݒ�
			device->SetTexture(0, m_pTexture);


			// �|���S���̕`��
			device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
				(i * 4),								// �`�悷��ŏ��̒��_
				2);										// �`�悷��v���~�e�B�u��

														// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

																			// ���C�g�_��
			device->SetRenderState(D3DRS_LIGHTING, TRUE);
		}
	}

}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F3D�̍X�V����
//  �߂�l�@�F
//=============================================================================
void CEnemy_Bullet_Up::Update(void)
{

	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CScore *m_Score = game->GetScore();

	CCamera *m_Camera = game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CEnemy *m_Enemy = game->GetEnemy();
	COrbit *m_Orbit = game->GetOrbit();
	CSmoke *m_Smoke = game->GetSmoke();
	CGameEnemy_001 *m_Enemy_001 = game->GetGameEnemy_001();
	CExplosion *m_Explosion = game->GetExplosion();
	CPlayer *m_Player = game->GetPlayer();
	CHpScore *m_HpScore = game->GetHpScore();
	CHpImage *m_HpImage = game->GetHpImage();
	for (int i = 0; i < ENEMY_BULLET_UP_MAX; i++, cnt++)
	{
		if (m_Enemy_Bullet_Up[i].m_bUse == true)
		{

			m_Enemy_Bullet_Up[i].m_Position.z += ENEMY_BULLET_UP_SPEED;

			m_Enemy_Bullet_Up[i].m_Life--;

			if (m_Enemy_Bullet_Up[i].m_Life <= 0)
			{
				m_Enemy_Bullet_Up[i].m_Position = D3DXVECTOR3(0.0f, 5000.0f, 0.0f);	// ���_���W
				m_Enemy_Bullet_Up[i].m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ��]
				m_Enemy_Bullet_Up[i].m_Life = 200;
				m_Enemy_Bullet_Up[i].m_bUse = false;
			}

			//�v���C���[�Ɠ����蔻��

			D3DXVECTOR3 vpe = m_Player->m_Position - m_Enemy_Bullet_Up[i].m_Position;
			vpe.y = 0.0f;
			if (Length(&vpe) < 50.0f)
			{
				if (m_Enemy_Bullet_Up[i].m_Position.y < m_Player->m_Position.y + 200.0f)
				{
					m_HpScore->AddScore(-1);
					m_Player->m_HP -= 1;
					m_HpImage->m_Alpha = true;
					m_Enemy_Bullet_Up[i].m_bUse = false;
				}
			}
		}
	}
	

}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCEnemy_Bullet_Up�̏I������
//  �߂�l�@�F
//=============================================================================
void CEnemy_Bullet_Up::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);

}
float  CEnemy_Bullet_Up::Length(D3DXVECTOR3 *Vector)
{
	float len = sqrtf(Vector->x * Vector->x +
		Vector->y * Vector->y +
		Vector->z * Vector->z);

	return len;

}

void CEnemy_Bullet_Up::SetBullet_Up(D3DXVECTOR3 pos)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CCamera *m_Camera = game->GetCCamera();
	CPlayer *m_Player = game->GetPlayer();
	CGameEnemy_001 *m_Enemy_001 = game->GetGameEnemy_001();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	for (int nCnt = 0; nCnt < ENEMY_BULLET_UP_MAX; nCnt++)
	{
			//	�e���g���Ă��Ȃ��Ȃ�
			if (m_Enemy_Bullet_Up[nCnt].m_bUse == false)
			{
					CGameEnemy_001_data *m_Enemy_001_data = m_Enemy_001->Get(cnt);

					m_Enemy_Bullet_Up[nCnt].m_Position = D3DXVECTOR3(pos.x, pos.y, pos.z);	//�ʒu
					m_Enemy_Bullet_Up[nCnt].m_bUse = true;		//�e���g�p���Ă���
					break;
			
			}
	}

}
ENEMY_BULLET_UP* CEnemy_Bullet_Up::GetEnemy_Bullet_Up(void)
{
	return &m_Enemy_Bullet_Up[0];
}