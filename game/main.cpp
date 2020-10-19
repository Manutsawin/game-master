#include <SFML/Graphics.hpp>
#include<windows.h>
#include<stdio.h>
#include"skill_player.h"
#include"Fuc.h"


struct charecter
{
	float x= 0, y= 530;
	float jump = 1.1;//speed of jump
	sf::Texture Texture;
	sf::IntRect rectSource;

} player1,enamy1  ,BG   ,hpBar_player,hpBar_enamy, manaBar_player, manaBar_enamy  ,skillthrow,   skillicon_enamy, skillicon_player;

sf::RenderWindow window(sf::VideoMode(1200, 800), "Road to champions");
sf::RectangleShape sprite_BG(sf::Vector2f(1200.0f,800.0f));

//charecter
sf::RectangleShape sprite_player1(sf::Vector2f(160.0f, 120.0f));
sf::RectangleShape sprite_enamy(sf::Vector2f(160.0f, 120.0f));

//HP
sf::RectangleShape sprite_hpBar_enamy(sf::Vector2f(500.0f, 40.0f));
sf::RectangleShape sprite_hpBar_player(sf::Vector2f(500.0f, 40.0f));

//Mana
sf::RectangleShape sprite_manaBar_enamy(sf::Vector2f(330.0f, 30.0f));
sf::RectangleShape sprite_manaBar_player(sf::Vector2f(330.0f, 30.0f));

//skill icon
sf::RectangleShape sprite_skillicon_enamy(sf::Vector2f(75.0f, 75.0f));
sf::RectangleShape sprite_skillicon_player(sf::Vector2f(75.0f, 75.0f));

//skill
sf::RectangleShape sprite_skillthrow(sf::Vector2f(300.0f, 500.0f));



sf::Clock clock_ani_player, clockJ_player , clock_ani_enamy, clockJ_enamy;

//movement control player
int Stay_player_Fuc(int);
int move_Right_player_Fuc(int);
int move_Left_player_Fuc(int);
int Jump_player_Fuc(int);
void PG_player_Fuc();
int Flash_player_Fuc(int);
int J_attack_player_Fuc(int);
void U_player_Fuc();

//movement control enamy
void enamystun();
int Stay_enamy_Fuc(int);

//int move_Right_player_Fuc(int);
//int move_Left_player_Fuc(int);
//int Jump_player_Fuc(int);
//void PG_player_Fuc();
//int Flash_player_Fuc(int);
//int J_attack_player_Fuc(int);
//void U_player_Fuc();

void control();
void draw_pic();
void setup();
void hpbar(float);
void hpbar_enamy(float);
void manabar(float);
void manabar_enamy(float);

struct Vector
{
	int direct = 0;
} player , enamy , jump_player , PG_player , J_player ,Uskill_player   ,stun_enamy,stun_player;

int combo_player, combo_enamy = 0;
int damage_player=0, total_hp_playyer =23, damage_enamy = 0, total_hp_enamy = 23; //hp = 1 lose

int manaDel_player = 0, total_mana_playyer = 26, manaDel_enamy = 0, total_mana_enamy = 26;// mana

float deltatime_player_skill = 0.0f;
float x_playercheak,y_playercheak, x_enamycheak, y_enamycheak, x_skillthrowcheak, y_skillthrowcheak;
sf::Clock skill_player_clock;
sf::Clock enamy_stun_clock;

