/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CTimeScore.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/21
* SCORE�|���S���`��-----------------------------------------------------------------------------------------------------------------------------------------------------
********************************************************************************/
#ifndef _CTIMESCORE_H_
#define _CTIMESCORE_H_
#define	MAX_TIMESCORE		(2)
#define	TEXTURE_TIMESCORE_FILE		"data\\TEXTURE\\timescore.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CTimeScore : public CScene2D
{
friend class CTime;

friend class CNumber;
public:
	CTimeScore();
	~CTimeScore();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void AddScore(int value);
	static CTimeScore* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
private:
	int m_nScore;		//�X�R�A�̐�
	float m_width_change;
	int nTimebg [2];
};
#endif