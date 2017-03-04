#///********************************************************************************
//* �t�@�C�����@CBuildMenu_Wall.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*�^�C�g����ʂ�menu
//********************************************************************************/
#ifndef	_CBUILDMENU_WALL_H_
#define	_CBUILDMENU_WALL_H_

#define MENU_WALL_NUM 2
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CBuildMenu_Wall :public CScene
{
friend class CBuildMenu;
friend class CWall;
friend class CBuildMap;
public:


	typedef enum
	{
		BUILD_MENU_WALL_00 = 0,
		BUILD_MENU_WALL_01,
		BUILD_MENU_WALL_02,
		BUILD_MENU_WALL_MAX
	}BUILD_MENU�QWALL;

	CBuildMenu_Wall();
	~CBuildMenu_Wall();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildMenu_Wall* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Build_Wall[MENU_WALL_NUM];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Build_Wall[MENU_WALL_NUM];
	bool m_bUse;
	BUILD_MENU�QWALL m_type;
};
#endif