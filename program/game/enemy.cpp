#include "enemy.h"
#include "../library/SystemLib/define.h"
#include "../library/SystemLib/pch.h"

#include "DxLib.h"

ENEMY::ENEMY()
{
	LoadGraph("../graphics/n_enemy1.png", TRUE);

	width = 128;
	height = 128;

	x = 50;
	y = 50;

	in_time = 180;
	stop_time = 300;
	out_time = 420;

	count = 0;
	endflag = false;
}

void ENEMY::Move()
{
	// o‚Ä‚«‚Ä‚©‚ç”‘‚Ü‚éŠÔ‚Ü‚Å‚ÌŠÔ‚È‚ç‰º‚ÉˆÚ“®
	if (in_time < g_count && g_count < stop_time)
	{
		y + 2;
		// ‹AŠÒŠÔ‚ğ‰ß‚¬‚½‚ç–ß‚é
	}
	else if (g_count > out_time) {
		y -= 2;
		if(y<40)
		{
			endflag = true;
		}
	}

}