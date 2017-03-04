/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CField.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/06/20
* field�`��
********************************************************************************/
#ifndef _CFIELD_H_
#define _CFIELD_H_
//------------------------------------------------------------------------------
//	�C���N���[�h�t�@�C��
//------------------------------------------------------------------------------

class CScene3D;
//------------------------------------------------------------------------------
//	�}�N����`	
//------------------------------------------------------------------------------
#define MESHFIELD_TEXTURE_FILE00	"./data/TEXTURE/field.jpg"	//�n�ʃe�N�X�`���t�@�C���ʒu

#define MESH_VTXH		(100)		//��
#define MESH_VTXV		(100)		//����


//  �V�[���^�C�v
typedef enum
{
	NONE = 0,
	LEFT_TOP,
	RIGHT_TOP,
	LEFT_DOWN,
	RIGHT_DOWN,
	TOP_SIDE,
	DOWN_SIDE,
	LEFT_SIDE,
	RIGHT_SIDE,
	MIDDLE
}NORMAL_TYPE;

//  ���b�V���\����
typedef struct
{
	int			nVtxV;			//  ���̒��_��
	int			nVtxH;			//  �c�̒��_��
	int			nVtx;			//  �����_��
	int			nIdx;			//  �C���f�b�N�X��
	int			nPrimitive;	//  �|���S����
	int			nBlockV;
	int			nBlockH;
	int			nBlock;			//  �u���b�N��
}MESH;

//  ���b�V���t�B�[���h�N���X
class CField : public CScene3D
{
friend class CDebugProc;
friend class CBall;
friend class CGun;
friend class CManager;
friend class CEffect;
friend class  CSceneMouse;
private:
	MESH	m_Mesh;				//  ���b�V�����
	LPDIRECT3DINDEXBUFFER9	m_IdxBuff;				//  �C���f�b�N�X�o�b�t�@�ւ̃|�C���^�[
	int	m_nHalfVtxV;			//  �c�̒��_���̔���
	int	m_nIdxEven;			//  �C���f�b�N�X�o�b�t�@���_�������̐�(�މ��O�p�`���_�ȊO)
	int	m_nNullVtx;			//  �k�ރ|���S�����_��
	int	m_nMultiple;			//  �C���f�b�N�X�o�b�t�@�p�W��
	float	m_fXAdjust;			//  Z���W�ʒu��␳
	float	m_fZAdjust;			//  Z���W�ʒu��␳
	float	m_fTexAdjust;			//  �e�N�X�`��Y���W�ʒu��␳
	
	D3DXVECTOR3	*m_VtxPos;				//  ���_���W
	NORMAL_TYPE	*m_NorType;			//  �@���̃^�C�v
	D3DXVECTOR3	*m_Nor;					//  �@��
	int	m_nVtxNum;				//	���_�ԍ�
	bool	m_bUseNor;				//  �@���̍X�V���K�v���ǂ���

	int	*m_nBlockVtxNo;		//  �u���b�N���_�ԍ�
	int	m_nGunInBlockNum;	//  �v���C���[�̂���u���b�N�ԍ�

	int		nBlockH;		//  ���u���b�N���_�ԍ����i�[���[�N
	int		nBlockV;		//  �c�u���b�N���_�ԍ����i�[���[�N
	float	fBlockH;		//  ���u���b�N���_�ԍ����i�[���[�N�ifloat�^�j
	float	fBlockV;		//  �c�u���b�N���_�ԍ����i�[���[�N�ifloat�^�j
	int		nInBlockNum;	//  �Ώۂ̂���u���b�N�ԍ�

	int m_billboardNum[MESH_VTXH * MESH_VTXV];
	int target_rand;

	bool m_Moveuse;
	bool m_Cut;
public:
	CField();
	~CField();
	HRESULT		Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);
	void		Uninit(void);
	void		Update(void);
	void		Draw(void);
	void		MakeVertex(void);
	void		MakeNormal(void);
	void		MakeBlockVtx(void);
	HRESULT		MakeIndex(LPDIRECT3DDEVICE9 pDevice);
	HRESULT		SetVertex(LPDIRECT3DDEVICE9 pDevice);
	D3DXVECTOR3	*GetNormal(void);
	int			*GetGunInBlock(void);
	int			CheckBlock(D3DXVECTOR3 pos);
	float		GetHeight(D3DXVECTOR3 pos, bool bMove);
	static CField* Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);
};

#endif