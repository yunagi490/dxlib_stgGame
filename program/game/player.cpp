#include "player.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"

#include "DxLib.h"

PLAYER::PLAYER()
{
	// 画像読み込み
	LoadGraph("../graphics/player1.png",TRUE);

	width = 64;
	height = 64;

	// 移動係数
	move = 1.0f;

	// 横方向と縦方向のカウント数
	xcount = 0, ycount = 0;
	// 添字用変数
	ix = 0, iy = 0, result = 0;

	// 初期位置
	x = 180;
	y = 400;

	// 生きてるかどうか
	life = true;

	// 弾初期化
	memset(shot, 0, sizeof(shot));

	// 弾画像読み込み
	int temp = LoadGraph("../graphics/shot.png");
	/// w=Width, h= Height
	int w, h;
	GetGraphSize(temp, &w, &h);

	// フラグを全部Falseにする
	// グラフィックハンドルと画像のサイズを代入しとく
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		shot[i].flag = false;
		shot[i].gh = temp;
		shot[i].width = w;
		shot[i].height = h;
	}

	count=0;
}

void PLAYER::Shot()
{
	// キーが押されていてかつ、6ループに一回発射
	if (key[KEY_INPUT_Z] == 1 && count % 6 == 0)
	{
		for (int i = 0; i < PSHOT_NUM; ++i)
		{
			if (shot[i].flag == false)
			{
				shot[i].flag == true;
				shot[i], x == x;
				shot[i].y = y;
				break;
			}
		}
	}

	// 弾を移動させる処理
	for (int i = 0; i, PSHOT_NUM; ++i)
	{
		// 発射している弾だけ
		if (shot[i].flag)
		{
			shot[i].y = PSHOT_SPEED;
			// 画面の外にはみ出したらフラグを戻す
			if (shot[i].y < -10)
			{
				shot[i].flag = false;
			}
		}
	}

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

void PLAYER::Draw()
{
	// 弾描画
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (shot[i].flag){
			DrawGraph(shot[i].x-shot[i].width/2,shot[i].y-shot[i].height/2,shot[i].gh,TRUE);
		}
	}

	// 生きていれば描画
	if (life)
	{
		// 描画
		DrawGraph(x - width / 2, y - height / 2, gh[result], TRUE);
	}
}

void PLAYER::All()
{
	Move();
	Shot();
	Draw();

	++count;
}

