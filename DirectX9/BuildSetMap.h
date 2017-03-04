/********************************************************************************
* �^�C�g���@BuildSetMap.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/27
* �Q�[���̃}�b�v�̕`��Ǘ�
********************************************************************************/


#ifndef _BUILDSETMAP_H_
#define _BUILDSETMAP_H_

/*******************************************************************************
�C���N���[�h�錾
*******************************************************************************/


/*******************************************************************************
�}�N����`
*******************************************************************************/


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
/*******************************************************************************
�N���X�錾
*******************************************************************************/
class BuildSetMap
{
	//�t�����h�N���X
	friend class CDebugProc;
	friend class CBullet;
	friend class CGameWall_001;
	friend class CGameWall_002;
	friend class CGameEnemy_001;
	friend class CGameEnemy_002;
	friend class CEnemy_Bullet;
	friend class CGameCeiling;
public:

	// �R���X�g���N�^�E�f�X�g���N�^
	BuildSetMap();
	~BuildSetMap();

	void Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
private:
};
#endif