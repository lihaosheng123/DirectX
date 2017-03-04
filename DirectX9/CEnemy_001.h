///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CEnemy_001.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Enemy_001�`��
//********************************************************************************/
#ifndef	_CENEMY_001_H_
#define	_CENEMY_001_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MAX_ENEMY_001 (10)
#define MODEL_ENEMY_001 "data\\MODEL\\ENEMY\\enemy_001.x"
#define ENEMY_MOVE 2.0f;
#define ENEMY_001_INERTIA_MOVE (0.025f)		//���������W��
class CEnemy_001:public CScene
{
friend class CBuildMenu;
friend class CBuildMap;
friend class CBuildLight;
friend class CTrail;
public:
enum ENEMY_001_TYPE
{
	ENEMY_001_NORMAL = 0,			// �ʏ�
	ENEMY_001_BUILDING_FRONT,
	ENEMY_001_BUILDING_BACK,
	ENEMY_001_BUILDING_LEFT,
	ENEMY_001_BUILDING_RIGHT,
	ENEMY_001_BUILDING_FALSE,
	ENEMY_001_MAX
};
public:
	CEnemy_001();
	~CEnemy_001();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CEnemy_001* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	ENEMY_001_TYPE m_type;
};
#endif