///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CWall_001.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*Wall_001�`��
//********************************************************************************/
#ifndef	_CWALL_001_H_
#define	_CWALL_001_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_WALL_001_FILE		"data\\TEXTURE\\wall_001.jpg"	// �ǂݍ��ރe�N�X�`���t�@�C����
class CWall_001 :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu_Wall_001;
	friend class CBuildMenu;
	//*************************************
	// �Ǐ�Ԃ̎��
	//*************************************
public:
	enum WALL_001_TYPE
	{
		WALL_001_NORMAL = 0,			// �ʏ�
		WALL_001_BUILDING_FRONT,
		WALL_001_BUILDING_BACK,
		WALL_001_BUILDING_LEFT,
		WALL_001_BUILDING_RIGHT,
		WALL_001_BUILDING_FALSE,
		WALL_001_MAX
	};
public:
	CWall_001();
	~CWall_001();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CWall_001* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);

private:

	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	WALL_001_TYPE m_type;
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	bool m_use;
};
#endif