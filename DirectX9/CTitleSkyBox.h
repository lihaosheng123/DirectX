///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CTitleSkyBox.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/04/28
//* CTitleSkyBox
//********************************************************************************/
#ifndef	_CTITLESKYBOX_H_
#define	_CTITLESKYBOX_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CTitleSkyBox :public CScene
{
public:
	CTitleSkyBox();
	~CTitleSkyBox();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleSkyBox* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	LPDIRECT3DTEXTURE9 m_pTexture[6];
};
#endif