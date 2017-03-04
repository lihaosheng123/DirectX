///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitleModel.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/02/10
//* TitleModel�`��
//********************************************************************************/
#ifndef	_CTITLEENEMY_H_
#define	_CTITLEENEMY_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_TITLE "data\\MODEL\\title.x"
class CTitleModel :public CScene
{

public:
	CTitleModel();
	~CTitleModel();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleModel* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
};
#endif
