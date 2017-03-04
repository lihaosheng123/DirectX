/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CTitleLight.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
* Light�`��
********************************************************************************/
#ifndef _CTITLELIGHT_H_
#define _CTITLELIGHT_H_
#include "main.h"
#include "manager.h"


//�\����
typedef struct
{
	D3DXCOLOR	diffuse;
	D3DXVECTOR3	vecDir;
}TITLELIGHT;

//�}�N����`

#define TITLE_LIGHT_NUM 4

class CTitleLight
{
public:
	CTitleLight();
	~CTitleLight();
	HRESULT Init(void);		// ����������
private:

	D3DLIGHT9	m_aLight[TITLE_LIGHT_NUM];		//���C�g���
	TITLELIGHT		m_Light[TITLE_LIGHT_NUM];		//���̕����ƌ��̋����̍\����
};

#endif
