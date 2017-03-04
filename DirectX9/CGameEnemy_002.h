///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameEnemy_002.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2016/07/11
//* GameEnemy_002�`��
//********************************************************************************/
#ifndef	_CGAMEENEMY_002_H_
#define	_CGAMEENEMY_002_H_
#include "CGameEnemy_002_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`

#define MODEL_ENEMY_002 "data\\MODEL\\ENEMY\\enemy_002.x"

class CGameEnemy_002_data;
class CGameEnemy_002 : public CScene
{
	friend class CLoadMap;

private:
	CGameEnemy_002_data m_data[5000];
public:
	CGameEnemy_002();
	~CGameEnemy_002();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGameEnemy_002(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	static CGameEnemy_002* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//�����֐�
	CGameEnemy_002_data* Get(int Index);
	float  Length(D3DXVECTOR3 *Vector);

};
#endif