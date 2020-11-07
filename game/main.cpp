#include <SFML/Graphics.hpp>
#include<windows.h>
#include<stdio.h>
#include"skill_player.h"
#include"Fuc.h"
#include"bot_control.h"
#include"select_enamy.h"
#include "Potion.h"
#include "Menu.h"

//movement control player
void playerstun();
int Stay_player_Fuc(int);
int move_Right_player_Fuc(int);
int move_Left_player_Fuc(int);
int Jump_player_Fuc(int);
void PG_player_Fuc();
int Flash_player_Fuc(int);
int J_attack_player_Fuc(int);
void U_player_Fuc();
void lose_player_Fuc();

//movement control enamy
void enamystun();
int Stay_enamy_Fuc(int);
int move_Right_enamy_Fuc(int);
int move_Left_enamy_Fuc(int);
int Jump_enamy_Fuc(int);
void PG_enamy_Fuc();
int Flash_enamy_Fuc(int);
int J_attack_enamy_Fuc(int);
void U_enamy_Fuc();
void lose_enamy_Fuc();

void control();
void draw_pic();
void setup();
void hpbar(float);
void hpbar_enamy(float);
void manabar(float);
void manabar_enamy(float);

//potion
void Calculation_system_potion();

struct charecter
{
	float x= 0, y= 530;
	float jump = 1.1;//speed of jump
	sf::Texture Texture;
	sf::IntRect rectSource;

} player1,enamy1  
  ,BG   
  ,hpBar_player,hpBar_enamy
  ,manaBar_player, manaBar_enamy  
  ,skillthrow_player, skillthrow_enamy
  ,skillicon_enamy, skillicon_player
  ,victory,defeat,blackscreen1,blackscreen2,nextstage
  ,iconcharecter_player, iconcharecter_enamy
  ,potion;

sf::RenderWindow window(sf::VideoMode(1200,800),"Road to champions");

//BG
sf::RectangleShape sprite_BG(sf::Vector2f(1200.0f,800.0f));

//charecter
sf::RectangleShape sprite_player1(sf::Vector2f(160.0f, 120.0f));
sf::RectangleShape sprite_enamy(sf::Vector2f(160.0f, 120.0f));

//HP
sf::RectangleShape sprite_hpBar_enamy(sf::Vector2f(470.0f, 40.0f));
sf::RectangleShape sprite_hpBar_player(sf::Vector2f(470.0f, 40.0f));

//Mana
sf::RectangleShape sprite_manaBar_enamy(sf::Vector2f(330.0f, 30.0f));
sf::RectangleShape sprite_manaBar_player(sf::Vector2f(330.0f, 30.0f));

//icon charecter
sf::RectangleShape sprite_iconcharecter_enamy(sf::Vector2f(100.0f, 100.0f));
sf::RectangleShape sprite_iconcharecter_player(sf::Vector2f(100.0f, 100.0f));

//skill icon
sf::RectangleShape sprite_skillicon_enamy(sf::Vector2f(50.0f, 50.0f));
sf::RectangleShape sprite_skillicon_player(sf::Vector2f(50.0f, 50.0f));

//skill
sf::RectangleShape sprite_skillthrow_player(sf::Vector2f(300.0f, 500.0f));
sf::RectangleShape sprite_skillthrow_enamy(sf::Vector2f(300.0f, 500.0f));

//potion
sf::RectangleShape sprite_potion(sf::Vector2f(70.0f, 70.0f));

//cvictory and defeat
sf::RectangleShape sprite_victory(sf::Vector2f(600.0f, 200.0f));
sf::RectangleShape sprite_defeat(sf::Vector2f(600.0f, 200.0f));
sf::RectangleShape sprite_blackscreen1(sf::Vector2f(1600.0f, 800.0f));
sf::RectangleShape sprite_blackscreen2(sf::Vector2f(1600.0f, 800.0f));

//nextstage
sf::RectangleShape sprite_nextstage(sf::Vector2f(1200.0f, 800.0f));

sf::Clock clock_ani_player, clockJ_player , clock_ani_enamy, clockJ_enamy;

int level = 1;
sf::Texture enamytext;
int stop = 0;

int typepotion;

struct Vector
{
	int direct = 0;
} player , enamy , jump_player , PG_player , J_player ,Uskill_player   ,stun_enamy,stun_player, jump_enamy, PG_enamy, J_enamy, Uskill_enamy,    blackscreen_2,  potionv;

int combo_player, combo_enamy = 0;
int damage_player=0, total_hp_player =48, damage_enamy = 0, total_hp_enamy = 48; //hp = 1 lose

int manaDel_player = 0, total_mana_playyer = 26, manaDel_enamy = 0, total_mana_enamy = 26;// mana

int cheak_damage_and_J_Player=0, cheak_damage_and_J_enamy = 0;

float deltatime_player_skill = 0.0f;
float x_playercheak,y_playercheak, x_enamycheak, y_enamycheak, x_skillthrowcheak_player, y_skillthrowcheak_player, x_skillthrowcheak_enamy, y_skillthrowcheak_enamy;
sf::Clock skill_player_clock;
sf::Clock enamy_stun_clock, player_stun_clock;
sf::Clock potion_clock;

