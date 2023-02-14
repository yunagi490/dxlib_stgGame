#include "../game/player.h"
#include "../game/back.h"
#include "../game/enemy.h"

class CONTROL
{
private:
	// プレイヤークラスのポインタ
	PLAYER *player;

	// 背景クラス
	BACK *back;

	// 敵クラス
	ENEMY *enemy;

public:
	CONTROL();
	~CONTROL();
	void All();
};

