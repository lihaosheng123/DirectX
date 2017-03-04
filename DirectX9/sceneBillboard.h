///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@scenebillboard.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/04/28
//* billboard�`��
//********************************************************************************/
#ifndef	_SCENEBILLBOARD_H_
#define	_SCENEBILLBOARD_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define MAX_BILLBOARD ( 1 )                     // BILLBOARD�̐�
#define	TEXTURE_BILLBOARD_FILE01		"data\\TEXTURE\\billboard01.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define	TEXTURE_BILLBOARD_FILE02		"data\\TEXTURE\\billboard02.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
#define	TEXTURE_BILLBOARD_FILE03		"data\\TEXTURE\\billboard03.png"	// �ǂݍ��ރe�N�X�`���t�@�C����
class CSceneBillboard :public CScene
{
public:
	CSceneBillboard();
	~CSceneBillboard();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CSceneBillboard* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
private:
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
};
#endif