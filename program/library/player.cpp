#include "player.h"
#include "DxLib.h"

PLAYER::PLAYER()
{
	// 画像読み込み
	if (-1 == LoadDivGraph("", 12, 3, 4, 29, 40, gh)) {
		MSG("エラー発生");
	}

	width = 29;
	height = 40;

	// 移動係数
	move = 1.0f;

	// 横方向と縦方向のカウント数
	xcount = 0, ycount = 0;
	// 添字用変数
	ix = 0, iy = 0, result = 0;

	// 初期位置
	x = 180;
	y = 400;

	life = true;
}

