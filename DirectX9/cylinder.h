///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@cylinder.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/11/15
//* �e�X�g�p�X�e���V���V���h�E�`��
//********************************************************************************/
#ifndef	_cylinder_H_
#define	_cylinder_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_CYLINDER_TEXTURE "data\\MODEL\\cylinder.x"
class cylinder : public CSceneX
{
public:
	cylinder();
	~cylinder();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static cylinder* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
private:
};
#endif
