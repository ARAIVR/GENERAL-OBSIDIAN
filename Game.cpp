#include "Game.h"
#include <chrono>
#include "TextureManager.h"
#include "GameObject.h"
#include "Halo1.h"
#include "Halo2.h"
#include "PlayerLives.h"
#include "Playershot.h"
#include "Halo2_Monitor.h"
#include "Halo1_Monitor.h"
#include "Blockchain.h"
#include "Enemy002.h"
#include "RedPower.h"
#include <stdio.h>
#include <SDL_mixer.h>
#include <string>
#include <SDL_ttf.h>

#include "Particles.h"

#include "Map.h"
#include "ProcessInput.h"

//#include "ECS.h"
//#include "Components.h"
const int FPS = 30;
int shotmove;
int frametime5 = 0;
extern int GlobalVariableSCORE;
extern bool WinnerMines = false;
Halo2_Monitor* Halmon2;
Halo1_Monitor* Halmon1;
GameObject* player;
GameObject* player2;
GameObject* player3;
GameObject* player4;
GameObject* player5;
GameObject* player6;
GameObject* player7;
GameObject* player8;
GameObject* player9;
GameObject* player10;
GameObject* player11;
GameObject* player12;
GameObject* player13;
GameObject* player14;
GameObject* player15;
GameObject* player16;
GameObject* player17;



GameObject* player18;
GameObject* player19;
GameObject* player20;
GameObject* player21;
GameObject* player22;
GameObject* player23;
GameObject* player24;
GameObject* player25;
GameObject* player26;
GameObject* player27;
GameObject* player28;
GameObject* player29;
GameObject* player30;
GameObject* player31;
GameObject* player32;
GameObject* player33;

GameObject** waves;

Particles particles;

GameObject* SHOT1;
GameObject* SHOT2;
GameObject* SHOT3;
GameObject* diamonds;
GameObject* diamonds1;
PlayerLives* gamelives;
Enemy002* enemy1;
Enemy002* enemy2;
Halo1* halo;
Halo2* halo2;
Playershot* shot;
RedPower* redpower;

//pointer to get the srcREct of the GameObject for collision between ANY gameobject and Enemy class
SDL_Rect* _rect1;
//pointer to get the srcREct of the GameObject for collision between ANY gameobject and Enemy class
SDL_Rect* _rect2;

//create a pointer to a new game object
//Mix_Music *bgm = NULL;
//Mix_Chunk *sfx = NULL;
int damage_start2;
int damage_start1;
const int JOYSTICK_DEAD_ZONE = 8000;
int x, y;
int * _xposEnemy002;
int * _yposEnemy002;
int EnemyFrameTime = 0;
int DiamondCNT = 100;
//track lives by collisions to player gameobject
int * _lives = 0;
int * _srch;
int * _srcw;
//pointers to get the address and values of the GameObjects values
int * _xpos;
int * _ypos;
int holdlives = 0;
SDL_Texture *_txt;
SDL_Texture *_txt1;
SDL_Texture *_txt2;
int arz[];
bool bonus1 = false;

//halo pointer position

int * _haloxpos;
int * _haloypos;

int * _haloxpos2;
int * _haloypos2;

int * _XboxAxis1;
int * _XboxAxis2;

int *_shotx;
int *_shoty;

//halo2 monitor damage management pointer
int * _halmon2Dam;

int * _hal2Monxpos;
int * _hal2Monypos;

//halo1 monitor damage management pointer
int *_halmon1Dam;

int * _hal1Monxpos;
int * _hal1Monypos;

//Enemy motion pointers



int *_redPx;
int *_redPy;
SDL_Rect *_sdl_rect;



//std::vector<SDL_Event>& GetFrameEvents()
//{
//	static std::vector<SDL_Event> frame_events;
//	return frame_events;
//}

ProcessInput* input;
//Add the Halo that will use gameobject position

Enemy002::Enemy002(const char* texturesheet, int x, int y, SDL_Rect rec)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	srcRect = rec;
	_xposEnemy002 = &xpos;
	_yposEnemy002 = &ypos;
	_txt2 = objTexture;
	_rect2 = &srcRect;

}
RedPower::RedPower(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	_redPx = &xpos;
	_redPy = &ypos;


}
//definitions in the correct CPP file


PlayerLives::PlayerLives(const char* texturesheet, int x, int y, int a, int b, int c)

