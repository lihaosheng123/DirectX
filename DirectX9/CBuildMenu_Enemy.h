#///********************************************************************************
//* �t�@�C�����@CBuildMenu_Enemy.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*another��enemy
//********************************************************************************/
#ifndef	_CBUILDMENU_ENEMY_H_
#define	_CBUILDMENU_ENEMY_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define MENU_ENEMY_NUM 2//�G�̎��


/*******************************************************************************
�N���X�錾
*******************************************************************************/
class CBuildMenu_Enemy :public CScene
{
	friend class CBuildMenu;
	friend class CEnemy;
	friend class CBuildMap;
	friend class CTrail;
public:


	typedef enum
	{
		BUILD_MENU_ENEMY_00 = 0,
		BUILD_MENU_ENEMY_01,
		BUILD_MENU_ENEMY_02,
		BUILD_MENU_ENEMY_MAX
	}BUILD_MENU�QENEMY;

	CBuildMenu_Enemy();
	~CBuildMenu_Enemy();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildMenu_Enemy* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer_Build_Enemy[MENU_ENEMY_NUM];	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture_Build_Enemy[MENU_ENEMY_NUM];
	bool m_bUse;
	BUILD_MENU�QENEMY m_type;
};
#endif#pragma once
