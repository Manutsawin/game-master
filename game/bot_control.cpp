#include "bot_control.h"
int fucbotcontrol(float xplayer, float xenamy, int level, int J, int potion, float potionX, float potionY,int enamydirect)
{
	// 1 move right // 2 move left // 3 jump // 4 PG // 5 flash // 6 J-acctack // 7 U skill
	if (level == 1)
	{
		

		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
			printf("4\n");
			return 4;
		}
		
		if (potion == 1)
		{
			if (xenamy < potionX - 5)
			{
				if (enamydirect == 1 || enamydirect == 11)
				{
					return 5;
				}
				printf("1\n");
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				printf("2\n");
				return 2; //move left
			}
			return 3;

		}
		
		
		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			printf("6\n");
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			printf("2\n");
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			printf("1\n");
			return 1; //move right
		}
			
		
		printf("0\n");
		return 0;
		
	}
	else if (level>0)
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