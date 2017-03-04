///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTextbubble.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*Textbubble�`��
//********************************************************************************/
#ifndef	_CTEXTBUBBLE_H_
#define	_CTEXTBUBBLE_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_TEXTBUBBLE_FILE		"data\\TEXTURE\\textbubble.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
class CTextbubble :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu;

public:
	CTextbubble();
	~CTextbubble();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTextbubble* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);

private:

	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	bool m_use;
};
#endif