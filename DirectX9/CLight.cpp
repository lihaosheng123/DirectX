/********************************************************************************
* �^�C�g���@OPENGL 01
* �t�@�C�����@sceneX.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/25
X�|���S���̕`��p
********************************************************************************/

#include "CLight.h"

//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================
CLight::CLight()
{
}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CLight::~CLight()
{

}
//================================================================================================================================================================================================
// Init�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
HRESULT CLight::Init( void )
{
	CManager *manager = GetManager();

	CRenderer *renderer = manager -> GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer -> GetDevice();
	D3DXVECTOR3 vecDir[LIGHT_NUM ];

	m_Light[ 0 ].diffuse	= D3DXCOLOR( 1.0f, 1.0f, 1.0f, 1.0f );
	m_Light[ 1 ].diffuse	= D3DXCOLOR( 0.75f, 0.75f, 0.75f, 1.0f );
	m_Light[ 2 ].diffuse	= D3DXCOLOR( 0.5f, 0.5f, 0.5f, 1.0f );
	m_Light[ 3 ].diffuse	= D3DXCOLOR( 0.4f, 0.8f, 0.8f, 1.0f );

	m_Light[ 0 ].vecDir		= D3DXVECTOR3( 0.0f, -1.0f, -2.0f );
	m_Light[ 1 ].vecDir		= D3DXVECTOR3( 0.0f, -1.0f, 2.0f );
	m_Light[ 2 ].vecDir		= D3DXVECTOR3( -1.0f, 1.0f, 0.0f );
	m_Light[ 3 ].vecDir		= D3DXVECTOR3(1.0f, 1.0f,0.0f );
	for( int nCntLight = 0; nCntLight < LIGHT_NUM; nCntLight++ )
	{
		ZeroMemory( &m_aLight[ nCntLight ],sizeof( D3DLIGHT9 ) );

		//���s����
		m_aLight[ nCntLight ].Type		= D3DLIGHT_DIRECTIONAL;

		//�g�U��
		m_aLight[ nCntLight ].Diffuse	= m_Light[ nCntLight ].diffuse;

		//���̕���
		vecDir[ nCntLight ]				= m_Light[ nCntLight ].vecDir;

		//���K��
		D3DXVec3Normalize( ( D3DXVECTOR3 * ) &m_aLight[ nCntLight ].Direction, &vecDir[ nCntLight ] );

		//���C�g�̐ݒ�
		device -> SetLight( nCntLight, &m_aLight[ nCntLight ] );

		//���C�g��L������
		//device -> LightEnable( nCntLight, TRUE );
	}
	return S_OK;
}