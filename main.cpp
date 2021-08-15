#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>
#include "Menu.h"
#include "DeadMenu.h"
#include "EndGameMenu.h"

using namespace std;

int main()
{
	srand(time(NULL));
	bool checksetpositionforstate2 = 0;
	bool checksetpositionforstate3 = 0;
	bool checksetpositionforstate1 = 0;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "NITI BIZARRE ADVENTURE : REQUIEM !!!");

	Menu menu(window.getSize().x, window.getSize().y);

	DeadMenu deadmenu(window.getSize().x, window.getSize().y);

	EndGameMenu endmenu(window.getSize().x, window.getSize().y);

	//sf::CircleShape collision(100.f);
	//collision.setPosition({ 750.f, 350.f });
	//collision.setFillColor(sf::Color::Red);

	sf::RectangleShape hitbox;
	hitbox.setSize(sf::Vector2f(64, 64));
	hitbox.setOutlineColor(sf::Color::Magenta);
	hitbox.setOutlineThickness(5);



	sf::Music themeMusic;

	if (!themeMusic.openFromFile("res/sound/Theme.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	themeMusic.play();




	sf::Music music;
	if (!music.openFromFile("res/sound/song001.ogg"))
	{ 
		std::cout << "ERROR" << std::endl;
	}

	sf::SoundBuffer yareyarebuffer;
	if (!yareyarebuffer.loadFromFile("res/sound/yare-yare.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::SoundBuffer firebuffer;
	if (!firebuffer.loadFromFile("res/sound/fire.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}
    
	
	sf::SoundBuffer enemybuffer;
	if (!enemybuffer.loadFromFile("res/sound/enemyHit.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::SoundBuffer doorbuffer;
	if (!doorbuffer.loadFromFile("res/sound/Pickup_Coin5.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}


	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("res/sound/playerHit.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::SoundBuffer attackbuffer;
	if (!attackbuffer.loadFromFile("res/sound/oraora.wav"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Texture obTexture;
	if (!obTexture.loadFromFile("res/images/wall.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Texture obTexture2;
	if (!obTexture2.loadFromFile("res/images/wall.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Texture obTexture3;
	if (!obTexture3.loadFromFile("res/images/wall.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Texture firetexture;
	if (!firetexture.loadFromFile("res/images/fireb001.png"))
	{
		std::cout << "ERROR" << std::endl;
	}
	

	sf::Texture Texture;
	if (!Texture.loadFromFile("res/images/bgmenu001.jpg"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture shapeTexture;
	if (!shapeTexture.loadFromFile("res/images/006.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture doorTexture;
	if (!doorTexture.loadFromFile("res/images/door003.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemy002Texture;
	if (!enemy002Texture.loadFromFile("res/images/enemy002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemy003Texture;
	if (!enemy003Texture.loadFromFile("res/images/enemy002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemy004Texture;
	if (!enemy004Texture.loadFromFile("res/images/enemy002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemy005Texture;
	if (!enemy005Texture.loadFromFile("res/images/enemy002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemy006Texture;
	if (!enemy006Texture.loadFromFile("res/images/enemy002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture enemystate3Texture;
	if (!enemystate3Texture.loadFromFile("res/images/enemy003.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Texture bossTexture;
	if (!bossTexture.loadFromFile("res/images/Boss.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	

	sf::Sprite enemy002Sprite;
	sf::Sprite enemy003Sprite;
	sf::Sprite enemy004Sprite;
	sf::Sprite enemy005Sprite;
	sf::Sprite enemy006Sprite;
	///////////ENEMY_STATE3//////////
	sf::Sprite enemyState3Sprite[6];
	sf::Sprite bossSprite;

	bossSprite.setTexture(bossTexture);
	enemy002Sprite.setTexture(enemy002Texture);
	enemy003Sprite.setTexture(enemy003Texture);
	enemy004Sprite.setTexture(enemy004Texture);
	enemy005Sprite.setTexture(enemy005Texture);
	enemy006Sprite.setTexture(enemy006Texture);
	///////////ENEMY_STATE3//////////
	enemyState3Sprite[0].setTexture(enemystate3Texture);
	enemyState3Sprite[1].setTexture(enemystate3Texture);
	enemyState3Sprite[2].setTexture(enemystate3Texture);
	enemyState3Sprite[3].setTexture(enemystate3Texture);
	enemyState3Sprite[4].setTexture(enemystate3Texture);
	enemyState3Sprite[5].setTexture(enemystate3Texture);
	

	/*sf::Texture attackLRTexture;
	if (!attackLRTexture.loadFromFile("res/images/attackrightleft.png"))
	{
		std::cout << "Load failed" << std::endl;
	}*/

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("res/images/002.png"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Sprite objtexture;
	sf::Sprite objtexture2;
	sf::Sprite objtexture3;
	sf::Sound sound;
	sf::Sound attackSound;
	sf::Sound enemyHit;
	sf::Sound yareyare;
	sf::Sound fire;
	sf::Sound doorsound;
	sf::Sprite bgTexture;
	sf::Sprite shapeSprite;
	sf::Sprite enemySprite[3];
	sf::Sprite fireSprite;
	sf::Sprite doorSprite;
	

	sf::Font font;
	sf::Font health;
	sf::Font hpPoint;

	if (!font.loadFromFile("res/font/manaspc.ttf"))
	{
		std::cout << "Load failed" << std::endl;
	}

	if (!health.loadFromFile("res/font/manaspc.ttf"))
	{
		std::cout << "Load failed" << std::endl;
	}

	if (!hpPoint.loadFromFile("res/font/manaspc.ttf"))
	{
		std::cout << "Load failed" << std::endl;
	}

	sf::Text scoreText;
	sf::Text healthText;
	sf::Text hpPointText;
	hpPointText.setFont(hpPoint);
	healthText.setFont(health);
	hpPointText.setPosition(160, 50);
	healthText.setPosition(0, 50);
	healthText.setString("HEALTH : ");
	scoreText.setFont(font);
	scoreText.setString("0");
	hpPointText.setString("100");



	std::vector<sf::Sprite> enemySpriteVector(3);
	enemySpriteVector.push_back(enemySprite[0]);
	enemySpriteVector.push_back(enemySprite[1]);
	enemySpriteVector.push_back(enemySprite[2]);

	///////ENVIRONMENTTEXTURE////////
	doorSprite.setTexture(doorTexture);
	doorSprite.setPosition({ -500, -7298 });
	
	//sf::Sprite attackLRSprite;
	objtexture.setTexture(obTexture);
	objtexture2.setTexture(obTexture2);
	objtexture3.setTexture(obTexture3);


	bgTexture.setTexture(Texture);
	fireSprite.setTexture(firetexture);
	//attackLRSprite.setTexture(attackLRTexture);
	shapeSprite.setTexture(shapeTexture);
	enemySpriteVector[0].setTexture(enemyTexture);
	enemySpriteVector[1].setTexture(enemyTexture);
	enemySpriteVector[2].setTexture(enemyTexture);
	sound.setBuffer(buffer);
	attackSound.setBuffer(attackbuffer);
	enemyHit.setBuffer(enemybuffer);
	yareyare.setBuffer(yareyarebuffer);
	fire.setBuffer(firebuffer);
	doorsound.setBuffer(doorbuffer);
	
	fireSprite.setScale({ 1,1 });
	fireSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	shapeSprite.setTextureRect(sf::IntRect(0, 0, 32, 48));
	doorSprite.setTextureRect(sf::IntRect(0, 0, 171, 204));
	enemySpriteVector[0].setTextureRect(sf::IntRect(0, 0, 32, 48));
	enemySpriteVector[1].setTextureRect(sf::IntRect(0, 0, 32, 48));
	enemySpriteVector[1].setTextureRect(sf::IntRect(0, 0, 32, 48));
	//attackLRSprite.setTextureRect(sf::IntRect(0, 0, 64, 48));

	sf::Vector2f spawnPoint = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint1 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint2 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint3 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint4 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint5 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint6 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f enemyspawnPoint7 = { static_cast<float> (rand() % 1080), static_cast<float> (rand() % 720) };
	sf::Vector2f deadPoint = { 0.f, 0.f};
	int animationFrame = 0;
	int enemyanimationFrame = 0;
	int enemy002animationFrame = 0;
	int enemy003animationFrame = 0;
	int enemy004animationFrame = 0;
	int enemy005animationFrame = 0;
	int enemy006animationFrame = 0;
	int enemyState3animationFrame = 0;
	int bossAnimationFrame = 0;
	int bossEnrageAnimation = 0;
	int fireFrame = 0;
	bool right;
	bool up;
	bool enemyRight;
	bool enemyRight1;
	bool enemyRight2;
	bool enemyRight3;
	bool enemyRight4;
	bool  enemyRstateBoss1;
	bool  enemyRstateBoss2;
	bool  enemyRstateBoss3;
	bool  enemyRstateBoss4;
	bool  enemyRstateBoss5;
	bool  enemyRstateBoss6;
	bool bossright;
	int score = 0;
	int hp = 100;
	int firedirection = 0;
	int playerdirection = 0;
	int state = 0;
	int kill_CountState1 = 0;
	int kill_CountState2 = 0;
	int kill_CountState3 = 0;
	bool enemy_Death[5] = {};
	bool enemystate3_Death[6] = {};
	bool boss_Death = 0 ;
	int hit_Count_FirstState[3] = {};
	int hit_Count_Sate2 = 0;
	int hit_Count_Sate2_1 = 0;
	int hit_Count_Sate2_2 = 0;
	int hit_Count_Sate2_3 = 0;
	int hit_Count_Sate2_4 = 0;
	int hit_Count_Sate3_1 = 0;
	int hit_Count_Sate3_2 = 0;
	int hit_Count_Sate3_3 = 0;
	int hit_Count_Sate3_4 = 0;
	int hit_Count_Sate3_5 = 0;
	int hit_Count_Sate3_6 = 0;
	int boss_Hit_Count = 0;
	//int attackanimationFrame = 0;
	
	shapeSprite.setPosition(spawnPoint);
	//fireSprite.setPosition(shapeSprite.getPosition().x + 1, shapeSprite.getPosition().y);
	enemySpriteVector[0].setPosition(enemyspawnPoint);
	enemySpriteVector[1].setPosition(enemyspawnPoint1);
	enemySpriteVector[2].setPosition(enemyspawnPoint2);
	objtexture.setPosition({ 750.f,350.f });
	fireSprite.setPosition(-500, -500);


	sf::Texture state2bgTexture;
	if (!state2bgTexture.loadFromFile("res/images/state2bg.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Sprite state2bgSprite;

	sf::Texture state3bgTexture;
	if (!state3bgTexture.loadFromFile("res/images/bgstate3.png"))
	{
		std::cout << "ERROR" << std::endl;
	}

	sf::Sprite state3bgSprite;

	while (window.isOpen())
	{
		
			if (state != 5 && state != 6) {
				sf::Event event;
				while (window.pollEvent(event))
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
								std::cout << "Play button has been pressed" << std::endl;
								state = 1;
								themeMusic.stop();
								music.play();

								objtexture.setPosition(750, 350);

								hp = 100;
								score = 0;

								

								window.draw(hpPointText);
								window.draw(scoreText);

								checksetpositionforstate2 = 0;
								checksetpositionforstate3 = 0;

								kill_CountState1 = 0;
								kill_CountState2 = 0;
								kill_CountState3 = 0;

								hit_Count_Sate2 = 0;
								hit_Count_Sate2_1 = 0;
								hit_Count_Sate2_2 = 0;
								hit_Count_Sate2_3 = 0;
								hit_Count_Sate2_4 = 0;

								score = 0;
								hp = 100;
								kill_CountState1 = 0;
								kill_CountState2 = 0;
								shapeSprite.setPosition(spawnPoint);
								enemySpriteVector[0].setPosition(enemyspawnPoint);
								enemySpriteVector[1].setPosition(enemyspawnPoint1);
								enemySpriteVector[2].setPosition(enemyspawnPoint2);

								enemySpriteVector[0].setTexture(enemyTexture);
								enemySpriteVector[1].setTexture(enemyTexture);
								enemySpriteVector[2].setTexture(enemyTexture);

								enemy002Sprite.setPosition(100, 500);
								enemy003Sprite.setPosition(200, 300);
								enemy004Sprite.setPosition(20, 600);
								enemy005Sprite.setPosition(378, 590);
								enemy006Sprite.setPosition(254, 100);

								enemyState3Sprite[0].setPosition(100, 200);
								enemyState3Sprite[1].setPosition(200, 333);
								enemyState3Sprite[2].setPosition(546, 148);
								enemyState3Sprite[3].setPosition(600, 420);
								enemyState3Sprite[4].setPosition(694, 350);
								enemyState3Sprite[5].setPosition(555, 666);

								for (int e=0; e < 6; e++) {
									enemystate3_Death[e] = 0;
								}

								boss_Death = 0;

								bossSprite.setPosition(enemyspawnPoint7);
								break;


							case 1:
								window.close();
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
			else if (state == 5){
				sf::Event deadevent;
				while (window.pollEvent(deadevent))
				{
					switch (deadevent.type)
					{
					case sf::Event::KeyReleased:
						switch (deadevent.key.code)
						{
						case sf::Keyboard::Up:
							deadmenu.MoveUp();
							break;

						case sf::Keyboard::Down:
							deadmenu.MoveDown();
							break;

						case sf::Keyboard::Return:
							switch (deadmenu.DeadGetPressedItem())
							{
							case 0:
								std::cout << "Back To Menu button has been pressed" << std::endl;
								state = 0;
								break;

							case 1:
								window.close();
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

		
		else if (state == 6)  {
			sf::Event endevent;
			while (window.pollEvent(endevent))
			{
				switch (endevent.type)
				{
				case sf::Event::KeyReleased:
					switch (endevent.key.code)
					{
					case sf::Keyboard::Up:
						endmenu.MoveUp();
						break;

					case sf::Keyboard::Down:
						endmenu.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (endmenu.EndGetPressedItem())
						{
						case 0:
							std::cout << "again button has been pressed" << std::endl;
							music.stop();
							themeMusic.play();
							state = 0;
							break;

						case 1:
							window.close();
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


		window.clear();

		if (state == 1) {



			
			
			if (checksetpositionforstate1 == 0) {

				shapeSprite.setPosition(0, 350);
				objtexture.setPosition({ 750.f,350.f });
				

				checksetpositionforstate1 = 1;

			}
			
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				state = 0;
			}
			//fire update/////////////////////////////////////////////////////////////////////////////////////
			if (firedirection == 1) {
				fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 2, 64, 64));
				fireSprite.move(0, -1);
			}
			if (firedirection == 2) {
				fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 3, 64, 64));
				fireSprite.move(0, 1);
			}
			if (firedirection == 3) {
				fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
				fireSprite.move(-1, 0);
			}
			if (firedirection == 4) {
				fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 0, 64, 64));
				fireSprite.move(1, 0);
			}

			/////////////////////////////////////////////FIREATTACK/////////////////////////////////////////////

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				fire.play();
				fireSprite.setPosition(shapeSprite.getPosition().x, shapeSprite.getPosition().y);
				//fireSprite.move(1.f, 0.f);
				//fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
				firedirection = playerdirection;

			}

			for (int enemy = 0; enemy < 3; enemy++) {
				if (fireSprite.getGlobalBounds().intersects(enemySpriteVector[enemy].getGlobalBounds())) {
					enemySpriteVector[enemy].setPosition(500000, 500000);
					enemyHit.play();


					fireSprite.setPosition(-50000, -50000);
					firedirection = 0;
					kill_CountState1 = kill_CountState1 + 1;

					score = score + 10;
					std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());


				}
			}


			/////////////////////////////////////MELEE//////////////////////////////////////////////////
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));
				for (int enemy = 0; enemy < 3; enemy++) {
					if (shapeSprite.getGlobalBounds().intersects(enemySpriteVector[enemy].getGlobalBounds())) {
						enemySpriteVector.erase(enemySpriteVector.begin() + enemy);
						enemyHit.play();
						kill_CountState1 = kill_CountState1 + 1;

						score = score + 10;
						std::cout << score << std::endl;
						std::stringstream ss;
						ss << score;
						scoreText.setString(ss.str());
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));
				for (int enemy = 0; enemy < 3; enemy++) {
					if (shapeSprite.getGlobalBounds().intersects(enemySpriteVector[enemy].getGlobalBounds())) {
						enemySpriteVector.erase(enemySpriteVector.begin() + enemy);
						enemyHit.play();

						kill_CountState1 = kill_CountState1 + 1;
						cout << "collision" << endl;

						score = score + 10;
						std::cout << score << std::endl;
						std::stringstream ss;
						ss << score;
						scoreText.setString(ss.str());

					}
				}


			}

			/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && up == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 6, 32, 96));

				if (shapeSprite.getGlobalBounds().intersects(enemySpriteVector[0].getGlobalBounds())) {
					enemySpriteVector[0].setPosition(enemyspawnPoint);
					sound.play();
				}

			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && up == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 7, 32, 96));

				if (shapeSprite.getGlobalBounds().intersects(enemySpriteVector[0].getGlobalBounds())) {
					enemySpriteVector[0].setPosition(enemyspawnPoint);
					sound.play();
				}

			}*/

			/////////////////////////////////////////////////////////MOVEMENT//////////////////////////////////////////////////////////
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shapeSprite.getPosition().x + 32 <= 1080)
			{
				shapeSprite.move(.1f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 2, 32, 48));
				right = 1;
				playerdirection = 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shapeSprite.getPosition().x > 0)
			{
				shapeSprite.move(-.1f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 1, 32, 48));
				right = 0;
				playerdirection = 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shapeSprite.getPosition().y > 0)
			{
				shapeSprite.move(0.f, -.1f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 3, 32, 48));
				up = 1;
				playerdirection = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shapeSprite.getPosition().y + 48 <= 720)
			{
				shapeSprite.move(0.f, .1f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 0, 32, 48));
				up = 0;
				playerdirection = 2;
			}

			////////////ENEMY/////////////////////////////////////////////
			for (int enemy = 0; enemy < 3; enemy++) {
				if (enemySpriteVector[enemy].getPosition().x > shapeSprite.getPosition().x)
				{
					enemySpriteVector[enemy].move(-0.01f, 0.00f);
					enemySpriteVector[enemy].setTextureRect(sf::IntRect(32 * enemyanimationFrame, 48 * 1, 32, 48));
				}
				if (enemySpriteVector[enemy].getPosition().x < shapeSprite.getPosition().x)
				{
					enemySpriteVector[enemy].move(0.01f, 0.00f);
					enemySpriteVector[enemy].setTextureRect(sf::IntRect(32 * enemyanimationFrame, 48 * 2, 32, 48));
				}
				if (enemySpriteVector[enemy].getPosition().y > shapeSprite.getPosition().y)
				{
					enemySpriteVector[enemy].move(0.00f, -0.01f);
					enemySpriteVector[enemy].setTextureRect(sf::IntRect(32 * enemyanimationFrame, 48 * 3, 32, 48));
				}
				if (enemySpriteVector[enemy].getPosition().y < shapeSprite.getPosition().y)
				{
					enemySpriteVector[enemy].move(0.00f, 0.01f);
					enemySpriteVector[enemy].setTextureRect(sf::IntRect(32 * enemyanimationFrame, 0, 32, 48));
				}
			}

			animationFrame++;
			enemyanimationFrame++;
			//fireFrame++;
			//attackanimationFrame++;

			if (animationFrame >= 4) {
				animationFrame = 0;
			}

			if (enemyanimationFrame >= 4) {
				enemyanimationFrame = 0;
			}

			if (animationFrame >= 6) {
				animationFrame = 0;
			}

			if (fireFrame >= 8) {
				fireFrame = 0;
			}

			/*if (objtexture.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
				shapeSprite.setPosition(spawnPoint);
				sound.play();
			}*/

			for (int enemy = 0; enemy < 3; enemy++) {
				if (enemySpriteVector[enemy].getGlobalBounds().intersects(shapeSprite.getGlobalBounds()) && playerdirection ==4) {
					//shapeSprite.setPosition(spawnPoint);
					sound.play();
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);

					hp = hp - 1;

					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());
				
					
					
				}
			}

			for (int enemy = 0; enemy < 3; enemy++) {
				if (enemySpriteVector[enemy].getGlobalBounds().intersects(shapeSprite.getGlobalBounds()) && playerdirection == 3) {
					//shapeSprite.setPosition(spawnPoint);
					sound.play();
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);

					hp = hp - 1;

					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
			}


			
			
	
		


			window.draw(bgTexture);
			window.draw(objtexture);
			//////////////////////////STATE2CONDITON////////////////////////
			if (kill_CountState1 == 3)
			{
				doorSprite.setPosition(900, 300);
				window.draw(doorSprite);

			}

			if (doorSprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
				
				doorsound.play();

				state = 2;
				doorSprite.setPosition(70000, 70000);

				enemy002Sprite.setPosition(enemyspawnPoint);
				enemy003Sprite.setPosition(enemyspawnPoint1);
				enemy004Sprite.setPosition(enemyspawnPoint2);
				enemy005Sprite.setPosition(enemyspawnPoint3);
				enemy006Sprite.setPosition(enemyspawnPoint4);
			
			}
			  
			window.draw(shapeSprite);
			window.draw(enemySpriteVector[0]);
			window.draw(enemySpriteVector[1]);
			window.draw(enemySpriteVector[2]);
			window.draw(healthText);
			window.draw(hpPointText);
			window.draw(scoreText);
			window.draw(fireSprite);
            
			
			
			//window.draw(attackLRSprite);

			sf::View view(sf::FloatRect(0, 0, 1080, 720));
			/*sf::Vector2f pPos = shapeSprite.getPosition();
			view.setCenter(shapeSprite.getPosition());
			window.setView(view);*/
		}


		/////////////////////////////////STATE2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (state == 2)
		{


		//fire update/////////////////////////////////////////////////////////////////////////////////////
		if (firedirection == 1) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 2, 64, 64));
			fireSprite.move(0, -1);
		}
		if (firedirection == 2) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 3, 64, 64));
			fireSprite.move(0, 1);
		}
		if (firedirection == 3) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
			fireSprite.move(-1, 0);
		}
		if (firedirection == 4) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 0, 64, 64));
			fireSprite.move(1, 0);
		}

		/////////////////////////////////////////////FIREATTACK/////////////////////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			fire.play();
			fireSprite.setPosition(shapeSprite.getPosition().x, shapeSprite.getPosition().y);
			//fireSprite.move(1.f, 0.f);
			//fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
			firedirection = playerdirection;
			

		}

		if (enemy002Sprite.getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate2 = hit_Count_Sate2 + 1;
			if (enemyRight == 0)
			{
				enemy002Sprite.setPosition(enemy002Sprite.getPosition().x - 30, enemy002Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRight == 1)
			{
				enemy002Sprite.setPosition(enemy002Sprite.getPosition().x + 30, enemy002Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate2 == 5)
			{
				enemy_Death[0] = 1;
				kill_CountState2 = kill_CountState2 + 1;
				enemy002Sprite.setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());


			}
			enemyHit.play();


		}

		if (enemy003Sprite.getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate2_1 = hit_Count_Sate2_1 + 1;
			if (enemyRight1 == 0)
			{
				enemy003Sprite.setPosition(enemy003Sprite.getPosition().x - 30, enemy003Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRight1 == 1)
			{
				enemy003Sprite.setPosition(enemy003Sprite.getPosition().x + 30, enemy003Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate2_1 == 5)
			{
				enemy_Death[1] = 1;
				kill_CountState2 = kill_CountState2 + 1;
				enemy003Sprite.setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());


			}
			enemyHit.play();


		}

		if (enemy004Sprite.getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate2_2 = hit_Count_Sate2_2 + 1;
			if (enemyRight2 == 0)
			{
				enemy004Sprite.setPosition(enemy004Sprite.getPosition().x - 30, enemy004Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRight2 == 1)
			{
				enemy004Sprite.setPosition(enemy004Sprite.getPosition().x + 30, enemy004Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate2_2 == 5)
			{
				enemy_Death[2] = 1;
				kill_CountState2 = kill_CountState2 + 1;
				enemy004Sprite.setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());


			}
			enemyHit.play();


		}

		if (enemy005Sprite.getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate2_3 = hit_Count_Sate2_3 + 1;
			if (enemyRight3 == 0)
			{
				enemy005Sprite.setPosition(enemy005Sprite.getPosition().x - 30, enemy005Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRight3 == 1)
			{
				enemy005Sprite.setPosition(enemy005Sprite.getPosition().x + 30, enemy005Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate2_3 == 5)
			{
				enemy_Death[3] = 1;
				kill_CountState2 = kill_CountState2 + 1;
				enemy005Sprite.setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());


			}
			enemyHit.play();


		}

		if (enemy006Sprite.getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate2_4 = hit_Count_Sate2_4 + 1;
			if (enemyRight4 == 0)
			{
				enemy006Sprite.setPosition(enemy006Sprite.getPosition().x - 30, enemy006Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRight4 == 1)
			{
				enemy006Sprite.setPosition(enemy006Sprite.getPosition().x + 30, enemy006Sprite.getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate2_4 == 5)
			{
				enemy_Death[4] = 1;
				kill_CountState2 = kill_CountState2 + 1;
				enemy006Sprite.setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());


			}
			enemyHit.play();


		}
		



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && state == 2)
		{
			state = 0;


		   }
			

			hpPointText.setFont(hpPoint);
			healthText.setFont(health);
			hpPointText.setPosition(160, 50);
			healthText.setPosition(0, 50);
			scoreText.setFont(font);
			
			//cout << enemy002Sprite.getPosition().x << " " << enemy002Sprite.getPosition().y << endl;
			////////////////////////////////////////////////////////////////////checksetpositionforstate2/////////////////////////////////////////////////////////////////

			if (checksetpositionforstate2 == 0) {
                
				enemy002Sprite.setPosition(enemyspawnPoint);
				enemy003Sprite.setPosition(enemyspawnPoint1);
				enemy004Sprite.setPosition(enemyspawnPoint2);
				enemy005Sprite.setPosition(enemyspawnPoint3);
				enemy006Sprite.setPosition(enemyspawnPoint4);
				shapeSprite.setPosition(spawnPoint);
				objtexture.setPosition({ 0.f,350.f });
				objtexture2.setPosition({ 750.f,350.f });
				
				
					enemy_Death[0] = 0;
					enemy_Death[1] = 0;
					enemy_Death[2] = 0;
					enemy_Death[3] = 0;
					enemy_Death[4] = 0;
				

				checksetpositionforstate2 = 1;
				
			}

			

			state2bgSprite.setTexture(state2bgTexture);

			enemy002Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
			enemy003Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
			enemy004Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
			enemy005Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
			enemy006Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));


			window.draw(state2bgSprite);

			

			

			window.draw(objtexture);
			window.draw(objtexture2);

			//std::cout << enemy_Death[0] << std::endl;
			//if(enemy_Death[0] == 0)
			//{
				window.draw(enemy002Sprite);
			//}

			//if (enemy_Death[1] == 0)
			//{
				window.draw(enemy003Sprite);
			//}

			//if (enemy_Death[2] == 0)
			//{
				window.draw(enemy004Sprite);
			//}

			//if (enemy_Death[3] == 0)
			//{
				window.draw(enemy005Sprite);
			//}

			/*if (enemy_Death[4] == 0)
			{*/
				window.draw(enemy006Sprite);
			//}


			window.draw(shapeSprite);

			window.draw(healthText);
			window.draw(hpPointText);
			window.draw(scoreText);
			window.draw(fireSprite);


			                                     ////////////////MOVEMENT//////////////////


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shapeSprite.getPosition().x + 32 <= 1080)
			{
				shapeSprite.move(0.1f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 2, 32, 48));
				right = 1;
				playerdirection = 4;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shapeSprite.getPosition().x > 0)
			{
				shapeSprite.move(-0.1f, 0.f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 1, 32, 48));
				right = 0;
				playerdirection = 3;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shapeSprite.getPosition().y > 0)
			{
				shapeSprite.move(0.f, -0.1f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 3, 32, 48));
				up = 1;
				playerdirection = 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shapeSprite.getPosition().y + 48 <= 720)
			{
				shapeSprite.move(0.f, 0.1f);
				shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 0, 32, 48));
				up = 0;
				playerdirection = 2;
			}

			animationFrame++;

			if (animationFrame >= 4) {
				animationFrame = 0;
			}


////////////////////////////////////////////////////ENEMY_MOVEMENT////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			if (enemy_Death[0] == 0) {

				if (enemy002Sprite.getPosition().x > shapeSprite.getPosition().x)
				{
					enemyRight = 1;
					enemy002Sprite.move(-0.01f, 0.00f);
					enemy002Sprite.setTextureRect(sf::IntRect(48 * enemy002animationFrame, 48 * 1, 48, 48));
				}
				if (enemy002Sprite.getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRight = 0;
					enemy002Sprite.move(0.01f, 0.00f);
					enemy002Sprite.setTextureRect(sf::IntRect(48 * enemy002animationFrame, 48 * 2, 48, 48));
				}
				if (enemy002Sprite.getPosition().y > shapeSprite.getPosition().y)
				{
					enemy002Sprite.move(0.00f, -0.01f);
					enemy002Sprite.setTextureRect(sf::IntRect(48 * enemy002animationFrame, 48 * 3, 48, 48));
				}
				if (enemy002Sprite.getPosition().y < shapeSprite.getPosition().y)
				{
					enemy002Sprite.move(0.00f, 0.01f);
					enemy002Sprite.setTextureRect(sf::IntRect(48 * enemy002animationFrame, 0, 48, 48));
				}
			}

			
			enemy002animationFrame++;
			

			if (enemy002animationFrame >= 4) {
				enemy002animationFrame = 0;
			}

			//////////////////////////////////////////MAEDOSA002////////////////////////////////////////////////////////////

			if (enemy_Death[1] == 0) {

				if (enemy003Sprite.getPosition().x > shapeSprite.getPosition().x)
				{
					enemyRight1 = 1;
					enemy003Sprite.move(-0.01f, 0.00f);
					enemy003Sprite.setTextureRect(sf::IntRect(48 * enemy003animationFrame, 48 * 1, 48, 48));
				}
				if (enemy003Sprite.getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRight1 = 0;
					enemy003Sprite.move(0.01f, 0.00f);
					enemy003Sprite.setTextureRect(sf::IntRect(48 * enemy003animationFrame, 48 * 2, 48, 48));
				}
				if (enemy003Sprite.getPosition().y > shapeSprite.getPosition().y)
				{
					enemy003Sprite.move(0.00f, -0.01f);
					enemy003Sprite.setTextureRect(sf::IntRect(48 * enemy003animationFrame, 48 * 3, 48, 48));
				}
				if (enemy003Sprite.getPosition().y < shapeSprite.getPosition().y)
				{
					enemy003Sprite.move(0.00f, 0.01f);
					enemy003Sprite.setTextureRect(sf::IntRect(48 * enemy003animationFrame, 0, 48, 48));
				}
			}


			enemy003animationFrame++;

			if (enemy003animationFrame >= 4) {
				enemy003animationFrame = 0;
			}



			////////////////////////////////////////////MAEDOSA003////////////////////////////////////////////////////////////

			if (enemy_Death[2] == 0) {

				if (enemy004Sprite.getPosition().x > shapeSprite.getPosition().x)
				{
					enemyRight2 = 1;
					enemy004Sprite.move(-0.01f, 0.00f);
					enemy004Sprite.setTextureRect(sf::IntRect(48 * enemy004animationFrame, 48 * 1, 48, 48));
				}
				if (enemy004Sprite.getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRight2 = 0;
					enemy004Sprite.move(0.01f, 0.00f);
					enemy004Sprite.setTextureRect(sf::IntRect(48 * enemy004animationFrame, 48 * 2, 48, 48));
				}
				if (enemy004Sprite.getPosition().y > shapeSprite.getPosition().y)
				{
					enemy004Sprite.move(0.00f, -0.01f);
					enemy004Sprite.setTextureRect(sf::IntRect(48 * enemy004animationFrame, 48 * 3, 48, 48));
				}
				if (enemy004Sprite.getPosition().y < shapeSprite.getPosition().y)
				{
					enemy004Sprite.move(0.00f, 0.01f);
					enemy004Sprite.setTextureRect(sf::IntRect(48 * enemy004animationFrame, 0, 48, 48));
				}
			}

			enemy004animationFrame++;

			if (enemy004animationFrame >= 4) {
				enemy004animationFrame = 0;
			}

			////////////////////////////////////////////MAEDOSA004/////////////////////////////////////////////////////////////


			if (enemy_Death[3] == 0) {

				if (enemy005Sprite.getPosition().x > shapeSprite.getPosition().x)
				{
					enemyRight3 = 1;
					enemy005Sprite.move(-0.01f, 0.00f);
					enemy005Sprite.setTextureRect(sf::IntRect(48 * enemy005animationFrame, 48 * 1, 48, 48));
				}
				if (enemy005Sprite.getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRight3 = 0;
					enemy005Sprite.move(0.01f, 0.00f);
					enemy005Sprite.setTextureRect(sf::IntRect(48 * enemy005animationFrame, 48 * 2, 48, 48));
				}
				if (enemy005Sprite.getPosition().y > shapeSprite.getPosition().y)
				{
					enemy005Sprite.move(0.00f, -0.01f);
					enemy005Sprite.setTextureRect(sf::IntRect(48 * enemy005animationFrame, 48 * 3, 48, 48));
				}
				if (enemy005Sprite.getPosition().y < shapeSprite.getPosition().y)
				{
					enemy005Sprite.move(0.00f, 0.01f);
					enemy005Sprite.setTextureRect(sf::IntRect(48 * enemy005animationFrame, 0, 48, 48));
				}
			}

			enemy005animationFrame++;
			

			if (enemy005animationFrame >= 4) {
				enemy005animationFrame = 0;
			}


			////////////////////////////////////////////MAEDOSA005/////////////////////////////////////////////////////////

			if (enemy_Death[4] == 0) {

				if (enemy006Sprite.getPosition().x > shapeSprite.getPosition().x)
				{
					enemyRight4 = 1;
					enemy006Sprite.move(-0.01f, 0.00f);
					enemy006Sprite.setTextureRect(sf::IntRect(48 * enemy006animationFrame, 48 * 1, 48, 48));
				}
				if (enemy006Sprite.getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRight4 = 0;
					enemy006Sprite.move(0.01f, 0.00f);
					enemy006Sprite.setTextureRect(sf::IntRect(48 * enemy006animationFrame, 48 * 2, 48, 48));
				}
				if (enemy006Sprite.getPosition().y > shapeSprite.getPosition().y)
				{
					enemy006Sprite.move(0.00f, -0.01f);
					enemy006Sprite.setTextureRect(sf::IntRect(48 * enemy006animationFrame, 48 * 3, 48, 48));
				}
				if (enemy006Sprite.getPosition().y < shapeSprite.getPosition().y)
				{
					enemy006Sprite.move(0.00f, 0.01f);
					enemy006Sprite.setTextureRect(sf::IntRect(48 * enemy006animationFrame, 0, 48, 48));
				}
			}

			enemy006animationFrame++;

			if (enemy006animationFrame >= 4) {
				enemy006animationFrame = 0;
			}


			//////////////////////////////////////////////////////////MELEEATTACK_FOR_STATE@////////////////////////////////////////////////////////////////////////////



			///////////////////////////////////////////////FOR_ENEMY_001////////////////////////////////////////////////////////////////////////////////////////////

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));
				
					if (shapeSprite.getGlobalBounds().intersects(enemy002Sprite.getGlobalBounds())) {
						hit_Count_Sate2 = hit_Count_Sate2 + 1;
						if (enemyRight == 0)
						{
							enemy002Sprite.setPosition(enemy002Sprite.getPosition().x - 30, enemy002Sprite.getPosition().y);
						}
						if (hit_Count_Sate2 == 5)
						{
							enemy_Death[0] = 1;
							kill_CountState2 = kill_CountState2 + 1;
							enemy002Sprite.setPosition(-1000, -1000);
							
							score = score + 10;
						//std::cout << score << std::endl;
						std::stringstream ss;
						ss << score;
						scoreText.setString(ss.str());


						}
						enemyHit.play();
						
						
						
					
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy002Sprite.getGlobalBounds())) {
					hit_Count_Sate2 = hit_Count_Sate2 + 1;

					if (enemyRight == 1)
					{
						enemy002Sprite.setPosition(enemy002Sprite.getPosition().x + 30, enemy002Sprite.getPosition().y);
					}
					if (hit_Count_Sate2 == 5)
					{
						enemy_Death[0] = 1;

						kill_CountState2 = kill_CountState2 + 1;
						enemy002Sprite.setPosition(-1000, -1000);
						score = score + 10;
						//std::cout << score << std::endl;
						std::stringstream ss;
						ss << score;
						scoreText.setString(ss.str());

					}
				
					
					enemyHit.play();
					

				}
			}
		

			////////////////////////////////////////////////////////////////FOR_ENENMY_002///////////////////////////////////////////////////////////////////

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy003Sprite.getGlobalBounds())) {
					hit_Count_Sate2_1 = hit_Count_Sate2_1 + 1;

					if (enemyRight1 == 0)
					{
						enemy003Sprite.setPosition(enemy003Sprite.getPosition().x - 30, enemy003Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_1 == 5)
					{
						enemy_Death[1] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy003Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					enemyHit.play();
				
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy003Sprite.getGlobalBounds())) {
					hit_Count_Sate2_1 = hit_Count_Sate2_1 + 1;

					if (enemyRight1 == 1)
					{
						enemy003Sprite.setPosition(enemy003Sprite.getPosition().x + 30, enemy003Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_1 == 5)
					{
						enemy_Death[1] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy003Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}
			

			////////////////////////////////////////////////////////////FOR_ENEMY_003///////////////////////////////////////////////////////////////////////////


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy004Sprite.getGlobalBounds())) {
					hit_Count_Sate2_2 = hit_Count_Sate2_2 + 1;

					if (enemyRight2 == 0)
					{
						enemy004Sprite.setPosition(enemy004Sprite.getPosition().x - 30, enemy004Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_2 == 5)
					{
						enemy_Death[2] = 1;
						kill_CountState2 = kill_CountState2 + 1;
					enemy004Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy004Sprite.getGlobalBounds())) {
					hit_Count_Sate2_2 = hit_Count_Sate2_2 + 1;

					if (enemyRight2 == 1)
					{
						enemy004Sprite.setPosition(enemy004Sprite.getPosition().x + 30, enemy004Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_2 == 5)
					{
						enemy_Death[2] = 1;
						kill_CountState2 = kill_CountState2 + 1;
					enemy004Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}


			////////////////////////////////////////////////////////FOR_ENENMY_004////////////////////////////////////////////////////////////////////////////////


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy005Sprite.getGlobalBounds())) {
					hit_Count_Sate2_3 = hit_Count_Sate2_3 + 1;

					if (enemyRight3 == 0)
					{
						enemy005Sprite.setPosition(enemy005Sprite.getPosition().x - 30, enemy005Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_3 == 5)
					{
						enemy_Death[3] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy005Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy005Sprite.getGlobalBounds())) {
					hit_Count_Sate2_3 = hit_Count_Sate2_3 + 1;

					if (enemyRight3 == 1)
					{
						enemy005Sprite.setPosition(enemy005Sprite.getPosition().x + 30, enemy005Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_3 == 5)
					{
						enemy_Death[3] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy005Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}


			///////////////////////////////////////////////////////////////FOR_ENEMY_005////////////////////////////////////////////////////////////////////////////////////

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy006Sprite.getGlobalBounds())) {
					hit_Count_Sate2_4 = hit_Count_Sate2_4 + 1;

					if (enemyRight4 == 0)
					{
						enemy006Sprite.setPosition(enemy006Sprite.getPosition().x - 30, enemy006Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_4 == 5)
					{
						enemy_Death[4] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy006Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
			{
				attackSound.play();
				shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

				if (shapeSprite.getGlobalBounds().intersects(enemy006Sprite.getGlobalBounds())) {
					hit_Count_Sate2_4 = hit_Count_Sate2_4 + 1;

					if (enemyRight4 == 1)
					{
						enemy006Sprite.setPosition(enemy006Sprite.getPosition().x + 30, enemy006Sprite.getPosition().y);
					}

					if (hit_Count_Sate2_4 == 5)
					{
						enemy_Death[4] = 1;
						
						kill_CountState2 = kill_CountState2 + 1;
					enemy006Sprite.setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					}
					
					enemyHit.play();
					

				}
			}
			
			
		


///////////////////////////////////////////////////////////////////////////ENEMY_HIT_PLAYER//////////////////////////////////////////////////////////////////////////////////////////////

			if (enemy002Sprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (enemyRight == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;
					
					//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
				}

				if (enemyRight == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;
					
					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());
				}

				
				sound.play();
				

			}

            /////////////////////////////////////////////////ENEMY_2///////////////////////////////////////////////////

			if (enemy003Sprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (enemyRight1 == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;

				    //std::cout << hp << std::endl;
				    std::stringstream hpP;
				    hpP << hp;
				    hpPointText.setString(hpP.str());

				}

				if (enemyRight1 == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}

				sound.play();

				

			}

			///////////////////////////////////////ENEMY_3////////////////////////////////////////////////////

			if (enemy004Sprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (enemyRight2 == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;
				
					//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

				}

				if (enemyRight2 == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}

				sound.play();

				

			}

			///////////////////////////////////////ENEMY_4//////////////////////////////////////////////

			if (enemy005Sprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (enemyRight3 == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;
				
					//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


				}

				if (enemyRight3 == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}

				sound.play();

				
			}

            ////////////////////////////////////ENEMY_5////////////////////////////////////////////////////

			if (enemy006Sprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (enemyRight4 == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;
				
					//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
				}

				if (enemyRight4 == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
					hp = hp - 0.1;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}

				sound.play();

				

			}





			if (kill_CountState2 == 5)
			{
				doorSprite.setPosition(900, 300);
				window.draw(doorSprite);

			}

			if (doorSprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				doorsound.play();
				state = 3;

			}
			





		}

//////////////////////////////////////////////////////////////////////////////STATE_BOSS////////////////////////////////////////////////////////////////////////////////////////////////////


		else if (state == 3)
		{

		state3bgSprite.setTexture(state3bgTexture);
		window.draw(state3bgSprite);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && state == 3)
		{
			state = 0;


		}


		//fire update/////////////////////////////////////////////////////////////////////////////////////
		if (firedirection == 1) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 2, 64, 64));
			fireSprite.move(0, -1);
		}
		if (firedirection == 2) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 3, 64, 64));
			fireSprite.move(0, 1);
		}
		if (firedirection == 3) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
			fireSprite.move(-1, 0);
		}
		if (firedirection == 4) {
			fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 0, 64, 64));
			fireSprite.move(1, 0);
		}

		/////////////////////////////////////////////FIREATTACK/////////////////////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			fire.play();
			fireSprite.setPosition(shapeSprite.getPosition().x, shapeSprite.getPosition().y);
			//fireSprite.move(1.f, 0.f);
			//fireSprite.setTextureRect(sf::IntRect(64 * fireFrame, 64 * 1, 64, 64));
			firedirection = playerdirection;

		}


		if (enemyState3Sprite[0].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_1 = hit_Count_Sate3_1 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[0].setPosition(enemyState3Sprite[0].getPosition().x - 30, enemyState3Sprite[0].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[0].setPosition(enemyState3Sprite[0].getPosition().x + 30, enemyState3Sprite[0].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_1 == 7)
			{
				enemystate3_Death[0] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[0].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}

		if (enemyState3Sprite[1].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_2 = hit_Count_Sate3_2 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[1].setPosition(enemyState3Sprite[1].getPosition().x - 30, enemyState3Sprite[1].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[1].setPosition(enemyState3Sprite[1].getPosition().x + 30, enemyState3Sprite[1].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_2 == 7)
			{
				enemystate3_Death[1] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[1].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}

		if (enemyState3Sprite[2].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_3 = hit_Count_Sate3_3 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[2].setPosition(enemyState3Sprite[2].getPosition().x - 30, enemyState3Sprite[2].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[2].setPosition(enemyState3Sprite[2].getPosition().x + 30, enemyState3Sprite[2].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_3 == 7)
			{
				enemystate3_Death[2] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[2].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}

		if (enemyState3Sprite[3].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_4 = hit_Count_Sate3_4 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[3].setPosition(enemyState3Sprite[3].getPosition().x - 30, enemyState3Sprite[3].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[3].setPosition(enemyState3Sprite[3].getPosition().x + 30, enemyState3Sprite[3].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_4 == 7)
			{
				enemystate3_Death[3] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[3].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}


		if (enemyState3Sprite[4].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_5 = hit_Count_Sate3_5 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[4].setPosition(enemyState3Sprite[4].getPosition().x - 30, enemyState3Sprite[4].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[4].setPosition(enemyState3Sprite[4].getPosition().x + 30, enemyState3Sprite[4].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_5 == 7)
			{
				enemystate3_Death[4] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[4].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}

		if (enemyState3Sprite[5].getGlobalBounds().intersects(fireSprite.getGlobalBounds()))
		{
			hit_Count_Sate3_6 = hit_Count_Sate3_6 + 1;

			if (enemyRstateBoss1 == 0)
			{
				enemyState3Sprite[5].setPosition(enemyState3Sprite[5].getPosition().x - 30, enemyState3Sprite[5].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}

			else if (enemyRstateBoss1 == 1)
			{
				enemyState3Sprite[5].setPosition(enemyState3Sprite[5].getPosition().x + 30, enemyState3Sprite[5].getPosition().y);
				fireSprite.setPosition(4561, 4561);
			}
			if (hit_Count_Sate3_6 == 7)
			{
				enemystate3_Death[5] = 1;
				kill_CountState3 = kill_CountState3 + 1;
				enemyState3Sprite[5].setPosition(-1000, -1000);

				score = score + 10;
				//std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());

				hp = hp + 5;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());


			}
			enemyHit.play();


		}



		hpPointText.setFont(hpPoint);
		healthText.setFont(health);
		hpPointText.setPosition(160, 50);
		healthText.setPosition(0, 50);
		scoreText.setFont(font);
		

/////////////////////////////////////////////////////////////CHECKPOSITION_FOR_STATE_3///////////////////////////////////////////////////////////////////////////////////////////

		if (checksetpositionforstate3 == 0) {

			fireSprite.setPosition(-500, -500);
			shapeSprite.setPosition(spawnPoint);
			objtexture2.setPosition({ 0.f,350.f });
			objtexture3.setPosition({ 750.f,350.f });
			doorSprite.setPosition(3000, 3000);
			enemyState3Sprite[0].setPosition(enemyspawnPoint);
			enemyState3Sprite[1].setPosition(enemyspawnPoint1);
			enemyState3Sprite[2].setPosition(enemyspawnPoint2);
			enemyState3Sprite[3].setPosition(enemyspawnPoint3);
			enemyState3Sprite[4].setPosition(enemyspawnPoint4);
			enemyState3Sprite[5].setPosition(enemyspawnPoint5);

			hit_Count_Sate3_1 = 0;
			hit_Count_Sate3_2 = 0;
			hit_Count_Sate3_3 = 0;
			hit_Count_Sate3_4 = 0;
			hit_Count_Sate3_5 = 0;
			hit_Count_Sate3_6 = 0;


			enemystate3_Death[0] = 0;
			enemystate3_Death[1] = 0;
			enemystate3_Death[2] = 0;
			enemystate3_Death[3] = 0;
			enemystate3_Death[4] = 0;
			enemystate3_Death[5] = 0;

			boss_Death = 0;
			boss_Hit_Count = 0;

			bossSprite.setPosition(enemyspawnPoint7);


			checksetpositionforstate3 = 1;

		}

		enemyState3Sprite[0].setTextureRect(sf::IntRect(0, 0, 48, 48));
		enemyState3Sprite[1].setTextureRect(sf::IntRect(0, 0, 48, 48));
		enemyState3Sprite[2].setTextureRect(sf::IntRect(0, 0, 48, 48));
		enemyState3Sprite[3].setTextureRect(sf::IntRect(0, 0, 48, 48));
		enemyState3Sprite[4].setTextureRect(sf::IntRect(0, 0, 48, 48));
		enemyState3Sprite[5].setTextureRect(sf::IntRect(0, 0, 48, 48));

		bossSprite.setTextureRect(sf::IntRect(0, 0, 110, 145));

		

		////////////////MOVEMENT//////////////////


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && shapeSprite.getPosition().x + 32 <= 1080)
		{
			shapeSprite.move(0.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 2, 32, 48));
			right = 1;
			playerdirection = 4;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && shapeSprite.getPosition().x > 0)
		{
			shapeSprite.move(-0.1f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 1, 32, 48));
			right = 0;
			playerdirection = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && shapeSprite.getPosition().y > 0)
		{
			shapeSprite.move(0.f, -0.1f);
			shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 48 * 3, 32, 48));
			up = 1;
			playerdirection = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && shapeSprite.getPosition().y + 48 <= 720)
		{
			shapeSprite.move(0.f, 0.1f);
			shapeSprite.setTextureRect(sf::IntRect(32 * animationFrame, 0, 32, 48));
			up = 0;
			playerdirection = 2;
		}


		animationFrame++;

		if (animationFrame >= 4) {
			animationFrame = 0;
		}

/////////////////////////////////////////////////////////////////////////////////ENEMY_STATE_3_MOVEMENT/////////////////////////////////////////////////////////////////////////////////////////


		for (int enemy3Movement = 0; enemy3Movement < 6; enemy3Movement++)
		{

			if (enemystate3_Death[enemy3Movement] == 0) {

				if ((enemyState3Sprite[enemy3Movement].getPosition().x > shapeSprite.getPosition().x))
				{
					enemyRstateBoss1 = 1;
					enemyState3Sprite[enemy3Movement].move(-0.01f, 0.00f);
					enemyState3Sprite[enemy3Movement].setTextureRect(sf::IntRect(48 * enemyState3animationFrame, 48 * 1, 48, 48));
				}
				if (enemyState3Sprite[enemy3Movement].getPosition().x < shapeSprite.getPosition().x)
				{
					enemyRstateBoss1 = 0;
					enemyState3Sprite[enemy3Movement].move(0.01f, 0.00f);
					enemyState3Sprite[enemy3Movement].setTextureRect(sf::IntRect(48 * enemyState3animationFrame, 48 * 2, 48, 48));
				}
				if (enemyState3Sprite[enemy3Movement].getPosition().y > shapeSprite.getPosition().y)
				{
					enemyState3Sprite[enemy3Movement].move(0.00f, -0.01f);
					enemyState3Sprite[enemy3Movement].setTextureRect(sf::IntRect(48 * enemyState3animationFrame, 48 * 3, 48, 48));
				}
				if (enemyState3Sprite[enemy3Movement].getPosition().y < shapeSprite.getPosition().y)
				{
					enemyState3Sprite[enemy3Movement].move(0.00f, 0.01f);
					enemyState3Sprite[enemy3Movement].setTextureRect(sf::IntRect(48 * enemyState3animationFrame, 0, 48, 48));
				}
			}

		}

		enemyState3animationFrame++;

		if (enemyState3animationFrame >= 4) {
			enemyState3animationFrame = 0;
		}


/////////////////////////^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ENEMY_STATE_3_MOVEMENT^^^^^^^^^^^^^^^^^^^^//////////////////////////////////////////////////////////////////////////////////////////




		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[0].getGlobalBounds())) {
				hit_Count_Sate3_1 = hit_Count_Sate3_1 + 1;
 				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[0].setPosition(enemyState3Sprite[0].getPosition().x - 30, enemyState3Sprite[0].getPosition().y);
				}
				if (hit_Count_Sate3_1 == 7)
				{
					enemystate3_Death[0] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[0].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[0].getGlobalBounds())) {
				hit_Count_Sate3_1 = hit_Count_Sate3_1 + 1;
				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[0].setPosition(enemyState3Sprite[0].getPosition().x + 30, enemyState3Sprite[0].getPosition().y);
				}
				if (hit_Count_Sate3_1 == 7)
				{
					enemystate3_Death[0] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[0].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}
         /////////////////////////////////////ENEMY_02////////////////////////////////////////////////
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[1].getGlobalBounds())) {
				hit_Count_Sate3_2 = hit_Count_Sate3_2 + 1;

				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[1].setPosition(enemyState3Sprite[1].getPosition().x - 30, enemyState3Sprite[1].getPosition().y);
				}
				if (hit_Count_Sate3_2 == 7)
				{
					enemystate3_Death[1] = 1;

					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[1].setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}


				enemyHit.play();


			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[1].getGlobalBounds())) {
				hit_Count_Sate3_2 = hit_Count_Sate3_2 + 1;
				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[1].setPosition(enemyState3Sprite[1].getPosition().x + 30, enemyState3Sprite[1].getPosition().y);
				}
				if (hit_Count_Sate3_2 == 7)
				{
					enemystate3_Death[1] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[1].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}
				enemyHit.play();




			}
		}



		///////////////////////////////////ENEMY_3//////////////////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[2].getGlobalBounds())) {
				hit_Count_Sate3_3 = hit_Count_Sate3_3 + 1;
				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[2].setPosition(enemyState3Sprite[2].getPosition().x - 30, enemyState3Sprite[2].getPosition().y);
				}
				if (hit_Count_Sate3_3 == 7)
				{
					enemystate3_Death[2] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[2].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[2].getGlobalBounds())) {
				hit_Count_Sate3_3 = hit_Count_Sate3_3 + 1;

				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[2].setPosition(enemyState3Sprite[2].getPosition().x + 30, enemyState3Sprite[2].getPosition().y);
				}
				if (hit_Count_Sate3_3 == 7)
				{
					enemystate3_Death[2] = 1;

					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[2].setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}


				enemyHit.play();


			}
		}

        //////////////////////////////////////ENEMY_4////////////////////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[3].getGlobalBounds())) {
				hit_Count_Sate3_4 = hit_Count_Sate3_4 + 1;
				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[3].setPosition(enemyState3Sprite[3].getPosition().x - 30, enemyState3Sprite[3].getPosition().y);
				}
				if (hit_Count_Sate3_4 == 7)
				{
					enemystate3_Death[3] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[3].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[3].getGlobalBounds())) {
				hit_Count_Sate3_4 = hit_Count_Sate3_4 + 1;

				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[3].setPosition(enemyState3Sprite[3].getPosition().x + 30, enemyState3Sprite[3].getPosition().y);
				}
				if (hit_Count_Sate3_4 == 7)
				{
					enemystate3_Death[3] = 1;

					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[3].setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}


				enemyHit.play();

			}
		}

		////////////////////////////////////////ENENMY_5////////////////////////////////////////////////

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[4].getGlobalBounds())) {
				hit_Count_Sate3_5 = hit_Count_Sate3_5 + 1;
				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[4].setPosition(enemyState3Sprite[4].getPosition().x - 30, enemyState3Sprite[4].getPosition().y);
				}
				if (hit_Count_Sate3_5 == 7)
				{
					enemystate3_Death[4] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[4].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[4].getGlobalBounds())) {
				hit_Count_Sate3_5 = hit_Count_Sate3_5 + 1;

				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[4].setPosition(enemyState3Sprite[4].getPosition().x + 30, enemyState3Sprite[4].getPosition().y);
				}
				if (hit_Count_Sate3_5 == 7)
				{
					enemystate3_Death[4] = 1;

					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[4].setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}


				enemyHit.play();


			}
		}


		//////////////////////////////////////////////ENEMY_6///////////////////////////////////////////////////////


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[5].getGlobalBounds())) {
				hit_Count_Sate3_6 = hit_Count_Sate3_6 + 1;
				if (enemyRstateBoss1 == 0)
				{
					enemyState3Sprite[5].setPosition(enemyState3Sprite[5].getPosition().x - 30, enemyState3Sprite[5].getPosition().y);
				}
				if (hit_Count_Sate3_6 == 7)
				{
					enemystate3_Death[5] = 1;
					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[5].setPosition(-1000, -1000);

					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(enemyState3Sprite[5].getGlobalBounds())) {
				hit_Count_Sate3_6 = hit_Count_Sate3_6 + 1;

				if (enemyRstateBoss1 == 1)
				{
					enemyState3Sprite[5].setPosition(enemyState3Sprite[5].getPosition().x + 30, enemyState3Sprite[5].getPosition().y);
				}
				if (hit_Count_Sate3_6 == 7)
				{
					enemystate3_Death[5] = 1;

					kill_CountState3 = kill_CountState3 + 1;
					enemyState3Sprite[5].setPosition(-1000, -1000);
					score = score + 10;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

					hp = hp + 5;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());
				}


				enemyHit.play();


			}
		}


