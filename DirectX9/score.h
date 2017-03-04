/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@score.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/21
* SCORE�|���S���`��
********************************************************************************/
#ifndef _SCORE_H_
#define _SCORE_H_
#define	MAX_SCORE		(2)
#define	TEXTURE_SCORE_FILE		"data\\TEXTURE\\score.png"	// �ǂݍ��ރe�N�X�`���t�@�C����


class CScore : public CScene2D
{
friend class CNumber;
friend class CPortal;
public:
	CScore();
	~CScore();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void AddScore(int value);
	static CScore* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�

private:
	int m_nScore;		//�X�R�A�̐�
	float m_width_change;
};
#endif