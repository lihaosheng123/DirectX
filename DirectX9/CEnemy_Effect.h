///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CEnemy_Effect.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/20
//*�G��effect�`��
//********************************************************************************/
#ifndef	_CENEMY_EFFECT_H_
#define	_CENEMY_EFFECT_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define	NUM_PATTERN_EFFECT_ENEMY			(8)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_EFFECT_ENEMY		(8.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_EFFECT_ENEMY		(1.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_EFFECT_ENEMY		(1.0f / TEXTURE_PATTERN_X_EFFECT_ENEMY)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_EFFECT_ENEMY		(1.0f / TEXTURE_PATTERN_Y_EFFECT_ENEMY)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_EFFECT_ENEMY	(4)						// �A�j���[�V�����̐؂�ւ��Ԋu
#define	TEXTURE_ENEMY_EFFECT_FILE		"data\\TEXTURE\\enemy_effect.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define ENEMY_EFFECT_MAX (100)
#include "scene.h"
typedef struct
{
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	bool m_bUse;
	int m_Life;

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	int nCount;			// �J�E���^
	int nPattern;		// �p�^�[��No.
	CMatrix m_Matrix;
}ENEMY_EFFECT;
class CEnemy_Effect :public CScene
{
	friend class CPlayer;
	friend class CDebugProc;
	friend class CExplosion;
	friend class CGameEnemy_001;
public:
	CEnemy_Effect();
	~CEnemy_Effect();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CEnemy_Effect* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
	void SetEffect(D3DXVECTOR3 pos);
	ENEMY_EFFECT* GetEnemy_Effect(void);
private:
	ENEMY_EFFECT m_Enemy_Effect[ENEMY_EFFECT_MAX];
	int cnt;
};
#endif