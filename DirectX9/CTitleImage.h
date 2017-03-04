/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CTitleImage.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* TITLE�̉�ʕ`��
********************************************************************************/
#ifndef _CTITLEIMAGE_H_
#define _CTITLEIMAGE_H_

#define	TEXTURE_TITLEIMAGE_FILE		"data\\TEXTURE\\TitleImage.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CTitleImage : public CScene
{
public:
	CTitleImage();
	~CTitleImage();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleImage* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

};
#endif