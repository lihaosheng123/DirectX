/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CTransferEffect.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
* `TransferEffect�`��
********************************************************************************/
#ifndef _TRANSFEREFFECT_H_
#define _TRANSFEREFFECT_H_

//�}�N����`
#define	TEXTURE_TRANSFEREFFECT "data\\TEXTURE\\transferEffect.png"

#define	NUM_PATTERN_TRANSFEREFFECT			(64)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_TRANSFEREFFECT		(8.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_TRANSFEREFFECT		(7.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_TRANSFEREFFECT		(1.0f / TEXTURE_PATTERN_X_TRANSFEREFFECT)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_TRANSFEREFFECT		(1.0f / TEXTURE_PATTERN_Y_TRANSFEREFFECT)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_TRANSFEREFFECT	(7)						// �A�j���[�V�����̐؂�ւ��Ԋu

#define TRANSFEREFFECT_MAX (256)
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
}TRANSFEREFFECT;
class CTransferEffect : public CScene
{
friend class CPlayer;
friend class CBall;
friend class CBullet;
public:
	CTransferEffect();
	~CTransferEffect();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTransferEffect* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
	void SetTransferEffect( D3DXVECTOR3 pos);
private:
	TRANSFEREFFECT m_TransferEffect[TRANSFEREFFECT_MAX];
};

#endif