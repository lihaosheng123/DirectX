/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@number.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/23
* NUMBER����
********************************************************************************/
#ifndef _NUMBER_H_
#define _NUMBER_H_
#define	MAX_DIGIT		(5)

class CNumber
{
friend class CScore;
friend class CTimeScore;
friend class CHpScore;
public:
	CNumber();
	~CNumber();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
private:
	int m_Number [MAX_DIGIT];
};
#endif