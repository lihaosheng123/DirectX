///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameWall_002.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/12
//*CGameWall_002�`��
//********************************************************************************/
#ifndef	_CGAMEWALL_002_H_
#define	_CGAMEWALL_002_H_
#include "CGameWall_002_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	GAME_TEXTURE_WALL_002_FILE		"data\\TEXTURE\\wall_002.jpg"	// �ǂݍ��ރe�N�X�`���t�@�C����
#include "CLoadMap.h"
class CLoadMap;
class CBuildLoad;
class CGameWall_002_data;
class CGameWall_002 :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
private:
	CGameWall_002_data m_data[5000];
public:
	CGameWall_002();
	~CGameWall_002();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGameWall_002(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	static CGameWall_002* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
	int m_warp;

};
#endif