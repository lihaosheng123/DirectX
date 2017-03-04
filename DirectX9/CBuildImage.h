/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CBuildImage.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
*�V���誂�/�\���̑���摜
********************************************************************************/
#ifndef _CBUILDIMAGE_H_
#define _CBUILDIMAGE_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
#define	TEXTURE_BUILDIMAGE_FILE		"data\\TEXTURE\\BUILD\\BuildImage.png"	// �ǂݍ��ރe�N�X�`���t�@�C����

class CBuildImage : public CScene
{
public:
	CBuildImage();
	~CBuildImage();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CBuildImage* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

};
#endif