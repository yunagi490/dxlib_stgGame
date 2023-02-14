#include "../library/SystemLib/pch.h"
#include "control.h"
#include "DxLib.h"
#include "../library/SystemLib/define.h"

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

	// 敵クラスのAll関数実行
	enemy -> All();
}




