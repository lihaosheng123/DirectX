/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CHpScore.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2017/02/13
* ���C�tCHPSCORE�|���S���`��
********************************************************************************/
#ifndef _CHPSCORE_H_
#define _CHPSCORE_H_
#define	MAX_HPSCORE		(2)
#define	TEXTURE_HPSCORE_FILE		"data\\TEXTURE\\score.png"	// �ǂݍ��ރe�N�X�`���t�@�C����


class CHpScore :public CScene
{
	friend class CNumber;
	friend class CPortal;
	friend class CPlayer;
public:
	CHpScore();
	~CHpScore();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void AddScore(int value);
	static CHpScore* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	int m_nScore;		//�X�R�A�̐�
	float m_width_change;
};
#endif