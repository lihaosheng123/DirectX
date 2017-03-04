#///********************************************************************************
//* �t�@�C�����@CBuildMenu_Another.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*another��menu
//********************************************************************************/
#ifndef	_CBUILDMENU_ANOTHER_H_
#define	_CBUILDMENU_ANOTHER_H_

#define MENU_ANOTHER_NUM 3		//another��menu��
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

/*******************************************************************************
�N���X�錾
*******************************************************************************/
class CBuildMenu_Another :public CScene
{
	//�t�����h�N���X
	friend class CBuildMenu;
	friend class CAnother;
	friend class CBuildMap;
public:
	typedef enum
	{
		BUILD_MENU_ANOTHER_00 = 0,
		BUILD_MENU_ANOTHER_START,
		BUILD_MENU_ANOTHER_END,
		BUILD_MENU_ANOTHER_PRESENT,
		BUILD_MENU_ANOTHER_MAX
	}BUILD_MENU�QANOTHER;

	CBuildMenu_Another();
	~CBuildMenu_Another();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildMenu_Another* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Build_Another[MENU_ANOTHER_NUM];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Build_Another[MENU_ANOTHER_NUM];//�e�N�X�`���̃|�C���^
	bool m_bUse;
	BUILD_MENU�QANOTHER m_type;
};
#endif
