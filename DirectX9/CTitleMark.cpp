/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@CTitleMark.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
���X�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "Camera.h"
#include "sceneX.h"
#include "manager.h"
#include "scene.h"
#include "CTitleMark.h"
#include "sceneMouse.h"
#include "score.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CTitleMark::CTitleMark()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	m_bUse = true;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CTitleMark::~CTitleMark()
{

}
CTitleMark* CTitleMark::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CTitleMark *sceneTitleMark;
	sceneTitleMark = new CTitleMark;

	sceneTitleMark->Init(pos, rot, height, width, TEXTURE_FILE);

	return sceneTitleMark;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CTitleMark::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();


	m_Position = pos;	// ���_���W
	m_Rotation = rot;	// ��]

	m_height = height;
	m_width = width;


	m_scl.x = 1.0f;
	m_scl.y = 1.0f;
	m_scl.z = 1.0f;

						//���_�o�b�t�@�̐���
	m_type = TITLE_MENU_START;
	if (FAILED(device->CreateVertexBuffer(
		sizeof(VERTEX_2D) * 1 * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&m_pVtxBuffer,
		NULL
	)))
	{
		return E_FAIL;
	}
	col.r = 1.0f;
	col.g = 1.0f;
	col.b = 1.0f;
	col.a = 1.0f;
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device, TEXTURE_FILE, &m_pTexture);

	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_2D *pVtx;

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
	pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
	pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);


	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	/* ���_��� �J�M���� */
	m_pVtxBuffer->Unlock();
	num = 1.0f;
	m_colMove = false;
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CTitleMark::Draw(void)
{
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�

	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();

	if (m_bUse == true)
	{
		// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h
		device->SetStreamSource(0, m_pVtxBuffer, 0, sizeof(VERTEX_2D));

		// ���_�t�H�[�}�b�g�̐ݒ�
		device->SetFVF(FVF_VERTEX_2D);

		// �e�N�X�`���̐ݒ�
		device->SetTexture(0, m_pTexture);
		device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		// �u�����h���Z����
		//device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
		//device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);				// ���f�X�e�B�l�[�V�����J���[�̎w��
		// �|���S���̕`��
		device->DrawPrimitive(D3DPT_TRIANGLESTRIP,						// TRIANGLELIST�Ōʂ̎O�p�`�̕`��BTRIANGLESTRIP�łȂ������O�p�A�����Ďl�p�BTRIANGLEFAN�ŉ~�B
			0,								// �`�悷��ŏ��̒��_
			2);										// �`�悷��v���~�e�B�u��
		//device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
		device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
		device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B

																		// �ʏ�u�����h
		device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
		device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		// ���f�X�e�B�l�[�V�����J���[�̎w��
	}
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F3D�̍X�V����
//  �߂�l�@�F
//=============================================================================
void CTitleMark::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();
	CTitle *Title = (CTitle*)CManager::GetMode();
	CTitleMenu *m_TitleMenu = Title->GetTitleMenu();
	if (m_bUse == true)
	{
		switch (m_type)
		{
		case TITLE_MENU_START:
			if (m_Input->GetKeyboardTrigger(DIK_S))
			{
				m_type = TITLE_MENU_BUILD;
			}
			break;


		case TITLE_MENU_BUILD:
			if (m_Input->GetKeyboardTrigger(DIK_W))
			{
				m_type = TITLE_MENU_START;
			}

			if (m_Input->GetKeyboardTrigger(DIK_S))
			{
				m_type = TITLE_MENU_END;
			}
			break;

		case TITLE_MENU_END:
			if (m_Input->GetKeyboardTrigger(DIK_W))
			{
				m_type = TITLE_MENU_BUILD;
			}
			break;

		default:
			break;

		}
		//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_2D *pVtx;
		// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

		switch (m_type)
		{
		case TITLE_MENU_START:
			// ���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y - m_height / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y - m_height / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y + m_height / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y + m_height / 2, 0.0f);
			break;

		case TITLE_MENU_BUILD:
			// ���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y - m_height / 2 + 80.0f , 0.0f);
			pVtx[1].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y - m_height / 2 + 80.0f , 0.0f);
			pVtx[2].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y + m_height / 2 + 80.0f , 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y + m_height / 2 + 80.0f , 0.0f);
			break;

		case TITLE_MENU_END:
			// ���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y - m_height / 2 + 80.0f * 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y - m_height / 2 + 80.0f * 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(m_Position.x - m_width / 2, m_Position.y + m_height / 2 + 80.0f * 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_Position.x + m_width / 2, m_Position.y + m_height / 2 + 80.0f * 2, 0.0f);
			break;

		default:
			break;
		}
		if (col.a <= 0.0f)
		{
			col.a = 0.0f;
		}
		if (col.r <= 0.0f)
		{
			col.r = 0.0f;
		}
		if (col.g <= 0.0f)
		{
			col.g = 0.0f;
		}
		if (col.b <= 0.0f)
		{
			col.b = 0.0f;
		}
		//
		if (num <= 0.0f)
		{
			m_colMove = false;
		}
		else if (num >= 255.0f)
		{
			m_colMove = true;
		}

		if (m_colMove == false)
		{
			num +=1.0f;
		}
		else if (m_colMove == true)
		{
			num -=1.0f;
		}
		col.r = float(num / 255.0f);
		col.g = float(num / 255.0f);
		col.b = float(num / 255.0f);
		col.a = 1.0f;

		// ���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
		pVtx[1].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
		pVtx[2].col = D3DXCOLOR(col.r, col.g, col.b, col.a);
		pVtx[3].col = D3DXCOLOR(col.r, col.g, col.b, col.a);

		// ���_�f�[�^���A�����b�N����
		m_pVtxBuffer->Unlock();
	}

}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCTitleMark�̏I������
//  �߂�l�@�F
//=============================================================================
void CTitleMark::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
