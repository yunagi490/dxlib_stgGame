class PLAYER {
private:
	// x���W, y���W
	double x, y;

	// �摜��
	int width, height;

	// �O���t�B�b�N�n���h���i�[�p�z��
	int gh[12];

	// �L�[�擾�p�z��
	char key[256];

	// �v���C���[�̑���
	char PLAYER_SPEED = 4;

	// �ړ��W��
	float move;

	// �������Əc�����̃J�E���g���B
	int xcount, ycount;

	//�Y���p�ϐ�
	int ix, iy, result;

	// �����Ă邩�ǂ����̃t���O
	bool life;

private:
	void Move();
	void Draw();

public:
	PLAYER();
	void All();
};