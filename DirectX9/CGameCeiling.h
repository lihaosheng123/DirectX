///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameCeiling.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/12
//*CGameCeiling�`��
//********************************************************************************/
#ifndef	_CGAMECEILING_H_
#define	_CGAMECEILING_H_
#include "CGameCeiling_data.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#define	GAME_TEXTURE_CEILING_FILE		"data\\TEXTURE\\ceiling.jpg"	// �ǂݍ��ރe�N�X�`���t�@�C����
#include "CLoadMap.h"
class CLoadMap;
class CBuildLoad;
class CGameCeiling_data;
class CGameCeiling :public CScene
{
	friend class CBullet;
	friend class CMap;
	friend class CDebugProc;
	friend class CBuildMap;
	friend class CLoadMap;
	friend class CPlayer;
public:
	CGameCeiling();
	~CGameCeiling();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	void SetGameCeiling(D3DXVECTOR3 pos);
	static CGameCeiling* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
	CGameCeiling_data m_data[MAX_WALL];
	int m_warp;

};
#endif