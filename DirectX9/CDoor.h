///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CDoor.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Enemy_001�`��
//********************************************************************************/
#ifndef	_CDOOR_H_
#define	_CDOOR_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_DOOR "data\\MODEL\\PROP\\DOOR\\door.x"
class CDoor :public CScene
{
	friend class CBuildMap;
public:
	enum DOOR_TYPE
	{
		DOOR_NORMAL = 0,			// �ʏ�
		DOOR_BUILDING_FRONT,
		DOOR_BUILDING_BACK,
		DOOR_BUILDING_LEFT,
		DOOR_BUILDING_RIGHT,
		DOOR_BUILDING_FALSE,
		DOOR_MAX
	};
public:
	CDoor();
	~CDoor();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CDoor* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	DOOR_TYPE m_type;
};
#endif