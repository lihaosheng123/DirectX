///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@skybox.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/04/28
//* billboard�`��
//********************************************************************************/
#ifndef	_SKYBOX_H_
#define	_SKYBOX_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CSkybox :public CScene
{
public:
	CSkybox();
	~CSkybox();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CSkybox* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
private:
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	LPDIRECT3DTEXTURE9 m_pTexture[6];
};
#endif