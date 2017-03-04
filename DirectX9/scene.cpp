/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@scene.cpp
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#include "main.h"
#include <stdio.h> 
#include "renderer.h"

#include "scene.h"


//�ÓI�����o�ϐ�
CScene *CScene::m_Top = NULL;
CScene *CScene::m_Cur = NULL;
//=============================================================================
// ����
//=============================================================================
CScene ::CScene (void)
{
	//���X�g�ɓo�^
	if(m_Top == NULL)
	{
		// ��������
		m_Top = this;
		m_Cur = this;
		//�g���ĂȂ����NULL
		m_Prev = NULL;
		m_Next = NULL;
	}
	else
	{
		m_Cur->m_Next = this;
		m_Prev = m_Cur;
		m_Cur = this;
		m_Next = NULL;
	}
}

//=============================================================================
// �j��
//=============================================================================
CScene ::~CScene (void)
{

}
//=============================================================================
// �S�Ă�Scene�̍X�V����
//=============================================================================
void CScene::UpdateAll(void)
{
	//���X�g�ɓo�^����Ă���S�ẴI�u�W�F�N�g��draw���Ăяo��
	CScene *scene = m_Top;
	CScene *save;
	while(scene!=NULL)
	{
		save = scene->m_Next;	//�|�C���^�ۑ�
		scene->Update();
		scene = save;		//	�|�C���^����ւ���
	}

}
//=============================================================================
// �S�Ă�Scene�̕`�揈��
//=============================================================================
void CScene::DrawAll(void)
{
	CScene *scene = m_Top;
	while(scene!=NULL)
	{
		scene->Draw();
		scene = scene->m_Next;
	}

}
//=============================================================================
// �S�Ă�Scene�̔j������
//=============================================================================
void CScene::UninitAll(void)
{
	CScene *scene = m_Top;
	CScene *next;
	while(scene!=NULL)
	{
		next = scene->m_Next;
		scene->Uninit();	
		delete scene;
		scene = next;
	}
	m_Top =NULL;
}
void CScene::Release(void)
{
	if( this == m_Top)
	{
		m_Top = m_Next;
	}
	else
	{
		m_Prev->m_Next = m_Next;
	}
	if(this == m_Cur)
	{
		m_Cur = m_Prev;
	}
	else
	{
		m_Next->m_Prev = m_Prev;
	}
	delete this;
}
D3DXVECTOR3* CScene::Get3DPosition(void)
{
	return &m_Position;
}
