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
#include "fade.h"

//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CFade::CFade()
{
	m_pTexture = NULL;
	m_pVtxBuffer  = NULL;	//���_�p�b�t�@�ւ̃|�C���^

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CFade::~CFade()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F�v���S���̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CFade ::Init(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	

	m_Position = D3DXVECTOR3(SCREEN_CENTER_X,SCREEN_CENTER_Y,0.0f);	// ���_���W
	m_Rotation = D3DXVECTOR3(0.0f,0.0f,0.0f);	// ��]

	m_height = SCREEN_HEIGHT;
	m_width = SCREEN_WIDTH;

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(device,				// �f�o�C�X�ւ̃|�C���^
								TEXTURE_FADEBG_FILE,		// �t�@�C���̖��O
								&m_pTexture);	// �ǂݍ��ރ������[

	 //�I�u�W�F�N�g�̒��_�o�b�t�@�𐶐�
    if(FAILED(device->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * 1,	// ���_�f�[�^�p�Ɋm�ۂ���o�b�t�@�T�C�Y(�o�C�g�P��)
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
			pVtx[0].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y - m_height/2, 0.0f);
			pVtx[1].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y - m_height/2, 0.0f);
			pVtx[2].pos = D3DXVECTOR3( m_Position.x - m_width/2, m_Position.y + m_height/2, 0.0f);
			pVtx[3].pos = D3DXVECTOR3( m_Position.x + m_width/2, m_Position.y + m_height/2, 0.0f);

			// rhw�̐ݒ�
			pVtx[0].rhw =	
			pVtx[1].rhw =
			pVtx[2].rhw =
			pVtx[3].rhw = 1.0f;

			// ���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
			pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
			pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
			pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);

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
void CFade :: Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F�v���S���̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CFade :: Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	// ���_�F�t�H�[�}�b�g
	device -> SetFVF ( FVF_VERTEX_2D );

	//�e�N�X�`���̐ݒ�
	device -> SetTexture ( 0, m_pTexture);

	// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h����
	device -> SetStreamSource(
								0,
								m_pVtxBuffer,
								0,
								sizeof(VERTEX_2D)
								);
	// �t�F�[�h�̕`��ݒ���e
	device -> DrawPrimitive(
							  D3DPT_TRIANGLESTRIP,		// �v���~�e�B�u�̎��
							  0,		// �ŏ��̒��_�̃C���f�b�N�X
							  2			// �`�悷��v���~�e�B�u��
							);
	// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHATESTENABLE, FALSE );			// �f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_ALWAYS );			// �f�t�H���g�ɖ߂��B
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F�v���S���̍X�V����	
//  �߂�l�@�F
//=============================================================================
void CFade :: Update(void)
{
	CManager *manager = GetManager();
	CSceneInput *m_Input = manager -> GetInput();
	{//���_�o�b�t�@�̒��g�𖄂߂�
		VERTEX_2D *pVtx;

		// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
		m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);



		// ���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, manager->m_FadeCount / 30.0f);
	
	}

	// ���_�f�[�^���A�����b�N����
	m_pVtxBuffer->Unlock();
}
