///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CGameCeiling_data.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/10
//* GameCeilingdata
//********************************************************************************/
#ifndef	_CGAMECEILING_DATA_H_
#define	_CGAMECEILING_DATA_H_
#include "scene.h"
//**************
//***********************************************************************************
//* �}�N����`*************************************************************/
//�}�N����`

class CGameCeiling_data
{
	friend class CLoadMap;
public:

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	D3DXVECTOR3 m_scl;	// �X�P�[���l
	CMatrix Matrix;
	bool m_bUse;

	CGameCeiling_data() {
		m_Position = D3DXVECTOR3(0.0f, 10.0f, 0.0f);
		m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_scl = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
		m_bUse = false;
	}
};
#endif