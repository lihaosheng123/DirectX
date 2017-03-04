/********************************************************************************
* �t�@�C�����@CBuildMenu_Another.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/12/17
2D�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "scene.h"
#include "scene2D.h"
#include "CBuildMenu_Another.h"

//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CBuildMenu_Another::CBuildMenu_Another()
{
	for (int i = 0; i < MENU_ANOTHER_NUM; i++)
	{
		m_pTexture_Build_Another[i] = NULL;
		m_pVtxBuffer_Build_Another[i] = NULL;	//���_�p�b�t�@�ւ̃|�C���^
	}
	m_bUse = false;

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CBuildMenu_Another::~CBuildMenu_Another()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F�v���S���̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CBuildMenu_Another::Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();


	m_Position = D3DXVECTOR3(pos.x, pos.y, pos.z);	// ���_���W
	m_Rotation = D3DXVECTOR3(rot.x, rot.y, rot.z);	// ��]

	m_height = height;
	m_width = width;
	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
		"data\\TEXTURE\\start.png",		// �t�@�C���̖��O
		&m_pTexture_Build_Another[0]);	// �ǂݍ��ރ�����

									// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
		"data\\TEXTURE\\end.png",		// �t�@�C���̖��O
		&m_pTexture_Build_Another[1]);	// �ǂݍ��ރ�����

										// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
		"data\\TEXTURE\\present.png",		// �t�@�C���̖��O
		&m_pTexture_Build_Another[2]);	// �ǂݍ��ރ�����


	for (int i = 0; i < MENU_ANOTHER_NUM; i++)
	{
		//�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
		if (FAILED(device->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * 1,	// ���_�f�[�^�p�Ɋm�ۂ���o�b�t�@�T�C�Y(�o�C�g�P��)
			D3DUSAGE_WRITEONLY,						// ���_�o�b�t�@�̎g�p�@
			FVF_VERTEX_2D,							// �g�p���钸�_�t�H�[�}�b�g
			D3DPOOL_MANAGED,						// ���\�[�X�̃o�b�t�@��ێ����郁�����N���X���w��
			&m_pVtxBuffer_Build_Another[i],						// ���_�o�b�t�@�C���^�[�t�F�[�X�ւ̃|�C���^
			NULL)))									// NULL�ɐݒ�
		{
			return E_FAIL;
		}

		{//���_�o�b�t�@�̒��g�𖄂߂�
			VERTEX_2D *pVtx;

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[i]->Lock(0, 0, (void**)&pVtx, 0);


			// ���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(m_Position.x - m_width / 2 + i*120.0f, m_Position.y - m_height / 2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(m_Position.x + m_width / 2 + i*120.0f, m_Position.y - m_height / 2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(m_Position.x - m_width / 2 + i*120.0f, m_Position.y + m_height / 2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(m_Position.x + m_width / 2 + i*120.0f, m_Position.y + m_height / 2, 0.0f);

			// rhw�̐ݒ�
			pVtx[0].rhw =
				pVtx[1].rhw =
				pVtx[2].rhw =
				pVtx[3].rhw = 1.0f;

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// �e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
			pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);
		}

		// ���_�f�[�^���A�����b�N����
		m_pVtxBuffer_Build_Another[i]->Unlock();
	}
	m_type = BUILD_MENU_ANOTHER_00;
	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CBuildMenu_Another::Uninit(void)
{
	for (int i = 0; i < MENU_ANOTHER_NUM; i++)
	{
		RELEASE(m_pTexture_Build_Another[i]);
		RELEASE(m_pVtxBuffer_Build_Another[i]);
	}
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F�v���S���̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CBuildMenu_Another::Draw(void)
{
	if (m_bUse == true)
	{
		CManager *manager = GetManager();

		CRenderer *renderer = manager->GetRenderer();

		LPDIRECT3DDEVICE9 device = renderer->GetDevice();
		for (int i = 0; i < MENU_ANOTHER_NUM; i++)
		{
			// ���_�F�t�H�[�}�b�g
			device->SetFVF(FVF_VERTEX_2D);

			//�e�N�X�`���̐ݒ�
			device->SetTexture(0, m_pTexture_Build_Another[i]);

			// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h����
			device->SetStreamSource(
				0,
				m_pVtxBuffer_Build_Another[i],
				0,
				sizeof(VERTEX_2D)
			);
			// �t�F�[�h�̕`��ݒ���e
			device->DrawPrimitive(
				D3DPT_TRIANGLESTRIP,		// �v���~�e�B�u�̎��
				0,		// �ŏ��̒��_�̃C���f�b�N�X
				2			// �`�悷��v���~�e�B�u��
			);
			// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);			// �f�t�H���g�ɖ߂��B
			device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_ALWAYS);			// �f�t�H���g�ɖ߂��B
		}
	}
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F�v���S���̍X�V����	
//  �߂�l�@�F
//=============================================================================
void CBuildMenu_Another::Update(void)
{
	CManager *manager = GetManager();
	CBuildManager *BuildManager = (CBuildManager*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();
	CBuildMenu *m_BuildMenu = BuildManager->GetBuildMenu();

	if (m_bUse == true)
	{
		switch (m_type)
		{
		case BUILD_MENU_ANOTHER_00:
			if (m_Input->GetKeyboardTrigger(DIK_RIGHT))
			{
				m_type = BUILD_MENU_ANOTHER_START;
			}
			break;
		case BUILD_MENU_ANOTHER_START:
			//���_�o�b�t�@�̒��g�𖄂߂�
			VERTEX_2D *pVtx;
			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[0]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(100, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[0]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[1]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[1]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[2]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[2]->Unlock();

			if (m_Input->GetKeyboardTrigger(DIK_LEFT))
			{
				m_bUse = false;
				m_type = BUILD_MENU_ANOTHER_00;
				m_BuildMenu->m_type = m_BuildMenu->BUILD_MENU_ANOTHER;
			}

			if (m_Input->GetKeyboardTrigger(DIK_RIGHT))
			{
				m_type = BUILD_MENU_ANOTHER_END;
			}

			break;

		case BUILD_MENU_ANOTHER_END:
			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[1]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(100, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[1]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[0]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[0]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[2]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[2]->Unlock();

			if (m_Input->GetKeyboardTrigger(DIK_LEFT))
			{
				m_type = BUILD_MENU_ANOTHER_START;
			}

			if (m_Input->GetKeyboardTrigger(DIK_RIGHT))
			{
				m_type = BUILD_MENU_ANOTHER_PRESENT;
			}
			break;


		case BUILD_MENU_ANOTHER_PRESENT:
			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[2]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(100, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(100, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[2]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[0]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[0]->Unlock();

			// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
			m_pVtxBuffer_Build_Another[1]->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
			pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);

			// ���_�f�[�^���A�����b�N����
			m_pVtxBuffer_Build_Another[1]->Unlock();

			if (m_Input->GetKeyboardTrigger(DIK_LEFT))
			{
				m_type = BUILD_MENU_ANOTHER_END;
			}
			break;

		default:
			break;

		}
	}
}

CBuildMenu_Another* CBuildMenu_Another::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE)
{
	CBuildMenu_Another *m_BuildMenu_Another;
	m_BuildMenu_Another = new CBuildMenu_Another;
	m_BuildMenu_Another->Init(pos, rot, height, width, TEXTURE_FILE);
	return m_BuildMenu_Another;
}
