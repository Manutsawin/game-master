#include "bot_control.h"
int fucbotcontrol(float xplayer, float xenamy, int level, int J, int potion, float potionX, float potionY,int enamydirect,int manaenamy,int hpplayer)
{
	// 1 move right // 2 move left // 3 jump // 4 PG // 5 flash // 6 J-acctack // 7 U skill
	if (level == 1)
	{
		srand(time(NULL));
		int per = ((rand() * rand() + rand() - rand()) % 100);

		if (manaenamy > 7)
		{
			if (per < 50)
			{
				if (xenamy < xplayer)
				{
					if (enamydirect == 1 || enamydirect == 11)
					{
						return 7;
					}
				}
				if (xenamy > xplayer)
				{
					if (enamydirect == 2 || enamydirect == 22)
					{
						return 7;
					}
				}
				
			}
			
		}
		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
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
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				return 2; //move left
			}
			return 3;

		}
		
		
		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}
			
		
		return 0;
		
	}
	
	if (level == 2)
	{
		srand(time(NULL));
		int per = ((rand() * rand() + rand() - rand()) % 100);

		if (manaenamy > 7)
		{
			if (per < 50)
			{
				if (xenamy < xplayer)
				{
					if (enamydirect == 1 || enamydirect == 11)
					{
						return 7;
					}
				}
				if (xenamy > xplayer)
				{
					if (enamydirect == 2 || enamydirect == 22)
					{
						return 7;
					}
				}

			}

		}
		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
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
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				return 2; //move left
			}
			return 3;

		}


		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}


		return 0;

	}

	if (level == 3)
	{
		srand(time(NULL));
		int per = ((rand() * rand() + rand() - rand()) % 100);

		if (manaenamy > 7)
		{
			if (per < 50)
			{
				if (xenamy < xplayer)
				{
					if (enamydirect == 1 || enamydirect == 11)
					{
						return 7;
					}
				}
				if (xenamy > xplayer)
				{
					if (enamydirect == 2 || enamydirect == 22)
					{
						return 7;
					}
				}

			}

		}
		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
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
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				return 2; //move left
			}
			return 3;

		}


		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}


		return 0;

	}

	if (level == 4)
	{
		srand(time(NULL));
		int per = ((rand() * rand() + rand() - rand()) % 100);

		if (manaenamy > 7)
		{
			if (per < 50)
			{
				if (xenamy < xplayer)
				{
					if (enamydirect == 1 || enamydirect == 11)
					{
						return 7;
					}
				}
				if (xenamy > xplayer)
				{
					if (enamydirect == 2 || enamydirect == 22)
					{
						return 7;
					}
				}

			}

		}
		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
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
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				return 2; //move left
			}
			return 3;

		}


		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}


		return 0;

	}

	if (level == 5)
	{
		srand(time(NULL));
		int per = ((rand() * rand() + rand() - rand()) % 100);

		if (manaenamy > 7)
		{
			if (per < 50)
			{
				if (xenamy < xplayer)
				{
					if (enamydirect == 1 || enamydirect == 11)
					{
						return 7;
					}
				}
				if (xenamy > xplayer)
				{
					if (enamydirect == 2 || enamydirect == 22)
					{
						return 7;
					}
				}

			}

		}
		if (J == 1 && xenamy <= xplayer + 100 && xenamy >= xplayer - 100)
		{
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
				return 1; //move Right
			}

			if (xenamy > potionX + 5)
			{
				if (enamydirect == 2 || enamydirect == 22)
				{
					return 5;
				}
				return 2; //move left
			}
			return 3;

		}


		if (xenamy <= xplayer + 70 && xenamy >= xplayer - 70)
		{
			return 6; // J acctack
		}

		if (xenamy > xplayer + 70)
		{
			return 2; //move left
		}

		if (xenamy < xplayer - 70)
		{
			return 1; //move right
		}


		return 0;

	}
	
}