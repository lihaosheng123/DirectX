/********************************************************************************
* �^�C�g���@CBuildLoadMap.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�̐��l�ǂݍ��݂̊Ǘ�
********************************************************************************/
#ifndef _CBUILDLOADMAP_H_
#define _CBUILDLOADMAP_H_
/*******************************************************************************
�}�N����`
*******************************************************************************/
#define MAX_BUFFER		(4000)				// �o�b�t�@�̑���
#define MAX_WALL		(300)			//�ǂ̐ݒ�ő�l(����𒴂���ƁAbug���o��)
#define MAX_ENEMY		(50)			//�G�̐ݒ�ő�l(����𒴂���ƁAbug���o��)
//�O���錾
class CGameEnemy_001;
class CGameEnemy_002;
class CGameEnemy_001_data;
class CGameEnemy_002_data;
class CGameWall_001;
class CGameWall_002;
class CGameWall_001_data;
class CGameWall_002_data;
class CGameCeiling_data;
class CGameCeiling;
class CGameDoor_data;
class CGameDoor;
class CGamePoint;
class CStart;
class CEnd;
class CRobot;
/*******************************************************************************
�N���X�錾
*******************************************************************************/
class CBuildLoadMap
{
	//�t�����h�N���X
	friend class CDebugProc;
	friend class CBullet;
	friend class CGameWall_001;
	friend class CGameWall_002;
	friend class CGameEnemy_001;
	friend class CGameEnemy_002;
	friend class CGameDoor;
	friend class CEnemy_Bullet;
	friend class CGameCeiling;
	friend class CGamePoint;
	friend class BuildSetMap;
	friend class CDoor_Effect;
	friend class CStart;
	friend class CEnd;
	friend class CRobot;
public:
	// �R���X�g���N�^�E�f�X�g���N�^
	CBuildLoadMap();
	~CBuildLoadMap();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����

public:
	int i;
	FILE *pFile;						// �t�@�C���|�C���^
	char aStr[MAX_BUFFER];		// �t�@�C���̍s�f�[�^
	char aData[MAX_BUFFER];		// �i�[����z��

	//�ʒu�ƌ����̔z��
	int fPosX[MAX_WALL];
	int fPosY[MAX_WALL];
	int fPosZ[MAX_WALL];
	float fRotX[MAX_WALL];
	float fRotY[MAX_WALL];
	float fRotZ[MAX_WALL];
	//�G�̋O�Քz��
	D3DXVECTOR3 fPos_To[MAX_ENEMY];
	//�Ǎ�
	//�e�X�g�p�ǂݍ���
	void LoadTest(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//��001�̓ǂݍ���
	void LoadWall_001(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//��002�̓ǂݍ���
	void LoadWall_002(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�G001�̓ǂݍ���
	void LoadEnemy_001(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�G002�̓ǂݍ���
	void LoadEnemy_002(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�V��̓ǂݍ���
	void LoadCeiling(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�h�A���f���̓ǂݍ���
	void LoadDoor(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�������f���̓ǂݍ���
	void LoadPoint(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�v���C���[�ŏ��ʒu�̓ǂݍ���
	void LoadStart(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//�Q�[���I���ʒu�̓ǂݍ���
	void LoadEnd(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//���[�����������̃��f���̓ǂݍ���
	void LoadRobot(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	HINSTANCE hInstance;
	HWND hWnd;
	//�e�X�g�p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Test[MAX_WALL];
	D3DXVECTOR3 m_Rot_Test[MAX_WALL];

	//��001�p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Wall_001[MAX_WALL];
	D3DXVECTOR3 m_Rot_Wall_001[MAX_WALL];

	//��002�p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Wall_002[MAX_WALL];
	D3DXVECTOR3 m_Rot_Wall_002[MAX_WALL];

	//�G001�p���W�ʒu�A�����ƋO�Ղ̔z��
	D3DXVECTOR3 m_Pos_Enemy_001[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Enemy_001[MAX_ENEMY];
	D3DXVECTOR3 m_Pos_To_Enemy_001[MAX_ENEMY];

	//�G002�p���W�ʒu�A�����ƋO�Ղ̔z��
	D3DXVECTOR3 m_Pos_Enemy_002[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Enemy_002[MAX_ENEMY];
	D3DXVECTOR3 m_Pos_To_Enemy_002[MAX_ENEMY];

	//�V��p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Ceiling[MAX_WALL];

	//�h�A���f���p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Door[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Door[MAX_ENEMY];

	//�������f���p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Point[MAX_ENEMY];

	//���[�����������̃��f���p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Robot[1];
	D3DXVECTOR3 m_Rot_Robot[1];

	//�v���C���[�ŏ��ʒu�p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_Start[1];

	//�Q�[���I���p���W�ʒu�ƌ����̔z��
	D3DXVECTOR3 m_Pos_End[1];

	//�ǂݍ��݂̕�001��
	int m_Wall001_num;
	//�ǂݍ��݂̕�002��
	int m_Wall002_num;
	//�ǂݍ��݂̓G001��
	int m_Enemy001_num;
	//�ǂݍ��݂̓G002��
	int m_Enemy002_num;
	//�ǂݍ��݂̓V���
	int m_Ceiling_num;
	//�ǂݍ��݂̃h�A���f����
	int m_Door_num;
	//�ǂݍ��݂̏������f����
	int m_Point_num;
};
#endif