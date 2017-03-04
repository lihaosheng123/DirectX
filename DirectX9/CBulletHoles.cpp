/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@m_BulletHoles.cpp
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
CBulletHoles::CBulletHoles()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	for(int i = 0;i<BULLETHOLES_MAX;i++)
	{
		m_BulletHoles[i].m_bUse = false;
	}

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CBulletHoles::~CBulletHoles()
{

}
CBulletHoles* CBulletHoles::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	CBulletHoles *m_BulletHoles;
	m_BulletHoles = new CBulletHoles;
	m_BulletHoles->Init(pos,rot,height ,width,TEXTURE_FILE);
	return m_BulletHoles;
}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CBulletHoles::Init (D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	//���_�o�b�t�@�̐���
	if( FAILED ( device -> CreateVertexBuffer(
												sizeof( VERTEX_3D ) * BULLETHOLES_MAX * 4,
												D3DUSAGE_WRITEONLY,
												FVF_VERTEX_3D,
												D3DPOOL_MANAGED,
												&m_pVtxBuffer,
												NULL
	) ) )
	{
		return E_FAIL;
	}
	for(int i = 0;i<BULLETHOLES_MAX;i++)
	{

		m_BulletHoles[i].m_Position = pos;	// ���_���W
		m_BulletHoles[i].m_Rotation = rot;	// ��]
		m_BulletHoles[i].m_height = height;
		m_BulletHoles[i].m_width = width;

		m_BulletHoles[i].m_Life = 200;

		m_BulletHoles[i].nCount = 0;			// �J�E���^
		m_BulletHoles[i].nPattern = 0;		// �p�^�[��No.	

		m_BulletHoles[i].m_scl.x = 1.0f;
		m_BulletHoles[i].m_scl.y = 1.0f;
		m_BulletHoles[i].m_scl.z = 1.0f;

	}

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile( device, TEXTURE_FILE, &m_pTexture );
	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;

	m_pVtxBuffer -> Lock( 0, 0, ( void** ) &pVtx, 0 );

	for(int i = 0;i<BULLETHOLES_MAX;i++, pVtx += 4 )
	{

		pVtx[ 0 ].pos = D3DXVECTOR3(m_BulletHoles[i].m_Position.x- m_BulletHoles[i].m_width/2,m_BulletHoles[i].m_Position.y+ m_BulletHoles[i].m_height/2,0.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_BulletHoles[i].m_Position.x+ m_BulletHoles[i].m_width/2,m_BulletHoles[i].m_Position.y+ m_BulletHoles[i].m_height/2,0.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_BulletHoles[i].m_Position.x- m_BulletHoles[i].m_width/2,m_BulletHoles[i].m_Position.y- m_BulletHoles[i].m_height/2,0.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_BulletHoles[i].m_Position.x+ m_BulletHoles[i].m_width/2,m_BulletHoles[i].m_Position.y- m_BulletHoles[i].m_height/2,0.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(TEXTURE_SIZE_X_BULLETHOLES, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, TEXTURE_SIZE_Y_BULLETHOLES);
		pVtx[3].tex = D3DXVECTOR2(TEXTURE_SIZE_X_BULLETHOLES, TEXTURE_SIZE_Y_BULLETHOLES);
	
	}
	/* ���_��� �J�M���� */
	m_pVtxBuffer -> Unlock();
	return S_OK;
}
//=============================================================================
//  �֐����@�FDraw
//  �@�\�T�v�F3D�̕`�揈��
//  �߂�l�@�F
//=============================================================================
void CBulletHoles::Draw (void)
{

	CManager *manager = GetManager();
	CRenderer *renderer = manager->GetRenderer();
	CGame *game = (CGame*)CManager::GetMode();
	CCamera *m_Camera =game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	for (int i = 0; i<BULLETHOLES_MAX; i++)
	{
		if (m_BulletHoles[i].m_bUse == true)
		{
			// �r���[�}�g���b�N�X���擾
			device->GetTransform(D3DTS_VIEW, &m_BulletHoles[i].mtxView);

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
			D3DXMatrixIdentity(&m_BulletHoles[i].m_mtxWorld);


			// �X�P�[���𔽉f
			D3DXMatrixScaling(&m_BulletHoles[i].mtxScl, m_BulletHoles[i].m_scl.x, m_BulletHoles[i].m_scl.y, m_BulletHoles[i].m_scl.z);
			D3DXMatrixMultiply(&m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].mtxScl);

			// ��]�𔽉f
			D3DXMatrixRotationYawPitchRoll(&m_BulletHoles[i].mtxRot, m_BulletHoles[i].m_Rotation.y, m_BulletHoles[i].m_Rotation.x, m_BulletHoles[i].m_Rotation.z);	// �r���{�[�h�͏�ɐ��ʂ��J�����Ɍ�����2D�|���S��������A�I�[��0.0�̏����l�ł����B
			D3DXMatrixMultiply(&m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].mtxRot);

			// �ʒu�𔽉f
			D3DXMatrixTranslation(&m_BulletHoles[i].mtxTrans, m_BulletHoles[i].m_Position.x, m_BulletHoles[i].m_Position.y, m_BulletHoles[i].m_Position.z);
			D3DXMatrixMultiply(&m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].m_mtxWorld, &m_BulletHoles[i].mtxTrans);

			// ���[���h�}�g���b�N�X��ݒ�
			device->SetTransform(D3DTS_WORLD, &m_BulletHoles[i].m_mtxWorld);

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
void CBulletHoles::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CSceneInput *m_Input = manager -> GetInput();

	CRenderer *renderer = manager -> GetRenderer();

	CScore *m_Score = game ->GetScore();

	CCamera *m_Camera = game->GetCCamera();
	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();

	for (int i = 0; i < BULLETHOLES_MAX; i++)
	{
		if (m_BulletHoles[i].m_bUse == true)
		{
			m_BulletHoles[i].m_Life--;
			if (m_BulletHoles[i].m_Life <= 0)
			{
				m_BulletHoles[i].m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ���_���W
				m_BulletHoles[i].m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	// ��]
				m_BulletHoles[i].m_Life = 200;
				m_BulletHoles[i].m_bUse = false;
			}
		}
	}
	////���_�o�b�t�@�̒��g�𖄂߂�
	//VERTEX_3D *pVtx;
	//// ���_�f�[�^�͈̔͂����b�N���A���_�o�b�t�@�ւ̃|�C���^���擾
	//m_pVtxBuffer->Lock(0, 0, (void**)&pVtx, 0);

	//for (int i = 0; i < BULLETHOLES_MAX; i++)
	//{
	//	if (m_BulletHoles[i].m_bUse == true)
	//	{
	//		m_BulletHoles[i].nCount++;
	//		if ((m_BulletHoles[i].nCount % INTERVAL_PATTERN_BULLETHOLES) == 0)
	//		{// �A�j���[�V�����؂�ւ�
	//			m_BulletHoles[i].nPattern++;
	//			if (m_BulletHoles[i].nPattern >= NUM_PATTERN_BULLETHOLES)
	//			{// �A�j���[�V�����p�^�[�����I��
	//				m_BulletHoles[i].m_bUse = false;
	//			}
	//		}

	//	}
	//}
		//for (int i = 0; i < BULLETHOLES_MAX; i++, pVtx += 4)
		//	{
		//		if (m_BulletHoles[i].m_bUse == true)
		//		{
		//			pVtx[0].tex = D3DXVECTOR2(m_BulletHoles[i].nPattern * TEXTURE_SIZE_X_BULLETHOLES, m_BulletHoles[i].nPattern * TEXTURE_SIZE_Y_BULLETHOLES);
		//			pVtx[1].tex = D3DXVECTOR2((m_BulletHoles[i].nPattern + 1) * TEXTURE_SIZE_X_BULLETHOLES, m_BulletHoles[i].nPattern * TEXTURE_SIZE_Y_BULLETHOLES);
		//			pVtx[2].tex = D3DXVECTOR2(m_BulletHoles[i].nPattern * TEXTURE_SIZE_X_BULLETHOLES, (m_BulletHoles[i].nPattern + 1) * TEXTURE_SIZE_Y_BULLETHOLES);
		//			pVtx[3].tex = D3DXVECTOR2((m_BulletHoles[i].nPattern + 1) * TEXTURE_SIZE_X_BULLETHOLES, (m_BulletHoles[i].nPattern + 1) * TEXTURE_SIZE_Y_BULLETHOLES);
		//			// ���_�f�[�^���A�����b�N����
		//			m_pVtxBuffer->Unlock();
		//		}
		//	}
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�FCBulletHoles�̏I������
//  �߂�l�@�F
//=============================================================================
void CBulletHoles::Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_pVtxBuffer);
}
float  CBulletHoles::Length( D3DXVECTOR3 *Vector )
{
	float len = sqrtf( Vector->x * Vector->x +
						Vector->y * Vector->y +
						Vector->z * Vector->z );

	return len;

}

void CBulletHoles::Normalize( D3DXVECTOR3 *Vector, D3DXVECTOR3 *Vector1 )
{
	*Vector = *Vector1 / Length( Vector1 );
}
void CBulletHoles::SetBulletHoles( D3DXVECTOR3 pos,D3DXVECTOR3 rot)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CSceneInput *m_Input = manager -> GetInput();

	CRenderer *renderer = manager -> GetRenderer();

	for( int nCnt = 0; nCnt < BULLETHOLES_MAX; nCnt++)
	{
		//�e���g���Ă��Ȃ��Ȃ�
		if(m_BulletHoles[nCnt].m_bUse == false )
		{
			m_BulletHoles[nCnt].m_Position = pos;
			m_BulletHoles[nCnt].m_Rotation = rot;
			m_BulletHoles[nCnt].nCount = 0;
			m_BulletHoles[nCnt].nPattern = 0;
			m_BulletHoles[nCnt].m_bUse	= true;		//�e���g�p���Ă���
			break;
		}
	}
}
