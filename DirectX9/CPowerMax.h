/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CPowerMax.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* Power�̉�ʕ`��
********************************************************************************/
#ifndef _CPOWERMAX_H_
#define _CPOWERMAX_H_

#define	TEXTURE_POWERMAX_FILE		"data\\TEXTURE\\PowerMax.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CPowerMax : public CScene
{
public:
	CPowerMax();
	~CPowerMax();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CPowerMax* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

	bool m_bUse;
};
#endif
