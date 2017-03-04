///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitleRobot.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* TitleRobot�`��
//********************************************************************************/
#ifndef	_CTITLEROBOT_H_
#define	_CTITLEROBOT_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_TITLE_MODEL "data\\MODEL\\ENEMY\\enemy_001.x"
#define ENEMY_MOVE 2.0f;
#define ENEMY_001_INERTIA_MOVE (0.025f)		//���������W��
class CTitleRobot :public CScene
{

public:
	CTitleRobot();
	~CTitleRobot();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleRobot* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	bool m_bMove;
	bool m_flag;
	int m_wait;
	bool m_rot;
	bool m_Backrot;
	int m_Time;
	bool m_newMove;
};
#endif