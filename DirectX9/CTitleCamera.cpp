/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@TitleCamera.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/28
* TitleCamera
********************************************************************************/
#include "CTitleCamera.h"
//=============================================================================
// �N���X�R���X�g���N�^
//=============================================================================//
CTitleCamera::CTitleCamera()
{

}
//=============================================================================
// �N���X�f�X�g���N�^
//=============================================================================
CTitleCamera::~CTitleCamera()
{

}
//================================================================================================================================================================================================
// Init�֐�
// ���� void
// �߂�l void
// ���� 
//================================================================================================================================================================================================
void CTitleCamera::Init(void)
{
	CManager *manager = GetManager();

	CGame *game = (CGame*)CManager::GetMode();

	CRenderer *renderer = manager->GetRenderer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();


	// ���_�i�����j
	m_posV = D3DXVECTOR3(0.0f, 100.0f, -100.0f);	// 0, 100~200, -100~-300

												// �����_�i���Ă��j
	m_posR = D3DXVECTOR3(0.0f, 50.5f, 400.0f);

	// ������x�N�g���i�J�����������j
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);	// �قڕς��Ȃ��B

											// �����i�p�x�j
	rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	// m_posV��m_posR�̑Ίp���̒���
	// posV��posR�̑Ίp���̒���
	m_fDistance = sqrtf(((m_posR.x - m_posV.x) * (m_posR.z - m_posV.z)) + ((m_posR.z - m_posV.z) * (m_posR.z - m_posV.z)));
	//	m_fDistance =450.0f;
	m_bRotate = true;

}
void CTitleCamera::Uninit(void)
{

}
void CTitleCamera::Update(void)
{
	CManager *manager = GetManager();
	CGame *game = (CGame*)CManager::GetMode();
	CSceneInput *m_Input = manager->GetInput();

	CSceneMouse *m_Mouse = manager->GetMouse();

	CScore *m_Score = game->GetScore();

	CRenderer *renderer = manager->GetRenderer();

	CPlayer *m_Model = game->GetPlayer();

	LPDIRECT3DDEVICE9 device = renderer->GetDevice();
	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	// �v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		(D3DX_PI / 4),						// ����p�i�J�����̃����Y�̂悤�ɁA�L�por�]���j
		(float)SCREEN_WIDTH / SCREEN_HEIGHT,		// �A�X�y�N�g��(16:9)
		NEAR_Z,									// NearZ�l�i�J�����ɉf���͈͂́A�őO�̋����j
		FAR_Z);								// Far�l  �i�J�����ɉf���͈͂́A�ŉ��̋����j

											// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	device->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	// �r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_posV,
		&m_posR,
		&m_vecU);

	// �r���[�}�g���b�N�X�̐ݒ�
	device->SetTransform(D3DTS_VIEW, &m_mtxView);

	//�����p�x�̃`�F�b�N
	if (rot.y > D3DX_PI)
	{
		rot.y -= D3DX_PI * 2.0f;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y += D3DX_PI * 2.0f;
	}

	//rot.y -= D3DX_PI * 0.0005f;
	m_bRotate = true;			//���񒆐S�𒍎��_�ɐݒ�


	//���_���S
	if (m_bRotate == true)
	{
		m_posV.x = m_posR.x - m_fDistance * sinf(rot.y);
		m_posV.z = m_posR.z - m_fDistance * cosf(rot.y);
		m_bRotate = false;
	}

	//�����_���S
	else
	{
		m_posR.x = m_posV.x + m_fDistance * sinf(rot.y);
		m_posR.z = m_posV.z + m_fDistance * cosf(rot.y);
	}

}
void CTitleCamera::Draw(void)
{

}
