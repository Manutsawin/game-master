#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<windows.h>
#include<stdio.h>
#include"skill_player.h"
#include"Fuc.h"
#include"bot_control.h"
#include"select_enamy.h"
#include"select_player.h"
#include"Potion.h"
#include "Map.h"
#include"Menu.h"
#include"Menu_in_game.h"
#include<string.h>
#include<sstream>
#include "hightscore.h"


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

//game 
void control();
void draw_pic();
void setup();
void hpbar(float);
void hpbar_enamy(float);
void manabar(float);
void manabar_enamy(float);

//potion
void Calculation_system_potion();

//section
void section4();

//score print and setup
void setupscore();
void drawscore();

//set fillter
void fillter();

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
  ,potion
  ,bgmenu
  ,bgmenuingame
  ,bgselect,recselect
  ,bgendgame,bggameover
  ,bghightscore
  ,bginputname
  ,bghowtoplay;

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

//bg menu
sf::RectangleShape sprite_bgmenu(sf::Vector2f(1200.0f, 800.0f));

//menu ingame
sf::RectangleShape sprite_bgmenuingame(sf::Vector2f(1200.0f, 800.0f));

//select player
sf::RectangleShape sprite_bgselect(sf::Vector2f(1200.0f, 800.0f));
sf::RectangleShape sprite_recselect(sf::Vector2f(150.0f, 150.0f));

//cvictory and defeat
sf::RectangleShape sprite_victory(sf::Vector2f(600.0f, 200.0f));
sf::RectangleShape sprite_defeat(sf::Vector2f(600.0f, 200.0f));
sf::RectangleShape sprite_blackscreen1(sf::Vector2f(1600.0f, 800.0f));
sf::RectangleShape sprite_blackscreen2(sf::Vector2f(1600.0f, 800.0f));

//nextstage
sf::RectangleShape sprite_nextstage(sf::Vector2f(1200.0f, 800.0f));

//BG endgame
sf::RectangleShape sprite_bgendgame(sf::Vector2f(1200.0f, 800.0f));

//BG gameover
sf::RectangleShape sprite_bggameover(sf::Vector2f(1200.0f, 800.0f));

//BG highscore
sf::RectangleShape sprite_hightscore(sf::Vector2f(1200.0f, 800.0f));

//BG howtoplay
sf::RectangleShape sprite_howtoplay(sf::Vector2f(1200.0f, 800.0f)); 

//BG inputname
sf::RectangleShape sprite_inputname(sf::Vector2f(1200.0f, 800.0f));

sf::Clock clock_ani_player, clockJ_player , clock_ani_enamy, clockJ_enamy;

sf::Texture enamytext,playertext,
			enamyskill,playerskill,
			iskillplayer,iskillenamy;

int level = 0;
int stop = 0;

int enter = 0;

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
Menu_in_game menuingame(window.getSize().x, window.getSize().y);

int section = 0; //0 = menu :: 1 = name input :: 2 = selectplayer :: 3 = game :: 9 = how to play :: 5 = hight score :: 6 = game over :: 7 = champion  

char nameplayer[10] = " ";
int looptestname = 0;
sf::Text textname;

int point = 0;
sf::Font font;
sf::Text score;

sf::Text hightscname, hightscscore;
std::stringstream Hscorename, Hscorescore;


float speedflashenamy = 1.0;
sf::Clock clock_uskillenamy;
float timecastskillenamy = 1;
int powerenamy_skill = 3;
int powerenamy = 1;

sf::SoundBuffer bufferswingsword, bufferblock, bufferbg0, bufferpotion, bufferlose, buffervictory, bufferchampion;
sf::Sound soundswingsword, soundblock, soundbg0, soundpotion, soundlose, soundvictory, soundchampion;

