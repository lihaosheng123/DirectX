//********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTrail.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/12
//*Trail�`��
//********************************************************************************/
#ifndef	_CTRAIL_H_
#define	_CTRAIL_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_TRAIL_FILE		"data\\TEXTURE\\trail.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CTrail :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu_Trail;
	friend class CBuildMenu;
public:
	enum TRAIL_TYPE
	{
		TRAIL_NORMAL = 0,			// �ʏ�
		TRAIL_BUILDING_FRONT,
		TRAIL_BUILDING_BACK,
		TRAIL_BUILDING_LEFT,
		TRAIL_BUILDING_RIGHT,
		TRAIL_BUILDING_FALSE,
		TRAIL_MAX
	};
public:
	CTrail();
	~CTrail();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTrail* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
private:
	int m_Changge;
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATRIX mtxView;		// �J�����Őݒ肵���r���[�}�g���b�N�X���󂯎�邽�߂̕ϐ�
	D3DXVECTOR3 m_NumCheck;
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	int Check;
	TRAIL_TYPE m_type;
};
#endif