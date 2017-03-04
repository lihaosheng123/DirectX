/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@sceneMouse.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/05/23
*�}�E�X����
********************************************************************************/
#ifndef _SCENEMOUSE_H_
#define _SCENEMOUSE_H_


/*------------------------------------------------------------------------------
|	�C���N���[�h�t�@�C��
------------------------------------------------------------------------------*/

class CScene2D;
class CSceneInput;
/*------------------------------------------------------------------------------
|	�}�N����`
------------------------------------------------------------------------------*/
//�}�E�X�{�^���̗񋓌^
typedef enum
{
	DIM_LEFT		= 0,		//�}�E�X���{�^��
	DIM_RIGHT,					//�}�E�X�E�{�^��
	DIM_CENTER,					//�}�E�X���{�^��
	DIM_MAX
}MOUSE_BUTTONS;

//�}�E�X�|�C���^���̍\����
typedef struct
{
	RECT		moveRect;	//��ʏ�œ�����͈�
	int			x;			//X���W
	int			y;			//Y���W
	int			moveAdd;	//�ړ���
}MSTATE;

class CSceneMouse 
{
friend class CField;
friend class CCamera;
friend class CBuildCamera;
friend class CDebugProc;
friend class CBall;
friend class CGun;
public:
	CSceneMouse();
	~CSceneMouse();
	HRESULT Init (HINSTANCE hInstance,HWND hWnd);		// ����������
	void Uninit(void);		// �I������
	void Update(void);		//�X�V����
	void Draw(void);		//�`�揈��
	MSTATE *GetMouseState( void );
	bool GetMousePress( int nKey );
	bool GetMouseTrigger( int nKey );
	bool GetMouseRelease( int key );
	bool GetMouseRepeat( int nKey );
	void SetMouse(int x,int y);
	D3DXVECTOR3* CalcScreenToWorld(D3DXVECTOR3* pout,int Sx,int Sy,float fZ,int Screen_w,int Screen_h,D3DXMATRIX* View,D3DXMATRIX* Prj);
	D3DXVECTOR3* CalcScreenToXZ(D3DXVECTOR3* pout,int Sx,int Sy,int Screen_w,int Screen_h,D3DXMATRIX* View,D3DXMATRIX* Prj);
private:
	LPDIRECTINPUT8 m_MouseInput;					//IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	MSTATE					g_Mouse;								//�}�E�X�̃��[�N
	DIMOUSESTATE			g_MouseState;							//�}�E�X���
	LPDIRECTINPUTDEVICE8	g_pDevMouse	;					//IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�}�E�X)
	BYTE					g_MouseStateTrigger[ NUM_KEY_MAX ];		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
	BYTE					g_MouseStateRelease[ NUM_KEY_MAX ];		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
	BYTE					g_MouseStateRepeat[ NUM_KEY_MAX ];		//�}�E�X�̏�Ԃ��󂯎�郏�[�N
	int						g_MouseStateRepeatCnt[ NUM_KEY_MAX ];	//�}�E�X�̃��s�[�g�J�E���^

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer ;	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture ;
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	int nCount;			// �J�E���^
	int nPattern;		// �p�^�[��No

};
#endif