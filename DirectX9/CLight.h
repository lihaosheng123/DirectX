/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@sceneX.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
* X�|���S���`��
********************************************************************************/
#ifndef _CLIGHT_H_
#define _CLIGHT_H_
#include "main.h"
#include "manager.h"


//�\����
typedef struct
{
	D3DXCOLOR	diffuse;
	D3DXVECTOR3	vecDir;
}LIGHT;

//�}�N����`

#define LIGHT_NUM 4

class CLight 
{
public:
	CLight();
	~CLight();
	HRESULT Init(void);		// ����������
private:

	D3DLIGHT9	m_aLight[ LIGHT_NUM ];		//���C�g���
	LIGHT		m_Light[ LIGHT_NUM ];		//���̕����ƌ��̋����̍\����
};

#endif