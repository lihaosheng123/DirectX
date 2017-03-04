/******************************************************************************
	二重インクルードガード
******************************************************************************/
#ifndef _DEBUGPROC_H_
#define _DEBUGPROC_H_

/******************************************************************************
	includeファイル
******************************************************************************/
#include "renderer.h"

/******************************************************************************
	ライブラリのリンク
******************************************************************************/

/******************************************************************************
	マクロ定義
******************************************************************************/
#define FONT_MAX	( 9000 )	// デバッグ文字列の最大数
#define DEBUG_COLOR	( D3DCOLOR_RGBA( 255, 0, 255, 255 ) )	// デバッグカラー

/******************************************************************************
	型定義
******************************************************************************/

/* DebugProcクラス 設定 */
class CDebugProc
{
	private:
		LPD3DXFONT	m_DebugFont;
		char		m_StrDebug[ FONT_MAX ];
		RECT		m_Rect;
	public:
		CDebugProc();	// コンストラクタ
		~CDebugProc();	// デストラクタ
		HRESULT Init( void );
		void Update	( void );
		void Draw	( void );
		void Uninit	( void );
		void Print	( char *fmt,... );

};

#endif