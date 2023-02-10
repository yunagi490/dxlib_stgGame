#include "player.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"

#include "DxLib.h"

PLAYER::PLAYER()
{
	// �摜�ǂݍ���
	if (-1 == LoadDivGraph("", 12, 3, 4, 29, 40, gh)) {
		/// MSG("�G���[����");
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

void PLAYER::Move()
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// �ړ��W����0.71�ɌŒ�
			move = 0.71f;
		}
		else {
			// �΂߂���Ȃ����0.1�ɐݒ�
			move = 0.1f;
		}
	}
	else if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
		move = 1.0f;
	}
	// X��
	if (key[KEY_INPUT_LEFT] == 1)
	{
		x -= (int)PLAYER_SPEED * move;
	}
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		x += (int)PLAYER_SPEED * move;
	}
	// Y��
	if (key[KEY_INPUT_UP] == 1)
	{
		y -= (int)PLAYER_SPEED * move;
	}
	if (key[KEY_INPUT_DOWN] == 1)
	{
		y += (int)PLAYER_SPEED * move;
	}
	


	// ���L�[��������ĂāA����xcount��0�ȏ�Ȃ�0�ɂ��Ă���1�����B
	// ����ȊO��1����
	if (key[KEY_INPUT_LEFT] == 1)
	{
		if (xcount > 0)
			xcount = 0;
		--xcount;
	}
	// �E�L�[��������Ă��āA����xcount��0�ȉ��Ȃ�0�ɂ��Ă���1�����B
	// ����ȊO��1�����B
	if (key[KEY_INPUT_RIGHT] == 1)
	{
		if (xcount < 0)
			xcount = 0;
		++xcount;
	}
	// ��L�[��������Ă��āA����ycount��0�ȏ�Ȃ�0�ɂ��Ă���1�����B
	// ����ȊO��1����
	if (key[KEY_INPUT_UP] == 1)
	{
		if (ycount > 0)
			ycount = 0;
		--ycount;
	}
	// ���L�[��������Ă��āA����ycount��0�ȉ��Ȃ�0�ɂ��Ă���1�����B
	// ����ȊO��1�����B
	if (key[KEY_INPUT_DOWN] == 1)
	{
		if (ycount < 0)
			ycount = 0;
		++ycount;
	}

	// �J�E���g������Y�������߂�
	ix = abs(xcount) % 30 / 10;

}
