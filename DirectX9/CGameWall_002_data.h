///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameWall_002_data.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/10
//* GameWall_002data
//********************************************************************************/
#ifndef	_CGAMEWALL_002_DATA_H_
#define	_CGAMEWALL_002_DATA_H_
#include "scene.h"
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/
//�}�N����`

class CGameWall_002_data
{
	friend class CLoadMap;
	friend class CGameWall_002;
public:

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	D3DXVECTOR3 m_scl;	// �X�P�[���l
	CMatrix Matrix;
	bool m_bUse;

	CGameWall_002_data() {
		m_Position = D3DXVECTOR3(5000.0f, 5000.0f, 5000.0f);
		m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_scl = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		m_bUse = false;
	}
};
#endif