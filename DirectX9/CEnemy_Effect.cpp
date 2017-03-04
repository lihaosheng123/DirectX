/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@m_Enemy_Effect.cpp
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
CEnemy_Effect::CEnemy_Effect()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	for (int i = 0; i<ENEMY_EFFECT_MAX; i++)
	{
		m_Enemy_Effect[i].m_bUse = false;
	}
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CEnemy_Effect::~CEnemy_Effect()
{


}
CEnemy_Effect* CEnemy_Effect::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CEnemy_Effect *m_Enemy_Effect;
	m_Enemy_Effect = new CEnemy_Effect;
	m_Enemy_Effect->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_Enemy_Effect;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CEnemy_Effect::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{

	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	//���_�o�b�t�@�̐���
	if (FAILED(device->CreateVertexBuffer(
		sizeof(VERTEX_3D) * ENEMY_EFFECT_MAX * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffer,
		NULL
	)))
	{
		return E_FAIL;
	}
	for (int i = 0; i < ENEMY_EFFECT_MAX; i++)
	{
		m_Enemy_Effect[i].m_Position = pos;	// ���_���W
		m_Enemy_Effect[i].m_Rotation = rot;	// ��]
		m_Enemy_Effect[i].m_height = height;
		m_Enemy_Effect[i].m_width = width;


		m_Enemy_Effect[i].m_scl.x = 1.0f;
		m_Enemy_Effect[i].m_scl.y = 1.0f;
		m_Enemy_Effect[i].m_scl.z = 1.0f;

		m_Enemy_Effect[i].nCount = 0;			// �J�E���^
		m_Enemy_Effect[i].nPattern = 0;		// �p�^�[��No.	
		//�e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);
	}
	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
	for (int i = 0; i < ENEMY_EFFECT_MAX; i++, pVtx += 4)
	{
		pVtx[0].pos = D3DXVECTOR3(-m_Enemy_Effect[i].m_width , 0.0f, m_Enemy_Effect[i].m_height);	// ���_���W
		pVtx[1].pos = D3DXVECTOR3(m_Enemy_Effect[i].m_width , 0.0f, m_Enemy_Effect[i].m_height);
		pVtx[2].pos = D3DXVECTOR3(-m_Enemy_Effect[i].m_width, 0.0f, -m_Enemy_Effect[i].m_height);
		pVtx[3].pos = D3DXVECTOR3(m_Enemy_Effect[i].m_width, 0.0f, -m_Enemy_Effect[i].m_height);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(TEXTURE_SIZE_X_EFFECT_ENEMY, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, TEXTURE_SIZE_Y_EFFECT_ENEMY);
		pVtx[3].tex = D3DXVECTOR2(TEXTURE_SIZE_X_EFFECT_ENEMY, TEXTURE_SIZE_Y_EFFECT_ENEMY);

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
void CEnemy_Effect::Draw(void)
{

	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CCamera *m_Camera = game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	for (int i = 0; i < ENEMY_EFFECT_MAX; i++)
	{
		if (m_Enemy_Effect[i].m_bUse == true)
		{
			// �r���[�}�g���b�N�X���擾
			device->GetTransform(D3DTS_VIEW, &m_Enemy_Effect[i].m_Matrix.View);

			// ���C�g�����B�ǂ̊p�x���猩�Ă������悤�ɂ��邽�߁A�r���{�[�h�̉A�e�𖳂����B
			device->SetRenderState(D3DRS_LIGHTING, FALSE);

																				// �u�����h���Z����
			device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
			device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�X�e�B�l�[�V�����J���[�̎w��
			device->SetFVF(FVF_VERTEX_3D);

			// ���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&m_Enemy_Effect[i].m_Matrix.World);


																// �X�P�[���𔽉f
			D3DXMatrixScaling(&m_Enemy_Effect[i].m_Matrix.Scl, m_Enemy_Effect[i].m_scl.x, m_Enemy_Effect[i].m_scl.y, m_Enemy_Effect[i].m_scl.z);
			D3DXMatrixMultiply(&m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.Scl);

			// ��]�𔽉f
			D3DXMatrixRotationYawPitchRoll(&m_Enemy_Effect[i].m_Matrix.Rot, m_Enemy_Effect[i].m_Rotation.y, m_Enemy_Effect[i].m_Rotation.x, m_Enemy_Effect[i].m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
			D3DXMatrixMultiply(&m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.Rot);

			// �ʒu�𔽉f
			D3DXMatrixTranslation(&m_Enemy_Effect[i].m_Matrix.Trans, m_Enemy_Effect[i].m_Position.x, m_Enemy_Effect[i].m_Position.y, m_Enemy_Effect[i].m_Position.z);
			D3DXMatrixMultiply(&m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.World, &m_Enemy_Effect[i].m_Matrix.Trans);

			// ���[���h�}�g���b�N�X��ݒ�
			device->SetTransform(D3DTS_WORLD, &m_Enemy_Effect[i].m_Matrix.World);

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
void CEnemy_Effect::Update(void)
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
	CGameEnemy_001_data *m_Enemy_001_data = m_Enemy_001->Get(0);

	cnt = 0;
	//���_�o�b�t�@�̒��g�𖄂߂�
	VERTEX_3D *pVtx;
	// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
	for (int i = 0; i < ENEMY_EFFECT_MAX; i++, cnt++)
	{
		if (m_Enemy_Effect[i].m_Position.x >= 1000 || m_Enemy_Effect[i].m_Position.y >= 1000 || m_Enemy_Effect[i].m_Position.z >= 1000)
		{
			m_Enemy_Effect[i].m_bUse = false;
		}
		if (m_Enemy_Effect[i].m_bUse == true)
		{
			m_Enemy_Effect[i].nCount++;
			if ((m_Enemy_Effect[i].nCount % INTERVAL_PATTERN_EFFECT_ENEMY) == 0)
			{// �A�j���[�V�����؂�ւ�
				m_Enemy_Effect[i].nPattern++;
				if (m_Enemy_Effect[i].nPattern >= NUM_PATTERN_EFFECT_ENEMY)
				{// �A�j���[�V�����p�^�[�����I��
					m_Enemy_Effect[i].nCount = 0;
					m_Enemy_Effect[i].nPattern = 0;
				}
			}
			m_Enemy_Effect[i].m_Position = D3DXVECTOR3((m_Enemy_001_data+cnt)->m_Position.x, (m_Enemy_001_data + cnt)->m_Position.y+1.0f, (m_Enemy_001_data + cnt)->m_Position.z);
 
		}
	}
	for (int nCnt = 0;  nCnt < ENEMY_EFFECT_MAX;  nCnt++, pVtx += 4)
	{
		if (m_Enemy_Effect[nCnt].m_bUse == true)
		{
			pVtx[0].tex = D3DXVECTOR2(m_Enemy_Effect[nCnt].nPattern * TEXTURE_SIZE_X_EFFECT_ENEMY, m_Enemy_Effect[ nCnt].nPattern * TEXTURE_SIZE_Y_EFFECT_ENEMY);
			pVtx[1].tex = D3DXVECTOR2((m_Enemy_Effect[ nCnt].nPattern + 1) * TEXTURE_SIZE_X_EFFECT_ENEMY, m_Enemy_Effect[ nCnt].nPattern * TEXTURE_SIZE_Y_EFFECT_ENEMY);
			pVtx[2].tex = D3DXVECTOR2(m_Enemy_Effect[ nCnt].nPattern * TEXTURE_SIZE_X_EFFECT_ENEMY, (m_Enemy_Effect[ nCnt].nPattern + 1) * TEXTURE_SIZE_Y_EFFECT_ENEMY);
			pVtx[3].tex = D3DXVECTOR2((m_Enemy_Effect[ nCnt].nPattern + 1) * TEXTURE_SIZE_X_EFFECT_ENEMY, (m_Enemy_Effect[ nCnt].nPattern + 1) * TEXTURE_SIZE_Y_EFFECT_ENEMY);
		}
	}
	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffer->Unlock();
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCEnemy_Effect�̏I������
//  �߂�l�@�F
//=============================================================================
void CEnemy_Effect::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);

}
void CEnemy_Effect::SetEffect(D3DXVECTOR3 pos)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CCamera *m_Camera = game->GetCCamera();
	CPlayer *m_Player = game->GetPlayer();
	CGameEnemy_001 *m_Enemy_001 = game->GetGameEnemy_001();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	for (int nCnt = 0; nCnt < ENEMY_EFFECT_MAX; nCnt++)
	{
		//	�g���Ă��Ȃ��Ȃ�
		if (m_Enemy_Effect[nCnt].m_bUse == false)
		{
			m_Enemy_Effect[nCnt].m_Position = D3DXVECTOR3(pos.x, pos.y, pos.z);	//�ʒu
			m_Enemy_Effect[nCnt].nCount = 0;
			m_Enemy_Effect[nCnt].nPattern = 0;
			m_Enemy_Effect[nCnt].m_bUse = true;		//�e���g�p���Ă���
			break;
		}
	}

}
ENEMY_EFFECT* CEnemy_Effect::GetEnemy_Effect(void)
{
	return &m_Enemy_Effect[0];
}