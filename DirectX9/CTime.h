//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
// CTime.h
//* Fox�`��
//********************************************************************************/
#ifndef	_CTIME_H_
#define	_CTIME_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`

class CTime
{
friend class CTimeScore;
public:
	CTime();
	~CTime();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
private:
	int m_time;
	int m_frame;
};
#endif
