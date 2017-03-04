///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CEnd.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/06/16
//*End�`��
//********************************************************************************/
#ifndef	_CEND_H_
#define	_CEND_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

class CEnd :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CBuildMenu;
public:
	enum END_TYPE
	{
		END_NORMAL = 0,			// �ʏ�
		END_BUILDING_TRUE,
		END_BUILDING_FALSE,
		END_MAX
	};
public:
	CEnd();
	~CEnd();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CEnd* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);

private:

	D3DXVECTOR3 m_scl;		//�X�P�[���l
	D3DXMATRIX m_mtxWorld;		//���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	bool m_use;
	END_TYPE m_type;

};
#endif