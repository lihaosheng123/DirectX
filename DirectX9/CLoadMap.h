/********************************************************************************
* �^�C�g���@CLoadMap.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�Ǘ�
********************************************************************************/


#ifndef _CLOADMAP_H_
#define _CLOADMAP_H_

/*******************************************************************************
�C���N���[�h�錾
*******************************************************************************/
#include <stdio.h>

/*******************************************************************************
�}�N����`
*******************************************************************************/

#define MAX_BUFFER		(4000)				// �o�b�t�@�̑���
#define MAX_WALL		(300)
#define MAX_ENEMY		(50)
/*******************************************************************************
�N���X�錾
*******************************************************************************/
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
class CGameRobot;
class CLoadMap
{
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
	friend class SetMap;
	friend class CDoor_Effect;
	friend class CColumnar;
	friend class CGame;
	friend class CPlayer;
	friend class CModel;
	friend class CGameRobot;
public:

	// �R���X�g���N�^�E�f�X�g���N�^
	CLoadMap();
	~CLoadMap();
	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����

private:

	int PosX;	
	int PosY;
	int PosZ;
	float RotX;
	float RotY;
	float RotZ;
	int i;
	int cnt;
	int m_type;
	FILE *pFile;						// �t�@�C���|�C���^
	char aStr[MAX_BUFFER];		// �t�@�C���̍s�f�[�^
	char aData[MAX_BUFFER];		// �i�[����z��


	int fPosX[MAX_WALL];
	int fPosY[MAX_WALL];
	int fPosZ[MAX_WALL];

	float fRotX[MAX_WALL];
	float fRotY[MAX_WALL];
	float fRotZ[MAX_WALL];

	D3DXVECTOR3 fPos_To[MAX_ENEMY];

	UINT uMsg;
	int nID;
	//�Ǎ�
	void LoadWall_001(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadWall_002(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadEnemy_001(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadEnemy_002(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadCeiling(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadDoor(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadPoint(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadStart(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadEnd(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadTest(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	void LoadRobot(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	//void LoadLight(const char *fileName, HINSTANCE hInstance, HWND hWnd);
	HINSTANCE hInstance;
	HWND hWnd;
	D3DXVECTOR3 m_Pos_Test[MAX_WALL];
	D3DXVECTOR3 m_Rot_Test[MAX_WALL];

	D3DXVECTOR3 m_Pos_Wall_001[MAX_WALL];
	D3DXVECTOR3 m_Rot_Wall_001[MAX_WALL];

	D3DXVECTOR3 m_Pos_Wall_002[MAX_WALL];
	D3DXVECTOR3 m_Rot_Wall_002[MAX_WALL];
	//
	D3DXVECTOR3 m_Pos_Enemy_001[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Enemy_001[MAX_ENEMY];
	D3DXVECTOR3 m_Pos_To_Enemy_001[MAX_ENEMY];

	D3DXVECTOR3 m_Pos_Enemy_002[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Enemy_002[MAX_ENEMY];
	D3DXVECTOR3 m_Pos_To_Enemy_002[MAX_ENEMY];

	D3DXVECTOR3 m_Pos_Ceiling[MAX_WALL];

	D3DXVECTOR3 m_Pos_Door[MAX_ENEMY];
	D3DXVECTOR3 m_Rot_Door[MAX_ENEMY];

	D3DXVECTOR3 m_Pos_Point[MAX_ENEMY];

	D3DXVECTOR3 m_Pos_Start[1];

	D3DXVECTOR3 m_Pos_End[1];


	D3DXVECTOR3 m_Pos_GameRobot[1];
	D3DXVECTOR3 m_Rot_GameRobot[1];

	int m_Wall001_num;
	int m_Wall002_num;
	int m_Enemy001_num;
	int m_Enemy002_num;
	int m_Ceiling_num;
	int m_Door_num;
	int m_Point_num;
	int now_Point;
	int m_Test_num;
};
#endif