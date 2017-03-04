		///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@portal.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* Portal�`��
//********************************************************************************/
#ifndef	_CPORTAL_H_
#define	_CPORTAL_H_

//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
#define MODEL_PORTAL_TEXTURE "data\\MODEL\\portal.x"

class CPortal : public CSceneX
{
friend class CBall;
friend class CGun;
friend class CBullet;
friend class CGame;
public:
	CPortal();
	~CPortal();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CPortal* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);//�����֐�
	float Length( D3DXVECTOR3 *Vector );
	void Normalize( D3DXVECTOR3 *Vector, D3DXVECTOR3 *Vector1 );
private:
	bool m_Buse;
	bool m_OneCheck;
};
#endif