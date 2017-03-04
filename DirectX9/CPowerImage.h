/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CPowerImage.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* Power�̉�ʕ`��
********************************************************************************/
#ifndef _CPOWERIMAGE_H_
#define _CPOWERIMAGE_H_

#define	TEXTURE_POWERIMAGE_FILE		"data\\TEXTURE\\PowerImage.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CPowerImage : public CScene
{
	friend class CEnemy_Bullet_Down;
	friend class CEnemy_Bullet_Up;
	friend class CEnemy_Bullet_Left;
	friend class CEnemy_Bullet_Right;
public:
	CPowerImage();
	~CPowerImage();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CPowerImage* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
};
#endif