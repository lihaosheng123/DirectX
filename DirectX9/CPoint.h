///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CPoint.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Point�`��
//********************************************************************************/
#ifndef	_CPOINT_H_
#define	_CPOINT_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_POINT "data\\MODEL\\PROP\\POINT\\point.x"
class CPoint :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CBuildLight;
	friend class CTrail;
	friend class CColumnar;
public:
	enum POINT_TYPE
	{
		POINT_NORMAL = 0,			// �ʏ�
		POINT_BUILDING_TRUE,
		POINT_BUILDING_FALSE,
		POINT_MAX
	};
public:
	CPoint();
	~CPoint();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CPoint* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	POINT_TYPE m_type;
};
#endif