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
public:
	void All();
	void GetPlayerPosition(double* x, double* y);
	void GetEnemyPosition(int index, double* x, double* y);
	static CONTROL& GetInstance()
	{
		static CONTROL control;
		return control;
	}
};
