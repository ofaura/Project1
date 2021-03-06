#include "Globals.h"
#include "Application.h"
#include "ModuleSceneLevel5.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBonus.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleUserInterface.h"
#include "ModuleEnemyBoss.h"
#include "ModuleShield.h"
#include "ModuleShield_p2.h"

ModuleSceneLevel5::ModuleSceneLevel5()
{
	// Background 
	background.x = 10;
	background.y = 0;
	background.w = 3970;
	background.h = 199;

	meteorites1.x = 200;
	meteorites1.y = 38;
	meteorites1.w = 1554;
	meteorites1.h = 240;

	meteorites2.x = 9;
	meteorites2.y = 15;
	meteorites2.w = 3766;
	meteorites2.h = 224;
	
	// Scenario
	pipeline1.x = 81;
	pipeline1.y = 11;
	pipeline1.w = 43;
	pipeline1.h = 112;

	pipeline2.x = 63;
	pipeline2.y = 11;
	pipeline2.w = 12;
	pipeline2.h = 112;

	pipeline3.x = 173;
	pipeline3.y = 11;
	pipeline3.w = 25;
	pipeline3.h = 48;

	pipeline4.x = 138;
	pipeline4.y = 10;
	pipeline4.w = 16;
	pipeline4.h = 128;

	trash1.x = 8;
	trash1.y = 19;
	trash1.w = 32;
	trash1.h = 61;

	trash2.x = 113;
	trash2.y = 153;
	trash2.w = 46;
	trash2.h = 63;

	trash3.x = 16;
	trash3.y = 153;
	trash3.w = 48;
	trash3.h = 48;

	pilar.x = 210;
	pilar.y = 10;
	pilar.w = 47;
	pilar.h = 64;

	rock1.x = 8;
	rock1.y = 246;
	rock1.w = 191;
	rock1.h = 128;

	rock2.x = 214;
	rock2.y = 262;
	rock2.w = 191;
	rock2.h = 112;
}

ModuleSceneLevel5::~ModuleSceneLevel5()
{}

