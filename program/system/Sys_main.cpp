#include "DxLib.h"

#include "../library/SystemLib/pch.h"
#include "../library/control.h"

// �L�[�擾�p�z��
char key[256];

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	
	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		// �G���[���N�����璼���ɏI��
		return -1;
	}

	CONTROL *control = new CONTROL;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0)
	{
		control->All();
	}
	
	// DX���C�u�����̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