int main()
{
	textname.setFont(font);
	textname.setCharacterSize(50);
	textname.setFillColor(sf::Color::White);
	textname.setPosition(510, 370);

	bufferswingsword.loadFromFile("Sound fx/Sword Swing.wav");
	soundswingsword.setBuffer(bufferswingsword);

	bufferblock.loadFromFile("Sound fx/block.wav");
	soundblock.setBuffer(bufferblock);

	bufferbg0.loadFromFile("Sound fx/bleach.wav");
	soundbg0.setBuffer(bufferbg0);

	bufferpotion.loadFromFile("Sound fx/potion.wav");
	soundpotion.setBuffer(bufferpotion);

	bufferlose.loadFromFile("Sound fx/lose.wav");
	soundlose.setBuffer(bufferlose);


	buffervictory.loadFromFile("Sound fx/Victory.wav");
	soundvictory.setBuffer(buffervictory);


	bufferchampion.loadFromFile("Sound fx/champion.wav");
	soundchampion.setBuffer(bufferchampion);


	window.setMouseCursorVisible(false);
	
	sprite_recselect.setPosition(150, 100);

	player.direct = 1;
	blackscreen2.x = -1600;
	setup();

	//setup hight score
	hightscname.setFont(font);
	hightscname.setFillColor(sf::Color::White);
	hightscname.setCharacterSize(60);
	hightscname.setPosition(250, 250);

	hightscscore.setFont(font);
	hightscscore.setFillColor(sf::Color::White);
	hightscscore.setCharacterSize(60);
	hightscscore.setPosition(650, 250);


	Hscorename = hightscoreupdate(0, point, nameplayer);
	Hscorescore = hightscoreupdate(1, point, nameplayer);
	hightscname.setString(Hscorename.str());
	hightscscore.setString(Hscorescore.str());

	//skill
	skill animetion_skilll_player(&skillthrow_player.Texture, sf::Vector2u(4, 1), 0.1f);//skill player
	skill animetion_skilll_enamy(&skillthrow_enamy.Texture, sf::Vector2u(4, 1), 0.1f);//skill enamy
	skill animetion_nextstage(&nextstage.Texture, sf::Vector2u(4, 1), 0.5f);//skill enamy
	//potion
	skill animetion_potion(&potion.Texture, sf::Vector2u(5, 1), 0.5f);//potion
	
	//bg menu
	bgmenu.Texture.loadFromFile("Menu/BG_menu_all3.png");
	sprite_bgmenu.setTexture(&bgmenu.Texture);
	skill animetion_bgmenu(&bgmenu.Texture, sf::Vector2u(12, 1), 0.095f);//potion
	animetion_bgmenu.Update(0, deltatime_player_skill);
	sprite_bgmenu.setTextureRect(animetion_bgmenu.uvRect);

	//menu ingame
	bgmenuingame.Texture.loadFromFile("Menu/bgmenuingame.png");
	sprite_bgmenuingame.setTexture(&bgmenuingame.Texture);

	//bg select
	bgselect.Texture.loadFromFile("select char/all.png");
	sprite_bgselect.setTexture(&bgselect.Texture);
	skill animetion_bgselect(&bgselect.Texture, sf::Vector2u(14, 1), 0.12f);//potion
	animetion_bgselect.Update(0, deltatime_player_skill);
	sprite_bgselect.setTextureRect(animetion_bgselect.uvRect);
	
	recselect.Texture.loadFromFile("select char/recall.png");
	sprite_recselect.setTexture(&recselect.Texture);
	skill animetion_recselect(&recselect.Texture, sf::Vector2u(14, 1), 0.12f);//rec select
	animetion_recselect.Update(0, deltatime_player_skill);
	sprite_recselect.setTextureRect(animetion_recselect.uvRect);
	sprite_recselect.setPosition(150, 100);

	bgendgame.Texture.loadFromFile("End game/all bg end2.png");
	sprite_bgendgame.setTexture(&bgendgame.Texture);
	skill animetion_bgendgame(&bgendgame.Texture, sf::Vector2u(6, 1), 0.12f);//bg endgame
	animetion_bgendgame.Update(0, deltatime_player_skill);
	sprite_bgendgame.setTextureRect(animetion_bgendgame.uvRect);

	bggameover.Texture.loadFromFile("End game/gameover.png");
	sprite_bggameover.setTexture(&bggameover.Texture);
	skill animetion_bggameover(&bggameover.Texture, sf::Vector2u(6, 1), 0.12f);//bg endgame
	animetion_bggameover.Update(0, deltatime_player_skill);
	sprite_bggameover.setTextureRect(animetion_bggameover.uvRect);
	
	bginputname.Texture.loadFromFile("inputname/allinputname.png");
	sprite_inputname.setTexture(&bginputname.Texture);
	skill animetion_inputname(&bginputname.Texture, sf::Vector2u(2, 1), 0.12f);//bg endgame
	animetion_inputname.Update(0, deltatime_player_skill);
	sprite_inputname.setTextureRect(animetion_inputname.uvRect);
	
	
	
	
	

	
	while (window.isOpen())
	{
		textname.setString(nameplayer);
		

		if (section == 1)
		{
			if (soundbg0.getStatus() == soundbg0.Stopped)
			{
				soundbg0.play();
			}
			
			animetion_inputname.Update(0, deltatime_player_skill);
			sprite_inputname.setTextureRect(animetion_inputname.uvRect);
			
			window.clear();
			window.draw(sprite_inputname);
			window.draw(textname);
			window.display();
		}
		
		if (section == 3)
		{
			soundbg0.stop();
		}

		if (section !=7)
		{
			soundchampion.stop();
		}
		
		if (section == 5)
		{
			window.clear();
			window.draw(sprite_hightscore);
			window.draw(hightscname);
			window.draw(hightscscore);
			window.display();
		}

		if (section == 9)
		{
			window.clear();
			window.draw(sprite_howtoplay);
			window.display();
		}

		if (level == 6)
		{
			section = 7;
			Hscorename = hightscoreupdate(0, point, nameplayer);
			Hscorescore = hightscoreupdate(1, point, nameplayer);
			hightscname.setString(Hscorename.str());
			hightscscore.setString(Hscorescore.str());
			level = 1;
		
		}
		if (section == 7)
		{
			
			if (soundchampion.getStatus() == soundchampion.Stopped)
			{
				soundchampion.play();
			}
			
			score.setFillColor(sf::Color::White);
			score.setCharacterSize(50);
			score.setPosition(510, 430);

			animetion_bgendgame.Update(0, deltatime_player_skill);
			sprite_bgendgame.setTextureRect(animetion_bgendgame.uvRect);
			sprite_player1.setPosition(537, 530);
			player.direct = Stay_player_Fuc(11);
			window.clear();
			window.draw(sprite_bgendgame);
			window.draw(sprite_player1);
			drawscore();
			window.display();
		}
		if (section == 6)
		{
			
			score.setFillColor(sf::Color::White);
			score.setCharacterSize(50);
			score.setPosition(490, 450);
			animetion_bggameover.Update(0, deltatime_player_skill);
			sprite_bggameover.setTextureRect(animetion_bggameover.uvRect);
			//sprite_player1.setPosition(537, 530);
			//player.direct = Stay_player_Fuc(11);
			window.clear();
			window.draw(sprite_bggameover);
			drawscore();
			//window.draw(sprite_player1);
			window.display();
		}

		
		if (section == 0)
		{
			enter = 0;
			looptestname = 0;
			nameplayer[0] = '\0';
			nameplayer[1] = '\0';
			nameplayer[2] = '\0';
			nameplayer[3] = '\0';
			nameplayer[4] = '\0';
			nameplayer[5] = '\0';
			nameplayer[6] = '\0';
			nameplayer[7] = '\0';
				

			if (soundbg0.getStatus() == soundbg0.Stopped)
			{
				soundbg0.play();
			}

			point = 0;
			level = 1;
			Uskill_player.direct = 0;
			Uskill_enamy.direct = 0;

			animetion_bgmenu.Update(0, deltatime_player_skill);
			sprite_bgmenu.setTextureRect(animetion_bgmenu.uvRect);
			window.clear();
			window.draw(sprite_bgmenu);
			menu.draw(window);
			window.display();

		}
		
		if (section == 2)
		{
			if (soundbg0.getStatus() == soundbg0.Stopped)
			{
				soundbg0.play();
			}

			animetion_bgselect.Update(0, deltatime_player_skill);
			sprite_bgselect.setTextureRect(animetion_bgselect.uvRect);

			animetion_recselect.Update(0, deltatime_player_skill);
			sprite_recselect.setTextureRect(animetion_recselect.uvRect);

			window.clear();
			window.draw(sprite_bgselect);
			window.draw(sprite_recselect);
			window.display();
		}
		section4();
		
		if (section == 3)
		{
			Calculation_system_potion();
		}
		

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

				if (section == 1)
				{
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode == 27)
						{
							section = 0;
						}
						if (event.text.unicode == 13)
						{
							if (looptestname > 0)
							{
								section = 2;
								printf("enter\n");

							}
							else if (looptestname >= 0)
							{
								looptestname--;
							}


						}
						if (event.text.unicode == 8)
						{
							if (looptestname > 0)
							{
								looptestname--;
								nameplayer[looptestname] = '\0';
							}

						}
						else
						{
							if (looptestname < 8)
							{
								printf("%c\n", event.text.unicode);
								nameplayer[looptestname] = event.text.unicode;
								looptestname++;
							}

						}
					}
				}

				if (section == 9)
				{
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Escape)))
					{
						section = 0;
					}
					
				}

				if (section == 3)
				{
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Escape)))
					{
						section = 4;
					}
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode == 'p')
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
				}
				if (section == 2)
				{
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Escape)))
					{
						section = 0;
					}
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode == 13)
						{
							enter++;
							if (enter > 1)
							{
								setup();
								section = 3;
							}
							
						}
					}
					/*if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Return)))
					{
						setup();
						section = 3;
					}*/
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Left)))
					{
						if (sprite_recselect.getPosition().x > 150)
						{
							sprite_recselect.move(-150, 0);
						}
					}
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Right)))
					{
						if (sprite_recselect.getPosition().x <750)
						{
							sprite_recselect.move(150, 0);
						}
					}
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode == 'a'|| event.text.unicode == 'A')
						{
							if (sprite_recselect.getPosition().x > 150)
							{
								sprite_recselect.move(-150, 0);
							}
							

						}
						if (event.text.unicode == 'd' || event.text.unicode == 'D')
						{
							if (sprite_recselect.getPosition().x < 750)
							{
								sprite_recselect.move(150, 0);
							}
						}



					}
				}
				
				if (section == 7)
				{
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Return)))
					{
						section = 5;
					}
				}

				if (section == 6)
				{
					enter = 1;
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Return)))
					{
						section = 5;
					}
				}

				if (section == 5)
				{
					if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key::Escape)))
					{
						section = 0;
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
						case sf::Keyboard::W:
							menu.MoveUp();
							break;

						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::S:
							menu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
							case 0:
								printf("Play button has been pressed\n");
								section = 1;
								//section = 2;
								break;
							case 1:
								printf("High score button has been pressed\n");
								section = 5;
								break;
							case 2:
								printf("How to play button has been pressed\n");
								section = 9;
								break;
							case 3:
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
					
					
				}
				


				if (section == 4)
				{
					
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menuingame.MoveUp();
							break;
						case sf::Keyboard::W:
							menuingame.MoveUp();
							break;

						case sf::Keyboard::Down:
							menuingame.MoveDown();
							break;
						case sf::Keyboard::S:
							menuingame.MoveDown();
							break;
						case sf::Keyboard::Return: 
							switch (menuingame.GetPressedItem())
							{
							case 0:
								printf("Resume button has been pressed\n");
								section = 3;
								break;
							case 1:
								printf("Menu button has been pressed\n");
								section = 0;
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


				}
				
				
			}
			//printf("x= %f  y=%f\t", x_playercheak, player1.y);
			//printf("x= %f  y=%f\t", x_enamycheak, enamy1.y);
			//printf("x= %f  y=%f\n", x_skillthrowcheak, skillthrow.y);
			
			if (section==3)
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
	fillter();

	upgradebot(&speedflashenamy, &timecastskillenamy, &powerenamy, &powerenamy_skill, level);	
	
	enter = 0;
	
	setupscore();
	total_mana_playyer = 26;
	total_mana_enamy = 26;

	total_hp_player = 48;
	total_hp_enamy = 48;
	
	bghightscore.Texture.loadFromFile("Hightscore/bg.png");
	sprite_hightscore.setTexture(&bghightscore.Texture);

	bghowtoplay.Texture.loadFromFile("how to play/howtoplay.png");
	sprite_howtoplay.setTexture(&bghowtoplay.Texture);

	potion.Texture.loadFromFile("potion/hpall.png");
	sprite_potion.setTexture(&potion.Texture);
	
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
	
	//BG
	BG.rectSource.top = 0;
	BG.rectSource.left = 0;
	BG.rectSource.width = 1200;
	BG.rectSource.height = 800;

	BG.Texture = randMap();
	//BG.Texture.loadFromFile("Map/6.1.png");
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
	


	player1.Texture = selectplayer(sprite_recselect.getPosition().x, &playertext,&playerskill,&iskillplayer);
	//player1.Texture.loadFromFile("Textures/5.png");
	sprite_player1.setTexture(&player1.Texture);
	sprite_player1.setTextureRect(player1.rectSource);

	//skill player
	skillthrow_player.Texture = playerskill;
	sprite_skillthrow_player.setTexture(&skillthrow_player.Texture);

	//skill icon player
	skillicon_player.Texture = iskillplayer;

	//charecter icon
	iconcharecter_player.Texture = playertext;
	iconcharecter_player.rectSource.top = 0;
	iconcharecter_player.rectSource.left = 0;
	iconcharecter_player.rectSource.width = 300;
	iconcharecter_player.rectSource.height = 300;
	sprite_iconcharecter_player.setTexture(&iconcharecter_player.Texture);
	sprite_iconcharecter_player.setPosition(5, 35);
	sprite_iconcharecter_player.setTextureRect(iconcharecter_player.rectSource);

	//enamy
	enamy1.x = 1100;
	enamy1.rectSource.top = 0;
	enamy1.rectSource.left = 35;
	enamy1.rectSource.width = 80;
	enamy1.rectSource.height = 60;

	enamy1.Texture=selectenamy(level,&enamytext,&enamyskill,&iskillenamy);
	sprite_enamy.setTexture(&enamy1.Texture);
	sprite_enamy.setTextureRect(enamy1.rectSource);
	
	//skill enamy
	skillthrow_enamy.Texture = enamyskill;
	sprite_skillthrow_enamy.setTexture(&skillthrow_enamy.Texture);

	//skill icon enamy
	skillicon_enamy.Texture = iskillenamy;

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

	drawscore();

	if (total_hp_enamy == 1 && blackscreen1.x>=0)
	{
		window.draw(sprite_nextstage);
	}

	window.draw(sprite_blackscreen1);
	window.draw(sprite_blackscreen2);
	
	
	
	window.display();
}

