///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CRobot.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Robot�`��
//********************************************************************************/
#ifndef	_CROBOT_H_
#define	_CROBOT_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MAX_ROBOT (10)
#define MODEL_ROBOT "data\\MODEL\\robot.x"
#define ENEMY_MOVE 2.0f;
#define ROBOT_INERTIA_MOVE (0.025f)		//���������W��
class CRobot :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CBuildLight;
	friend class CTrail;
public:
	enum ROBOT_TYPE
	{
		ROBOT_NORMAL = 0,			// �ʏ�
		ROBOT_BUILDING_FRONT,
		ROBOT_BUILDING_BACK,
		ROBOT_BUILDING_LEFT,
		ROBOT_BUILDING_RIGHT,
		ROBOT_BUILDING_FALSE,
		ROBOT_MAX
	};
public:
	CRobot();
	~CRobot();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CRobot* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	ROBOT_TYPE m_type;
};
#endif
