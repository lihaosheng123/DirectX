/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@CModel.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/08/23
* ``X�|���S���`��
********************************************************************************/
#ifndef _CMODEL_H_
#define _CMODEL_H_

//�}�N����`



class CModel 
{
friend class CPlayer;
friend class CEnemy;
friend class CDebugProc;
public:
	CModel();
	~CModel();
	HRESULT Init(LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����
	static CModel* Create(LPCSTR TEXTURE_FILE);//�����֐�
private:

	D3DXMATRIX mtxScl, mtxRot, mtxTrans;
	D3DXMATERIAL *pMat;		// �}�e���A�����
	D3DMATERIAL9 matDef;	// �f�t�H���g�̃}�e���A���B���̃}�e���A���̏���ޔ������邽�߂̕ϐ��B
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	CModel *m_Parent;
	D3DXVECTOR3 m_scl;        // �X�P�[���l
	D3DXMATRIX GetWorldMatrix(void);
	void SetParent( CModel *Parent );
	void SetPosition( D3DXVECTOR3 Position );
	void SetRotation( D3DXVECTOR3 Rotation );
	D3DXMATRIX parentMatrix;
	LPDIRECT3DTEXTURE9 m_pTexture;

};
#endif