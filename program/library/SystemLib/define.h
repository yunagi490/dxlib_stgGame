#define PLAYER_SPEED 4
#define MARGIN 10
#define SCROLL_SPEED 2
#define PSHOT_NUM 20
struct Shot
{
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