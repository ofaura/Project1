#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 1000

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	int damage;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
	bool go;
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* enemy_death = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:

	Particle torpede;
	Particle torpedeFire;

	Particle ring1;
	Particle ring2;
	Particle ring3;
	Particle ring4;
	Particle ring5;

	Particle laser1, laser1_2, laser1_3; // 1
	Particle laser2_1, laser2_2, laser2_3a, laser2_3b, laser2_4a, laser2_4b, laser2_5, laser2_6; // 2
	Particle laser3[13]; // 3
	Particle laser4[13]; // 4

	Particle missile1_1, missile1_2, missile1_3a, missile1_3b;
	Particle missile2_1, missile2_2, missile2_3, missile2_4;
	Particle missile3;
	Particle missile4[8];

	Particle explosionP1;
	Particle explosionP2;
	Particle enemy_explosion;
	Particle enemy_hit;
	Particle enemy_explosion_alt;
	Particle meteor_explosion;

	Particle enemy_shot_yellow1;
	Particle enemy_shot_yellow2;

	Particle enemy_shot_blue1;
	Particle enemy_shot_blue2;
	Particle enemy_shot_blue3;
	Particle enemy_shot_blue4;
	Particle enemy_shot_blue5;
	Particle enemy_shot_blue6;

	Particle beamShotUp;
	Particle beamShotDown;

	Particle big_shot;

	// Shoots of the little turrets
	Particle enemy_shot_orange1u;
	Particle enemy_shot_orange2u;
	Particle enemy_shot_orange3u;
	Particle enemy_shot_orange4u;
	Particle enemy_shot_orange5u;
	Particle enemy_shot_orange6u;
	Particle enemy_shot_orange7u;
	Particle enemy_shot_orange8u;
	Particle enemy_shot_orange9u;

	Particle enemy_shot_orange1d;
	Particle enemy_shot_orange2d;
	Particle enemy_shot_orange3d;
	Particle enemy_shot_orange4d;
	Particle enemy_shot_orange5d;
	Particle enemy_shot_orange6d;
	Particle enemy_shot_orange7d;
	Particle enemy_shot_orange8d;
	Particle enemy_shot_orange9d;

	Particle ultimates[4][10];

	Particle enemy_missile1;
	Particle enemy_missile2;
};

#endif // __MODULEPARTICLES_H__