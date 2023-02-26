#include "../library/SystemLib/define.h"

#ifndef _ENEMY
#define _ENEMY

class ENEMY
{
private:
	// ���W�ƃO���t�B�b�N�n���h��
	double x, y;
	int gh[3];

	// �摜�T�C�Y
	int width, height;

	// �o���A��~�A�A�ҁA���˃^�C�~���O
	int in_time, stop_time, out_time, shot_time;
	
	// �G�̎��
	int type;

	// �e�̎��
	int stype;
	// �ړ��p�^�[��
	int m_pattern;	// move_pattern
	// �V���b�g�p�^�[��
	int s_pattern;	// shot_pattern
	// HP
	int hp;
	// �A�C�e��
	int item;

	// �G���o�����Ă���̃J�E���g
	int count;

	// ���˂����e��
	int num;
	// ���˒���̃��W�A��
	double rad;

	// �G���Ńt���O
	bool deadflag;
	// �G�N���X���Ńt���O
	bool endflag;

	// �e�\����
	E_SHOT shot[ENEMY_SNUM];

	// �V���b�g���łĂ�悤�ɂȂ������̃t���O
	bool sflag;
	// �V���b�g���łĂ�悤�ɂȂ��Ă���̃J�E���g
	int scount;

private:
	void Move();
	void Shot();
	void Draw();
	bool OutCheck();
	bool ShotOutCheck(int i);

public:
	bool All();
	void GetPosition(double* x, double* y);
	ENEMY(int type,int stype,int m_pattern,int s_pattern,
		int in_time,int stop_time, int shot_time,int out_time,int x, int y,int speed,int hp, int item);
};

#endif // !_ENEMY