int main()
{
	//skill
	
	setup();
	skill animetion(&skillthrow.Texture, sf::Vector2u(4, 1), 0.1f);
	

	
	while (window.isOpen())
	{
		while (total_hp_playyer > 1)
		{
			//cheak position player
			if (player.direct == 1 || player.direct == 11)
			{
				x_playercheak = player1.x + 80;
			}
			else
			{
				x_playercheak = player1.x - 80;
			}
			//cheak position enamy
			if (enamy.direct == 1 || enamy.direct == 11)
			{
				x_enamycheak = enamy1.x + 80;
			}
			else
			{
				x_enamycheak = enamy1.x - 80;
			}
			//cheak position skillthrow
			if (Uskill_player.direct == 1)
			{
				x_skillthrowcheak = skillthrow.x + 200;
			}
			else
			{
				x_skillthrowcheak = skillthrow.x - 200;
			}

			deltatime_player_skill = skill_player_clock.restart().asSeconds();
			
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (event.type == sf::Event::TextEntered)
				{
					//printf("%c\n", event.text.unicode);
					//printf("x= %f  y=%f\n", x_playercheak, player1.y);

				}
			}
			//printf("x= %f  y=%f\t", x_playercheak, player1.y);
			//printf("x= %f  y=%f\t", x_enamycheak, enamy1.y);
			//printf("x= %f  y=%f\n", x_skillthrowcheak, skillthrow.y);
			animetion.Update(0, deltatime_player_skill);
			sprite_skillthrow.setTextureRect(animetion.uvRect);
			draw_pic();
			damage_player = 0;
			damage_enamy = 0;
			manaDel_player = 0;
			manaDel_enamy = 0;
			control();

		}
	}	
	
	return 0;
}
void setup()
{
	//skill
	
	skillthrow.Texture.loadFromFile("skill/fireball.png");
	sprite_skillthrow.setTexture(&skillthrow.Texture);
	
	//skill icon
	skillicon_player.Texture.loadFromFile("skill icon/ichigozall.png");
	skillicon_enamy.Texture.loadFromFile("skill icon/ichigozall.png");

	skillicon_enamy.rectSource.top = 0;
	skillicon_enamy.rectSource.left = 0;
	skillicon_enamy.rectSource.width = 200;
	skillicon_enamy.rectSource.height = 200;
	sprite_skillicon_enamy.setTexture(&skillicon_enamy.Texture);
	sprite_skillicon_enamy.setPosition(1070, 100);
	sprite_skillicon_enamy.setTextureRect(skillicon_enamy.rectSource);

	skillicon_player.rectSource.top = 0;
	skillicon_player.rectSource.left = 0;
	skillicon_player.rectSource.width = 200;
	skillicon_player.rectSource.height = 200;
	sprite_skillicon_player.setTexture(&skillicon_player.Texture);
	sprite_skillicon_player.setPosition(55, 100);
	sprite_skillicon_player.setTextureRect(skillicon_player.rectSource);
	
	//player setup
	player.direct = 1;
	enamy.direct = 2;
	sprite_enamy.setScale({ -1, 1 });
	//player.setFillColor(sf::Color::Cyan);
	
	//BG
	BG.rectSource.top = 10;
	BG.rectSource.left = 200;
	BG.rectSource.width = 300;
	BG.rectSource.height = 200;

	BG.Texture.loadFromFile("Map/1.png");
	sprite_BG.setTexture(&BG.Texture);
	sprite_BG.setTextureRect(BG.rectSource);

	//player
	player1.x = 0;
	player1.rectSource.top = 0;
	player1.rectSource.left = 35;
	player1.rectSource.width = 80;
	player1.rectSource.height = 60;

	player1.Texture.loadFromFile("Textures/12.png");
	sprite_player1.setTexture(&player1.Texture);
	sprite_player1.setTextureRect(player1.rectSource);

	//enamy
	enamy1.x = 700;
	enamy1.rectSource.top = 0;
	enamy1.rectSource.left = 35;
	enamy1.rectSource.width = 80;
	enamy1.rectSource.height = 60;

	enamy1.Texture.loadFromFile("Textures/12.png");
	sprite_enamy.setTexture(&enamy1.Texture);
	sprite_enamy.setTextureRect(enamy1.rectSource);

	//hp_player
	hpBar_player.Texture.loadFromFile("HP/hpall.png");
	//hp_enamy
	hpBar_enamy.Texture.loadFromFile("HP/hpall.png");

	//mana_player
	manaBar_player.Texture.loadFromFile("HP/manaall.png");
	//mana_enamy
	manaBar_enamy.Texture.loadFromFile("HP/manaall.png");

	
}
void draw_pic()
{
	
	

	sprite_player1.setPosition(player1.x, player1.y);
	sprite_enamy.setPosition(enamy1.x, enamy1.y);

	sprite_skillthrow.setPosition(skillthrow.x, player1.y);
	
	//hp player
	total_hp_playyer = hpcalculate(damage_player, total_hp_playyer);
	hpbar(total_hp_playyer);
	//hp enamy
	total_hp_enamy = hpcalculate(damage_enamy, total_hp_enamy);
	hpbar_enamy(total_hp_enamy);

	//mana player
	total_mana_playyer = manacalculate(manaDel_player, total_mana_playyer);
	manabar(total_mana_playyer);
	//mana enamy
	total_mana_enamy = manacalculate(manaDel_enamy, total_mana_enamy);
	manabar_enamy(total_mana_enamy);


	window.clear();
	window.draw(sprite_BG);

	window.draw(sprite_enamy);
	window.draw(sprite_player1);
	
	if (Uskill_player.direct == 1|| Uskill_player.direct == 2)
	{
		window.draw(sprite_skillthrow);
	}

	window.draw(sprite_hpBar_player);
	window.draw(sprite_hpBar_enamy);
	window.draw(sprite_manaBar_player);
	window.draw(sprite_manaBar_enamy);

	//skill icon player
	skillicon_player.rectSource.top = selectIcon(total_mana_playyer);
	sprite_skillicon_player.setTextureRect(skillicon_player.rectSource);
	window.draw(sprite_skillicon_player);
	//skill icon enamy
	skillicon_enamy.rectSource.top = selectIcon(total_mana_enamy);
	sprite_skillicon_enamy.setTextureRect(skillicon_enamy.rectSource);
	window.draw(sprite_skillicon_enamy);
	
	window.display();
}