// Load assets
bool ModuleSceneLevel5::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	//Textures are loaded
	background_texture = App->textures->Load("Assets/Sprites/lvl5/Background/background5.png");
	meteorites_texture1 = App->textures->Load("Assets/Sprites/lvl5/Background/meteorites1.png");
	meteorites_texture2 = App->textures->Load("Assets/Sprites/lvl5/Background/meteorites2.png");
	scenario_texture = App->textures->Load("Assets/Sprites/lvl5/Background/Scenario.png");

	if (IsEnabled()) {
		if (App->player->IsEnabled() == false) {
			App->player->Enable();
		}
	}
	if (IsEnabled() == false) {
		if (App->player->IsEnabled() == true) {
			App->player->Disable();
		}
	}

	App->user_interface->Enable();

	// Reseting the camera to the start of the level
	App->render->camera.x = App->render->camera.y = 0;
	App->render->camera.w = SCREEN_WIDTH;
	App->render->camera.h = SCREEN_HEIGHT;

	//Enemies ---
	App->enemies->Enable();	

	//App->enemies->AddEnemy(ENEMY_TYPES::PIXEL, 500, (SCREEN_HEIGHT / 2) - 20);

	
	
	
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 300, (SCREEN_HEIGHT / 2 - 20));
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 1175, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 2060, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 2925, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 3800, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 4675, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 5550, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 6425, (SCREEN_HEIGHT / 2) - 20);
	
	// Rotating Green Ball
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 500, (SCREEN_HEIGHT / 2) - 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 1000, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 1500, (SCREEN_HEIGHT / 2) - 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 2000, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 2500, (SCREEN_HEIGHT / 2) - 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 3000, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 3500, (SCREEN_HEIGHT / 2) - 20);
	//App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 4000, (SCREEN_HEIGHT / 2) - 20);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_BALL, 4500, (SCREEN_HEIGHT / 2) - 20);
	
	// Mines
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 760, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 800, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 860, 10);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 900, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 960, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINE, 1000, 150);
		
	// Shuttle
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1250, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1265, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1280, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1295, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1310, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1325, 70);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1500, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1515, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1530, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1545, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1560, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 1575, 120);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 2600, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 2615, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 2630, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 2645, 60);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5800, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5815, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5830, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5845, 90);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5875, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5890, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5905, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SHUTTLE, 5920, 60);

	// Enemy Wasp
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 1400, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 1450, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 1500, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 1550, 100);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 4425, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 4465, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_WASP, 4505, 100);

	// Little turret
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_UP, 1750, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_UP, 1796, 63);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_UP, 1835, 49);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_UP, 1875, 38);

	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 2195, 181);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 2248, 165);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 2297, 176);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 2353, 185);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 2420, 186);

	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 3456, 190);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 3612, 197);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 3712, 190);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 3784, 173);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 3878, 193);

	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 4942, 190);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 4977, 172);
	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_DOWN, 5178, 195);

	App->enemies->AddEnemy(ENEMY_TYPES::LITTLE_TURRET_UP, 6295, 202);

	// Enemy Solar Panel
	App->enemies->AddEnemy(ENEMY_TYPES::SOLAR_PANEL, 2580, 150);
	App->enemies->AddEnemy(ENEMY_TYPES::SOLAR_PANEL, 2650, 70);
	
	// Enemy Beyblade
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_BEYBLADE, 2100, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_BEYBLADE, 2150, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_BEYBLADE, 2200, 140);

	// Enemy Xwing
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2275, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2300, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2325, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2350, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2375, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2450, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2475, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2500, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 2525, 90);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6000, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6025, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6050, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6075, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6100, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6125, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_XWING, 6150, 90);

	// Enemy spinner
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER, 2750, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER, 2850, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER, 2850, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER, 2950, 100);

	// Enemy spinner up
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 450, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 470, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 490, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 510, -20);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 5650, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 5670, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 5690, -20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_UP, 5710, -20);

	// Enemy spinner down
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 570, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 590, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 610, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 630, 240);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 4890, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 4910, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 4930, 240);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPINNER_DOWN, 4950, 240);
	
	// Enemy ninja ball
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6450, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6465, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6480, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6500, 105);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6510, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6525, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6545, 55);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6570, 130);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6580, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6600, 80);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6620, 110);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6615, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6630, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6645, 105);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6660, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6685, 95);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6700, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6725, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6735, 100);
	App->enemies->AddEnemy(ENEMY_TYPES::NINJA_BALL, 6770, 60);
	
	// Green plane
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5300, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5320, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5340, 140);

	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5380, 170);	
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5400, 170);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN_PLANE, 5420, 170);

	// Missile thrower
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE_THROWER, 5720, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE_THROWER, 5760, 70);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE_THROWER, 5800, 40);
	App->enemies->AddEnemy(ENEMY_TYPES::MISSILE_THROWER, 5840, 60);

	// Spaceship
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6235, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6250, 50);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6265, 50);

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6235, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6250, 160);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_SPACESHIP, 6265, 160);

	// Enemy in pipelines
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 4871, 200);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 4856, 48);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 5096, 178);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 5112, 145);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 5511, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_PIPELINER, 6265, 110);

	// Mechromancer
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MECHROMANCER, 6720, 90);

	// Meteorites
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 340, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 390, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 400, 180);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 400, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 430, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 350, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 500, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 500, 180);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 530, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 560, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 510, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 560, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 600, 140);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 680, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 600, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 630, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 700, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 700, 120);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 720, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 800, 20);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 800, 30);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 830, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 900, 90);
	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_METEORITE, 950, 120);
	
	
	// Colliders ---
	App->collision->Enable();
	
	// Meteorite 1
	App->collision->AddCollider({ 1028, 86, 38, 6 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1013, 92, 67, 20 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1005, 112, 78, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1012, 132, 60, 5 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1017, 137, 52, 7 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1028, 144, 35, 8 }, COLLIDER_WALL);	
	
	// Meteorite 2
	App->collision->AddCollider({ 1220, 6, 72, 9 }, COLLIDER_WALL);		
	App->collision->AddCollider({ 1205, 15, 102, 20 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1197, 35, 108, 22 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1207, 57, 89, 8 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1220, 65, 69, 11 }, COLLIDER_WALL);	

	// Meteorite 3
	App->collision->AddCollider({ 1396, 182, 72, 9 }, COLLIDER_WALL);		
	App->collision->AddCollider({ 1381, 191, 102, 20 }, COLLIDER_WALL);	
	App->collision->AddCollider({ 1373, 211, 108, 30 }, COLLIDER_WALL);	
		
	App->collision->AddCollider({ 1581, 52, 48, 40 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1725, 0, 191, 41 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1767, 41, 55, 22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1822, 41, 40, 10 }, COLLIDER_WALL);

	App->collision->AddCollider({ 2155, 214, 24, 18 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2179, 195, 36, 37 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2215, 176, 70, 56 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2285, 186, 50, 46 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2335, 199, 46, 33 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2381, 193, 27, 39 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2408, 202, 42, 30 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2450, 209, 14, 23 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2464, 213, 5, 19 }, COLLIDER_WALL);  //same meteorite
	App->collision->AddCollider({ 2469, 216, 11, 16 }, COLLIDER_WALL); //same meteorite
	App->collision->AddCollider({ 2480, 223, 10, 9 }, COLLIDER_WALL);  //same meteorite

	App->collision->AddCollider({ 2363, 0, 191, 49 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2405, 49, 55, 22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 2460, 49, 40, 10 }, COLLIDER_WALL);
	
	// Start of the second half
	App->collision->AddCollider({ 3438, 218, 551, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3441, 208, 525, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3624, 201, 47, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3880, 201, 47, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3447, 203, 158, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3703, 203, 158, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3473, 192, 109, 11 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3731, 192, 109, 11 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3480, 186, 65, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 3736, 186, 65, 6 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 4272, 0, 177, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4275, 6, 166, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4303, 24, 69, 23 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4372, 24, 35, 13 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6176, 0, 177, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6178, 6, 166, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6206, 24, 69, 23 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6275, 24, 35, 13 }, COLLIDER_WALL);

	App->collision->AddCollider({ 4852, 87, 57, 14 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4840, 101, 79, 41 }, COLLIDER_WALL);

	App->collision->AddCollider({ 4504, 199, 15, 25 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4519, 190, 14, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4533, 171, 34, 53 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4567, 156, 68, 68 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4635, 166, 41, 60 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4676, 170, 19, 54 }, COLLIDER_WALL);

	App->collision->AddCollider({ 4934, 204, 32, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 4966, 186, 68, 38 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5034, 193, 44, 31 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5078, 200, 76, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5154, 208, 44, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5198, 218, 19, 6 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5080, 72, 9, 22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5089, 69, 7, 31 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5096, 60, 58, 41 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5117, 52, 19, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5092, 100, 46, 4 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5154, 67, 4, 30 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5235, 0, 29, 41 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5264, 0, 64, 61 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5328, 0, 36, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5364, 0, 34, 39 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5398, 0, 14, 24 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5481, 112, 75, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5483, 127, 62, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5489, 92, 66, 19 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5503, 146, 27, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5510, 86, 28, 7 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5580, 211, 14, 13 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5594, 200, 14, 24 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5608, 187, 32, 37 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5640, 172, 66, 52 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5706, 187, 53, 42 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5759, 190, 40, 34 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5799, 186, 91, 38 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5890, 196, 44, 33 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5934, 204, 29, 20 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5963, 215, 12, 9 }, COLLIDER_WALL);

	App->collision->AddCollider({ 5719, 0, 12, 8 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5732, 0, 14, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5746, 0, 53, 26 }, COLLIDER_WALL);
	App->collision->AddCollider({ 5799, 0, 90, 20}, COLLIDER_WALL);
	App->collision->AddCollider({ 5889, 0, 56, 27}, COLLIDER_WALL);
	App->collision->AddCollider({ 5945, 0, 17, 19}, COLLIDER_WALL);
	App->collision->AddCollider({ 5962, 0, 12, 9 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6011, 83, 7, 22 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6018, 65, 14, 47 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6032, 52, 57, 68 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6089, 63, 27, 43 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6249, 167, 8, 18 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6257, 165, 8, 31 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6265, 157, 61, 41 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6283, 148, 20, 9 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6287, 198, 25, 3 }, COLLIDER_WALL);

	App->collision->AddCollider({ 6573, 213, 15, 10 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6588, 200, 9, 23 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6597, 189, 30, 35 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6627, 189, 81, 42 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6631, 176, 58, 6 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6633, 171, 43, 5 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6655, 164, 16, 7 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6708, 185, 51, 99 }, COLLIDER_WALL);
	App->collision->AddCollider({ 6716, 178, 19, 7 }, COLLIDER_WALL);
	
	App->collision->AddCollider({ 6620, 182, 100, 7 }, COLLIDER_WALL);
	
	//Audio ---
	App->audio->PlayMusic("Assets/Audio/Music/level5.ogg", 1.0f);

	return ret;
}

