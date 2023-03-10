#include "DxLib.h"

#include "../library/SystemLib/pch.h"
#include "../library/control.h"

// キー取得用配列
char key[256];

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	
	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	CONTROL *control = new CONTROL;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0)
	{
		control->All();
	}
	
	// DXライブラリの終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}
