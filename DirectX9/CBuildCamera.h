/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CBuildCamera.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/12/20
* �c�[�����[�h�ŁA�J�����̍쐬
********************************************************************************/
#ifndef	_CBUILDCAMERA_H_
#define	_CBUILDCAMERA_H_

/*******************************************************************************
* �}�N����`
*******************************************************************************/
#define BUILDCAMERA_MOVE (20.0f)		//�J�����̈ړ���
class CBuildCamera
{
	//�t�����h�N���X
	friend class CWall_001;
	friend class CWall_002;
	friend class CEnemy_001;
	friend class CEnemy_002;
	friend class CBuildLight;
	friend class CTrail;
	friend class CCeiling;
	friend class CDoor;
	friend class CPoint;
	friend class CColumnar;
	friend class CStart;
	friend class CEnd;
	friend class CRobot;
private:
	D3DXVECTOR3 m_posV;		//���_
	D3DXVECTOR3 m_posR;		//�����_
	D3DXVECTOR3 m_vecU;		//����ʃx�N�g��
	D3DXVECTOR3 m_RotCheck;		//check����
	D3DXVECTOR3 m_3DPos;
	D3DXVECTOR3 rot;		//����
	D3DXMATRIX m_mtxProjection;		//�v���W�F�N�V�����X�g���b�N�X
	D3DXMATRIX m_mtxView;		//�r���[�}�g���b�N�X

	float m_fDistance;		//����
	bool m_bRotate;	//true:���_�𒆐S�Afalse:�����_�𒆐S


public:
	CBuildCamera();
	~CBuildCamera();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����


};

#endif