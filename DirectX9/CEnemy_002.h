///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CEnemy_002.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Enemy_002�`��
//********************************************************************************/
#ifndef	_CENEMY_002_H_
#define	_CENEMY_002_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MAX_ENEMY_002 (10)
#define MODEL_ENEMY_002 "data\\MODEL\\ENEMY\\enemy_002.x"
#define ENEMY_MOVE 2.0f;
#define ENEMY_002_INERTIA_MOVE (0.025f)		//���������W��
class CEnemy_002 :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CTrail;
public:
	enum ENEMY_002_TYPE
	{
		ENEMY_002_NORMAL = 0,			// �ʏ�
		ENEMY_002_BUILDING_FRONT,
		ENEMY_002_BUILDING_BACK,
		ENEMY_002_BUILDING_LEFT,
		ENEMY_002_BUILDING_RIGHT,
		ENEMY_002_BUILDING_FALSE,
		ENEMY_002_MAX
	};
public:
	CEnemy_002();
	~CEnemy_002();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CEnemy_002* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	ENEMY_002_TYPE m_type;
};
#endif