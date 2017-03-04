#///********************************************************************************
//* �t�@�C�����@CBuildMenu_Prop.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*prop
//********************************************************************************/
#ifndef	_CBUILDMENU_PROP_H_
#define	_CBUILDMENU_PROP_H_

#define MENU_PROP_NUM 2
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CBuildMenu_Prop :public CScene
{
	friend class CBuildMenu;
	friend class CProp;
	friend class CBuildMap;
public:


	typedef enum
	{
		BUILD_MENU_PROP_00 = 0,
		BUILD_MENU_PROP_DOOR,
		BUILD_MENU_PROP_POINT,
		BUILD_MENU_PROP_MAX
	}BUILD_MENU�QPROP;

	CBuildMenu_Prop();
	~CBuildMenu_Prop();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildMenu_Prop* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Build_Prop[MENU_PROP_NUM];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Build_Prop[MENU_PROP_NUM];
	bool m_bUse;
	BUILD_MENU�QPROP m_type;
};
#endif