void control()
{
	
	sprite_player1.setTextureRect(player1.rectSource);
	sprite_enamy.setTextureRect(enamy1.rectSource);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = move_Left_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = move_Right_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
	{
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			jump_player.direct = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
	{
		
		combo_player = 0;
		if (J_player.direct != 1&& jump_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = Flash_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
	{
		if (J_player.direct == 0 && jump_player.direct != 1 && PG_player.direct != 1 &&combo_player<3)
		{
			player.direct = Stay_player_Fuc(player.direct);
			J_player.direct = 1;
			clockJ_player.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		combo_player = 0;
		PG_player_Fuc();
		PG_player.direct = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U) && total_mana_playyer > 6)
	{
		if (Uskill_player.direct != 1 && Uskill_player.direct != 2)
		{
			combo_player = 0;
			U_player_Fuc(); //edit

			if (Uskill_player.direct != 22 && Uskill_player.direct != 11)
			{
				manaDel_player += 7;
			}

			if (player.direct == 1 || player.direct == 11)
			{
				sprite_skillthrow.setScale({ 1, 1 });
				skillthrow.x = x_playercheak;
				Uskill_player.direct = 11;
				
			}
			else
			{
				sprite_skillthrow.setScale({ -1, 1 });
				skillthrow.x = x_playercheak;
				Uskill_player.direct = 22;
				
			}


		}
		
		
	}
	else if (J_player.direct != 1)
	{
		
		if (PG_player.direct == 1 || Uskill_player.direct == 11|| Uskill_player.direct == 22)
		{
			player1.rectSource.left = 35; // left default
			PG_player.direct = 0;
			if (Uskill_player.direct == 11)
			{
				Uskill_player.direct = 1;
			}
			else if(Uskill_player.direct == 22)
			{
				Uskill_player.direct = 2;
			}
			
		}
		player1.rectSource.top = 0; // top default
		player.direct = Stay_player_Fuc(player.direct);
	}

	enamy.direct = Stay_enamy_Fuc(enamy.direct);//test anime bot

	if (J_player.direct == 1)
	{

		if (clockJ_player.getElapsedTime().asSeconds() > 0.65f)
		{
			J_player.direct = 0;
			clockJ_player.restart();
			player1.rectSource.top = 0;  // top default
			player.direct = Stay_player_Fuc(player.direct);
			combo_player++;

			if (player.direct == 1 || player.direct == 11)
			{
				if (x_playercheak + 120 >= x_enamycheak && x_enamycheak > x_playercheak-40)
				{
					damage_enamy++;
					
					stun_enamy.direct = 1;
					enamy_stun_clock.restart();
				}
			}
			else
			{
				if (x_playercheak - 120 <= x_enamycheak && x_enamycheak < x_playercheak+40)
				{
					damage_enamy++;

					stun_enamy.direct = 1;
					enamy_stun_clock.restart();
				}
			}


		}
		else
		{
			player.direct = J_attack_player_Fuc(player.direct);
		}

	}
	
	//skill player cheack
	if (Uskill_player.direct == 1)
	{
		skillthrow.x += 4.0f;
	}
	else if (Uskill_player.direct == 2)
	{
		skillthrow.x -= 4.0f;
	}

	if (skillthrow.x < 0 || skillthrow.x>1200)
	{
		Uskill_player.direct = 0;
	}
	// cheack skill position vs enamy
	if (x_skillthrowcheak < x_enamycheak + 4 && x_skillthrowcheak >= x_enamycheak)
	{
		damage_enamy += 3;
		stun_enamy.direct = 1;
		enamy_stun_clock.restart();
	}
	//------------------------------------------------

	if (stun_enamy.direct == 1)
	{
		enamystun();
	}


	jump_player.direct = Jump_player_Fuc(jump_player.direct);

}
int Stay_player_Fuc(int direct)
{
	if (direct == 1 || direct == 2)
	{
		player1.rectSource.left = 35; //left default left 
		if (direct == 1)
		{
			direct = 11;
		}
		else
		{
			direct = 22;
		}

	}
	if (clock_ani_player.getElapsedTime().asSeconds() > 0.150f)
	{
		if (player1.rectSource.left == 431) //stay max left 
		{
			player1.rectSource.left = 35; //stay default left 
			combo_player = 0;
		}
		else
		{
			player1.rectSource.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();
		
		
	}
	return direct;

}

int Stay_enamy_Fuc(int direct)
{
	if (direct == 1 || direct == 2)
	{
		enamy1.rectSource.left = 35; //left default left 
		if (direct == 1)
		{
			direct = 11;
		}
		else
		{
			direct = 22;
		}

	}
	if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.150f)
	{
		if (enamy1.rectSource.left == 431) //stay max left 
		{
			enamy1.rectSource.left = 35; //stay default left 
			combo_enamy = 0;
		}
		else
		{
			enamy1.rectSource.left += 132; //plus left 
		}
		sprite_enamy.setTextureRect(enamy1.rectSource);
		clock_ani_enamy.restart();


	}
	return direct;

}

int move_Right_player_Fuc(int direct)
{
	
	if (direct == 11)
	{
		player1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 1 && direct != 11)
	{
		player1.x -= 160;
		sprite_player1.setScale({ 1, 1 });
		player1.rectSource.left = 563; //move left,right default left 

	}
	direct = 1;
	if (player1.x < 1040)
	{
		player1.x += 0.5f;
	}

	if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSource.left == 1091) //move left,right max left 
		{
			player1.rectSource.left = 563; //move left,right default left 
		}
		else
		{
			player1.rectSource.left += 132; //plus left 
		}
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();


	}

	return direct;
}

int move_Left_player_Fuc(int direct)
{
	
	
	if (direct == 22)
	{
		player1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 2 && direct != 22)
	{
		player1.x += 160;
		sprite_player1.setScale({ -1, 1 });
		player1.rectSource.left = 563; //move left,right default left 
	}
	direct = 2;
	if (player1.x >= 160)
	{
		player1.x += -0.5f;
	}
	
	if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
	{
		if (player1.rectSource.left == 1091) //move left,right max left 
		{
			player1.rectSource.left = 563; //move left,right default left 

		}
		else
		{
			player1.rectSource.left += 132; //plus
		}
		
		sprite_player1.setTextureRect(player1.rectSource);
		clock_ani_player.restart();


	}

	return direct;
}
int Jump_player_Fuc(int directjump)
{
	
	if (directjump == 1)
	{
		player1.rectSource.top = 200; 
		player1.rectSource.left = 35; //jump defualt left 

		player1.y -= player1.jump;
		if (player1.y < 390)
		{
			player1.jump = player1.jump * -1;
		}
		else if (player1.y >= 530 && player1.jump < 0)
		{
			directjump = 0;
			player1.jump = player1.jump * -1;
			player1.y = 530;
			player1.rectSource.top = 0; // top defualt 
		}

	}
	return directjump;
}

void PG_player_Fuc()
{
	player1.rectSource.top = 100; //PG top
	player1.rectSource.left = 695;//PG left
	
}

void U_player_Fuc()
{
	player1.rectSource.top = 739; 
	player1.rectSource.left = 1223;

}
void enamystun()
{
	if (enamy_stun_clock.getElapsedTime().asSeconds() > 0.700f)
	{
		stun_enamy.direct = 0;
		enamy1.rectSource.top = 0;
		enamy1.rectSource.left = 35;
	}
	else
	{
		enamy1.rectSource.top = 739; 
		enamy1.rectSource.left = 1223;
	}
	
}

int Flash_player_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSource.left = 563; //move left,right default left

		}
		direct = 1;

		if (player1.x < 1040)
		{
			player1.x += 3.0f;
		}

		if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSource.left == 1091) //move left,right  max left
			{
				player1.rectSource.left = 563; //move left,right default left
			}
			else
			{
				player1.rectSource.left += 132; // plus left 
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();


		}

		return direct;
	}

	if (direct == 2 || direct == 22)
	{

		if (direct == 22)
		{
			player1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSource.left = 563; //move left,right default left
		}
		direct = 2;
		if (player1.x >= 160)
		{
			player1.x += -3.0f;
		}
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.100f)
		{
			if (player1.rectSource.left == 1091) //move left,right max left
			{
				player1.rectSource.left = 563; //move left,right default left

			}
			else
			{
				player1.rectSource.left += 132; //plus left
			}

			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();


		}

		return direct;
	}
	
}
int J_attack_player_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			player1.rectSource.left = 563; //attack  default left
			player1.rectSource.top = 950; //attack  default top
		}
		if (direct != 1 && direct != 11)
		{
			player1.x -= 160;
			sprite_player1.setScale({ 1, 1 });
			player1.rectSource.left = 563; //attack  default left
		}
		if (player1.x < 1040)
		{
			player1.x += 0.03f;
		}
		direct = 1;
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSource.left == 1223) //attack  max left
			{
				player1.rectSource.left = 563; //attack  default left
			}
			else
			{
				player1.rectSource.left += 132; // plus left
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();
		}

		return direct;
	}
	if (direct == 2 || direct == 22)
	{
		if (direct == 22)
		{
			player1.rectSource.left = 563; //attack  default left
			player1.rectSource.top = 950; //attack  default top
		}
		if (direct != 2 && direct != 22)
		{
			player1.x += 160;
			sprite_player1.setScale({ -1, 1 });
			player1.rectSource.left = 563; //attack  default left
		}
		if (player1.x >= 160)
		{
			player1.x += -0.03f;
		}
		direct = 2;
		if (clock_ani_player.getElapsedTime().asSeconds() > 0.120f)
		{
			if (player1.rectSource.left == 1223) //attack  max left
			{
				player1.rectSource.left = 563; //attack  default left
			}
			else
			{
				player1.rectSource.left += 132; //plus left
			}
			sprite_player1.setTextureRect(player1.rectSource);
			clock_ani_player.restart();
		}
		return direct;
	}

}
void hpbar(float total_hp)
{
	hpBar_player.rectSource.top = (total_hp-1)*40;
	hpBar_player.rectSource.left = 0;
	hpBar_player.rectSource.width = 500;
	hpBar_player.rectSource.height = 40;
	sprite_hpBar_player.setTexture(&hpBar_player.Texture);
	sprite_hpBar_player.setPosition(15, 35);
	sprite_hpBar_player.setTextureRect(hpBar_player.rectSource);
}
void hpbar_enamy(float total_hp)
{
	hpBar_enamy.rectSource.top = (total_hp - 1) * 40;
	hpBar_enamy.rectSource.left = 0;
	hpBar_enamy.rectSource.width = 500;
	hpBar_enamy.rectSource.height = 40;
	sprite_hpBar_enamy.setScale({ -1, 1 });
	sprite_hpBar_enamy.setTexture(&hpBar_enamy.Texture);
	sprite_hpBar_enamy.setPosition(1185, 35);
	sprite_hpBar_enamy.setTextureRect(hpBar_enamy.rectSource);
}

void manabar(float total_mana)
{
	manaBar_player.rectSource.top = (total_mana - 1) * 40;
	manaBar_player.rectSource.left = 0;
	manaBar_player.rectSource.width = 500;
	manaBar_player.rectSource.height = 40;
	sprite_manaBar_player.setTexture(&manaBar_player.Texture);
	sprite_manaBar_player.setPosition(15, 750);
	sprite_manaBar_player.setTextureRect(manaBar_player.rectSource);
}

void manabar_enamy(float total_mana)
{
	manaBar_enamy.rectSource.top = (total_mana - 1) * 40;
	manaBar_enamy.rectSource.left = 0;
	manaBar_enamy.rectSource.width = 500;
	manaBar_enamy.rectSource.height = 40;
	sprite_manaBar_enamy.setScale({ -1, 1 });
	sprite_manaBar_enamy.setTexture(&manaBar_enamy.Texture);
	sprite_manaBar_enamy.setPosition(1185, 750);
	sprite_manaBar_enamy.setTextureRect(manaBar_enamy.rectSource);
}

