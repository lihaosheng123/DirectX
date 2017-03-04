///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CCeiling.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*Ceiling�`��
//********************************************************************************/
#ifndef	_CCEILING_H_
#define	_CCEILING_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_CEILING_FILE		"data\\TEXTURE\\ceiling.jpg"	// �ǂݍ��ރe�N�X�`���t�@�C����
class CCeiling :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu_Ceiling;
	friend class CBuildMenu;
public:
	enum CEILING_TYPE
	{
		CEILING_NORMAL = 0,			// �ʏ�
		CEILING_BUILDING_TRUE,
		CEILING_BUILDING_FALSE,
		CEILING_MAX
	};
public:
	CCeiling();
	~CCeiling();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CCeiling* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);

private:

	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	bool m_use;
	CEILING_TYPE m_type;

};
#endif