/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CResultbg.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* RESULT�̉�ʕ`��
********************************************************************************/
#ifndef _CRESULTBG_H_
#define _CRESULTBG_H_

#define	TEXTURE_RESULTBG_FILE		"data\\TEXTURE\\result.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CResultbg : public CScene
{
public:
	CResultbg();
	~CResultbg();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CResultbg* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�

};
#endif