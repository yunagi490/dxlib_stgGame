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
	// 弾が発射中かどうか
	bool flag;
	
	// x座標
	double x;

	// y座標
	double y;

	// グラフィックハンドル
	int gh;

	// 画像の幅と高さ
	int width, height;
};

struct E_SHOT {
public:
	bool flag;	// 弾が発射するかどうか
	double x;	// x座標
	double y;	// y座標
	double rad;	// 角度(ラジアン)
	int gh;		// グラフィックハンドル
	int widhth, height;	// 画像の幅と高さ
	int pattern;	// ショットパターン
	int speed; // 弾スピード
};

#define ENEMY_SNUM 50