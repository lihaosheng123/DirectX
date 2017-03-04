/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@Unique_skill.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/17
* `Unique_skill�`��
********************************************************************************/
#ifndef _UNIQUE_SKILL_H_
#define _UNIQUE_SKILL_H_

//�}�N����`
#define	TEXTURE_UNIQUE_SKILL "data\\TEXTURE\\skull.png"

#define	NUM_PATTERN_UNIQUE_SKILL			(9)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_UNIQUE_SKILL		(20.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_UNIQUE_SKILL		(11.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_UNIQUE_SKILL		(1.0f / TEXTURE_PATTERN_X_UNIQUE_SKILL)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_UNIQUE_SKILL		(1.0f / TEXTURE_PATTERN_Y_UNIQUE_SKILL)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_UNIQUE_SKILL	(10)						// �A�j���[�V�����̐؂�ւ��Ԋu

#define UNIQUE_SKILL_MAX (1)
typedef struct
{
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X�B

	bool m_Buse;

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�
}UNIQUE_SKILL;
class CUnique_skill : public CScene
{
	friend class CPlayer;
	friend class CBall;
	friend class CBullet;
	friend class CFox;
	friend class CDebugProc;
	friend class Cskillbg;
public:
	CUnique_skill();
	~CUnique_skill();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CUnique_skill* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	void SetUnique_skill(D3DXVECTOR3 pos);
private:
	int nCount;			// �J�E���^
	int nPattern;		// �p�^�[��No.
	UNIQUE_SKILL m_Unique_skill[UNIQUE_SKILL_MAX];
	bool m_bgUse;
	int m_frame;
	bool m_CheckUse;
	Cskillbg *m_skillbg;
};

#endif