Menu menu(window.getSize().x, window.getSize().y);



int main()
{
	
	player.direct = 1;
	blackscreen2.x = -1600;
	int section = 0;
	setup();

	//skill
	skill animetion_skilll_player(&skillthrow_player.Texture, sf::Vector2u(4, 1), 0.1f);//skill player
	skill animetion_skilll_enamy(&skillthrow_enamy.Texture, sf::Vector2u(4, 1), 0.1f);//skill enamy
	skill animetion_nextstage(&nextstage.Texture, sf::Vector2u(4, 1), 0.5f);//skill enamy
	skill animetion_potion(&potion.Texture, sf::Vector2u(5, 1), 0.5f);//potion

	while (window.isOpen())
	{
		
			Calculation_system_potion();

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
			//cheak position skillthrow player
			if (Uskill_player.direct == 1)
			{
				x_skillthrowcheak_player = skillthrow_player.x + 30;
			}
			else
			{
				x_skillthrowcheak_player = skillthrow_player.x - 30;
			}

			//cheak position skillthrow enamy
			if (Uskill_enamy.direct == 1)
			{
				x_skillthrowcheak_enamy = skillthrow_enamy.x + 30;
			}
			else
			{
				x_skillthrowcheak_enamy = skillthrow_enamy.x - 30;
			}

			deltatime_player_skill = skill_player_clock.restart().asSeconds();
			

			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					return 0;
				}
				if (event.type == sf::Event::TextEntered)
				{
					//printf("%c\n", event.text.unicode);
					//printf("x= %f  y=%f\n", x_playercheak, player1.y);

				}
				
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode=='p')
					{
						if (stop == 0)
						{
							stop = 1;
						}
						else
						{
							stop = 0;
						}

					}
					


				}

				if (section == 0)
				{
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
							case 0:
								printf("Play button has been pressed");
								section = 1;
								break;
							case 1:
								printf("Option button has been pressed");
								break;
							case 2:
								window.close();
								return 0;
								break;
							}

							break;
						}

						break;
					case sf::Event::Closed:
						window.close();

						break;

					}
					window.clear();
					menu.draw(window);
					window.display();
					
				}
				
				
			}
			//printf("x= %f  y=%f\t", x_playercheak, player1.y);
			//printf("x= %f  y=%f\t", x_enamycheak, enamy1.y);
			//printf("x= %f  y=%f\n", x_skillthrowcheak, skillthrow.y);
			
			if (section==1)
			{
				if (stop == 0)
				{
					control();
				}
				

				animetion_skilll_player.Update(0, deltatime_player_skill);
				animetion_skilll_enamy.Update(0, deltatime_player_skill);
				sprite_skillthrow_player.setTextureRect(animetion_skilll_player.uvRect);
				sprite_skillthrow_enamy.setTextureRect(animetion_skilll_enamy.uvRect);

				animetion_nextstage.Update(0, deltatime_player_skill);
				sprite_nextstage.setTextureRect(animetion_nextstage.uvRect);



				animetion_potion.Update(0, deltatime_player_skill);
				sprite_potion.setTextureRect(animetion_potion.uvRect);

				if (stop == 0)
				{
					draw_pic();
				}

				damage_player = 0;
				damage_enamy = 0;
				manaDel_player = 0;
				manaDel_enamy = 0;
			}

		
	}	
	
	return 0;
}
void setup()
{
	window.clear();
	menu.draw(window);
	window.display();

	total_mana_playyer = 26;
	total_mana_enamy = 26;

	total_hp_player = 48;
	total_hp_enamy = 48;
	
	potion.Texture.loadFromFile("potion/hpall.png");
	sprite_potion.setTexture(&potion.Texture);

	//skill player
	skillthrow_player.Texture.loadFromFile("skill/getsuka.png");
	sprite_skillthrow_player.setTexture(&skillthrow_player.Texture);

	//skill enamy

	skillthrow_enamy.Texture.loadFromFile("skill/fireball.png");
	sprite_skillthrow_enamy.setTexture(&skillthrow_enamy.Texture);
	
	//skill icon
	skillicon_player.Texture.loadFromFile("skill icon/ichigozall.png");
	skillicon_enamy.Texture.loadFromFile("skill icon/ichigozall.png");
	
	skillicon_enamy.rectSource.top = 0;
	skillicon_enamy.rectSource.left = 0;
	skillicon_enamy.rectSource.width = 200;
	skillicon_enamy.rectSource.height = 200;
	sprite_skillicon_enamy.setTexture(&skillicon_enamy.Texture);
	sprite_skillicon_enamy.setPosition(1020, 125);
	sprite_skillicon_enamy.setTextureRect(skillicon_enamy.rectSource);

	skillicon_player.rectSource.top = 0;
	skillicon_player.rectSource.left = 0;
	skillicon_player.rectSource.width = 200;
	skillicon_player.rectSource.height = 200;
	sprite_skillicon_player.setTexture(&skillicon_player.Texture);
	sprite_skillicon_player.setPosition(130, 125);
	sprite_skillicon_player.setTextureRect(skillicon_player.rectSource);
	

	//charecter icon
	iconcharecter_player.Texture.loadFromFile("iconcharecter/11.png");

	iconcharecter_player.rectSource.top = 0;
	iconcharecter_player.rectSource.left = 0;
	iconcharecter_player.rectSource.width = 300;
	iconcharecter_player.rectSource.height = 300;
	sprite_iconcharecter_player.setTexture(&iconcharecter_player.Texture);
	sprite_iconcharecter_player.setPosition(5,35);
	sprite_iconcharecter_player.setTextureRect(iconcharecter_player.rectSource);


	//BG
	BG.rectSource.top = 0;
	BG.rectSource.left = 0;
	BG.rectSource.width = 1200;
	BG.rectSource.height = 800;

	BG.Texture.loadFromFile("Map/1.png");
	sprite_BG.setTexture(&BG.Texture);
	sprite_BG.setTextureRect(BG.rectSource);

	//player
	if (player.direct == 1 || player.direct == 11)
	{
		player1.x = 0;// edit
	}
	else
	{
		player1.x = 160;// edit
	}
	player1.rectSource.top = 0;
	player1.rectSource.left = 35;
	player1.rectSource.width = 80;
	player1.rectSource.height = 60;
	player.direct = move_Left_player_Fuc(player.direct);
	player.direct = move_Right_player_Fuc(player.direct);
	player.direct = Stay_player_Fuc(player.direct);

	//player setup
	player.direct = 11;
	enamy.direct = 2;
	sprite_enamy.setScale({ -1, 1 });
	//player.setFillColor(sf::Color::Cyan);

	player1.Texture.loadFromFile("Textures/2.png");
	sprite_player1.setTexture(&player1.Texture);
	sprite_player1.setTextureRect(player1.rectSource);

	//enamy
	enamy1.x = 1100;
	enamy1.rectSource.top = 0;
	enamy1.rectSource.left = 35;
	enamy1.rectSource.width = 80;
	enamy1.rectSource.height = 60;

	enamy1.Texture=selectenamy(level,&enamytext);
	sprite_enamy.setTexture(&enamy1.Texture);
	sprite_enamy.setTextureRect(enamy1.rectSource);

	//icon enamy
	iconcharecter_enamy.Texture = enamytext;
	iconcharecter_enamy.rectSource.top = 0;
	iconcharecter_enamy.rectSource.left = 0;
	iconcharecter_enamy.rectSource.width = 300;
	iconcharecter_enamy.rectSource.height = 300;
	sprite_iconcharecter_enamy.setTexture(&iconcharecter_enamy.Texture);
	sprite_iconcharecter_enamy.setPosition(1195, 35);
	sprite_iconcharecter_enamy.setTextureRect(iconcharecter_enamy.rectSource);
	sprite_iconcharecter_enamy.setScale({ -1, 1 });

	//hp_player
	hpBar_player.Texture.loadFromFile("HP/newhpall.png");
	//hp_enamy
	hpBar_enamy.Texture.loadFromFile("HP/newhpall.png");

	//mana_player
	manaBar_player.Texture.loadFromFile("HP/manaall.png");
	//mana_enamy
	manaBar_enamy.Texture.loadFromFile("HP/manaall.png");

	//victory and defeat
	victory.Texture.loadFromFile("Victory/victorymini.png");
	defeat.Texture.loadFromFile("Victory/defeat.png");
	blackscreen1.Texture.loadFromFile("Victory/black.png");
	blackscreen2.Texture.loadFromFile("Victory/black.png");
	
	victory.x = -600;
	victory.rectSource.top = 0;
	victory.rectSource.left = 0;
	victory.rectSource.width = 600;
	victory.rectSource.height = 200;
	sprite_victory.setTexture(&victory.Texture);
	sprite_victory.setPosition(victory.x, 200);
	sprite_victory.setTextureRect(victory.rectSource);

	defeat.x = 1200;
	defeat.rectSource.top = 0;
	defeat.rectSource.left = 0;
	defeat.rectSource.width = 600;
	defeat.rectSource.height = 200;
	sprite_defeat.setTexture(&defeat.Texture);
	sprite_defeat.setPosition(defeat.x, 200);
	sprite_defeat.setTextureRect(defeat.rectSource);

	blackscreen1.x = -1600;
	blackscreen1.rectSource.top = 0;
	blackscreen1.rectSource.left = 0;
	blackscreen1.rectSource.width = 1600;
	blackscreen1.rectSource.height = 800;
	sprite_blackscreen1.setTexture(&blackscreen1.Texture);
	sprite_blackscreen1.setPosition(blackscreen1.x, 0);
	sprite_blackscreen1.setTextureRect(blackscreen1.rectSource);

	//blackscreen2.x = -1600;
	blackscreen2.rectSource.top = 0;
	blackscreen2.rectSource.left = 0;
	blackscreen2.rectSource.width = 1600;
	blackscreen2.rectSource.height = 800;
	sprite_blackscreen2.setTexture(&blackscreen2.Texture);
	sprite_blackscreen2.setPosition(blackscreen2.x, 0);
	sprite_blackscreen2.setTextureRect(blackscreen2.rectSource);

	nextstage.Texture.loadFromFile("Victory/nextstageall.png");
	sprite_nextstage.setTexture(&nextstage.Texture);

}
void draw_pic()
{
	
	

	sprite_player1.setPosition(player1.x, player1.y);
	sprite_enamy.setPosition(enamy1.x, enamy1.y);

	sprite_skillthrow_player.setPosition(skillthrow_player.x, skillthrow_player.y);
	sprite_skillthrow_enamy.setPosition(skillthrow_enamy.x, skillthrow_enamy.y);

	sprite_victory.setPosition(victory.x, 200);
	sprite_defeat.setPosition(defeat.x, 200);

	sprite_nextstage.setPosition(0, 0);// next stage


	sprite_blackscreen1.setPosition(blackscreen1.x, 0);
	sprite_blackscreen2.setPosition(blackscreen2.x, 0);
	
	//hp player
	total_hp_player = hpcalculate(damage_player, total_hp_player);
	hpbar(total_hp_player);
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

	if (potionv.direct == 1)
	{
		window.draw(sprite_potion);
	}
	
	window.draw(sprite_enamy);
	window.draw(sprite_player1);
	
	if (Uskill_player.direct == 1|| Uskill_player.direct == 2)
	{
		window.draw(sprite_skillthrow_player);
	}

	if (Uskill_enamy.direct == 1 || Uskill_enamy.direct == 2)
	{
		window.draw(sprite_skillthrow_enamy);
	}

	
	window.draw(sprite_hpBar_player);
	window.draw(sprite_hpBar_enamy);
	window.draw(sprite_manaBar_player);
	window.draw(sprite_manaBar_enamy);

	window.draw(sprite_victory);
	window.draw(sprite_defeat);

	//skill icon player
	skillicon_player.rectSource.top = selectIcon(total_mana_playyer);
	sprite_skillicon_player.setTextureRect(skillicon_player.rectSource);
	window.draw(sprite_skillicon_player);
	//skill icon enamy
	skillicon_enamy.rectSource.top = selectIcon(total_mana_enamy);
	sprite_skillicon_enamy.setTextureRect(skillicon_enamy.rectSource);
	window.draw(sprite_skillicon_enamy);
	
	
	// icon charecter
	if (total_hp_player == 1)
	{	iconcharecter_player.rectSource.top = 300;	}
	else
	{	iconcharecter_player.rectSource.top = 0;	}

	if (total_hp_enamy == 1)
	{	iconcharecter_enamy.rectSource.top = 300;	}
	else
	{	iconcharecter_enamy.rectSource.top = 0;	}


	sprite_iconcharecter_player.setTextureRect(iconcharecter_player.rectSource);
	window.draw(sprite_iconcharecter_player);
	sprite_iconcharecter_enamy.setTextureRect(iconcharecter_enamy.rectSource);
	window.draw(sprite_iconcharecter_enamy);

	if (total_hp_enamy == 1 && blackscreen1.x>=0)
	{
		window.draw(sprite_nextstage);// test
	}

	window.draw(sprite_blackscreen1);
	window.draw(sprite_blackscreen2);
	
	
	
	window.display();
}

