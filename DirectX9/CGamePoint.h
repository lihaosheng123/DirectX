///********************************************************************************
//* タイトル　01
//* ファイル名　CGamePoint.h
//* 作成者 AT13B284 42 李昊盛
//* 作成日 2016/07/11
//* GamePoint描画
//********************************************************************************/
#ifndef	_CGAMPOINT_H_
#define	_CGAMPOINT_H_
#include "CGamePoint_data.h"
//*******************************************************************************
//* マクロ定義
//*******************************************************************************/
//マクロ定義
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
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// 初期化処理
	void Uninit(void);		// 終了処理
	void Draw(void);		//描画処理
	void Update(void);		//更新処理
	void SetGamePoint(D3DXVECTOR3 pos);
	static CGamePoint* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//生成関数
	CGamePoint_data* Get(int Index);
	float Length(D3DXVECTOR3 *Vector);
	bool m_Flag;
	int num;
};
#endif