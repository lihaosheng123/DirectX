/********************************************************************************
* �^�C�g���@TITLE
* �t�@�C�����@CTitle.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
*
********************************************************************************/
#ifndef _CTITLE_H_
#define _CTITLE_H_
#include "CTitleCamera.h"
#include "CTitleImage.h"
#include "CTitleLight.h"
#include "scene3D.h"
#include "CField.h"
#include "CTitleMenu.h"
#include "CTitleMark.h"
#include "CTitleModel.h"
#include "CTitle_R_Model.h"
#include "CTitleRobot.h"
#include "CTitleSkyBox.h"
//�}�N����`
class CRenderer;
class CTitleEffect;
class CTitleCamera;
class CTitleLight;
class CField;
class CTitleMenu;
class CTitleMark;
class CTitleModel;
class CTitleImage;
class CTitle_R_Model;
class CTitleRobot;
class CTitleSkyBox;
class CTitle : public CMode
{

public:
	CTitle();
	~CTitle();
	virtual void Init(void);		// ����������
	virtual void Uninit(void);		// �I������
	virtual void Draw(void);		//�`�揈��
	virtual void Update(void);		//�X�V����
	CTitleMark* GetTitleMark(void);
	CTitleMenu* GetTitleMenu(void);
	CTitle_R_Model* GetTitle_R_Model(void);
private:
	CTitleCamera *m_Camera;
	CTitleLight *m_Light;
	CRenderer *m_Renderer;
	CSceneMouse *m_Mouse;
	CTitleEffect *m_TitleEffect;
	CField *m_Field;
	CTitleMenu *m_TitleMenu;
	CTitleMark *m_TitleMark;
	CTitleModel *m_TitleModel;
	CTitleImage *m_TitleImage;
	CTitle_R_Model *m_Title_R_Model;
	CTitleRobot *m_TitleRobot;
	CTitleSkyBox *m_TitleSkyBox;
	HWND hWnd;
};

#endif