//********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@Caxis.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/12
//*���W�n�`��
//********************************************************************************/
#ifndef	_CAXIS_H_
#define	_CAXIS_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	TEXTURE_AXIS_FILE		"data\\TEXTURE\\BUILD\\axis.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class Caxis :public CScene
{
public:
	Caxis();
	~Caxis();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static Caxis* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
private:

};
#endif