//////////////////////////////////////////////////////////////////////////////ENEMY_HIT_PLAYER_STATE_3/////////////////////////////////////////////////////////////////////////////////////////////

		if (enemyState3Sprite[0].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (enemyState3Sprite[1].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (enemyState3Sprite[2].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (enemyState3Sprite[3].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (enemyState3Sprite[4].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (enemyState3Sprite[5].getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (enemyRstateBoss1 == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (enemyRstateBoss1 == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 30, shapeSprite.getPosition().y);
				hp = hp - 0.1;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

//////////////////////////////////////////////////////////////////////////////////////BOSS_HUD///////////////////////////////////////////////////////////////////////////////////////

		
		


				


		
		if (boss_Death == 0) {

			if ((bossSprite.getPosition().x > shapeSprite.getPosition().x))
			{
				bossright = 1;
				bossSprite.move(-0.02f, 0.00f);
				bossSprite.setTextureRect(sf::IntRect(110 * bossAnimationFrame, 145 * 1, 110, 145));
			}
			if (bossSprite.getPosition().x < shapeSprite.getPosition().x)
			{
				bossright = 0;
				bossSprite.move(0.02f, 0.00f);
				bossSprite.setTextureRect(sf::IntRect(110 * bossAnimationFrame, 145 * 2, 110, 145));
			}
			if (bossSprite.getPosition().y > shapeSprite.getPosition().y)
			{
				bossSprite.move(0.00f, -0.02f);
				bossSprite.setTextureRect(sf::IntRect(110 * bossAnimationFrame, 145 * 3, 110, 145));
			}
			if (bossSprite.getPosition().y < shapeSprite.getPosition().y)
			{
				bossSprite.move(0.00f, 0.02f);
				bossSprite.setTextureRect(sf::IntRect(110 * bossAnimationFrame, 0, 110, 145));
			}
		}


		bossAnimationFrame++;

		
		
		if (bossAnimationFrame >= 4) {
			bossAnimationFrame = 0;
		}

		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 0)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 4, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(bossSprite.getGlobalBounds())) {
				boss_Hit_Count = boss_Hit_Count + 1;
				if (bossright == 0)
				{
					bossSprite.setPosition(bossSprite.getPosition().x - 30, bossSprite.getPosition().y);
				}
				if (boss_Hit_Count == 20)
				{
					boss_Death = 1;
					kill_CountState3 = kill_CountState3 + 1;
					bossSprite.setPosition(-1000, -1000);

					score = score + 100;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());


				}
				enemyHit.play();




			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && right == 1)
		{
			attackSound.play();
			shapeSprite.setTextureRect(sf::IntRect(64 * animationFrame, 48 * 5, 64, 48));

			if (shapeSprite.getGlobalBounds().intersects(bossSprite.getGlobalBounds())) {
				boss_Hit_Count = boss_Hit_Count + 1;

				if (bossright == 1)
				{
					bossSprite.setPosition(bossSprite.getPosition().x + 30, bossSprite.getPosition().y);
				}
				if (boss_Hit_Count == 20)
				{
					boss_Death = 1;

					kill_CountState3 = kill_CountState3 + 1;
					bossSprite.setPosition(-1000, -1000);
					score = score + 100;
					//std::cout << score << std::endl;
					std::stringstream ss;
					ss << score;
					scoreText.setString(ss.str());

				}


				enemyHit.play();


			}
		}


		
		if (bossSprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			if (bossright == 0)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x + 120, shapeSprite.getPosition().y);
				hp = hp - 15;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());
			}

			if (bossright == 1)
			{
				shapeSprite.setPosition(shapeSprite.getPosition().x - 120, shapeSprite.getPosition().y);
				hp = hp - 15;

				//std::cout << hp << std::endl;
				std::stringstream hpP;
				hpP << hp;
				hpPointText.setString(hpP.str());

			}

			sound.play();



		}

		if (fireSprite.getGlobalBounds().intersects(bossSprite.getGlobalBounds()))
		{
			if (bossright == 0)
			{
				bossSprite.setPosition(bossSprite.getPosition().x - 20, bossSprite.getPosition().y);
				fireSprite.setPosition(3210, 3210);
			}

			if (bossright == 1)
			{
				bossSprite.setPosition(bossSprite.getPosition().x + 20, bossSprite.getPosition().y);
				fireSprite.setPosition(3210, 3210);
			}
		}
		
		
		
	///////////////////////////////////BOSS_ENRAGE_MODE//////////////////////////////////	
		if (boss_Hit_Count >= 10)
		{
			if (boss_Death == 0) {

				if ((bossSprite.getPosition().x > shapeSprite.getPosition().x))
				{
					bossright = 1;
					bossSprite.move(-0.04f, 0.00f);
					bossSprite.setTextureRect(sf::IntRect(110 * bossEnrageAnimation, 145 * 1, 110, 145));
				}
				if (bossSprite.getPosition().x < shapeSprite.getPosition().x)
				{
					bossright = 0;
					bossSprite.move(0.04f, 0.00f);
					bossSprite.setTextureRect(sf::IntRect(110 * bossEnrageAnimation, 145 * 2, 110, 145));
				}
				if (bossSprite.getPosition().y > shapeSprite.getPosition().y)
				{
					bossSprite.move(0.00f, -0.04f);
					bossSprite.setTextureRect(sf::IntRect(110 * bossEnrageAnimation, 145 * 3, 110, 145));
				}
				if (bossSprite.getPosition().y < shapeSprite.getPosition().y)
				{
					bossSprite.move(0.00f, 0.04f);
					bossSprite.setTextureRect(sf::IntRect(110 * bossEnrageAnimation, 0, 110, 145));
				}
			}


			bossEnrageAnimation++;



			if (bossEnrageAnimation >= 4) {
				
				bossEnrageAnimation = 0;
			}


			if (bossSprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

				if (bossright == 0)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x + 150, shapeSprite.getPosition().y);
					hp = hp - 20;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());
				}

				if (bossright == 1)
				{
					shapeSprite.setPosition(shapeSprite.getPosition().x - 150, shapeSprite.getPosition().y);
					hp = hp - 20;

					//std::cout << hp << std::endl;
					std::stringstream hpP;
					hpP << hp;
					hpPointText.setString(hpP.str());

				}

				sound.play();

			}




		}
		




		window.draw(objtexture2);
		window.draw(objtexture3);
		window.draw(shapeSprite);
		window.draw(healthText);
		window.draw(hpPointText);
		window.draw(scoreText);
		window.draw(fireSprite);
		
		for (int enemystate3 = 0; enemystate3 < 6; enemystate3++)
		{

			if (enemystate3_Death[enemystate3] == 0)
			{
				window.draw(enemyState3Sprite[enemystate3]);
			}

		}


		

		
			window.draw(bossSprite);



		

		if (boss_Death == 1)
		{
			doorSprite.setPosition(900, 300);
			window.draw(doorSprite);

		}

		if (doorSprite.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {

			doorsound.play();
			state = 6;

		}
		
			
		

 }
		

		//////////////////////////////////////////////////////DEATH_NEWGAME////////////////////////////////////////////////////////////

		if (hp <= 0)
		{
			music.stop();
			themeMusic.play();

			hp = 0;

			state = 0;

			if (hp == 0)
			{
				state = 5;

				objtexture.setPosition(750, 350);

				checksetpositionforstate2 = 0;
				checksetpositionforstate3 = 0;

				kill_CountState1 = 0;
				kill_CountState2 = 0;
				kill_CountState3 = 0;

				hit_Count_Sate2 = 0;
				hit_Count_Sate2_1 = 0;
				hit_Count_Sate2_2 = 0;
				hit_Count_Sate2_3 = 0;
				hit_Count_Sate2_4 = 0;

				score = 0;
				hp = 100;
				std::cout << score << std::endl;
				std::stringstream ss;
				ss << score;
				scoreText.setString(ss.str());
				kill_CountState1 = 0;
				kill_CountState2 = 0;
				shapeSprite.setPosition(spawnPoint);
				enemySpriteVector[0].setPosition(enemyspawnPoint);
				enemySpriteVector[1].setPosition(enemyspawnPoint1);
				enemySpriteVector[2].setPosition(enemyspawnPoint2);

				enemySpriteVector[0].setTexture(enemyTexture);
				enemySpriteVector[1].setTexture(enemyTexture);
				enemySpriteVector[2].setTexture(enemyTexture);

				enemy002Sprite.setPosition(enemyspawnPoint1);
				enemy003Sprite.setPosition(enemyspawnPoint2);
				enemy004Sprite.setPosition(enemyspawnPoint3);
				enemy005Sprite.setPosition(enemyspawnPoint4);
				enemy006Sprite.setPosition(enemyspawnPoint5);

				enemyState3Sprite[0].setPosition(enemyspawnPoint);
				enemyState3Sprite[1].setPosition(enemyspawnPoint1);
				enemyState3Sprite[2].setPosition(enemyspawnPoint2);
				enemyState3Sprite[3].setPosition(enemyspawnPoint3);
				enemyState3Sprite[4].setPosition(enemyspawnPoint4);
				enemyState3Sprite[5].setPosition(enemyspawnPoint5);

				bossSprite.setPosition(enemyspawnPoint7);






				
			}
			std::cout << hp << std::endl;
			std::stringstream hpP;
			hpP << hp;
			hpPointText.setString(hpP.str());
		}



	
		else if (state == 0) {
			
			menu.draw(window);
			
			

		}

		else if (state == 5) {
			deadmenu.draw(window);
		}


		else if (state == 6) {
			hp = 100;
			score = 0;
			window.draw(hpPointText);
			window.draw(scoreText);
			endmenu.draw(window);
			doorSprite.setPosition(5000, 5000);

			hp = 100;

			std::cout << hp << std::endl;
			std::stringstream hpP;
			hpP << hp;
			hpPointText.setString(hpP.str());

			score = 0;

			std::cout << score << std::endl;
			std::stringstream ss;
			ss << score;
			scoreText.setString(ss.str());

		}
		


		if (hp % 10 == 0)
		{
			yareyare.play();
		}



		





		window.display();
	}
	return 0;
}
