//=============================================================================
//
// �T�E���h���� [sound.h]
// Author : AKIRA TANAKA
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_


//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_BGM000 = 0,		// BGM0
	SOUND_LABEL_BGM001,			// BGM1
	SOUND_LABEL_BGM002,			// BGM2
	SOUND_LABEL_SE_SHOT,		// �e���ˉ�
	SOUND_LABEL_SE_HIT,			// �q�b�g��
	SOUND_LABEL_SE_EXPLOSION,	// ������
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// �p�����[�^�\���̒�`
//*****************************************************************************
typedef struct
{
	char *pFilename;	// �t�@�C����
	int nCntLoop;		// ���[�v�J�E���g
} SOUNDPARAM;

class CSound
{
private:
	IXAudio2 *g_pXAudio2 ;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *g_pMasteringVoice ;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *g_apSourceVoice[SOUND_LABEL_MAX] ;	// �\�[�X�{�C�X
	BYTE *g_apDataAudio[SOUND_LABEL_MAX] ;					// �I�[�f�B�I�f�[�^
	DWORD g_aSizeAudio[SOUND_LABEL_MAX] ;					// �I�[�f�B�I�f�[�^�T�C�Y
public:
	CSound();
	~CSound();
	HRESULT Init(HWND hWnd);
	void Uninit(void);
	HRESULT Play(SOUND_LABEL label);
	void Stop(SOUND_LABEL label);
	void StopAll(void);
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

};
#endif
