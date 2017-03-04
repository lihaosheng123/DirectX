/********************************************************************************
* �^�C�g���@FADE
* �t�@�C�����@fade.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/13
*
********************************************************************************/
#ifndef _FADE_H_
#define _FADE_H_
#define	TEXTURE_FADEBG_FILE		"data\\TEXTURE\\fade.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
//�}�N����`
class CFade 
{
public:
	CFade();
	~CFade();
	HRESULT Init(void);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer;	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
};

#endif