///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitle_R_Model.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/02/10
//* R_Model�`��
//********************************************************************************/
#ifndef	_CTITLE_R_MODEL_H_
#define	_CTITLE_R_MODEL_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_R "data\\MODEL\\title_r.x"
class CTitle_R_Model :public CScene
{
	friend class CTitleRobot;
public:
	CTitle_R_Model();
	~CTitle_R_Model();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitle_R_Model* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	int m_time;
	bool m_Rot;
	bool m_flag;
};
#endif
