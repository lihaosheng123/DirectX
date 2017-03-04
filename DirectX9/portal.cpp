/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@CPortal.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
���X�|���S���̕`��p
********************************************************************************/
#include "main.h"
#include "Camera.h"
#include "sceneX.h"
#include "manager.h"
#include "scene.h"
#include "portal.h"
#include "sceneMouse.h"
#include "score.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CPortal::CPortal()
{
	m_pTexture = NULL;			// Direct3D�e�N�X�`���̃|�C���^

	m_pVtxBuffer = NULL;		// Direct3D�o�b�t�@�ւ̃|�C���^
	m_Buse = true;
	m_OneCheck = false;
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CPortal::~CPortal()
{

}
//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F3D�̏�����
//  �߂�l�@�FHRESULT
//=============================================================================
HRESULT CPortal::Init (D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	int nNumVertices;	// ���_��
	DWORD sizeFVF;		// ���_�t�H�[�}�b�g�̃T�C�Y
	BYTE *pVtxBuff;		// ���_���i���_���W�j�ւ̃|�C���^


	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CRenderer *renderer = manager -> GetRenderer();

	CEffect *m_Effect = game ->GetEffect();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
////////////

		D3DXCreateTextureFromFile(device,"data\\TEXTURE\\portal.png",&m_pTexture);// �e�N�X�`���ǂݍ���
		// X�t�@�C���̓ǂݍ���
		if( FAILED( D3DXLoadMeshFromX( TEXTURE_FILE,
									   D3DXMESH_SYSTEMMEM,				// �m�ۂ���o�b�t�@�̃T�C�Y�i�o�C�g�P�ʁj�B�Q�[���ɂ���ĉ����_�Ȃ̂��ς��B����͎l�p������S�B
									   device,
									   NULL,
									   &m_BuffMat,		// �}�e���A�����
									   NULL,
									   &m_nNumMat,			// �}�e���A����
									   &m_Mesh ) ) )		// ���b�V�����
		{
			return E_FAIL;
		}
		// ���f���̏����ݒ�
		m_Position = D3DXVECTOR3(pos.x,pos.y,pos.z);	// ���_���W
		m_Rotation = D3DXVECTOR3(rot.x,rot.y,rot.z);	// ��]
		m_scl = D3DXVECTOR3( 1.0f,  1.0f, 1.0f );
		m_Max = D3DXVECTOR3( 0.0f,  0.0f, 0.0f );
		m_Min = D3DXVECTOR3( 0.0f,  0.0f, 0.0f );
		// �Փ˔���Ŏg�����߂̏���////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// x�t�@�C���̒��_�����擾����B
		nNumVertices = m_Mesh->GetNumVertices();

		// ���_�t�H�[�}�b�g�̃T�C�Y���擾����B
		sizeFVF = D3DXGetFVFVertexSize( m_Mesh->GetFVF() );

		// �Փ˔���Ŏg�����߂ɁA����x�t�@�C���̒��ň�ԑ傫��x,y,z�̒l�ƁA��ԏ�����x,y,z�̒l���`�F�b�N����B
		m_Mesh->LockVertexBuffer( D3DLOCK_READONLY, ( void** )&pVtxBuff);
		for( int nCntVtx = 0; nCntVtx < nNumVertices; nCntVtx++ )
		{
			// ���_�����擾����B
			D3DXVECTOR3 vtx = *( D3DXVECTOR3* )pVtxBuff;

			if( vtx.x <m_Min.x )		m_Min.x = vtx.x;		// x�̍ŏ��l�̍X�V
			if( vtx.x > m_Max.x )		m_Max.x = vtx.x;		// x�̍ő�l�̍X�V
			if( vtx.y < m_Min.y )		m_Min.y = vtx.y;		// y�̍ŏ��l�̍X�V
			if( vtx.y > m_Max.y )		m_Max.y = vtx.y;		// y�̍ő�l�̍X�V
			if( vtx.z < m_Min.z )		m_Min.z = vtx.z;		// z�̍ŏ��l�̍X�V
			if( vtx.z > m_Max.z )		m_Max.z = vtx.z;		// z�̍ő�l�̍X�V

			// ���̒��_�Ɉړ�����B
			pVtxBuff += sizeFVF;
		}
		m_Mesh->UnlockVertexBuffer();



		// �Փ˔���̒����̐ݒ�
		if( m_Size.x < m_Size.z )
		{
			m_Collisoin = m_Size.z;
		}
		else
		{
			m_Collisoin = m_Size.x;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�v���S���̏I������
//  �߂�l�@�F
//=============================================================================
void CPortal:: Uninit(void)
{
	RELEASE(m_pTexture);
	RELEASE(m_BuffMat);
	RELEASE(m_Mesh);
}
//------------------------------------------------------------------------------
//	�֐���:	void CPortal::Draw
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CPortal::Draw(void)
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATERIAL *pMat;		// �}�e���A�����
	D3DMATERIAL9 matDef;	// �f�t�H���g�̃}�e���A���B���̃}�e���A���̏���ޔ������邽�߂̕ϐ��B
	if(m_Buse== true)
	{
	// ���݂̃}�e���A�������擾����B
	device->GetMaterial( &matDef );
	// �����_�[�X�e�[�g�̐ݒ�iz�e�X�g�j
	device->SetRenderState( D3DRS_ZENABLE, TRUE );
	device->SetRenderState( D3DRS_ZFUNC,D3DCMP_LESSEQUAL );
	device->SetRenderState( D3DRS_ZWRITEENABLE, TRUE );		//z�l�̍X�V
	// �����_�[�X�e�[�g�̐ݒ�i�A���t�@�e�X�g�j


	//���f���ɖ���ɂȂ�
	device->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	device->SetRenderState(D3DRS_SPECULARENABLE, true);

		// ���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity( &m_mtxWorld );

		// �X�P�[���𔽉f
		D3DXMatrixScaling( &mtxScl, m_scl.x, m_scl.y, m_scl.z );
		D3DXMatrixMultiply( &m_mtxWorld, &m_mtxWorld, &mtxScl );

		// ��]�𔽉f
		D3DXMatrixRotationYawPitchRoll( &mtxRot, m_Rotation.y, m_Rotation.x, m_Rotation.z );	// y,x,z
		D3DXMatrixMultiply( &m_mtxWorld, &m_mtxWorld, &mtxRot );



		// �ʒu�𔽉f
		D3DXMatrixTranslation( &mtxTrans, m_Position.x, m_Position.y, m_Position.z );
		D3DXMatrixMultiply( &m_mtxWorld, &m_mtxWorld, &mtxTrans );



		// ���[���h�}�g���b�N�X��ݒ�
		device->SetTransform( D3DTS_WORLD, &m_mtxWorld );

		// �L���X�g�ϊ�
		pMat = ( D3DXMATERIAL* )m_BuffMat->GetBufferPointer();

		for( int nCntMat = 0; nCntMat < ( int )m_nNumMat; nCntMat++ )
		{
			// �}�e���A���̐ݒ�
			device->SetMaterial( &pMat[ nCntMat ].MatD3D );

			// �e�N�X�`���̐ݒ�
			device->SetTexture( 0, m_pTexture);		
			// ���b�V���̕`��
			m_Mesh->DrawSubset( nCntMat );
		}
	// �����_�[�X�e�[�g�̐ݒ���f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHATESTENABLE, FALSE );			// �f�t�H���g�ɖ߂��B
	device->SetRenderState( D3DRS_ALPHAFUNC, D3DCMP_ALWAYS );			// �f�t�H���g�ɖ߂��B
	// �}�e���A���������ɖ߂��B�߂��Ȃ��Ǝ��ɕ`�悳���}�e���A�������������Ȃ�B�ԐF�̂܂܁A�Ƃ��B
	device->SetMaterial( &matDef );
	}
}
//------------------------------------------------------------------------------
//	�֐���:	void CPortal::Update
//	����:	�Ȃ�
//	�߂�l:	�Ȃ�
//	����:	�`�揈��
//------------------------------------------------------------------------------
void CPortal::Update(void)
{
	//  �f�o�C�X�̃Q�b�^�[
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager:: GetMode();
	CCamera *m_Camera = game->GetCCamera();
	CSceneInput *m_Input = manager -> GetInput();
	CScore *m_Score = game ->GetScore();
	CTransferEffect *m_TransferEffect = game->GetTransferEffect();
	//for( int index = 0; index < MAX_BALL; index++ )
	//{
	//	CBall *m_Ball = game ->GetBall(index);
	//	D3DXVECTOR3 vpe_Portal = m_Ball->m_Position - m_Position;//�n�_����I�_�܂ł̃x�N�g��
	//	//ball�Ƃ̓����蔻��
	//	if( Length( &vpe_Portal ) < 120.0f )
	//		{
	//			if(m_Ball->m_state == BALL_COMMON)
	//			{
	//				m_Ball->m_DrawUse = false;
	//				//m_OneCheck = true;
	//				m_Ball->Release();
	//				m_Score->AddScore(1);
	//				return;
	//			}
	//		}
	//}
	//if(m_OneCheck == true)
	//{
	//	m_Score->AddScore(1);
	//	m_OneCheck = false;
	//}
}
CPortal* CPortal::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE)
{
	CPortal *Portal;
	Portal = new CPortal;
	Portal->Init(pos,rot,height ,width,TEXTURE_FILE);
	return Portal;
}
float  CPortal::Length( D3DXVECTOR3 *Vector )
{

	float len = sqrtf( Vector->x * Vector->x +
						Vector->y * Vector->y +
						Vector->z * Vector->z );

	return len;

}

void CPortal::Normalize( D3DXVECTOR3 *Vector, D3DXVECTOR3 *Vector1 )
{

	*Vector = *Vector1 / Length( Vector1 );

}