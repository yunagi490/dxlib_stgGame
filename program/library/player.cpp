#include "player.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"

#include "DxLib.h"

PLAYER::PLAYER()
{
	// 画像読み込み
	if (-1 == LoadDivGraph("", 12, 3, 4, 29, 40, gh)) {
		/// MSG("エラー発生");
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

void PLAYER::Move()
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// 移動係数を0.71に固定
			move = 0.71f;
		}
		else {
			// 斜めじゃなければ0.1に設定
			move = 0.1f;
		}
	}
	else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
		move = 1.0f;
	}
	// X軸
	if (key[KEY_INPUT_LEFT] == 1)
	{
		x -= (int)PLAYER_SPEED * move;
	}
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		x += (int)PLAYER_SPEED * move;
	}
	// Y軸
	if (key[KEY_INPUT_UP] == 1)
	{
		y -= (int)PLAYER_SPEED * move;
	}
	if (key[KEY_INPUT_DOWN] == 1)
	{
		y += (int)PLAYER_SPEED * move;
	}
	


	// 左キーが押されてて、かつxcountが0以上なら0にしてから1引く。
	// それ以外は1引く
	if (key[KEY_INPUT_LEFT] == 1)
	{
		if (xcount > 0)
			xcount = 0;
		--xcount;
	}
	// 右キーが押されていて、かつxcountが0以下なら0にしてから1足す。
	// それ以外は1引く。
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		if (xcount < 0)
			xcount = 0;
		++xcount;
	}
	// 上キーが押されていて、かつycountが0以上なら0にしてから1引く。
	// それ以外は1引く
	if (key[KEY_INPUT_UP] == 1)
	{
		if (ycount > 0)
			ycount = 0;
		--ycount;
	}
	// 下キーが押されていて、かつycountが0以下なら0にしてから1足す。
	// それ以外は1足す。
	if (key[KEY_INPUT_DOWN] == 1)
	{
		if (ycount < 0)
			ycount = 0;
		++ycount;
	}

	// カウント数から添字を求める
	ix = abs(xcount) % 30 / 10;

}
