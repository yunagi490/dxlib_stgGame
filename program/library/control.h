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
	void All();
};

