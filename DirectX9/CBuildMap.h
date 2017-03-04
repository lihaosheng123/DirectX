/********************************************************************************
* �^�C�g���@CBuildMap.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�Ǘ��A�ǂݍ��݁A�t�@�C���쐬
********************************************************************************/


#ifndef _CBUILDMAP_H_
#define _CBUILDMAP_H_

/*******************************************************************************
�C���N���[�h�錾
*******************************************************************************/
#include <stdio.h>
#include "CLoadMap.h"
/*******************************************************************************
�}�N����`
*******************************************************************************/

//�O���錾
class CWall_001;
class CWall_002;
class CEnemy_001;
class CEnemy_002;
class CBuildLight;
class CTrail;
class CCeiling;
class CDoor;
class CPoint;
class CColumnar;
class CStart;
class CEnd;
class CRobot;
/*******************************************************************************
�N���X�錾
*******************************************************************************/
class CBuildMap
{
	//�t�����h�N���X
	friend class CDebugProc;
	friend class CBullet;
	friend class CTitle;
public:
	// �R���X�g���N�^�E�f�X�g���N�^
	CBuildMap();
	~CBuildMap();


	// �֐�
	void Init(void);
	void Uninit(void);
	void Update(HINSTANCE hInstance, HWND hWnd);
	void Draw(void);
private:
	//�`��̎��\���p
	CWall_001 *p_Wall_001[1];
	CWall_002 *p_Wall_002[1];
	CEnemy_001 *p_Enemy_001[1];
	CEnemy_002 *p_Enemy_002[1];

	CBuildLight *p_Light[1];
	CTrail *p_Trail[1];

	CCeiling *p_Ceiling[1];
	CDoor *p_Door[1];
	CPoint *p_Point[1];
	CColumnar *p_Columnar[1];
	CStart *p_Start[1];
	CEnd *p_End[1];
	CRobot *p_Robot[1];

	//�f�[�^�̓ǂݍ��ݗp(�ʒu)
	int PosX;
	int PosY;
	int PosZ;
	//�f�[�^�̓ǂݍ��ݗp(�O��)
	int m_Trail_PosX;
	int m_Trail_PosY;
	int m_Trail_PosZ;
	//�f�[�^�̓ǂݍ��ݗp(����)
	float RotX;
	float RotY;
	float RotZ;

	//for���p
	int i;
	int cnt;

	//�t�@�C���|�C���^
	FILE *pFile;
	//�t�@�C���̍s�f�[�^
	char aStr[MAX_BUFFER];
	//�i�[����z��
	char aData[MAX_BUFFER];	

};
#endif