#include "../game/player.h"
#include "../game/back.h"

class CONTROL
{
private:
	// プレイヤークラスのポインタ
	PLAYER *player;

	// 背景クラス
	BACK *back;
public:
	CONTROL();
	~CONTROL();
	void All();
};

