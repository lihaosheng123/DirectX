///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameRobot.cpp
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GameRobot�`��
//********************************************************************************/
#include "main.h"
#include "manager.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CGameRobot.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CGameRobot::CGameRobot()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_Mesh = NULL;

	m_BuffMat = NULL;

	m_bUse = true;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CGameRobot::~CGameRobot()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CGameRobot::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CLoadMap *m_LoadMap = game->GetLoadMap();
	CRenderer *renderer = manager->GetRenderer();


	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	////////////
	D3DXCreateTextureFromFile(device, "data\\TEXTURE\\robot.png", &m_pTexture);// �e�N�X�`���ǂݍ���
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
	m_Position = m_LoadMap->m_Pos_GameRobot[0];	// ���_���W
	m_Rotation = m_LoadMap->m_Rot_GameRobot[0];	// ��]

	m_scl = D3DXVECTOR3(0.5f, 0.5f, 0.5f);
	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CGameRobot::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_BuffMat);
	RELEASE(m_Mesh);
}
//------------------------------------------------------------------------------
//	�֐���:	void CGameRobot::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CGameRobot::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	if (m_bUse == true)
	{
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

}
//------------------------------------------------------------------------------
//	�֐���:	void CGameRobot::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CGameRobot::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CRenderer *renderer = manager->GetRenderer();

	CBuildCamera *m_BuildCamera = BuildManager->GetBuildCamera();
	CBuildMenu_Wall *m_BuildMenu_Wall = BuildManager->GetBuildMenu_Wall();
	CGameRobot *m_GameRobot = game->GetGameRobot();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	CPlayer *m_Player = game->GetPlayer();
	CTalkRobotImage *m_TalkRobotImage = game->GetTalkRobotImage();
	if (m_bUse == true)
	{
		D3DXVECTOR3 vpe = m_Position - m_Player->m_Position;
		vpe.y = 0.0f;
		if (Length(&vpe) < 250.0f)
		{
			if (m_Input->GetKeyboardTrigger(DIK_T) && m_TalkRobotImage->m_bUse == false)
			{
				m_TalkRobotImage->m_bUse = true;
			}
		}
		else
		{
			m_TalkRobotImage->m_bUse = false;
		}
	}

}
CGameRobot* CGameRobot::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CGameRobot *GameRobot;
	GameRobot = new CGameRobot;
	GameRobot->Init(pos, rot, height, width, TEXTURE_FILE);
	return GameRobot;
}
float  CGameRobot::Length(D3DXVECTOR3 *Vector)
{
	float len = sqrtf(Vector->x * Vector->x +
		Vector->y * Vector->y +
		Vector->z * Vector->z);

	return len;

}