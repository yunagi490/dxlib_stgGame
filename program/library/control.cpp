#include "../library/SystemLib/pch.h"
#include "control.h"
#include "DxLib.h"
#include "../library/SystemLib/define.h"

#include "../game/player.h"
#include "../game/enemy.h"

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
	
	// �w�肵���Y���̓G�̍��W���擾
	enemy[index]->GetPosition(&tempx, &tempy);


	// ���
	*x = tempx;
	*y = tempy;
}