{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	Plives = a;
	srcH = b;
	srcW = c;
	_lives = &Plives;
	_srch = &srcH;
	_srcw = &srcW;
	_txt1 = objTexture;


}
Halo1_Monitor::Halo1_Monitor(const char* texturesheet, int x, int y, int _halo1state)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	Halo1_State = _halo1state;
	_hal1Monxpos = &xpos;
	_hal1Monypos = &ypos;
	_halmon1Dam = &Halo1_State;






}

Halo2_Monitor::Halo2_Monitor(const char* texturesheet, int x, int y, int _halo2state)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	Halo2_State = _halo2state;
	_hal2Monxpos = &xpos;
	_hal2Monypos = &ypos;
	_halmon2Dam = &Halo2_State;






}
GameObject::GameObject(const char* texturesheet, int x, int y, int a, int b, SDL_Rect rec, Map *m)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	srcRect = rec;
	xpos = x;
	ypos = y;
	XboxAxis1 = a;
	XboxAxis2 = b;

	//use pointers to get the address of the values of the Gameobjects for later use
	//use this same methond to randomise enemy spawn positions
	//This is an example of using pointers to extract the gameobject position
	_xpos = &xpos;
	_ypos = &ypos;
	_XboxAxis1 = &XboxAxis1;
	_XboxAxis2 = &XboxAxis2;
	_rect1 = &srcRect;
	_txt = objTexture;
}

Halo1::Halo1(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;


	//use pointers to get the address of the values of the Gameobjects for later use
	//use this same methond to randomise enemy spawn positions
	//This is an example of using pointers to extract the gameobject position

	//
	_haloxpos = &xpos;
	_haloypos = &ypos;


}


Halo2::Halo2(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;


	//use pointers to get the address of the values of the Gameobjects for later use
	//use this same methond to randomise enemy spawn positions
	//This is an example of using pointers to extract the gameobject position

	//
	_haloxpos2 = &xpos;
	_haloypos2 = &ypos;


}

//Playershot::Playershot(const char* texturesheet, int x, int y)
//{
//
//	objTexture = TextureManager::LoadTexture(texturesheet);
//
//	xpos = x;
//	ypos = y;
//
//
//	//use pointers to get the address of the values of the Gameobjects for later use
//	//use this same methond to randomise enemy spawn positions
//	//This is an example of using pointers to extract the gameobject position
//
//	//
//	_shotx = &xpos;
//	_shoty = &ypos;
//
//
//}

Map* map;

SDL_GameController *controller = nullptr;
//SDL_Renderer pointer we set to nullptr as we have not started yet
SDL_Renderer* Game::renderer = nullptr; Mix_Music *bmg = NULL;

//We can now call our components like UNITY!!!!

//Game constructor from Game.h header file

