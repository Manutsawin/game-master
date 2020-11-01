#include "bot_control.h"
int fucbotcontrol(float xplayer,float xenamy,int level)
{
	if (level == 1)
	{
		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6;
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}
	}
	else
	{
		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6;
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}
	}
	
}