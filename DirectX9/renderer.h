/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@renderer.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "main.h"
#include "manager.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
const float PI = 3.141592653589159f;

typedef struct
{
	D3DXVECTOR3 pos;	// ���_���W
	float rhw;			// �e�N�X�`���̃p�[�X�y�N�e�B�u�R���N�g�p
	D3DCOLOR col;		// ���_�J���[
	D3DXVECTOR2 tex;	// �e�N�X�`�����W
} VERTEX_2D;

//�\���̒�`

typedef struct
{
	D3DXVECTOR3	pos;	//���_���W
	D3DXVECTOR3	nor;	//�@���x�N�g��( �ʂ̌��� )
	D3DCOLOR	col;	//���_�J���[
	D3DXVECTOR2	tex;	//�e�N�X�`�����W
	float			tu;
	float			tv;
}VERTEX_3D;

//*************************************
// D3D�N���X
//*************************************
class CRenderer 
{
public:
	CRenderer();				// �R���X�g���N�^
	~CRenderer();				// �f�X�g���N�^
	HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL bWindow);		// ����������
	void Uninit(void);		// �I������
	void Begin (void);
	void End (void);
	void Update(void);		//�X�V����
	void DrawFPS( void );
	LPDIRECT3DDEVICE9 GetDevice(void);
private:
	LPDIRECT3D9 m_pD3D ;		//Direct3D�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECT3DDEVICE9 m_pD3DDevice ;	//Direct3D�f�o�C�X�ւ̃|�C���^
	LPD3DXFONT m_pFont ;		//�t�H���g�ւ̃|�C���^
	//CRenderer *m_Renderer;
};
extern int g_nCountFPS;		//FPS�J�E���^
#endif