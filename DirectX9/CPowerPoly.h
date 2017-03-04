/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CPowerPoly.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* Power�̉�ʕ`��
********************************************************************************/
#ifndef _CPOWERPOLY_H_
#define _CPOWERPOLY_H_

#define	TEXTURE_POWERPOLY_FILE		"data\\TEXTURE\\PowerPoly.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CPowerPoly : public CScene
{
	friend class CEnemy_Bullet_Down;
	friend class CEnemy_Bullet_Up;
	friend class CEnemy_Bullet_Left;
	friend class CEnemy_Bullet_Right;
public:
	CPowerPoly();
	~CPowerPoly();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CPowerPoly* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
};
#endif