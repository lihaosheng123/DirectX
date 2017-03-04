///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CWall_002.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*Wall_002�`��
//********************************************************************************/
#ifndef	_CWALL_002_H_
#define	_CWALL_002_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_WALL_002_FILE		"data\\TEXTURE\\wall_002.jpg"	// �ǂݍ��ރe�N�X�`���t�@�C����
class CWall_002 :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu_Wall_002;
	friend class CBuildMenu;
	//*************************************
	// �Ǐ�Ԃ̎��
	//*************************************
public:
	enum WALL_002_TYPE
	{
		WALL_002_NORMAL = 0,			// �ʏ�
		WALL_002_BUILDING_FRONT,
		WALL_002_BUILDING_BACK,
		WALL_002_BUILDING_LEFT,
		WALL_002_BUILDING_RIGHT,
		WALL_002_BUILDING_FALSE,
		WALL_002_MAX
	};
public:
	CWall_002();
	~CWall_002();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CWall_002* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);

private:

	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	WALL_002_TYPE m_type;
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	bool m_use;

};
#endif