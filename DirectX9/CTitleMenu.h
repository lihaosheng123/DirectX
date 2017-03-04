///********************************************************************************
//* �t�@�C�����@CTitleMenu.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*�^�C�g����ʂ�menu
//********************************************************************************/
#ifndef	_CTITLEMENU_H_
#define	_CTITLEMENU_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CTitleMenu :public CScene
{
	friend class CTitleMark;
	friend class CTitle;
public:
	CTitleMenu();
	~CTitleMenu();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleMenu* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Title[3];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Title[3];
	int alpha;
	bool m_bUse;
};
#endif