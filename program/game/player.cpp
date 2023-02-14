#include "player.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"

#include "DxLib.h"

PLAYER::PLAYER()
{
	// �摜�ǂݍ���
	LoadGraph("../graphics/player1.png",TRUE);

	width = 64;
	height = 64;

	// �ړ��W��
	move = 1.0f;

	// �������Əc�����̃J�E���g��
	xcount = 0, ycount = 0;
	// �Y���p�ϐ�
	ix = 0, iy = 0, result = 0;

	// �����ʒu
	x = 180;
	y = 400;

	// �����Ă邩�ǂ���
	life = true;

	// �e������
	memset(shot, 0, sizeof(shot));

	// �e�摜�ǂݍ���
	int temp = LoadGraph("../graphics/shot.png");
	/// w=Width, h= Height
	int w, h;
	GetGraphSize(temp, &w, &h);

	// �t���O��S��False�ɂ���
	// �O���t�B�b�N�n���h���Ɖ摜�̃T�C�Y�������Ƃ�
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		shot[i].flag = false;
		shot[i].gh = temp;
		shot[i].width = w;
		shot[i].height = h;
	}

	count=0;
}

void PLAYER::Shot()
{
	// �L�[��������Ă��Ă��A6���[�v�Ɉ�񔭎�
	if (key[KEY_INPUT_Z] == 1 && count % 6 == 0)
	{
		for (int i = 0; i < PSHOT_NUM; ++i)
		{
			if (shot[i].flag == false)
			{
				shot[i].flag == true;
				shot[i], x == x;
				shot[i].y = y;
				break;
			}
		}
	}

	// �e���ړ������鏈��
	for (int i = 0; i, PSHOT_NUM; ++i)
	{
		// ���˂��Ă���e����
		if (shot[i].flag)
		{
			shot[i].y = PSHOT_SPEED;
			// ��ʂ̊O�ɂ͂ݏo������t���O��߂�
			if (shot[i].y < -10)
			{
				shot[i].flag = false;
			}
		}
	}

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

void PLAYER::Draw()
{
	// �e�`��
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (shot[i].flag){
			DrawGraph(shot[i].x-shot[i].width/2,shot[i].y-shot[i].height/2,shot[i].gh,TRUE);
		}
	}

	// �����Ă���Ε`��
	if (life)
	{
		// �`��
		DrawGraph(x - width / 2, y - height / 2, gh[result], TRUE);
	}
}

void PLAYER::All()
{
	Move();
	Shot();
	Draw();

	++count;
}

