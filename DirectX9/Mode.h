/********************************************************************************
* �^�C�g���@01
* �t�@�C�����@Mode.h
* �쐬�� AT13B284 42 ���ݐ�
* �쐬�� 2016/07/11
*
********************************************************************************/
#ifndef _MODE_H_
#define _MODE_H_

class CMode

{
	private:

	public:
		//���퉼�z�֐�
		virtual void Init(void) = 0;
		virtual void Uninit(void) = 0;
		virtual void Update(void) = 0;
		virtual void Draw(void) = 0;

};


#endif