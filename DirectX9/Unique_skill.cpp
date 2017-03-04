/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@Unique_skill.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
���X�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "Camera.h"
#include "sceneX.h"
#include "manager.h"
#include "scene.h"
#include "sceneMouse.h"
#include "score.h"
#include "Unique_skill.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CUnique_skill::CUnique_skill()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	for (int i = 0; i<UNIQUE_SKILL_MAX; i++)
	{
		m_Unique_skill[i].m_Buse = false;
	}
	m_bgUse = false;
	m_CheckUse = false;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CUnique_skill::~CUnique_skill()
{

}
CUnique_skill* CUnique_skill::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CUnique_skill *sceneUnique_skill;
	sceneUnique_skill = new CUnique_skill;

	sceneUnique_skill->Init(pos, rot, height, width, TEXTURE_FILE);

	return sceneUnique_skill;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CUnique_skill::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	if (FAILED(device->CreateVertexBuffer(
			sizeof(VERTEX_3D) * UNIQUE_SKILL_MAX * 4,
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
	for (int i = 0; i<UNIQUE_SKILL_MAX; i++)
	{

			m_Unique_skill[i].m_Position = pos;	// ���_���W
			m_Unique_skill[i].m_Rotation = rot;	// ��]

			m_Unique_skill[i].m_height = height;
			m_Unique_skill[i].m_width = width;


			m_Unique_skill[i].m_scl.x = 1.0f;
			m_Unique_skill[i].m_scl.y = 1.0f;
			m_Unique_skill[i].m_scl.z = 1.0f;

			nCount = 0;			// �J�E���^
			nPattern = 0;		// �p�^�[��No.	
			m_frame = 0;
												
			m_Unique_skill[i].m_Buse = false;
	}
	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

	for (int i = 0; i<UNIQUE_SKILL_MAX; i++, pVtx += 4)
	{
		pVtx[0].pos = D3DXVECTOR3(-m_Unique_skill[i].m_width / 2, m_Unique_skill[i].m_height, 0.0f);	// ���_���W
		pVtx[1].pos = D3DXVECTOR3(m_Unique_skill[i].m_width / 2, m_Unique_skill[i].m_height, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-m_Unique_skill[i].m_width / 2, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(m_Unique_skill[i].m_width / 2, 0.0f, 0.0f);

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



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(TEXTURE_SIZE_X_UNIQUE_SKILL, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, TEXTURE_SIZE_Y_UNIQUE_SKILL);
		pVtx[3].tex = D3DXVECTOR2(TEXTURE_SIZE_X_UNIQUE_SKILL, TEXTURE_SIZE_Y_UNIQUE_SKILL);
	}
	/* ���_��� �J�M���� */
	m_pVtxBuffer->Unlock();
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CUnique_skill::Draw(void)
{


	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	for (int i = 0; i<UNIQUE_SKILL_MAX; i++)
	{
		if (m_Unique_skill[i].m_Buse == true)
		{
			// �r���[�}�g���b�N�X���擾
			device->GetTransform(D3DTS_VIEW, &m_Unique_skill[i].mtxView);

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
			D3DXMatrixIdentity(&m_Unique_skill[i].m_mtxWorld);

			// �r���[�}�g���b�N�X�̋t�s������߂�B
			D3DXMatrixInverse(&m_Unique_skill[i].m_mtxWorld, NULL, &m_Unique_skill[i].mtxView);

			m_Unique_skill[i].m_mtxWorld._41 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A
			m_Unique_skill[i].m_mtxWorld._42 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A
			m_Unique_skill[i].m_mtxWorld._43 = 0.0f;		// �ړ��Ɋւ���ϐ����N���A
															// �X�P�[���𔽉f
			D3DXMatrixScaling(&m_Unique_skill[i].mtxScl, m_Unique_skill[i].m_scl.x, m_Unique_skill[i].m_scl.y, m_Unique_skill[i].m_scl.z);
			D3DXMatrixMultiply(&m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].mtxScl);

			// ��]�𔽉f
			D3DXMatrixRotationYawPitchRoll(&m_Unique_skill[i].mtxRot, m_Unique_skill[i].m_Rotation.y, m_Unique_skill[i].m_Rotation.x, m_Unique_skill[i].m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
			D3DXMatrixMultiply(&m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].mtxRot);

			// �ʒu�𔽉f
			D3DXMatrixTranslation(&m_Unique_skill[i].mtxTrans, m_Unique_skill[i].m_Position.x, m_Unique_skill[i].m_Position.y, m_Unique_skill[i].m_Position.z);
			D3DXMatrixMultiply(&m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].m_mtxWorld, &m_Unique_skill[i].mtxTrans);

			// ���[���h�}�g���b�N�X��ݒ�
			device->SetTransform(D3DTS_WORLD, &m_Unique_skill[i].m_mtxWorld);

			// ���_�o�b�t�@���f�[�^�X�g���[���i�x���g�R���x�A�j�Ƀo�C���h����i���t����j�B
			device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_3D));			//sizeof( VERTEX_2D )�̓f�[�^�̊Ԋu

																					// �e�N�X�`���̐ݒ�
			device->SetTexture(0, m_pTexture);
			device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
			// �u�����h���Z����

		//	device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�X�e�B�l�[�V�����J���[�̎w��


																				// �|���S���̕`��
			device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
				(i * 4),								// �`�悷��ŏ��̒��_
				2);										// �`�悷��v���~�e�B�u��


			device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
			// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

																			// �ʏ�u�����h
			device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
			device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��

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
void CUnique_skill::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();
	CBullet *m_Bullet = game->GetBullet();
	CScore *m_Score = game->GetScore();
	CSceneMouse *m_Mouse = manager->GetMouse();
	Cskillbg *m_skillbg = game->Getskillbg();
	CPlayer *m_Player = game->GetPlayer();
	if (m_bgUse == true)
	{
		m_skillbg = Cskillbg::Create(D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), SCREEN_HEIGHT, SCREEN_WIDTH, "NULL");
		m_bgUse = false;
	}
	//if (m_CheckUse != false)
	//{
	//	m_CheckUse = true;
	//}

	//���_�o�b�t�@�̒��g�𖄂߂�
	VERTEX_3D *pVtx;
	// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);
	for (int i = 0; i < UNIQUE_SKILL_MAX; i++)
	{
		if (m_frame == 0)
		{
			m_CheckUse = false;
		}
		if (m_frame >240)
		{
			m_Unique_skill[i].m_Buse = false;
			m_frame = 0;
		}
		else
		{
			m_frame++;
		}
	
		if (m_Unique_skill[i].m_Buse == true)
		{

			nCount++;
			{
			//	m_Score->AddScore(1);
			}
			if ((nCount % INTERVAL_PATTERN_UNIQUE_SKILL) == 0)
			{// �A�j���[�V�����؂�ւ�
				nPattern++;
				if (nPattern >= NUM_PATTERN_UNIQUE_SKILL)
				{// �A�j���[�V�����p�^�[�����I��
					nCount = 0;
					nPattern = NUM_PATTERN_UNIQUE_SKILL;
					//m_Unique_skill[i].m_Buse = false;
				}

			}
		}
	}

	for (int i = 0; i < UNIQUE_SKILL_MAX; i++, pVtx += 4)
	{
		if (m_Unique_skill[i].m_Buse == true)
		{
			
			pVtx[0].pos = D3DXVECTOR3(-m_Unique_skill[i].m_width / 2, m_Unique_skill[i].m_height, 0.0f);	// ���_���W
			pVtx[1].pos = D3DXVECTOR3(m_Unique_skill[i].m_width / 2, m_Unique_skill[i].m_height, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(-m_Unique_skill[i].m_width / 2, 0.0f, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_Unique_skill[i].m_width / 2, 0.0f, 0.0f);

			pVtx[0].tex = D3DXVECTOR2(nPattern * TEXTURE_SIZE_X_UNIQUE_SKILL, nPattern * TEXTURE_SIZE_Y_UNIQUE_SKILL);
			pVtx[1].tex = D3DXVECTOR2((nPattern + 1) * TEXTURE_SIZE_X_UNIQUE_SKILL, nPattern * TEXTURE_SIZE_Y_UNIQUE_SKILL);
			pVtx[2].tex = D3DXVECTOR2(nPattern * TEXTURE_SIZE_X_UNIQUE_SKILL, (nPattern + 1) * TEXTURE_SIZE_Y_UNIQUE_SKILL);
			pVtx[3].tex = D3DXVECTOR2((nPattern + 1) * TEXTURE_SIZE_X_UNIQUE_SKILL, (nPattern + 1) * TEXTURE_SIZE_Y_UNIQUE_SKILL);
		}
	}
	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffer->Unlock();
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FUnique_skill�̏I������
//  �߂�l�@�F
//=============================================================================
void CUnique_skill::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
void CUnique_skill::SetUnique_skill(D3DXVECTOR3 pos)
{

	for (int i = 0; i < UNIQUE_SKILL_MAX; i++)
	{
			m_Unique_skill[i].m_Position = pos;
			nCount = 0;
			nPattern = 0;
			m_frame = 0;
			m_CheckUse = true;
			m_Unique_skill[i].m_Buse = true;
			break;
	}
}