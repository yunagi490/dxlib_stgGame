#include "../library/SystemLib/pch.h"
#include "control.h"
#include "DxLib.h"
#include "../library/SystemLib/define.h"

#include "../game/player.h"
#include "../game/enemy.h"

CONTROL::CONTROL()
{
	// プレイヤークラスの生成
	player = new PLAYER;
	
	// 背景クラスの生成
	back = new BACK;

	// 敵クラスの生成
	enemy = new ENEMY;
}
CONTROL::~CONTROL()
{
	// プレイヤークラスの解放
	delete player;
}
void CONTROL::All()
{
	// 描画領域を指定
	SetDrawArea(MARGIN, MARGIN, MARGIN + 380, MARGIN + 460);

	// 背景クラスのAll関数実行
	back->All();

	// プレイヤークラスのAll関数実行
	player->All();

	if (enemy != NULL) {
		if (enemy->All()) {
			delete enemy;
			enemy = NULL;
		}
	}

	++g_count;
}

void CONTROL::GetPlayerPosition(double* x, double* y)
{
	double tempx, tempy;

	player->GetPosition(&tempx, &tempy);

	*x = tempx;
	*y = tempy;
}
void CONTROL::GetEnemyPosition(int index, double* x, double* y)
{
	double tempx, tempy;
	
	// 指定した添字の敵の座標を取得
	enemy[index]->GetPosition(&tempx, &tempy);


	// 代入
	*x = tempx;
	*y = tempy;
}


