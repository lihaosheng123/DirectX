/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@scene.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/18
*
********************************************************************************/
#ifndef _SCENE_H_
#define _SCENE_H_
//*****************************************************************************
// �}�N����`
//*****************************************************************************

//*************************************
// Matrix�N���X
//*************************************
class CMatrix
{
public:
	D3DXMATRIX World;// ���[���h�}�g���b�N�X
	D3DXMATRIX Scl;
	D3DXMATRIX Rot;
	D3DXMATRIX Trans;
	D3DXMATRIX View;

	CMatrix()
	{
		D3DXMatrixIdentity(&World);
		D3DXMatrixIdentity(&Scl);
		D3DXMatrixIdentity(&Rot);
		D3DXMatrixIdentity(&Trans);
		D3DXMatrixIdentity(&View);
	}
};
class CScene 
{
//friend class CDebugProc;
	/*�p��*/
protected:
	static CScene *m_Top;	//�擪		//�ÓI�����o�ϐ�
	static CScene *m_Cur;	//����		//�ÓI�����o�ϐ�

	CScene *m_Prev;	//�O�̃|�C���^
	CScene *m_Next;	//���̃|�C���^

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuffer ;	//���_�p�b�t�@�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 m_pTexture ;
	D3DXVECTOR3 m_Position;	// ���_���W
	D3DXVECTOR3 m_Rotation;	// ��]
	D3DXVECTOR3 m_scl;        // �X�P�[���l
	float m_height;		//����
	float m_width;		//����
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	CMatrix m_Matrix;
public:
	CScene();				// �R���X�g���N�^
	~CScene();				// �f�X�g���N�^
	//���z�֐�
	virtual HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE) = 0;		// ����������
	virtual void Uninit(void) = 0;		// �I������
	virtual void Draw(void) = 0;		//�`�揈��
	virtual void Update(void) = 0;		//�X�V����
	static void UpdateAll(void);
	static void DrawAll(void);
	static void UninitAll(void);
	void Release(void);
	D3DXVECTOR3* Get3DPosition(void);
};
#endif	