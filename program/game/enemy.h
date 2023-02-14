class ENEMY
{
private:
	double x, y;
	int gh[3];

	int width, height;
	int in_time, stop_time, out_time;
	int count;
	int g_count;
	bool endflag;

public:
	bool All();
	void Move();
	void Draw();
	ENEMY();
};