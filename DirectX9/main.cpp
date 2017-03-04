/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@main.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#include "main.h"

CManager *g_Manager;


//�O���[�o���ϐ�
int g_nCountFPS;		//FPS�J�E���^
//�֐��錾
HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow);
void Update (void);
void Draw (void);
void Uninit (void);
LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
//�錾
int nID;

/********************************************************************
WinMain�֐��@Windows �v���O������ WinMain ����J�n
*	�\���E�B���h�E�̑����ݒ��Windows�ւ̓o�^
*	�����ݒ�
*	���b�Z�[�W���[�v
*********************************************************************/
int WINAPI WinMain ( HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR LPCmdLine,int nCmdShow )
{
	HWND hWnd;//���C���h�E�n���h��
	MSG msg;//���b�Z�[�W
	g_Manager = new CManager;
	//CManager::Init(hInstance,hWnd,bWindow);	//�C���X�^���X����,(new)���Ȃ�
	WNDCLASSEX wcex =
	{
		sizeof(WNDCLASSEX),//�����X���擾
		CS_CLASSDC,//�E�C���h�E�X�g
		WndProc,//�E�C���h���t���V�W�̃A�h���X
		0,
		0,
		hInstance,//�C���X�^���X�n���h����
		NULL,
		LoadCursor(NULL,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		"DX9",//���O
		NULL
	};

	//wcex.lpszMenuName= MAKEINTRESOURCE(1);

	RegisterClassEx(&wcex);
	hWnd = CreateWindowEx(0,
		"DX9",
		"DirectX",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);


	if(FAILED(g_Manager->Init(hInstance,hWnd,TRUE)))	//����������(���s������)
	{
		return -1;
	}

	Init(hInstance,hWnd,TRUE);

	ShowWindow( hWnd, nCmdShow ) ;
	UpdateWindow( hWnd ) ;
	DWORD dwFrameCount;
	DWORD dwCurrentTime;
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	timeBeginPeriod (1);
	dwFrameCount =
	dwCurrentTime = 0;
	dwExecLastTime =
	dwFPSLastTime = timeGetTime();
	//���b�Z�[�W���[�v
	while(1)
	{
		if(PeekMessage( &msg, NULL, 0, 0 ,PM_REMOVE)!= 0)
		{
			if(msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage( &msg );//���b�Z�[�W�̖|��//�L�[�{�[�h���p���\�ɂ���
				DispatchMessage( &msg ) ;// �����Windows�ɖ߂�
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();
			if((dwCurrentTime -dwFPSLastTime)>=500)		//FPS
			{
				g_nCountFPS =
					(dwFrameCount *1000)
					/(dwCurrentTime - dwFPSLastTime );
				dwFPSLastTime = dwCurrentTime;
				dwFrameCount = 0;
			}
			if((dwCurrentTime -dwExecLastTime)>=(1000/60))
			{
				dwExecLastTime = dwCurrentTime;
			Update();	//�X�V����
			Draw();	//�`�揈��
			dwFrameCount ++;
			}
		}	

	}
	Uninit();	//�I������
	UnregisterClass("box",wcex.hInstance);//���O
	timeEndPeriod(1);
	return(int)msg.wParam;
}

//=============================================================================
//  �֐����@�FInit
//  �@�\�T�v�F�S�v���O��������������
//  �߂�l�@�FS_OK
//=============================================================================
HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow)
{
	//g_Manager -> Init( hInstance, hWnd, TRUE );
	return S_OK;
}
//=============================================================================
//  �֐����@�FUninit
//  �@�\�T�v�F�S�v���O�����I������
//  �߂�l�@�F
//=============================================================================
void Uninit (void)
{
	g_Manager -> Uninit();
	delete g_Manager;
}
////=============================================================================
////  �֐����@�FDraw
////  �@�\�T�v�F���b�Z�[�W��ʕ`��
////  �߂�l�@�F
////=============================================================================
void Draw (void)
{
	g_Manager -> Draw();
}
//=============================================================================
//  �֐����@�FUpdate
//  �@�\�T�v�F�v���O�����X�V����
//  �߂�l�@�F
//=============================================================================
void Update(void)
{
	g_Manager -> Update();
}
//=============================================================================
//		�E�B���h�E�v���V�[�W���֐��iWindowProcedure�j
//		(Windows���b�Z�[�W�������s��)
//=============================================================================
LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch(uMsg)
	{
	case WM_DESTROY://"WM_QUIT"���b�Z�[�W��Ԃ�//����{�^�����N���b�N������
		PostQuitMessage(0);// WM_QUIT���b�Z�[�W�𔭍s
		break;
	case WM_KEYDOWN://�L�[�������ꂽ
		switch(wParam)
		{
		case VK_ESCAPE://ESC�L�[
		nID=MessageBox(hWnd,"ESC���܂���","ESC",MB_YESNO);

		if(nID==IDYES)
		{
			SendMessage(hWnd, WM_CLOSE, 0, 0);
			DestroyWindow(hWnd);
		}
		break;
		}

	case VK_MENU:
	case 'F':
	case WM_COMMAND:
		{
			int menuID = LOWORD(wParam);
			switch(menuID)
			{
			case ID_MODE_PLAYERMODE:

				break;
				//��
			case ID_BULIDMODE_40007:
				break;
				//�G
			case ID_BULIDMODE_40006:
				break;

			}
			break;

		}
	default:	//��L�ȊO�̃��b�Z�[�W��Windows�֏�����C����
	break;

	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}
CManager *GetManager ( void )
{
	return g_Manager;
}
