#include "../game/player.h"
#include "../game/back.h"
#include "../game/enemy.h"

class CONTROL
{
private:
	// �v���C���[�N���X�̃|�C���^
	PLAYER *player;

	// �w�i�N���X
	BACK *back;

	// �G�N���X
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
