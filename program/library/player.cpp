#include "player.h"
#include "DxLib.h"

PLAYER::PLAYER()
{
	// �摜�ǂݍ���
	if (-1 == LoadDivGraph("", 12, 3, 4, 29, 40, gh)) {
		MSG("�G���[����");
	}

	width = 29;
	height = 40;

	// �ړ��W��
	move = 1.0f;

	// �������Əc�����̃J�E���g��
	xcount = 0, ycount = 0;
	// �Y���p�ϐ�
	ix = 0, iy = 0, result = 0;

	// �����ʒu
	x = 180;
	y = 400;

	life = true;
}

