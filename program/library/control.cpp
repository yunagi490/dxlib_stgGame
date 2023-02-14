#include "../library/SystemLib/pch.h"
#include "control.h"
#include "DxLib.h"
#include "../library/SystemLib/define.h"

CONTROL::CONTROL()
{
	// �v���C���[�N���X�̐���
	player = new PLAYER;
	
	// �w�i�N���X�̐���
	back = new BACK;

	// �G�N���X�̐���
	enemy = new ENEMY;
}
CONTROL::~CONTROL()
{
	// �v���C���[�N���X�̉��
	delete player;
}
void CONTROL::All()
{
	// �`��̈���w��
	SetDrawArea(MARGIN, MARGIN, MARGIN + 380, MARGIN + 460);

	// �w�i�N���X��All�֐����s
	back->All();

	// �v���C���[�N���X��All�֐����s
	player->All();

	// �G�N���X��All�֐����s
	enemy -> All();
}




