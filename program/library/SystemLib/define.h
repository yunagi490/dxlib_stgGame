#define PLAYER_SPEED 4
#define MARGIN 10
#define SCROLL_SPEED 2
#define PSHOT_NUM 20
#define ENEMY_SNUM 5
#define PSHOT_SPEED 14

extern int g_count;

struct SHOT
{
public:
	// �e�����˒����ǂ���
	bool flag;
	
	// x���W
	double x;

	// y���W
	double y;

	// �O���t�B�b�N�n���h��
	int gh;

	// �摜�̕��ƍ���
	int width, height;
};

struct E_SHOT {
public:
	bool flag;	// �e�����˂��邩�ǂ���
	double x;	// x���W
	double y;	// y���W
	double rad;	// �p�x(���W�A��)
	int gh;		// �O���t�B�b�N�n���h��
	int widhth, height;	// �摜�̕��ƍ���
	int pattern;	// �V���b�g�p�^�[��
	int speed; // �e�X�s�[�h
};

#define ENEMY_SNUM 50