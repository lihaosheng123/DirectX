/********************************************************************************
* �^�C�g���@01
* �t�@�C���� main.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_
//�C���N���[�h�t�@�C��
#define  DIRECTINPUT_VERSION ( 0x0800 )
#include <windows.h>
#include "resource.h"
#include "d3dx9.h"	//�`�揈���ɕK�v
#include "dinput.h"		//���͏����ɕK�v
#include "xaudio2.h"		// XAudio2�֘A�̃w�b�_�[
#include "manager.h"
//#pragma�f�B���B�f�B�u�ǉ��i���C�u�����̃����N�j
#pragma comment(lib,"d3d9.lib")		//�`�揈���ɕK�v
#pragma comment(lib,"d3dx9.lib")	//��L�̊g�����C�u�E��
#pragma comment(lib,"dxguid.lib")	//DirectX�R���{�\�l���g�g�p�ɕK�v
#pragma comment(lib,"winmm.lib")
#pragma comment ( lib, "dinput8.lib" )		//���͏����ɕK�v
#pragma warning ( disable: 4996 )			//
//�}�N����`
#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define SCREEN_CENTER_X	( SCREEN_WIDTH / 2 )		//�E�C���h�E�̒��S�w���W
#define SCREEN_CENTER_Y	( SCREEN_HEIGHT / 2 )		//�E�C���h�E�̒��S�x���W
#define FVF_VERTEX_2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1)	//�e�N�X�`�����W
#define FVF_VERTEX_3D	( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 )	//���_���W(3d) | �@�� | ���_�J���[ | �e�N�X�`�����W


//�}�N���J��
#define RELEASE( d )	if( d != NULL )					\
						{								\
							( d ) -> Release();			\
							d = NULL;					\
						}
class CManager;
class CGmae;
class CRenderer;		//�O���錾
CManager *GetManager ( void );
#endif