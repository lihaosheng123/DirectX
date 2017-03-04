/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@Camera.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/28
* Title��Camera
********************************************************************************/
#ifndef	_CTITLECAMERA_H_
#define	_CTITLECAMERA_H_

#include "main.h"
#include "manager.h"

/*******************************************************************************
* �}�N����`
*******************************************************************************/
#define ANGLE_CAMERA (45.0f)		//���W�A��
#define ASPECT_CAMERA (SCREEN_WIDTH/SCREEN_HEIGHT)		//�A�X�y�N�g��
#define NEAR_Z (10.0f)		//NearZ�l
#define FAR_Z (10000.0f)		//FarZ�l
class CTitleCamera
{
	friend class CField;
private:
	D3DXVECTOR3 m_posV;		//���_
	D3DXVECTOR3 m_posR;		//�����_
	D3DXVECTOR3 m_OldPosV;
	D3DXVECTOR3 m_vecU;		//����ʃx�N�g��
	D3DXMATRIX m_mtxProjection;		//�v���W�F�N�V�����X�g���b�N�X
	D3DXMATRIX m_mtxView;		//�r���[�}�g���b�N�X
	D3DXVECTOR3 rot;		//����
	float m_fDistance;		//����
	bool m_bRotate;	//true�Ȃ王�_�𒆐S�Afalse�Ȃ璍���_�𒆐S
	D3DXVECTOR3 m_RotCheck;		//check����
	D3DXVECTOR3 m_Velocity;
	D3DXVECTOR3 m_Vektor;
	D3DXVECTOR3 m_regulator;


public:
	CTitleCamera();
	~CTitleCamera();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����


};
#endif