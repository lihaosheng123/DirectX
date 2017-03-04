///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CStart.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Start�`��
//********************************************************************************/
#ifndef	_CSTART_H_
#define	_CSTART_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MAX_START (10)
#define MODEL_START "data\\MODEL\\PROP\\start.x"

class CStart :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CBuildLight;
	friend class CTrail;
public:
	enum START_TYPE
	{
		START_NORMAL = 0,			// �ʏ�
		START_BUILDING_TRUE,
		START_BUILDING_FALSE,
		START_MAX
	};
public:
	CStart();
	~CStart();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CStart* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	START_TYPE m_type;
};
#endif