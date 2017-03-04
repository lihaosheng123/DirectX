///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameRobot.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GameRobot�`��
//********************************************************************************/
#ifndef	_CGAMEROBOT_H_
#define	_CGAMEROBOT_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_GAMEROBOT "data\\MODEL\\robot.x"

class CGameRobot :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CBuildLight;
	friend class CTrail;
	friend class CTextbubble;
public:
	CGameRobot();
	~CGameRobot();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CGameRobot* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	float  Length(D3DXVECTOR3 *Vector);
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	bool m_bUse;
};
#endif
