///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@bullet.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*bullet�`��
//********************************************************************************/
#ifndef	_BULLETHOLES_H_
#define	_BULLETHOLES_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define	TEXTURE_BULLETHOLES_FILE		"data\\TEXTURE\\bulletholes.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define BULLETHOLES_MAX (256)

#define	NUM_PATTERN_BULLETHOLES			(1)						// �A�j���[�V�����̃p�^�[����

#define	TEXTURE_PATTERN_X_BULLETHOLES		(1.0f)	// �e�N�X�`�����̂P�p�^�[����x
#define	TEXTURE_PATTERN_Y_BULLETHOLES		(1.0f)					// �e�N�X�`�����̂P�p�^�[����y

#define	TEXTURE_SIZE_X_BULLETHOLES		(1.0f / TEXTURE_PATTERN_X_BULLETHOLES)	// �e�N�X�`�����̂P�p�^�[���̕�
#define	TEXTURE_SIZE_Y_BULLETHOLES		(1.0f / TEXTURE_PATTERN_Y_BULLETHOLES)					// �e�N�X�`�����̂P�p�^�[���̍���

#define	INTERVAL_PATTERN_BULLETHOLES	(5)						// �A�j���[�V�����̐؂�ւ��Ԋu
typedef struct
{
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	D3DXVECTOR3 m_OldPosition;
	bool m_bUse;
	int m_Life;
	bool m_OneCheck;

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�
	int nCount;			// �J�E���^
	int nPattern;		// �p�^�[��No.

}BULLETHOLES;
class CBulletHoles :public CScene
{
friend class CPlayer;
friend class CDebugProc;
friend class CExplosion;
public:
	CBulletHoles();
	~CBulletHoles();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBulletHoles* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);
	float Length( D3DXVECTOR3 *Vector );
	void Normalize( D3DXVECTOR3 *Vector, D3DXVECTOR3 *Vector1 );
	void SetBulletHoles( D3DXVECTOR3 pos,D3DXVECTOR3 rot);

private:
	BULLETHOLES m_BulletHoles[BULLETHOLES_MAX];


};
#endif