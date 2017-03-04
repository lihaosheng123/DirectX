#include "main.h"
#include "manager.h"
#include "skybox.h"
//�O���[�o���ϐ�

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CSkybox::CSkybox()
{
	for(int i = 0;i < 6 ; i ++ )
	{
	m_pTexture[i] = NULL;			// Direct3D�e�N�X�`���̃|�C���^
	}
	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^

	m_Position.x = 0.0f;		//�n�ʂ�X�̏�����
	m_Position.y = 0.0f;		//�n�ʂ�Y�̏�����
	m_Position.z = 0.0f;		//�n�ʂ�Z�̏�����

	m_Rotation.x = 0.0f;		//�n�ʂ�X�̉�]������
	m_Rotation.y = 0.0f;		//�n�ʂ�Y�̉�]������
	m_Rotation.z = 0.0f;		//�n�ʂ�Z�̉�]������

	m_scl.x = 1.0f;		//�n�ʂ�X�̃X�P�[��������
	m_scl.y = 1.0f;		//�n�ʂ�Y�̃X�P�[��������
	m_scl.z = 1.0f;		//�n�ʂ�Z�̃X�P�[��������

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CSkybox::~CSkybox()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CSkybox::Init (D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();

	m_Position = D3DXVECTOR3(m_Position.x,m_Position.y,m_Position.z);	// ���_���W
	//m_Rotation = rot;	// ��]
	//m_height = height;
	//m_width = width;
	//���_�o�b�t�@�̐���
	if( FAILED ( device -> CreateVertexBuffer(
												sizeof( VERTEX_3D ) * 6 *4,
												D3DUSAGE_WRITEONLY,
												FVF_VERTEX_3D,
												D3DPOOL_MANAGED,
												&m_pVtxBuffer,
												NULL
	) ) )
	{
		return E_FAIL;
	}
	//�e�N�X�`���̓ǂݍ���

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_lf.tga", &m_pTexture[0] );

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_bk.tga", &m_pTexture[1] );

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_rt.tga", &m_pTexture[2] );

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_ft.tga", &m_pTexture[3] );

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_up.tga", &m_pTexture[4] );

	D3DXCreateTextureFromFile( device, "data\\TEXTURE\\sandstorm_dn.tga", &m_pTexture[5] );




	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;
	m_pVtxBuffer -> Lock( 0, 0, ( void** ) &pVtx, 0 );

	for( int i = 0; i < 6; i++ ,pVtx += 4 )
	{
		switch(i)
		{
			//�������̖�
		case 0:
		
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z +50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̑O
		case 1:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y + 50000.0f,m_Position.z+50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̉E
		case 2:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̌�
		case 3:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

		//�ʂ̏�
		case 4:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;
		

		//�ʂ̉�
		case 5:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;
		}

	}
	/* ���_��� �J�M���� */
	m_pVtxBuffer -> Unlock();

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CSkybox:: Uninit(void)
{
	for(int i = 0;i < 6 ; i ++ )
	{
	RELEASE(m_pTexture[i]);
	}
	RELEASE(m_pVtxBuffer);
}
//------------------------------------------------------------------------------
//	�֐���:	void CSkybox::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CSkybox::Draw(void)
{

	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;

	// ���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity( &m_Matrix.World);

	// �X�P�[���𔽉f
	D3DXMatrixScaling( &mtxScl, m_scl.x, m_scl.y, m_scl.z );
	D3DXMatrixMultiply( &m_Matrix.World, &m_Matrix.World, &mtxScl );

	// ��]�𔽉f
	D3DXMatrixRotationYawPitchRoll( &mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z );	// y,x,z
	D3DXMatrixMultiply( &m_Matrix.World, &m_Matrix.World, &mtxRot );

	// �ʒu�𔽉f
	D3DXMatrixTranslation( &mtxTrans, m_Position.x, m_Position.y, m_Position.z );
	D3DXMatrixMultiply( &m_Matrix.World, &m_Matrix.World, &mtxTrans );
		

	// ���[���h�}�g���b�N�X��ݒ�
	device -> SetTransform( D3DTS_WORLD, &m_Matrix.World );

	device->SetRenderState( D3DRS_LIGHTING, FALSE );
	// ���_�F�t�H�[�}�b�g
	device -> SetFVF ( FVF_VERTEX_3D );




	//device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);		//����������̏ꍇ
	//device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	//device ->SetTextureStageState( 0 , D3DTSS_COLOROP , D3DTOP_MODULATE );
	for(int i = 0;i < 6 ; i ++ )
	{
	// �e�N�X�`���̐ݒ�
	device -> SetTexture ( 0, m_pTexture[i] );


	// ���_�o�b�t�@���f�[�^�X�g���[���Ƀo�C���h����
	device -> SetStreamSource(
								0,
								m_pVtxBuffer,
								0,
								sizeof(VERTEX_3D)
								);
	

	device ->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_MIRROR);
	device ->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_MIRROR);
	// �|���S���̕`��
	device -> DrawPrimitive(
							  D3DPT_TRIANGLESTRIP, // �v���~�e�B�u�̎��
							  i * 4,                   // �ŏ��̒��_�̃C���f�b�N�X
							  2                     // �`�悷��v���~�e�B�u��
							);

	}


	// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device ->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	device ->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	device->SetRenderState( D3DRS_ALPHATESTENABLE, FALSE );			// �f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_ALWAYS );			// �f�t�H���g�ɖ߂��B

	// ���C�g�_��
	device->SetRenderState( D3DRS_LIGHTING, TRUE );
}
//------------------------------------------------------------------------------
//	�֐���:	void CSkybox::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CSkybox::Update(void)
{
	//  �f�o�C�X�̃Q�b�^�[

	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CCamera *m_Camera =game->GetCCamera();
	CPlayer *m_Player = game->GetPlayer();
	m_Position.x = m_Player->m_Position.x;
	m_Position.y = m_Player->m_Position.y;
	//�t�B�[���h���_�o�b�t�@�̏�����
	VERTEX_3D *pVtx;
	m_pVtxBuffer -> Lock( 0, 0, ( void** ) &pVtx, 0 );

	for( int i = 0; i < 6; i++ ,pVtx += 4 )
	{
		switch(i)
		{
			//�������̖�
		case 0:
		
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z +50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̑O
		case 1:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y + 50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y + 50000.0f,m_Position.z+50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̉E
		case 2:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

			//�ʂ̌�
		case 3:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;

		//�ʂ̏�
		case 4:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z-50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y+ 50000.0f,m_Position.z+50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);



		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;
		

		//�ʂ̉�
		case 5:
			
		pVtx[ 0 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);	// ���_���W
		pVtx[ 1 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z+50000.0f);
		pVtx[ 2 ].pos = D3DXVECTOR3(m_Position.x-50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);
		pVtx[ 3 ].pos = D3DXVECTOR3(m_Position.x+50000.0f,m_Position.y -50000.0f,m_Position.z-50000.0f);

		// ���_�F�ݒ�
		pVtx[0].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[1].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[2].col = D3DCOLOR_RGBA(255, 255, 255, 255);
		pVtx[3].col = D3DCOLOR_RGBA(255, 255, 255, 255);


		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	

		// ���W�ϊ��ςݒ��_�ݒ�
		pVtx[0].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[1].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[2].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );
		pVtx[3].nor = D3DXVECTOR3( 0.0f, 1.0f, 0.0f );

		break;
		}

	}
	/* ���_��� �J�M���� */
	m_pVtxBuffer -> Unlock();


}
CSkybox* CSkybox::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	CSkybox *skybox;
	skybox = new CSkybox;
	skybox->Init(pos,rot,height ,width,TEXTURE_FILE);
	return skybox;
}