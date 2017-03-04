///********************************************************************************
//* �t�@�C�����@CTitleMark.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/12/17
//*�^�C�g����ʂ�menu��mark
//********************************************************************************/
#ifndef	_CTITLEMARK_H_
#define	_CTITLEMARK_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define	TEXTURE_TITLEMARK "data\\TEXTURE\\titlemark.png"

class CTitleMark :public CScene
{
friend class CTitle;
friend class CTitleMenu;
public:

	typedef enum
	{
		TITLE_MENU_START = 0,
		TITLE_MENU_BUILD,
		TITLE_MENU_END,
		TITLE_MENU_MAX
	}TITLE_MENU;

	CTitleMark();
	~CTitleMark();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CTitleMark* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�

private:
	TITLE_MENU m_type;
	bool m_bUse;
	D3DXCOLOR col;
	float num;
	bool m_colMove;
};
#endif