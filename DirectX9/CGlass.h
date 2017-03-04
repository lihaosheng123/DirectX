/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CGlass.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/11/17
* `CGlass�`��
********************************************************************************/
#ifndef _CGLASS_H_
#define _CGLASS_H_

//�}�N����`
#define	TEXTURE_GLASS "data\\TEXTURE\\glass.png"

#define	NUM_PATTERN_GLASS			(8)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_GLASS		(8.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_GLASS		(1.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_GLASS		(1.0f / TEXTURE_PATTERN_X_GLASS)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_GLASS		(1.0f / TEXTURE_PATTERN_Y_GLASS)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_GLASS	(2)						// �A�j���[�V�����̐؂�ւ��Ԋu

#define GLASS_MAX (256)
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
}GLASS;
class CGlass : public CScene
{
	friend class CPlayer;
	friend class CBall;
	friend class CBullet;
	friend class CFox;
	friend class CDebugProc;
	friend class Cskillbg;
public:
	CGlass();
	~CGlass();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CGlass* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	void SetGlass(D3DXVECTOR3 pos);
private:

	GLASS m_Glass[GLASS_MAX];
};

#endif