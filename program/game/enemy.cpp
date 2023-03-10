#include "enemy.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"
#include "DxLib.h"

ENEMY::ENEMY()
{
	LoadGraph("../graphics/n_enemy1.png", TRUE);

	width = 128;
	height = 128;

	x = 50;
	y = 50;

	in_time = 180;
	stop_time = 300;
	out_time = 420;

	count = 0;
	endflag = false;
}

void ENEMY::Move()
{
	// 出てきてから泊まる時間までの間なら下に移動
	if (in_time < g_count && g_count < stop_time)
	{
		y + 2;
		// 帰還時間を過ぎたら戻る
	}
	else if (g_count > out_time) {
		y -= 2;
		if(y<40)
		{
			endflag = true;
		}
	}
}

void ENEMY::Draw()
{
	int temp;
	if (!endflag) {

		temp = count % 40 / 10;
		if (temp == 3)
			temp = 1;

		DrawGraph(x, y, gh[temp], TRUE);
	}
}

bool ENEMY::All()
{
	Move();
	Draw();
	++count;
	return endflag;
}
