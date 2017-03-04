/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CColumnar.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/14
* skydome�`��
********************************************************************************/
#ifndef	_CCOLUMNAR_H_
#define	_CCOLUMNAR_H_

class CColumnar :public CScene
{
	friend class CBuildMap;
	friend class CGamePoint;
	friend class CBullet;
	friend class CDebugProc;
public:
	CColumnar();
	~CColumnar();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CColumnar* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	bool m_bUse;
	int m_Life;
	CMatrix m_Matrix;
	bool m_bMove;
	int Point_num;
};

#endif