void control()
{
	int botcontrol = fucbotcontrol(x_playercheak, x_enamycheak,level, J_player.direct , potionv.direct, sprite_potion.getPosition().x, sprite_potion.getPosition().y,enamy.direct, total_mana_enamy, total_hp_player);
	
	
	
	if (botcontrol != 7)
	{
		clock_uskillenamy.restart();
	}
	
	if (clock_uskillenamy.getElapsedTime().asSeconds() > timecastskillenamy)
	{
		botcontrol = 0;
	}
	
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::U) && total_hp_player != 1 && total_mana_playyer > 6 && stun_player.direct != 1&& J_player.direct == 0)
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
				if (x_playercheak + 120 >= x_enamycheak && x_enamycheak > x_playercheak - 40)
				{
					
					
					if (PG_enamy.direct != 1)
					{
						soundswingsword.play();
						damage_enamy++;
						if (total_mana_playyer < 26)
						{
							total_mana_playyer++;
						}
						stun_enamy.direct = 1;
						enamy_stun_clock.restart();
						cheak_damage_and_J_Player = 1;
					}
					else
					{
						if (soundblock.getStatus() == soundblock.Stopped)
						{
							soundblock.play();
						}
						

					}
					
					
				}
			}
			else
			{
				if (x_playercheak - 120 <= x_enamycheak && x_enamycheak < x_playercheak + 40)
				{
					if (PG_enamy.direct != 1)
					{
						soundswingsword.play();
						damage_enamy++;
						if (total_mana_playyer < 26)
						{
							total_mana_playyer++;
						}

						stun_enamy.direct = 1;
						enamy_stun_clock.restart();
						cheak_damage_and_J_Player = 1;
					}
					else
					{
						if (soundblock.getStatus() == soundblock.Stopped)
						{
							soundblock.play();
						}
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
				soundswingsword.play();
				damage_enamy += 3;
				stun_enamy.direct = 1;
				enamy_stun_clock.restart();
			}
		}
		else if (skillthrow_player.y >= enamy1.y && skillthrow_player.y -80 <= enamy1.y)
		{
			if (Uskill_player.direct == 1 || Uskill_player.direct == 2)
			{
				soundswingsword.play();
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
	
	if (botcontrol != 4)
	{
		PG_enamy.direct = 0;
	}
	
	if (botcontrol ==1 || botcontrol == 2 || botcontrol == 5)
	{
		if (J_enamy.direct != 1)
		{
			enamy1.rectSource.top = 0;
		}
		
	}


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
	else if (botcontrol == 7 && total_hp_enamy != 1 && total_mana_enamy > 6 && stun_enamy.direct != 1&& J_enamy.direct == 0)
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
				if (x_enamycheak + 120 >= x_playercheak && x_playercheak > x_enamycheak - 40)
				{
					if (PG_player.direct != 1)
					{
						soundswingsword.play();
						damage_player+= powerenamy;
						if (total_mana_enamy < 26)
						{
							total_mana_enamy++;
						}
						stun_player.direct = 1;
						player_stun_clock.restart();
						cheak_damage_and_J_enamy = 1;
					}
					else
					{
						if (soundblock.getStatus() == soundblock.Stopped)
						{
							soundblock.play();
						}
					}


				}
			}
			else
			{
				if (x_enamycheak - 120 <= x_playercheak && x_playercheak < x_enamycheak + 40)
				{
					if (PG_player.direct != 1)
					{
						soundswingsword.play();
						damage_player+= powerenamy;
						if (total_mana_enamy < 26)
						{
							total_mana_enamy++;
						}
						stun_player.direct = 1;
						player_stun_clock.restart();
						cheak_damage_and_J_enamy = 1;
					}
					else
					{
						if (soundblock.getStatus() == soundblock.Stopped)
						{
							soundblock.play();
						}
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
				soundswingsword.play();
				damage_player += powerenamy_skill;
				stun_player.direct = 1;
				player_stun_clock.restart();
			}
		}
		if (skillthrow_enamy.y >= player1.y && skillthrow_enamy.y - 80 <= player1.y)
		{
			if (Uskill_enamy.direct == 1 || Uskill_enamy.direct == 2)
			{
				soundswingsword.play();
				damage_player += powerenamy_skill;
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
		if (soundvictory.getStatus() == soundvictory.Stopped)
		{
			soundvictory.play();
		}
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
		point += total_hp_player * 2.084;
		setup();
		
	}

	if (total_hp_player == 1 && defeat.x > 0) // defeat
	{
		if (soundlose.getStatus() == soundlose.Stopped)
		{
			soundlose.play();
		}
		
		defeat.x -= 0.7f;
	}

	if (total_hp_player == 1 && defeat.x <= 0) // defeat
	{
		Hscorename = hightscoreupdate(0, point, nameplayer);
		Hscorescore = hightscoreupdate(1, point, nameplayer);
		hightscname.setString(Hscorename.str());
		hightscscore.setString(Hscorescore.str());
		section = 6;
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
			enamy1.x += speedflashenamy;
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
			enamy1.x -= speedflashenamy;
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
void setupscore()
{
	//setup score
	if (!font.loadFromFile("impact.ttf"))
	{
		//handle error
	}
	score.setFont(font);
	score.setFillColor(sf::Color::Green);
	score.setCharacterSize(27);
	score.setPosition(130, 35);
}
void drawscore()
{
	std::stringstream sc;
	sc << "Score : " << point << "\n";
	score.setString(sc.str());
	window.draw(score);
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
		soundpotion.play();
		point += 5;
		potionv.direct = 0;
		potion_clock.restart().asSeconds();
	}
	if (enamy1.y >= sprite_potion.getPosition().y && enamy1.y < sprite_potion.getPosition().y + 10 && x_enamycheak + 30 >= sprite_potion.getPosition().x && x_enamycheak < sprite_potion.getPosition().x + 90 && potionv.direct == 1)
	{
		sprite_potion.setPosition(randompositionpotion(), 390);

		if (typepotion == 0)
		{
			damage_enamy = -7;
		}
		if (typepotion == 1)
		{
			manaDel_enamy = -7;
		}
		if (typepotion == 2)
		{
			manaDel_enamy = -5;
			damage_enamy = -5;
		}
		soundpotion.play();
		potionv.direct = 0;
		potion_clock.restart().asSeconds();
	}
}
void section4()
{
	if (section == 4)
	{
		window.clear();
		window.draw(sprite_BG);

		if (potionv.direct == 1)
		{
			window.draw(sprite_potion);
		}
		potion_clock.restart().asSeconds();
		window.draw(sprite_enamy);
		window.draw(sprite_player1);
		
		if (Uskill_player.direct == 1 || Uskill_player.direct == 2)
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
		window.draw(sprite_skillicon_player);
		window.draw(sprite_skillicon_enamy);
		window.draw(sprite_iconcharecter_player);
		window.draw(sprite_iconcharecter_enamy);
		drawscore();
		if (total_hp_enamy == 1 && blackscreen1.x >= 0)
		{
			window.draw(sprite_nextstage);// test
		}
		window.draw(sprite_blackscreen1);
		window.draw(sprite_blackscreen2);
		window.draw(sprite_bgmenuingame);
		menuingame.draw(window);
		window.display();
	}
}
void fillter()
{
	if (sprite_recselect.getPosition().x == 150 && level == 1)
	{
		sprite_enamy.setFillColor(sf::Color::Cyan);
	}
	else if (sprite_recselect.getPosition().x == 300 && level == 2)
	{
		sprite_enamy.setFillColor(sf::Color::Cyan);
	}
	else if (sprite_recselect.getPosition().x == 450 && level == 3)
	{
		sprite_enamy.setFillColor(sf::Color::Cyan);
	}
	else if (sprite_recselect.getPosition().x == 600 && level == 4)
	{
		sprite_enamy.setFillColor(sf::Color::Cyan);
	}
	else if (sprite_recselect.getPosition().x == 750 && level == 5)
	{
		sprite_enamy.setFillColor(sf::Color::Cyan);
	}
	else
	{
		sprite_enamy.setFillColor(sf::Color::White);
	}
}