void Draw() {
	//
	//particles.Render(renderFrame);
}
Game::Game()
{}
//the deconstructor
Game::~Game()
{}
//Youtube Let's Make Games Tutorial SDL2
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	//{

	//}
	////sfx = Mix_LoadWAV("03 BIP.mp3");


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems Initialised..." << std::endl;


		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{


			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			}

			isRunning = true;

		}
		else {
			isRunning = false;
		}
	}

	//halo position set with xpos and ypos and use pointer 
	SHOT1 = new GameObject("assets/obsidian1.png", 300, 300, 0, 0, { 0, 0, 32, 32 },map);
	SHOT1->GetXPos();
	SHOT1->GetYPos();
	SHOT2 = new GameObject("assets/obsidian1.png", 1000, 300, 0, 0, { 0, 0, 32, 32 },map);
	SHOT2->GetXPos();
	SHOT2->GetYPos();
	SHOT3 = new GameObject("assets/obsidian1.png", 1000, 300, 0, 0, { 0, 0, 32, 32 },map);
	SHOT3->GetXPos();
	SHOT3->GetYPos();


	diamonds = new GameObject("assets/obsidian2.png", 300, 300, 0, 0, { 0, 0, 32, 32 },map);
	halo = new Halo1("assets/Halo1.png", 0, 0);
	halo2 = new Halo2("assets/Halo2.png", 0, 0);
	gamelives = new PlayerLives("assets/obsidian.png", 400, 0, 0, 32, 96);
	//shot = new Playershot("assets/obsidian1.png", 400,400,0, 0);

	//test this by changing to a for loop
	player2 = new GameObject("assets/aloo.png", 400, 300, 0, 1, { 0, 0, 32, 32 },map);
	player3 = new GameObject("assets/aloo.png", 400, 350, 0, 1, { 0, 0, 32, 32 },map);
	player4 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player5 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player6 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player7 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player8 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player9 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player10 = new GameObject("assets/aloo.png", 400, 300, 0, 1, { 0, 0, 32, 32 },map);
	player11 = new GameObject("assets/aloo.png", 400, 350, 0, 1, { 0, 0, 32, 32 },map);
	player12 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player13 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player14 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player15 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player16 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player17 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);



	player18 = new GameObject("assets/aloo.png", 400, 300, 0, 1, { 0, 0, 32, 32 },map);
	player19 = new GameObject("assets/aloo.png", 400, 350, 0, 1, { 0, 0, 32, 32 },map);
	player20 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player21 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player22 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player23 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player24 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player25 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player26 = new GameObject("assets/aloo.png", 400, 300, 0, 1, { 0, 0, 32, 32 },map);
	player27 = new GameObject("assets/aloo.png", 400, 350, 0, 1, { 0, 0, 32, 32 },map);
	player28 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player29 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player30 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player31 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player32 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	player33 = new GameObject("assets/aloo.png", 400, 400, 0, 1, { 0, 0, 32, 32 },map);
	

	waves = new GameObject*[21];
	for (int i = 0; i < 21; i++) waves[i] = new GameObject("assets/aloo2.png", -400, -400, 0, 1, { 0, 0, 32, 32 }, map);


	player = new GameObject("assets/obsidian.png", 400, 300, 0, 1, { 0, 0, 32, 32 },map);
	enemy1 = new Enemy002("assets/EnemyPurp104x104.png", 100, 0, { 104, 104, 104, 104 });
	enemy2 = new Enemy002("assets/EnemyPurp104x104.png", -70, 0, { 104, 104, 104, 104 });
	//correct method to get positions
	//Enemy002* enemy3 = new Enemy002("assets/EnemyPurp104x104.png", -90, 10);
	//the new object can now getXpos
	enemy2->GetXPos();
	enemy1->GetXPos();
	Halmon2 = new Halo2_Monitor("assets/halo2_lives 600x68.png", 0, 0, 100);
	Halmon1 = new Halo1_Monitor("assets/halo1_lives 600x68.png", 200, 0, 100);
	redpower = new RedPower("assets/haloRed.png", 500, 500);
	//background = new GameObject("assets/bg.png", renderer);	

	//call the gameobject pointer  dereference operator

	map = new Map();



}

