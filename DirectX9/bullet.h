///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@bullet.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*bullet�`��
//********************************************************************************/
#ifndef	_BULLET_H_
#define	_BULLET_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define	TEXTURE_BULLET_FILE		"data\\TEXTURE\\bullet.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define BULLET_MAX (256)
#define BULLET_SPEED (40.0f);
typedef struct
{
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	//D3DXVECTOR3 m_OldPosition;
	bool m_bUse;
	int m_Life;
	bool m_OneCheck;

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�
	D3DXVECTOR3 m_Vektor;
}BULLET;
class CBullet :public CScene
{
friend class CPlayer;
friend class CDebugProc;
friend class CExplosion;

public:
	CBullet();
	~CBullet();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBullet* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);
	float Length( D3DXVECTOR3 *Vector );
	void Normalize( D3DXVECTOR3 *Vector, D3DXVECTOR3 *Vector1 );
	void SetBullet( D3DXVECTOR3 pos);
	BULLET* GetBullet(void);
private:
	BULLET m_Bullet[BULLET_MAX];
	int m_Num;
	int frame;

};
#endif