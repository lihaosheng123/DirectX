/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@Cskillbg.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
* TITLE�̉�ʕ`��
********************************************************************************/
#ifndef _CSKILLBG_H_
#define _CSKILLBG_H_



class Cskillbg : public CScene
{
	friend class CUnique_skill;
	friend class CPlayer;
public:
	Cskillbg();
	~Cskillbg();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static Cskillbg* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:

};
#endif