///********************************************************************************
//* �t�@�C�����@CBuildMenu.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*Build��ʂ�menu
//********************************************************************************/
#ifndef	_CBUILDMENU_H_
#define	_CBUILDMENU_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define MENU_NUM 8		//menu��

/*******************************************************************************
�N���X�錾
*******************************************************************************/
class CBuildMenu :public CScene
{
	//�t�����h�N���X
	friend class CBuildMap;
	friend class CBuildMenu_Wall;
	friend class CBuildMenu_Enemy;
	friend class CBuildMenu_Prop;
	friend class CBuildMenu_Another;
public:
	//Menu�̎��
	typedef enum
	{
		BUILD_MENU_WALL = 0,//��
		BUILD_MENU_ENEMY,//�G
		BUILD_MENU_LIGHT,//���C�g
		BUILD_MENU_CEILING,//�V���
		BUILD_MENU_PROP,//����
		BUILD_MENU_ANOTHER,//��
		BUILD_MENU_GAMESTART,	//�Q�[���J�n(��ʑJ��)
		BUILD_MENU_BACKTITLE,	//�^�C�g����ʑJ��
		BUILD_MENU_MAX
	}BUILD_MENU;

	// �R���X�g���N�^�E�f�X�g���N�^
	CBuildMenu();
	~CBuildMenu();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildMenu* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Build[MENU_NUM];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Build[MENU_NUM];//�e�N�X�`���̃|�C���^
	BUILD_MENU m_type;	//���
};
#endif