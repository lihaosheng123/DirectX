/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CBuildLight
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2017/01/09
* BuildLight
********************************************************************************/
#ifndef _CBUILDLIGHT_H_
#define _CBUILDLIGHT_H_
#include "main.h"
#include "manager.h"


//�\����
typedef struct
{
	D3DXCOLOR	diffuse;
	D3DXVECTOR3	vecDir;
	float m_Range;
}BUILDLIGHT;

//�}�N����`
#define BUILD_LIGHT_NUM 1

class CBuildLight
{
	friend class CBuildMap;
public:
	CBuildLight();
	~CBuildLight();
	HRESULT Init(D3DXVECTOR3 pos);		// ����������
	void Update(void);
	static CBuildLight* Create(D3DXVECTOR3 pos);//�����֐�
private:

	D3DLIGHT9	m_aLight[BUILD_LIGHT_NUM];		//���C�g���
	BUILDLIGHT		m_Light[BUILD_LIGHT_NUM];		//���̕����ƌ��̋����̍\����

	D3DXVECTOR3 vecDir[BUILD_LIGHT_NUM];
	D3DXVECTOR3	m_Position;
	int m_Changge;
};

#endif