void control()
{
	int botcontrol = fucbotcontrol(x_playercheak, x_enamycheak,level);
	
	sprite_player1.setTextureRect(player1.rectSource);
	sprite_enamy.setTextureRect(enamy1.rectSource);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && total_hp_player != 1 && stun_player.direct != 1 && Uskill_player.direct != 11&& Uskill_player.direct != 22)
	{
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = move_Left_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && total_hp_player != 1 && stun_player.direct != 1 && Uskill_player.direct != 11 && Uskill_player.direct != 22)
	{
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = move_Right_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K) && total_hp_player != 1 && stun_player.direct != 1 && Uskill_player.direct != 11 && Uskill_player.direct != 22)
	{
		
		combo_player = 0;
		if (J_player.direct != 1&& PG_player.direct != 1 )
		{
			jump_player.direct = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L) && total_hp_player != 1 && stun_player.direct != 1 && Uskill_player.direct != 11 && Uskill_player.direct != 22)
	{
		
		combo_player = 0;
		if (J_player.direct != 1&& jump_player.direct != 1&& PG_player.direct != 1 )
		{
			player.direct = Flash_player_Fuc(player.direct);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J) && total_hp_player != 1 && combo_player!=3 && stun_player.direct != 1 && Uskill_player.direct != 11 && Uskill_player.direct != 22)
	{
		if (J_player.direct == 0 && jump_player.direct != 1 && PG_player.direct != 1 &&combo_player<3)
		{
			player.direct = Stay_player_Fuc(player.direct);
			J_player.direct = 1;
			clockJ_player.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && total_hp_player != 1 && stun_player.direct != 1&& J_player.direct != 1 && Uskill_player.direct != 11 && Uskill_player.direct != 22)
	{
		combo_player = 0;
		PG_player_Fuc();
		PG_player.direct = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U) && total_hp_player != 1 && total_mana_playyer > 6 && stun_player.direct != 1)
	{
		if (Uskill_player.direct != 1 && Uskill_player.direct != 2)
		{
			combo_player = 0;
			U_player_Fuc(); //edit

			if (player.direct == 1 || player.direct == 11)
			{
				sprite_skillthrow_player.setScale({ 1, 1 });
				skillthrow_player.x = x_playercheak;
				skillthrow_player.y = player1.y;
				Uskill_player.direct = 11;
				
			}
			else
			{
				sprite_skillthrow_player.setScale({ -1, 1 });
				skillthrow_player.x = x_playercheak;
				skillthrow_player.y = player1.y;
				Uskill_player.direct = 22;
				
			}


		}
		
		
	}
	else if (J_player.direct != 1 && total_hp_player != 1 && stun_player.direct != 1)
	{
		
		if (PG_player.direct == 1 || Uskill_player.direct == 11|| Uskill_player.direct == 22)
		{
			player1.rectSource.left = 35; // left default
			PG_player.direct = 0;
			if (Uskill_player.direct == 11)
			{
				Uskill_player.direct = 1;
				manaDel_player += 7;
			}
			else if(Uskill_player.direct == 22)
			{
				Uskill_player.direct = 2;
				manaDel_player += 7;
			}
			
		}
		player1.rectSource.top = 0; // top default
		player.direct = Stay_player_Fuc(player.direct);
	}


	if (J_player.direct == 1)
	{
		if (clockJ_player.getElapsedTime().asSeconds() > 0.25f&& cheak_damage_and_J_Player == 0)
		{

			if (player.direct == 1 || player.direct == 11)
			{
				if (x_playercheak + 100 >= x_enamycheak && x_enamycheak > x_playercheak - 40)
				{
					if (PG_enamy.direct != 1)
					{
						damage_enamy++;
						if (total_mana_playyer < 26)
						{
							total_mana_playyer++;
						}
						stun_enamy.direct = 1;
						enamy_stun_clock.restart();
						cheak_damage_and_J_Player = 1;
					}
					
					
				}
			}
			else
			{
				if (x_playercheak - 120 <= x_enamycheak && x_enamycheak < x_playercheak + 40)
				{
					if (PG_enamy.direct != 1)
					{
						damage_enamy++;
						if (total_mana_playyer < 26)
						{
							total_mana_playyer++;
						}

						stun_enamy.direct = 1;
						enamy_stun_clock.restart();
						cheak_damage_and_J_Player = 1;
					}
					
				}
			}

		}

		if (clockJ_player.getElapsedTime().asSeconds() > 0.65f)
		{
			J_player.direct = 0;
			clockJ_player.restart();
			player1.rectSource.top = 0;  // top default
			player.direct = Stay_player_Fuc(player.direct);
			combo_player++;
			cheak_damage_and_J_Player = 0;

		}
		else
		{
			player.direct = J_attack_player_Fuc(player.direct);
		}

	}
	
	//skill player cheack
	if (Uskill_player.direct == 1)
	{
		skillthrow_player.x += 4.0f;
	}
	else if (Uskill_player.direct == 2)
	{
		skillthrow_player.x -= 4.0f;
	}

	if (skillthrow_player.x < 0 || skillthrow_player.x>1200)
	{
		Uskill_player.direct = 0;
	}
	// cheack skill position vs enamy
	if (x_skillthrowcheak_player <= x_enamycheak + 5 && x_skillthrowcheak_player >= x_enamycheak)
	{
		if (skillthrow_player.y <= enamy1.y && skillthrow_player.y+80 >= enamy1.y)
		{
			if (Uskill_player.direct == 1 || Uskill_player.direct == 2)
			{
				damage_enamy += 3;
				stun_enamy.direct = 1;
				enamy_stun_clock.restart();
			}
		}
		else if (skillthrow_player.y >= enamy1.y && skillthrow_player.y -80 <= enamy1.y)
		{
			if (Uskill_player.direct == 1 || Uskill_player.direct == 2)
			{
				damage_enamy += 3;
				stun_enamy.direct = 1;
				enamy_stun_clock.restart();
			}
		}
		
	}
	//------------------------------------------------

	
	jump_player.direct = Jump_player_Fuc(jump_player.direct);

	if (stun_player.direct == 1 && total_hp_player != 1)
	{
		J_player.direct = 0;
		playerstun();
	}

	if (total_hp_player == 1)
	{
		lose_player_Fuc();
	}

	//------------------------------------------------------------------------------------------------------------------------------------------
	
	
	if (botcontrol==1 && total_hp_enamy != 1&& stun_enamy.direct!=1 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{
		combo_enamy = 0;
		if (J_enamy.direct != 1 && PG_enamy.direct != 1)
		{
			enamy.direct = move_Right_enamy_Fuc(enamy.direct);
		}
	}
	else if(botcontrol == 2 && total_hp_enamy != 1 && stun_enamy.direct != 1 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{
		combo_enamy = 0;
		if (J_enamy.direct != 1 && PG_enamy.direct != 1)
		{
			enamy.direct = move_Left_enamy_Fuc(enamy.direct);
		}
	}
	else if (botcontrol == 3 && total_hp_enamy != 1 && stun_enamy.direct != 1 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{
		combo_enamy = 0;
		if (J_enamy.direct != 1 && PG_enamy.direct != 1)
		{
			jump_enamy.direct = 1;
		}
	}
	else if (botcontrol == 4 && total_hp_enamy != 1 && stun_enamy.direct != 1 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{
		combo_enamy = 0;
		PG_enamy_Fuc();
		PG_enamy.direct = 1;
	}
	else if (botcontrol == 5 && total_hp_enamy != 1 && stun_enamy.direct != 1 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{

		combo_enamy = 0;
		if (J_enamy.direct != 1 && jump_enamy.direct != 1 && PG_enamy.direct != 1)
		{
			enamy.direct = Flash_enamy_Fuc(enamy.direct);
		}
	}
	else if (botcontrol == 6 && total_hp_enamy != 1 && stun_enamy.direct != 1 && combo_enamy != 3 && Uskill_enamy.direct != 11 && Uskill_enamy.direct != 22)
	{
		if (J_enamy.direct == 0 && jump_enamy.direct != 1 && PG_enamy.direct != 1 && combo_enamy < 3)
		{
			enamy.direct = Stay_enamy_Fuc(enamy.direct);
			J_enamy.direct = 1;
			clockJ_enamy.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && total_hp_enamy != 1 && total_mana_enamy > 6 && stun_enamy.direct != 1)
	{
		if (Uskill_enamy.direct != 1 && Uskill_enamy.direct != 2)
		{
			combo_enamy = 0;
			U_enamy_Fuc(); //edit

			if (enamy.direct == 1 || enamy.direct == 11)
			{
				sprite_skillthrow_enamy.setScale({ 1, 1 });
				skillthrow_enamy.x = x_enamycheak;
				skillthrow_enamy.y = enamy1.y;
				Uskill_enamy.direct = 11;

			}
			else
			{
				sprite_skillthrow_enamy.setScale({ -1, 1 });
				skillthrow_enamy.x = x_enamycheak;
				skillthrow_enamy.y = enamy1.y;
				Uskill_enamy.direct = 22;

			}


		}


	}
	else if (J_enamy.direct != 1 && total_hp_enamy != 1 && stun_enamy.direct != 1)
	{

		if (PG_enamy.direct == 1 || Uskill_enamy.direct == 11 || Uskill_enamy.direct == 22)
		{
			enamy1.rectSource.left = 35; // left default
			PG_enamy.direct = 0;
			if (Uskill_enamy.direct == 11)
			{
				Uskill_enamy.direct = 1;
				manaDel_enamy += 7;
			}
			else if (Uskill_enamy.direct == 22)
			{
				Uskill_enamy.direct = 2;
				manaDel_enamy += 7;
			}

		}
		enamy1.rectSource.top = 0; // top default
		enamy.direct = Stay_enamy_Fuc(enamy.direct);
	}
	
	jump_enamy.direct = Jump_enamy_Fuc(jump_enamy.direct);

	if (J_enamy.direct == 1)
	{
		if (clockJ_enamy.getElapsedTime().asSeconds() > 0.25f && cheak_damage_and_J_enamy == 0)
		{

			if (enamy.direct == 1 || enamy.direct == 11)
			{
				if (x_enamycheak + 100 >= x_playercheak && x_playercheak > x_enamycheak - 40)
				{
					if (PG_player.direct != 1)
					{
						damage_player++;
						if (total_mana_enamy < 26)
						{
							total_mana_enamy++;
						}
						stun_player.direct = 1;
						player_stun_clock.restart();
						cheak_damage_and_J_enamy = 1;
					}


				}
			}
			else
			{
				if (x_enamycheak - 120 <= x_playercheak && x_playercheak < x_enamycheak + 40)
				{
					if (PG_player.direct != 1)
					{
					damage_player++;
					if (total_mana_enamy < 26)
					{
						total_mana_enamy++;
					}

					stun_player.direct = 1;
					player_stun_clock.restart();
					cheak_damage_and_J_enamy = 1;
					}

				}
			}

		}

		if (clockJ_enamy.getElapsedTime().asSeconds() > 0.65f)
		{
			J_enamy.direct = 0;
			clockJ_enamy.restart();
			enamy1.rectSource.top = 0;  // top default
			enamy.direct = Stay_enamy_Fuc(enamy.direct);
			combo_enamy++;
			cheak_damage_and_J_enamy = 0;

		}
		else
		{
			enamy.direct = J_attack_enamy_Fuc(enamy.direct);
		}

	}

	//skill enamy cheack
	if (Uskill_enamy.direct == 1)
	{
		skillthrow_enamy.x += 4.0f;
	}
	else if (Uskill_enamy.direct == 2)
	{
		skillthrow_enamy.x -= 4.0f;
	}

	if (skillthrow_enamy.x < 0 || skillthrow_enamy.x>1200)
	{
		Uskill_enamy.direct = 0;
	}
	// cheack skill position vs player
	if (x_skillthrowcheak_enamy <= x_playercheak + 5 && x_skillthrowcheak_enamy >= x_playercheak)
	{
		if (skillthrow_enamy.y <= player1.y && skillthrow_enamy.y + 80 >= player1.y)
		{
			if (Uskill_enamy.direct == 1 || Uskill_enamy.direct == 2)
			{
				damage_player += 3;
				stun_player.direct = 1;
				player_stun_clock.restart();
			}
		}
		if (skillthrow_enamy.y >= player1.y && skillthrow_enamy.y - 80 <= player1.y)
		{
			if (Uskill_enamy.direct == 1 || Uskill_enamy.direct == 2)
			{
				damage_player += 3;
				stun_player.direct = 1;
				player_stun_clock.restart();
			}
		}


	}
	//------------------------------------------------

	if (stun_enamy.direct == 1 && total_hp_enamy != 1)
	{
		J_enamy.direct = 0;
		enamystun();
	}

	if (total_hp_enamy == 1)
	{
		lose_enamy_Fuc();
	}
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (total_hp_enamy == 1 && victory.x < 600) // victory
	{
		victory.x += 0.7f;
	}
	if (total_hp_enamy == 1 && victory.x >= 600)
	{
		blackscreen1.x += 1.5f;
	}
	if (blackscreen1.x >= 2000)
	{
		blackscreen_2.direct = 1;
	}
	if (blackscreen_2.direct == 1)
	{
		if (blackscreen2.x >= 1200)
		{
			blackscreen_2.direct = 0;
			blackscreen2.x = -1600;
		}
		blackscreen2.x += 1.5f;

	}
	if (blackscreen2.x >= 0 && blackscreen2.x <=1.5)
	{
		level++;
		setup();
	}

	if (total_hp_player == 1 && defeat.x > 0) // defeat
	{
		defeat.x -= 0.7f;
	}
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
int move_Right_enamy_Fuc(int direct)
{

	if (direct == 11)
	{
		enamy1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 1 && direct != 11)
	{
		enamy1.x -= 160;
		sprite_enamy.setScale({ 1, 1 });
		enamy1.rectSource.left = 563; //move left,right default left 

	}
	direct = 1;
	if (enamy1.x < 1040)
	{
		enamy1.x += 0.5f;
	}

	if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.100f)
	{
		if (enamy1.rectSource.left == 1091) //move left,right max left 
		{
			enamy1.rectSource.left = 563; //move left,right default left 
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
int move_Left_enamy_Fuc(int direct)
{


	if (direct == 22)
	{
		enamy1.rectSource.left = 563; //move left,right default left 
	}

	if (direct != 2 && direct != 22)
	{
		enamy1.x += 160;
		sprite_enamy.setScale({ -1, 1 });
		enamy1.rectSource.left = 563; //move left,right default left 
	}
	direct = 2;
	if (enamy1.x >= 160)
	{
		enamy1.x += -0.5f;
	}

	if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.100f)
	{
		if (enamy1.rectSource.left == 1091) //move left,right max left 
		{
		    enamy1.rectSource.left = 563; //move left,right default left 

		}
		else
		{
			enamy1.rectSource.left += 132; //plus
		}

		sprite_enamy.setTextureRect(enamy1.rectSource);
		clock_ani_enamy.restart();


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
int Jump_enamy_Fuc(int directjump)
{

	if (directjump == 1)
	{
		enamy1.rectSource.top = 200;
		enamy1.rectSource.left = 35; //jump defualt left 

		enamy1.y -= enamy1.jump;
		if (enamy1.y < 390)
		{
			enamy1.jump = enamy1.jump * -1;
		}
		else if (enamy1.y >= 530 && enamy1.jump < 0)
		{
			directjump = 0;
			enamy1.jump = enamy1.jump * -1;
			enamy1.y = 530;
			enamy1.rectSource.top = 0; // top defualt 
		}

	}
	return directjump;
}

void PG_player_Fuc()
{
	player1.rectSource.top = 100; //PG top
	player1.rectSource.left = 695;//PG left
	
}

void PG_enamy_Fuc()
{
	enamy1.rectSource.top = 100; //PG top
	enamy1.rectSource.left = 695;//PG left

}

void U_player_Fuc()
{
	player1.rectSource.top = 739; 
	player1.rectSource.left = 1223;

}

void U_enamy_Fuc()
{
	enamy1.rectSource.top = 739;
	enamy1.rectSource.left = 1223;

}

void playerstun()
{
	if (player_stun_clock.getElapsedTime().asSeconds() > 0.675f)
	{
		stun_player.direct = 0;
		player1.rectSource.top = 0;
		player1.rectSource.left = 35;

		//add direct stun = 0;
	}
	else
	{
		player1.rectSource.top = 423;
		player1.rectSource.left = 35;

		//add direct stun = 1;
	}

}
void enamystun()
{
	if (enamy_stun_clock.getElapsedTime().asSeconds() > 0.675f)
	{
		stun_enamy.direct = 0;
		enamy1.rectSource.top = 0;
		enamy1.rectSource.left = 35; 

		//add direct stun = 0;
	}
	else
	{
		enamy1.rectSource.top = 423; 
		enamy1.rectSource.left = 35;

		//add direct stun = 1;
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
int Flash_enamy_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			enamy1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 1 && direct != 11)
		{
			enamy1.x -= 160;
			sprite_enamy.setScale({ 1, 1 });
			enamy1.rectSource.left = 563; //move left,right default left

		}
		direct = 1;

		if (enamy1.x < 1040)
		{
			enamy1.x += 3.0f;
		}

		if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.100f)
		{
			if (enamy1.rectSource.left == 1091) //move left,right  max left
			{
				enamy1.rectSource.left = 563; //move left,right default left
			}
			else
			{
				enamy1.rectSource.left += 132; // plus left 
			}
			sprite_enamy.setTextureRect(enamy1.rectSource);
			clock_ani_enamy.restart();


		}

		return direct;
	}

	if (direct == 2 || direct == 22)
	{

		if (direct == 22)
		{
			enamy1.rectSource.left = 563; //move left,right default left
		}

		if (direct != 2 && direct != 22)
		{
			enamy1.x += 160;
			sprite_enamy.setScale({ -1, 1 });
			enamy1.rectSource.left = 563; //move left,right default left
		}
		direct = 2;
		if (enamy1.x >= 160)
		{
			enamy1.x += -3.0f;
		}
		if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.100f)
		{
			if (enamy1.rectSource.left == 1091) //move left,right max left
			{
				enamy1.rectSource.left = 563; //move left,right default left

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

int J_attack_enamy_Fuc(int direct)
{
	if (direct == 1 || direct == 11)
	{
		if (direct == 11)
		{
			enamy1.rectSource.left = 563; //attack  default left
			enamy1.rectSource.top = 950; //attack  default top
		}
		if (direct != 1 && direct != 11)
		{
			enamy1.x -= 160;
			sprite_enamy.setScale({ 1, 1 });
			enamy1.rectSource.left = 563; //attack  default left
		}
		if (enamy1.x < 1040)
		{
			enamy1.x += 0.03f;
		}
		direct = 1;
		if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.120f)
		{
			if (enamy1.rectSource.left == 1223) //attack  max left
			{
				enamy1.rectSource.left = 563; //attack  default left
			}
			else
			{
				enamy1.rectSource.left += 132; // plus left
			}
			sprite_enamy.setTextureRect(enamy1.rectSource);
			clock_ani_enamy.restart();
		}

		return direct;
	}
	if (direct == 2 || direct == 22)
	{
		if (direct == 22)
		{
			enamy1.rectSource.left = 563; //attack  default left
			enamy1.rectSource.top = 950; //attack  default top
		}
		if (direct != 2 && direct != 22)
		{
			enamy1.x += 160;
			sprite_enamy.setScale({ -1, 1 });
			enamy1.rectSource.left = 563; //attack  default left
		}
		if (enamy1.x >= 160)
		{
			enamy1.x += -0.03f;
		}
		direct = 2;
		if (clock_ani_enamy.getElapsedTime().asSeconds() > 0.120f)
		{
			if (enamy1.rectSource.left == 1223) //attack  max left
			{
				enamy1.rectSource.left = 563; //attack  default left
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

}
void lose_enamy_Fuc()
{
	enamy1.rectSource.top = 320; 
	enamy1.rectSource.left = 167;
}

void lose_player_Fuc()
{
	player1.rectSource.top = 320;
	player1.rectSource.left = 167;
}

void hpbar(float total_hp)
{
	hpBar_player.rectSource.top = (total_hp-1)*40;
	hpBar_player.rectSource.left = 0;
	hpBar_player.rectSource.width = 500;
	hpBar_player.rectSource.height = 40;
	sprite_hpBar_player.setTexture(&hpBar_player.Texture);
	sprite_hpBar_player.setPosition(95, 75);
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
	sprite_hpBar_enamy.setPosition(1105, 75);
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

void Calculation_system_potion()
{

	if (potion_clock.getElapsedTime().asSeconds() > 5.00f)
	{
		potionv.direct = 1;
		potion_clock.restart().asSeconds();
		sprite_potion.setPosition(randompositionpotion(), 390);
		potion.Texture = selectpotion(randomtypepotion(), &typepotion);
		sprite_potion.setTexture(&potion.Texture);
	}
	if (player1.y >= sprite_potion.getPosition().y && player1.y < sprite_potion.getPosition().y + 10 && x_playercheak+30 >= sprite_potion.getPosition().x && x_playercheak < sprite_potion.getPosition().x + 90 && potionv.direct == 1)
	{
		sprite_potion.setPosition(randompositionpotion(), 390);

		if (typepotion == 0)
		{
			damage_player = -7;
		}
		if (typepotion == 1)
		{
			manaDel_player = -7;
		}
		if (typepotion == 2)
		{
			manaDel_player = -5;
			damage_player =  -5;
		}

		potionv.direct = 0;
		potion_clock.restart().asSeconds();
	}
}


