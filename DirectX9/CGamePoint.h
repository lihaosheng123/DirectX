///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGamePoint.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GamePoint�`��
//********************************************************************************/
#ifndef	_CGAMPOINT_H_
#define	_CGAMPOINT_H_
#include "CGamePoint_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
class CGamePoint_data;
class CGamePoint : public CScene
{
	friend class CLoadMap;
	friend class CEnemy_Bullet;
	friend class CEnemy_Effect;
	CGamePoint_data m_data[MAX_ENEMY];

public:

	CGamePoint();
	~CGamePoint();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGamePoint(D3DXVECTOR3 pos);
	static CGamePoint* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	CGamePoint_data* Get(int Index);
	float Length(D3DXVECTOR3 *Vector);
	bool m_Flag;
	int num;
};
#endif