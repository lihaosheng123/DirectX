/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CTalkRobotImage.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* ��b
********************************************************************************/
#ifndef _CTALKROBOTIMAGE_H_
#define _CTALKROBOTIMAGE_H_

#define	TEXTURE_TALKROBOTIMAGE_FILE		"data\\TEXTURE\\talk.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CTalkRobotImage : public CScene
{
public:
	CTalkRobotImage();
	~CTalkRobotImage();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTalkRobotImage* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	bool m_bUse;
};
#endif