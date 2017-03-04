/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@manger.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/09
*
********************************************************************************/
#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "main.h"
#include "scene.h"
#include "Mode.h"
#include "fade.h"

#include "sceneInput.h"
#include "sceneMouse.h"

#include "CTitle.h"
#include "CBuildManager.h"
#include "CGame.h"
#include "CResult.h"

#include "sound.h"
#include "renderer.h"
/* �O���錾 */
class CRenderer;
class CScene;
class CSceneInput;
class CMode;
class CTitle;
class CGame;
class CBuildManager;
class CResult;
class CBubble;

//�}�N���J��
#define RELEASE( d )	if( d != NULL )					\
						{								\
							( d ) -> Release();			\
							d = NULL;					\
						}
/* �����_���N���X �ݒ� */
class CManager
{
	friend class CBuildMap;
	friend class CTitle;
	friend class CBuildLoadMap;
	friend class CLevelLight;
	friend class CLevelModel;
	friend class CLoadMap;
	friend class CBuildManager;
	friend class CGameEnemy_001;
	friend class CGameEnemy_002;
	friend class CGameWall_001;
	friend class CGameWall_002;
	friend class CGame;
	friend class CGameCeiling;
	friend class CGameDoor;
	friend class CGamePoint;
	friend class CFade;
	friend class CGame002;
	public:
	
		enum MODE
		{
			MODE_TITLE,
			MODE_GAME,
			MODE_BUILD,
			MODE_RESULT
		};

	private:
	static CMode *m_Mode;

	static MODE m_OldMode;
	static MODE m_NewMode;

	static int m_FadeMode;
	static int m_FadeCount;
	static int m_ModeDelay;

	CRenderer *m_Renderer;
	CSceneInput *m_Input;
	CSceneMouse *m_Mouse;
	CFade *m_Fade;
	bool m_Build;
	bool m_MouseDraw;
	public:
		CManager();	// �R���X�g���N�^
		~CManager();	// �f�X�g���N�^
		/* ���C�� �֘A */
		HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow);		// ����������
		void Uninit(void);		// �I������
		void Draw(void);		//�`�揈��
		void Update(void);		//�X�V����
		static CMode* GetMode(void);
		static void SetMode( MODE Mode);
		/*�Q�b�g�f�o�C�X */
		CRenderer* GetRenderer ( void );
		CSceneInput* GetInput ( void );
		CSceneMouse* GetMouse ( void );
		//CGame *GetGame ( void );

};
#endif