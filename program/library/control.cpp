#include "../library/SystemLib/pch.h"
#include "control.h"

CONTROL::CONTROL()
{
	// �v���C���[�N���X�̐���
	player = new PLAYER;
}
CONTROL::~CONTROL()
{
	// �v���C���[�N���X�̉��
	delete player;
}
void CONTROL::All()
{
	// �v���C���[�N���X��All�֐����s
	player->All();
}