void Game::handleEvents()
{
	//polling is where it is waiting to see what the status of the event is
	SDL_Event event;
	SDL_PollEvent(&event);

	//A switch statement is used depending on the status of the event that has been poll'd
	//Mix_PlayMusic(bgm, -1);


	//particles.Update();



	switch (event.type) {
	case SDL_QUIT:
		//When we click the X in our window the event handler will see that the handlerEvents isRunning is False
		//and stop the game running on its next loop
		isRunning = false;

		//Get the rect or two objects for this to work





	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:  *_xpos -= 45; *_haloxpos = *_xpos - 16;
			*_haloxpos2 = *_xpos - 32; *_haloypos = *_ypos - 16;
			*_haloypos2 = *_ypos - 32; break;
		case SDLK_RIGHT: *_xpos += 45; *_haloxpos = *_xpos - 16;
			*_haloxpos2 = *_xpos - 32; *_haloypos = *_ypos - 16;
			*_haloypos2 = *_ypos - 32; break;
		case SDLK_UP:   *_ypos -= 45; *_haloxpos = *_xpos - 16;
			*_haloxpos2 = *_xpos - 32; *_haloypos = *_ypos - 16;
			*_haloypos2 = *_ypos - 32; break;
		case SDLK_DOWN:  *_ypos += 45; *_haloxpos = *_xpos - 16;
			*_haloxpos2 = *_xpos - 32; *_haloypos = *_ypos - 16;
			*_haloypos2 = *_ypos - 32; break;
		case SDLK_a:  SHOT1->SetXPos(*_xpos - 90);
			SHOT1->SetYPos(*_ypos); 
			if (bonus1 == true) {
				SHOT2->SetXPos(*_xpos);
				SHOT2->SetYPos(*_ypos - 90);

			}
			
			break;
		case SDLK_d:  SHOT1->SetXPos(*_xpos + 90);
			SHOT1->SetYPos(*_ypos); 
			if (bonus1 == true) {
				SHOT2->SetXPos(*_xpos);
				SHOT2->SetYPos(*_ypos + 90);

			}
			
			break;
		}

		//set shot2 position after diamond bonus
		break;



	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Event handler
	//SDL_Event e;

	//These variables from the Game Object need to be seen in the Game.cpp
	//The SDL_Event is doing too much!!!
	bool quit;
	int xDir = 0;
	int yDir = 0;

	while (SDL_PollEvent(&event) != 0)
		/*{GetFrameEvents().push_back(event);
		}*/
	{


		//User requests quit
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}

		//	//This will hand the keyboard input for the main character
		//	//Set the proper message surface
		//	switch (event.key.keysym.sym)
		//	{
		//	case SDLK_UP:  std::cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
		//		*_xpos + 34; break;
		//	case SDLK_DOWN:  break;
		//	case SDLK_LEFT: break;
		//	case SDLK_RIGHT:  break;
		//	}



		else if (event.type == SDL_JOYAXISMOTION)
		{

			//Mix_PlayMusic(bgm, -1);

			//Motion on controller 0
			if (event.jaxis.which == 0)

			{
				//X axis motion
				//*_Xbox.... etc dereferenced
				if (event.jaxis.axis == *_XboxAxis1)
				{
					//Left of dead zone
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						xDir = -1;
						//xDir < 0;
						*_xpos -= 45;
						*_haloxpos = *_xpos - 16;
						*_haloxpos2 = *_xpos - 32;


					}
					//Right of dead zone
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						xDir = 1;
						//xDir > 0;

						*_xpos += 45;
						*_haloxpos = *_xpos - 16;
						*_haloxpos2 = *_xpos - 32;


					}
					else
					{
						xDir = 0;
					}
				}



				//Y axis motion
				//the objects created can have different controls Xbox Axis can siwtch left or right as the a and b parameter accepts int
				else if (event.jaxis.axis == *_XboxAxis2)
				{
					//Below of dead zone
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
					{
						yDir = -1;
						*_ypos -= 45;
						*_haloypos = *_ypos - 16;
						*_haloypos2 = *_ypos - 32;

					}
					//Above of dead zone
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
					{
						yDir = 1;
						*_ypos += 45;
						*_haloypos = *_ypos - 16;
						*_haloypos2 = *_ypos - 32;

					}
					else
					{
						yDir = 0;
					}
				}
			}




		}

		else if (event.type == SDL_JOYBUTTONDOWN) {

			//////////////////
			if (event.jbutton.which == 0)

			{
				if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A)

				{


					//Obsidian drop
					*_ypos += 34;
					//if (Mix_PlayingMusic() == 0)
					//{
					//	//Play the music
					//	Mix_PlayMusic(bgm, -1);
					//}

					/*	Mix_PlayChannel(-1, sfx, 0);*/



				}


				else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_B)
				{

					std::cout << "BUTTON B pressed>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;






					//Launch the shot with a velocity. When it hits the enemy with  a collsion return it to the position behind obsidian character
					switch (xDir) {

					case 0:
						xDir = 1;
						if (bonus1 == true) {
							SHOT2->SetXPos(*_xpos);
							SHOT2->SetYPos(*_ypos - 90);

						}

						SHOT1->SetXPos(*_xpos - 90);
						SHOT1->SetYPos(*_ypos);

						//this controls the movement across the sprite sheet
						//SHOT1->SetXPos = 90;
						/**_shotx = *_xpos - 90;
						*_shoty = *_ypos;*/

						//frametime5 = 0;



						break;

					case 1:
						xDir = -1;
						if (bonus1 == true) {
							SHOT2->SetXPos(*_xpos);
							SHOT2->SetYPos(*_ypos + 90);

						}
						SHOT1->SetXPos(*_xpos + 90);
						SHOT1->SetYPos(*_ypos);
						/**_shotx = *_xpos +90;
						*_shoty = *_ypos;*/
						break;

					default:
						break;
					}


					//switch (yDir) {

					//case 0:
					//	yDir = 1;




					//	//this controls the movement across the sprite sheet

					//	*_shotx = *_xpos;
					//	*_shoty = *_ypos -90;

					//	frametime5 = 0;



					//	break;

					//case 1:
					//	yDir= - 1;
					//	*_shotx = *_xpos;
					//	*_shoty = *_ypos + 90;
					//	break;

					//default:
					//	break;
					//}



				}
				else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_X & GlobalVariableSCORE <= 19999)
				{
					*_xpos = 400;
					*_ypos = 300;

				}
			}
		}


	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



}

//Handle events on queue

//poll for event to shoot and object

//this is a constructor

void addScore()
{

	GlobalVariableSCORE = GlobalVariableSCORE + 10;


}


