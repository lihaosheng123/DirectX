///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CEnemy_Bullet_Left.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/20
//*�G��bullet�`��
//********************************************************************************/
#ifndef	_CENEMY_BULLET_LEFT_H_
#define	_CENEMY_BULLET_LEFT_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define	TEXTURE_ENEMY_BULLET_LEFT_FILE		"data\\TEXTURE\\bullet.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define ENEMY_BULLET_LEFT_MAX (256)
#define ENEMY_BULLET_LEFT_SPEED (10.0f);
#include "scene.h"
typedef struct
{
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	bool m_bUse;
	int m_Life;
	bool m_OneCheck;

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	CMatrix m_Matrix;
	D3DXVECTOR3 m_Vektor;
}ENEMY_BULLET_LEFT;
class CEnemy_Bullet_Left :public CScene
{
	friend class CPlayer;
	friend class CDebugProc;
	friend class CExplosion;
	friend class CGameEnemy_001;
public:
	CEnemy_Bullet_Left();
	~CEnemy_Bullet_Left();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CEnemy_Bullet_Left* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
	float Length(D3DXVECTOR3 *Vector);
	void SetBullet_Left(D3DXVECTOR3 pos);
	ENEMY_BULLET_LEFT* GetEnemy_Bullet_Left(void);
private:
	ENEMY_BULLET_LEFT m_Enemy_Bullet_Left[ENEMY_BULLET_LEFT_MAX];
	int m_Num;
	int frame;
	int cnt;
};
#endif