// Update: draw background
update_status ModuleSceneLevel5::Update()
{
	if (App->render->camera.x >= 0 && App->render->camera.x <= 7150 * SCREEN_SIZE)
	{
		App->render->camera.x += 1 * SCREEN_SIZE;
		App->player->position.x += 1;
		App->player2->position.x += 1;
	}
	else {
		if (App->boss->IsEnabled() == false) {
			App->boss->Enable();
		}
	}

	//Win condition
	if (App->boss->dead)
	{
		App->boss->dead = false;
		App->fade->FadeToBlack(App->level5, App->bonus, 1.0f);
	}

	App->render->Blit(background_texture, ((background_pos_x) / 3.5), 20, &background, 0.5f, true);

	// Details of the level
	App->render->Blit(scenario_texture, 4313, 32, &pilar, 1.0f, true);
	App->render->Blit(scenario_texture, 4227, 80, &rock1, 1.0f, true);
	App->render->Blit(scenario_texture, 4589, 95, &pilar, 1.0f, true);
	App->render->Blit(scenario_texture, 4535, background_pos_y, &rock2, 1.0f, true);
	App->render->Blit(scenario_texture, 4858, background_pos_y, &pipeline1, 1.0f, true);
	App->render->Blit(scenario_texture, 4873, 128, &pipeline2, 1.0f, true);
	App->render->Blit(scenario_texture, 5113, 96, &pipeline1, 1.0f, true);
	App->render->Blit(scenario_texture, 5098, 96, &pipeline2, 1.0f, true);
	App->render->Blit(scenario_texture, 5113, 5, &trash1, 1.0f, true);
	App->render->Blit(scenario_texture, 5321, 32, &trash3, 1.0f, true);
	App->render->Blit(scenario_texture, 5371, 48, &trash2, 1.0f, true);
	App->render->Blit(scenario_texture, 5513, background_pos_y, &pipeline2, 1.0f, true);
	App->render->Blit(scenario_texture, 5570, 98, &trash2, 1.0f, true);
	App->render->Blit(scenario_texture, 5703, 149, &trash3, 1.0f, true);
	App->render->Blit(scenario_texture, 5600, background_pos_y, &pipeline3, 1.0f, true);
	App->render->Blit(scenario_texture, 5915, 20, &pipeline3, 1.0f, true);
	App->render->Blit(scenario_texture, 6265, 20, &pipeline4, 1.0f, true);

	// Meteorites
	App->render->Blit(meteorites_texture1, 1000, background_pos_y, &meteorites1, 1.0f, true);
	App->render->Blit(meteorites_texture2, 3000, background_pos_y, &meteorites2, 1.0f, true);

	return UPDATE_CONTINUE;
}

// Load assets
bool ModuleSceneLevel5::CleanUp()
{
	// Remove all memory leaks
	LOG("Unloading textures");
	App->textures->Unload(scenario_texture);
	App->textures->Unload(meteorites_texture2);
	App->textures->Unload(meteorites_texture1);
	App->textures->Unload(background_texture);

	App->collision->CleanUp();

	App->user_interface->Disable();
	App->enemies->CleanUp();
	App->enemies->Disable();
	
	App->collision->Disable();
	App->player->Disable();

	if (App->boss->IsEnabled() == true)
		App->boss->Disable();	
	
	if(App->shield->IsEnabled() == true)
		App->shield->Disable();

	if (App->shield_p2->IsEnabled() == true)
		App->shield_p2->Disable();

	if (App->player2->IsEnabled() == true)
		App->player2->Disable();

	return true;
}