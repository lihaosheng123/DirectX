/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@sceneNumber.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/15
* Number�`��
********************************************************************************/
#ifndef _SCENENUMBER_H_
#define _SCENENUMBER_H_
#define	TEXTURE_NUM_FILE		"data\\TEXTURE\\test.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CNumber : public CScene
{
public:
	CNumber();
	~CNumber();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CNumber* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
	CNumber* SetPotion(D3DXVECTOR3 pos,D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);
protected:

};
#endif