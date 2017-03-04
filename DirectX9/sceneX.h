/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@sceneX.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/04/26
* X�|���S���`��
********************************************************************************/
#ifndef _SCENEX_H_
#define _SCENEX_H_

//�}�N����`



class CSceneX : public CScene
{
friend class CDebugProc;
public:
	CSceneX();
	~CSceneX();
	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 rot,float height ,float width,LPCSTR TEXTURE_FILE);		// ����������
	void Uninit(void);		// �I������
	void Draw(void);		//�`�揈��
	void Update(void);		//�X�V����

protected:
	LPD3DXBUFFER m_BuffMat;             // ���_�o�b�t�@�ւ̃|�C���^
	LPD3DXMESH m_Mesh;                  // ���b�V���̏��
	DWORD m_nNumMat;                     // �}�e���A����
	D3DXMATRIX m_mtxWorld;               // ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_scl;        // �X�P�[���l
	D3DXVECTOR3 m_Max;        // ���_���W�̍ő�l
	D3DXVECTOR3 m_Min;        // ���_���W�̍ŏ��l
	D3DXVECTOR3 m_Size;       // Max��Min�̐�Βl�𑫂��ĂQ�Ŋ��������́B�܂��Փ˔���Ŏg�����f���̔��a�Bx:�� y:���� z:���s���B
	float m_Collisoin;        // �Փ˔���Ŏg�������Bsize��x��z�ŁA�傫�����������Փ˔���Ɏg���B
	D3DXVECTOR3 m_Velocity;		//�d��

};

#endif