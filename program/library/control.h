#include "../game/player.h"
#include "../game/back.h"

class CONTROL
{
private:
	// �v���C���[�N���X�̃|�C���^
	PLAYER *player;

	// �w�i�N���X
	BACK *back;
public:
	CONTROL();
	~CONTROL();
	void All();
};

