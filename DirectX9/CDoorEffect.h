///********************************************************************************
//* �^�C�g���@01
//* �t�@�C�����@CDoorEffect.h
//* �쐬�� AT13B284 42 ���ݐ�
//* �쐬�� 2017/01/20
//*door��effect�`��
//********************************************************************************/
#ifndef	_CDOOREFFECT_H_
#define	_CDOOREFFECT_H_
//*******************************************************************************
//* �}�N����`
//*******************************************************************************/

#include "scene.h"

class CDoor_Effect :public CScene
{
	friend class CPlayer;
	friend class CDebugProc;
	friend class CExplosion;
	friend class CGameDoor;
public:
	CDoor_Effect();
	~CDoor_Effect();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CDoor_Effect* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot, float height, float width, LPCSTR TEXTURE_FILE);
private:
	D3DXVECTOR3 m_scl;		//�X�P�[���l
	bool m_bUse;
	int m_Life;

	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	float m_height;		//����
	float m_width;		//����
	CMatrix m_Matrix;
	int alpha;
};
#endif