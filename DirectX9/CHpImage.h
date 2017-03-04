/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CHpImage.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* Hp�̉�ʕ`��
********************************************************************************/
#ifndef _CHPIMAGE_H_
#define _CHPIMAGE_H_

#define	TEXTURE_HPIMAGE_FILE		"data\\TEXTURE\\HpImage.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CHpImage : public CScene
{
	friend class CEnemy_Bullet_Down;
	friend class CEnemy_Bullet_Up;
	friend class CEnemy_Bullet_Left;
	friend class CEnemy_Bullet_Right;
public:
	CHpImage();
	~CHpImage();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CHpImage* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	int m_r;
	int m_b;
	bool m_Alpha;
};
#endif