void mineBlocks()
{

	if (bonus1=true ){
		bonus1 = false;
	Blockchain bChain = Blockchain();

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(Block(1, "Block 1 Data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(Block(2, "Block 2 Data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(Block(3, "Block 3 Data"));
	
	
	}
	
}





void Game::update()
{
	//player calls the Update using the class member access operator->
	//Map->map.lvl1[];

	
	particles.Update();

	
	//need to change the controller variable so
	//player is controlled by the left joystick
	//obsidiantarget is controlled by the right joystick
	diamonds->Update();
	player->Update();
	player2->Update();
	player3->Update();
	player4->Update();
	player5->Update();
	player6->Update();
	player7->Update();
	player8->Update();
	player9->Update();

	player10->Update();
	player11->Update();
	player12->Update();
	player13->Update();
	player14->Update();
	player15->Update();
	player16->Update();
	player17->Update();


	player18->Update();
	player19->Update();
	player20->Update();
	player21->Update();
	player22->Update();
	player23->Update();
	player24->Update();
	player25->Update();

	player26->Update();
	player27->Update();
	player28->Update();
	player29->Update();
	player30->Update();
	player31->Update();
	player32->Update();
	player33->Update();



	halo->Update();
	halo2->Update();
	SHOT1->Update();
	SHOT2->Update();
	SHOT3->Update();
	//shot->Update();
	Halmon2->Update();
	Halmon1->Update();
	gamelives->Update();
	enemy1->Update();
	enemy2->Update();
	redpower->Update();
	//function that determines how you can win the game by collisions player2 is an enemy
	//they can harm the player they are randomly generated
	//You must maintain the halos
	// destroy the enemies so you can collect and maintain the halo





	//restrict and penalty for going outside game area
	if (*_ypos >= 630) {

		*_ypos = 630;
	}

	if (*_ypos <= 0) {
		*_ypos = 0;

	}
	if (*_xpos >= 780) {

		*_xpos = 780;
	}
	if (*_xpos <= 0) {

		*_xpos = 0;
	}

	//test this if statement and see how fast it is with the for loop
	if (SHOT1->intersectsWithEnemy(*player2))
	{
		addScore();
		
	}
	if (SHOT1->intersectsWithEnemy(*player3))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player4))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player5))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player6))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player7))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player8))
	{
		addScore();
	}


	if (SHOT1->intersectsWithEnemy(*player9))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player10))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player11))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player12))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player13))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player14))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player15))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player16))
	{
		addScore();
	}


	if (SHOT1->intersectsWithEnemy(*player17))
	{
		addScore();
	}




	if (SHOT1->intersectsWithEnemy(*player18))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player19))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player20))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player21))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player22))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player23))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player24))
	{
		addScore();
	}


	if (SHOT1->intersectsWithEnemy(*player25))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player26))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player27))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player28))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player29))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player30))
	{
		addScore();
	}
	if (SHOT1->intersectsWithEnemy(*player31))
	{
		addScore();
	}

	if (SHOT1->intersectsWithEnemy(*player32))
	{
		addScore();
	}


	if (SHOT1->intersectsWithEnemy(*player33))
	{
		addScore();
	}

	

	for (int i = 0; i < 21; i++) {
		if (SHOT1->intersectsWithEnemy(*waves[i])) addScore();
	}


