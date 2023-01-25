#include "DxLib.h"
#include "player.h"

void PLAYER::Move()
{
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1)
	{
		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1)
		{
			// �ړ��W���� 0.71 �ɐݒ�
			move = 0.71f;
		}
		else {
			// �΂߂���Ȃ���� 1.0 �ɌŒ�
			move = 1.0f;
		}
	}
	else if(key[KEY_INPUT_UP]==1	||	key[KEY_INPUT_DOWN]==1){
		move = 1.0;
	}

	// �������̈ړ��Ȃ̂� "x"
	if (key[KEY_INPUT_LEFT] == 1) {
		 x -= (int)PLAYER_SPEED*move;
		
	}
	if (key[KEY_INPUT_RIGHT] == 1) {
		x += (int)PLAYER_SPEED * move;

	}
	// �c�����̈ړ��Ȃ̂� "y"
	if (key[KEY_INPUT_UP] == 1) {
		y -= (int)PLAYER_SPEED * move;

	}
	if (key[KEY_INPUT_DOWN] == 1) {
		y += (int)PLAYER_SPEED * move;
	}


	// ���L�[��������Ă��āA���� xcount ��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_LEFT] == 1) {
		if (xcount > 0)
			xcount = 0;
		--xcount;

	}
	// �E�L�[��������Ă��āA���� xcount ��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_RIGHT] == 1) {
		if (xcount < 0);
			xcount = 0;
		++xcount;
	}
	// ���L�[��������Ă��āA���� ycount ��0�ȏ�Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_UP] == 1) {
		if (ycount > 0)
			ycount = 0;
		--ycount;

	}
	// �E�L�[��������Ă��āA���� ycount ��0�ȉ��Ȃ�0�ɂ��Ă���1����
	// ����ȊO��1����
	if (key[KEY_INPUT_DOWN] == 1) {
		if (ycount < 0);
			ycount = 0;
		++ycount;
	}


	// �J�E���g������Y�������߂�
	ix = abs(xcount) % 30 / 10;
	iy = abs(ycount) % 30 / 10;

	// x�J�E���g���v���X�Ȃ�E�����Ȃ̂�2�s�ڂ̐擪�Y���ԍ��𑫂��B
	if (xcount > 0)
	{
		ix += 3;
		result = ix;
	}else if(xcount<0){
		// �}�C�i�X�Ȃ獶�����Ȃ̂ŁA4�s�ڂ̐擪�Y���ԍ��𑫂��B
		ix += 9;
	}
	// y�J�E���g���v���X�Ȃ牺�����Ȃ̂ŁA3�s�ڂ̐擪�Y���ԍ��𑫂��B
		// 1�擪�̓Y���ԍ���0�Ȃ̂ŉ�������K�v�Ȃ��B
}