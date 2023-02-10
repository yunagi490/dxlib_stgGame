#define PLAYER_SPEED 4
#define MARGIN 10
#define SCROLL_SPEED 2
#define PSHOT_NUM 20
struct Shot
{
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