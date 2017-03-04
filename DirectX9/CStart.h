///********************************************************************************
//* タイトル　01
//* ファイル名　CStart.h
//* 作成者 AT13B284 42 李昊盛
//* 作成日 2016/07/11
//* Start描画
//********************************************************************************/
#ifndef	_CSTART_H_
#define	_CSTART_H_

//*******************************************************************************
//* マクロ定義
//*******************************************************************************/
//マクロ定義
#define MAX_START (10)
#define MODEL_START "data\\MODEL\\PROP\\start.x"

class CStart :public CScene
{
	friend class CBuildMenu;
	friend class CBuildMap;
	friend class CBuildLight;
	friend class CTrail;
public:
	enum START_TYPE
	{
		START_NORMAL = 0,			// 通常
		START_BUILDING_TRUE,
		START_BUILDING_FALSE,
		START_MAX
	};
public:
	CStart();
	~CStart();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// 初期化処理
	void Uninit(void);		// 終了処理
	void Draw(void);		//描画処理
	void Update(void);		//更新処理
	static CStart* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);//生成関数
private:
	LPD3DXBUFFER m_BuffMat;             // 頂点バッファへのポインタ
	LPD3DXMESH m_Mesh;                  // メッシュの情報
	DWORD m_nNumMat;                     // マテリアル数
	D3DXMATRIX m_mtxWorld;               // ワールドマトリックス
	D3DXVECTOR3 m_NumCheck;
	int m_Changge;
	START_TYPE m_type;
};
#endif