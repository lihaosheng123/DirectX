///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameDoor.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GameDoor�`��
//********************************************************************************/
#ifndef	_CGAMDOOR_H_
#define	_CGAMDOOR_H_
#include "CGameDoor_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`
class CGameDoor_data;
class CGameDoor :public CScene
{
	friend class CLoadMap;
	friend class CEnemy_Bullet;
	friend class CEnemy_Effect;
	CGameDoor_data m_data[MAX_ENEMY];

public:

	CGameDoor();
	~CGameDoor();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGameDoor(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	static CGameDoor* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	CGameDoor_data* Get(int Index);
	float Length(D3DXVECTOR3 *Vector);
	int m_warp;
};
#endif