///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameEnemy_001.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GameEnemy_001�`��
//********************************************************************************/
#ifndef	_CGAMEENEMY_001_H_
#define	_CGAMEENEMY_001_H_
#include "CGameEnemy_001_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`

#define MODEL_ENEMY_001 "data\\MODEL\\ENEMY\\enemy_001.x"

class CGameEnemy_001_data;
class CGameEnemy_001 :public CScene
{ 
	friend class CLoadMap;
	friend class CEnemy_Bullet;
	friend class CEnemy_Effect;
	CGameEnemy_001_data m_data[MAX_ENEMY];

public:

	CGameEnemy_001();
	~CGameEnemy_001();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGameEnemy_001(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	static CGameEnemy_001* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	CGameEnemy_001_data* Get(int Index);
	float Length(D3DXVECTOR3 *Vector);
};
#endif