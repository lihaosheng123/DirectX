/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CExplosion.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/17
* `CExplosion�`��
********************************************************************************/
#ifndef _CEXPLOSION_H_
#define _CEXPLOSION_H_

//�}�N����`
#define	TEXTURE_EXPLOSION "data\\TEXTURE\\explosion.png"

#define	NUM_PATTERN_EXPLOSION			(10)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_EXPLOSION		(10.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_EXPLOSION		(1.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_EXPLOSION		(1.0f / TEXTURE_PATTERN_X_EXPLOSION)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_EXPLOSION		(1.0f / TEXTURE_PATTERN_Y_EXPLOSION)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_EXPLOSION	(2)						// �A�j���[�V�����̐؂�ւ��Ԋu

#define EXPLOSION_MAX (256)
typedef struct
{
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X�B
	int nCount;			// �J�E���^
	int nPattern;		// �p�^�[��No.
	bool m_Buse;

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�
}EXPLOSION;
class CExplosion : public CScene
{
	friend class CPlayer;
	friend class CBall;
	friend class CBullet;
	friend class CFox;
	friend class CDebugProc;
	friend class Cskillbg;
public:
	CExplosion();
	~CExplosion();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CExplosion* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	void SetExplosion(D3DXVECTOR3 pos);
private:

	EXPLOSION m_Explosion[EXPLOSION_MAX];
};

#endif