// test which is faster when a for loop is used for this function

	if (SHOT2->intersectsWithEnemy(*player2))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player3))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player4))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player5))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player6))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player7))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player8))
	{
		addScore();
	}


	if (SHOT2->intersectsWithEnemy(*player9))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player10))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player11))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player12))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player13))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player14))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player15))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player16))
	{
		addScore();
	}


	if (SHOT2->intersectsWithEnemy(*player17))
	{
		addScore();
	}




	if (SHOT2->intersectsWithEnemy(*player18))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player19))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player20))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player21))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player22))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player23))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player24))
	{
		addScore();
	}


	if (SHOT2->intersectsWithEnemy(*player25))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player26))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player27))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player28))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player29))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player30))
	{
		addScore();
	}
	if (SHOT2->intersectsWithEnemy(*player31))
	{
		addScore();
	}

	if (SHOT2->intersectsWithEnemy(*player32))
	{
		addScore();
	}


	if (SHOT2->intersectsWithEnemy(*player33))
	{
		addScore();
	}

	for (int i = 0; i < 21; i++) {
		if (SHOT2->intersectsWithEnemy(*waves[i])) addScore();
	}

	/*if (SHOT2->intersectsWithEnemy(*Wave1))
	{
	addScore();
	}*/

	
	/*if (*_halmon1Dam = 20) {
	*_srcw = 64;
	}*/

	if (player->intersectsWithEnemy(*diamonds))
	{
//activate second halo to destroy more enemies
		bonus1 = true;
		DiamondCNT = DiamondCNT + 3;
		std::cout << "Diamonds>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" + DiamondCNT << std::endl;
		*_halmon1Dam = *_halmon1Dam + 40;
		WinnerMines = true;

		




	}
	// more efficient way of testing intersect using array
	bool intersected = false;
	for (int i = 0; i < 21; i++) {
		if (player->intersectsWithEnemy(*waves[i])) intersected = true;
	}


	if (player->intersectsWithEnemy(*player2) == true 
		| player->intersectsWithEnemy(*player3) == true 
		| player->intersectsWithEnemy(*player4) == true 
		| player->intersectsWithEnemy(*player5) == true 
		| player->intersectsWithEnemy(*player6) == true 
		| player->intersectsWithEnemy(*player7) == true 
		| player->intersectsWithEnemy(*player8) == true 
		| player->intersectsWithEnemy(*player9) == true 
		| player->intersectsWithEnemy(*player10) == true 
		| player->intersectsWithEnemy(*player11) == true 
		| player->intersectsWithEnemy(*player12) == true 
		| player->intersectsWithEnemy(*player13) == true 
		| player->intersectsWithEnemy(*player14) == true 
		| player->intersectsWithEnemy(*player15) == true 
		| player->intersectsWithEnemy(*player16) == true 
		| player->intersectsWithEnemy(*player17) == true 
		| player->intersectsWithEnemy(*player18) == true 
		| player->intersectsWithEnemy(*player19) == true 
		| player->intersectsWithEnemy(*player20) == true 
		| player->intersectsWithEnemy(*player21) == true 
		| player->intersectsWithEnemy(*player22) == true 
		| player->intersectsWithEnemy(*player23) == true 
		| player->intersectsWithEnemy(*player24) == true 
		| player->intersectsWithEnemy(*player25) == true 
		| player->intersectsWithEnemy(*player26) == true 
		| player->intersectsWithEnemy(*player27) == true 
		| player->intersectsWithEnemy(*player28) == true 
		| player->intersectsWithEnemy(*player29) == true 
		| player->intersectsWithEnemy(*player30) == true 
		| player->intersectsWithEnemy(*player31) == true 
		| player->intersectsWithEnemy(*player32) == true 
		| player->intersectsWithEnemy(*player33) == true 
		| intersected)
	{

		std::cout << "NOTTTTTTTTTTtttttt WOOOOORKIING" + DiamondCNT << std::endl;
		//*_halmon1Dam = *_halmon1Dam - 20;




		int monitorCase = *_halmon1Dam;

		switch (monitorCase) {
		case 100:
			*_halmon1Dam = *_halmon1Dam - 20;
			break;

		case 80:
			*_halmon1Dam = *_halmon1Dam - 20;
			break;
		case 60:
			*_halmon1Dam = *_halmon1Dam - 20;
			break;
		case 40:
			*_halmon1Dam = *_halmon1Dam - 20;
			break;

		case 20:
			*_halmon1Dam = *_halmon1Dam - 20;



			*_srcw = *_srcw - 32;
			*_halmon1Dam = 100;


			break;
		case 0:
			holdlives++;
			break;
		default:
			break;


		}




		






	}

	//_rect1 pointer is for GameObject
	//_rect2 pointer is for Enemy002


	SDL_bool collision = SDL_HasIntersection(_rect1, _rect2);
	///*SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
	

	frametime5++;
	if (frametime5 == 120)

	{
		frametime5 = 0;

		//this controls the movement across the sprite sheet

		//*_shotx = *_xpos;



	}


	
	diamonds->SetXPos(rand() % 1000 + -345);
	
	cnt++;
	//if (player->GetXPos >= 600)
	//{



	//}
	//Replace the image for player 2 and set up as an enemy from the GameObject
	player2->SetXPos(rand() % 300 + 70);
	player2->SetYPos(rand() % 300 + 70);

	player3->SetXPos(rand() % 300 + 70);
	player3->SetYPos(rand() % 300 + 70);


	player4->SetXPos(rand() % 300 + 70);
	player4->SetYPos(rand() % 300 + 70);


	player5->SetXPos(rand() % 300 + 70);
	player5->SetYPos(rand() % 300 + 70);

	player6->SetXPos(rand() % 300 + 70);
	player6->SetYPos(rand() % 300 + 70);


	player7->SetXPos(rand() % 300 + 70);
	player7->SetYPos(rand() % 300 + 70);

	player8->SetXPos(rand() % 300 + 70);
	player8->SetYPos(rand() % 300 + 70);

	player9->SetXPos(rand() % 300 + 70);
	player9->SetYPos(rand() % 300 + 70);

	player10->SetXPos(rand() % 800 + 70);
	player10->SetYPos(rand() % 800 + 70);

	//player11->SetXPos(rand() % 800 + 70);
	player11->SetYPos(rand() % 800 + 70);


	player12->SetXPos(rand() % 800 + 70);
	player12->SetYPos(rand() % 800 + 70);


	player13->SetXPos(rand() % 800 + 70);
	//player13->SetYPos(rand() % 800 + 70);

	player14->SetXPos(rand() % 800 + 70);
	player14->SetYPos(rand() % 800 + 70);


	player15->SetXPos(rand() % 800 + 70);
	player15->SetYPos(rand() % 800 + 70);

	player16->SetXPos(rand() % 800 + 70);
	player16->SetYPos(rand() % 800 + 70);

	player17->SetXPos(rand() % 800 + 70);
	//player17->SetYPos(rand() % 800 + 70);


	player18->SetXPos(rand() % 300 + 70);
	player18->SetYPos(rand() % 300 + 70);

	player19->SetXPos(rand() % 300 + 70);
	player19->SetYPos(rand() % 300 + 70);


	player20->SetXPos(rand() % 300 + 70);
	player20->SetYPos(rand() % 300 + 70);


	player21->SetXPos(rand() % 300 + 70);
	player21->SetYPos(rand() % 300 + 70);

	player22->SetXPos(rand() % 300 + 70);
	player22->SetYPos(rand() % 300 + 70);


	player23->SetXPos(rand() % 300 + 70);
	player23->SetYPos(rand() % 300 + 70);

	player24->SetXPos(rand() % 300 + 70);
	player24->SetYPos(rand() % 300 + 70);

	player25->SetXPos(rand() % 300 + 70);
	player25->SetYPos(rand() % 300 + 70);

	player26->SetXPos(rand() % 800 + 70);
	player26->SetYPos(rand() % 800 + 70);

	//player27->SetXPos(rand() % 800 + 70);
	player27->SetYPos(rand() % 800 + 70);


	player28->SetXPos(rand() % 800 + 70);
	player28->SetYPos(rand() % 800 + 70);


	player29->SetXPos(rand() % 800 + 70);
	//player29->SetYPos(rand() % 800 + 70);

	player30->SetXPos(rand() % 800 + 70);
	player30->SetYPos(rand() % 800 + 70);


	player31->SetXPos(rand() % 800 + 70);
	player31->SetYPos(rand() % 800 + 70);

	player32->SetXPos(rand() % 800 + 70);
	player32->SetYPos(rand() % 800 + 70);


	//player33->SetYPos(rand() % 800 + 70);

	//Enemy movement if 800x640
	//if enemy position x and y bigger than game area bounce off edge and return


	/*
	if (*_halmon1Dam = 0) {
	*_srcw = -32;
	}*/

	if (*_srcw == 32)
	{

		GlobalVariableSCORE = 20000;
		*_xpos = -400;
		*_ypos = -300;




	}

	if (GlobalVariableSCORE > 301 & GlobalVariableSCORE <800)
	{

		*_xpos = -400;
		*_ypos = -300;

		mineBlocks();
		
	}





	if (GlobalVariableSCORE > 100) {

		WinnerMines = true;
		waves[0]->SetYPos(rand() % 300 + 20);
		waves[0]->SetXPos(rand() % 200 + 20);
		waves[1]->SetYPos(rand() % 500 + 70);
		waves[1]->SetXPos(rand() % 300 + 90);
		waves[2]->SetYPos(rand() % 500 + 20);
		waves[2]->SetXPos(rand() % 600 + 201);
		waves[3]->SetYPos(rand() % 300 + 60);
		waves[3]->SetXPos(rand() % 200 + 50);
		waves[4]->SetYPos(rand() % 400 + 201);
		waves[4]->SetXPos(rand() % 400 + 50);
		waves[5]->SetYPos(rand() % 700 + 70);
		waves[5]->SetXPos(rand() % 800 + 30);
		waves[6]->SetYPos(rand() % 300 + 20);
		waves[6]->SetXPos(rand() % 500 + 45);
		waves[7]->SetYPos(rand() % 300 + 76);
		waves[7]->SetXPos(rand() % 200 + 23);
		waves[8]->SetYPos(rand() % 800 + 89);
		waves[8]->SetXPos(rand() % 500 + 56);
		waves[9]->SetYPos(rand() % 400 + 200);
		waves[9]->SetXPos(rand() % 300 + 101);
		waves[10]->SetYPos(rand() % 600 + 90);
		waves[10]->SetYPos(rand() % 500 + 90);


		waves[11]->SetXPos(rand() % 200 + 20);
		waves[11]->SetYPos(rand() % 500 + 70);
		waves[12]->SetXPos(rand() % 300 + 90);
		waves[12]->SetYPos(rand() % 500 + 20);
		waves[13]->SetXPos(rand() % 600 + 201);
		waves[13]->SetYPos(rand() % 300 + 60);
		waves[14]->SetXPos(rand() % 200 + 50);
		waves[14]->SetYPos(rand() % 400 + 201);
		waves[15]->SetXPos(rand() % 400 + 50);
		waves[15]->SetYPos(rand() % 700 + 70);
		waves[16]->SetXPos(rand() % 800 + 30);
		waves[16]->SetYPos(rand() % 300 + 20);
		waves[17]->SetXPos(rand() % 500 + 45);
		waves[17]->SetYPos(rand() % 300 + 76);
		waves[18]->SetXPos(rand() % 200 + 23);
		waves[18]->SetYPos(rand() % 800 + 89);
		waves[19]->SetXPos(rand() % 500 + 56);
		waves[19]->SetYPos(rand() % 400 + 200);
		waves[20]->SetXPos(rand() % 300 + 101);
		waves[20]->SetYPos(rand() % 600 + 90);


		//waves[0]->Update();
	
		for (int i = 0; i < 21; i++) waves[i]->Update();


		std::cout << "****************************************************************88" << std::endl;
	}
	SDL_Renderer *renderTarget = nullptr;
	SDL_AudioInit("waveout");
	TTF_Font *font = TTF_OpenFont("comic.ttf", 20);
	SDL_Color color = { 0,255,255,255 };
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, "score--------------------------------", color);
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderTarget, textSurface);
	SDL_Rect textRect;
	textRect.x = textRect.y = 35;

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
	SDL_FreeSurface(textSurface);
	textSurface = nullptr;
	SDL_RenderCopy(renderTarget, text, NULL, &textRect);

	SDL_UpdateWindowSurface(window);

	SDL_SetRenderDrawColor(renderTarget, 0xFF, 0, 0, 0xFF);
	
	//************************************************************************
	//ENEMIES and their pointers to control their movement
	//This needs to be trasferred to an array
	SDL_RenderPresent(renderTarget);
	text = nullptr;
	TTF_CloseFont(font);
	TTF_Quit();
	IMG_Quit();
}
// this is called to render our objects to the screen
void Game::render()
{


	

	SDL_RenderClear(renderer);
	//This is where we add stuff to render
	//We will now call the playerTex
	//This has a layer order. The bottom one will be at the top of the surface
	//as it is rendered last
	map->DrawMap();
	//shot->Render();
	diamonds->Render();
	
	//test this for speedby making into a loop
	SHOT1->Render();
	SHOT2->Render();
	SHOT3->Render();
	player->Render();
	player2->Render();
	player3->Render();
	player4->Render();
	player5->Render();
	player6->Render();
	player7->Render();
	player8->Render();
	player9->Render();


	player10->Render();
	player11->Render();
	player12->Render();
	player13->Render();
	player14->Render();
	player15->Render();
	player16->Render();
	player17->Render();


	player18->Render();
	player19->Render();
	player20->Render();
	player21->Render();
	player22->Render();
	player23->Render();
	player24->Render();
	player25->Render();


	player26->Render();
	player27->Render();
	player28->Render();
	player29->Render();
	player30->Render();
	player31->Render();
	player32->Render();
	player33->Render();



	halo->Render();
	halo2->Render();
	//Halmon2->Render();
	Halmon1->Render();
	gamelives->Render();
	enemy1->Render();
	enemy2->Render();
	redpower->Render();

	for (int i = 0; i < 21; i++) waves[i]->Render();


	











	SDL_RenderPresent(renderer);







}

void Game::clean()
{
	cnt = 0;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_GameControllerClose(controller);
	
	//TTF_CloseFont(font);
	//Mix_FreeChunk(sfx);
	//Mix_FreeMusic(bgm);
	//bgm = nullptr;
	//text = nullptr;
	//Mix_Quit();
	controller = NULL;
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();


	std::cout << "Game Cleaned" << std::endl;



}