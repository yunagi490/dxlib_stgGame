#include "DxLib.h"
#include "player.h"

void PLAYER::Move()
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// 移動係数を 0.71 に設定
			move = 0.71f;
		}
		else {
			// 斜めじゃなければ 1.0 に固定
			move = 1.0f;
		}
	}
	else if(key[KEY_INPUT_UP]==1	||	key[KEY_INPUT_DOWN]==1){
		move = 1.0;
	}

	// 横方向の移動なので "x"
	if (key[KEY_INPUT_LEFT] == 1) {
		 x -= (int)PLAYER_SPEED*move;
		
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		x += (int)PLAYER_SPEED * move;

	}
	// 縦方向の移動なので "y"
	if (key[KEY_INPUT_UP] == 1) {
		y -= (int)PLAYER_SPEED * move;

	}
	if (key[KEY_INPUT_DOWN] == 1) {
		y += (int)PLAYER_SPEED * move;
	}


	// 左キーが押されていて、かつ xcount が0以上なら0にしてから1引く
	// それ以外は1引く
	if (key[KEY_INPUT_LEFT] == 1) {
		if (xcount > 0)
			xcount = 0;
		--xcount;

	}
	// 右キーが押されていて、かつ xcount が0以下なら0にしてから1足す
	// それ以外は1足す
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (xcount < 0);
			xcount = 0;
		++xcount;
	}
	// 左キーが押されていて、かつ ycount が0以上なら0にしてから1引く
	// それ以外は1引く
	if (key[KEY_INPUT_UP] == 1) {
		if (ycount > 0)
			ycount = 0;
		--ycount;

	}
	// 右キーが押されていて、かつ ycount が0以下なら0にしてから1足す
	// それ以外は1足す
	if (key[KEY_INPUT_DOWN] == 1) {
		if (ycount < 0);
			ycount = 0;
		++ycount;
	}


	// カウント数から添字を求める
	ix = abs(xcount) % 30 / 10;
	iy = abs(ycount) % 30 / 10;

	// xカウントがプラスなら右向きなので2行目の先頭添字番号を足す。
	if (xcount > 0)
	{
		ix += 3;
		result = ix;
	}else if(xcount<0){
		// マイナスなら左向きなので、4行目の先頭添字番号を足す。
		ix += 9;
	}
	// yカウントがプラスなら下向きなので、3行目の先頭添字番号を足す。
		// 1先頭の添字番号は0なので何もする必要なし。
}