/********************************************************************************
* �^�C�g���@RESULT
* �t�@�C�����@CResult.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
*
********************************************************************************/
#ifndef _CRESULT_H_
#define _CRESULT_H_

//�O���錾
class CResultbg;
class CRenderer;
class CResult : public CMode
{

public:
	CResult();
	~CResult();
	virtual void Init(void);		// ����������
	virtual void Uninit(void);		// �I������
	virtual void Draw(void);		//�`�揈��
	virtual void Update(void);		//�X�V����

private:
	CResultbg *m_Resultbg;
	CRenderer *m_Renderer;
};

#endif