#ifndef _MODULE_SHIELD_H_
#define _MODULE_SHIELD_H_

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

#define ROT_STEPS (8)
#define ROT_ANIM (2*ROT_STEPS)


struct SDL_Texture;

class ModuleShield : public Module{
public:
	ModuleShield();
	~ModuleShield();

	void OnCollision(Collider* col_1, Collider* col_2);
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Animation base_anim_2, lvl1_behind;
	Animation base_anim_3[2], lvl1_sides[2];
	Animation* current_base;


	SDL_Texture* graphics = nullptr;

	Animation base_anim, lvl1, lvl2, lvl3;
	Animation rotation_lvl1[ROT_ANIM];
	Animation rotation_level[ROT_ANIM];
	
	Animation* current_lvl;
	int timer;

	Collider* collider1;
	Collider* collider2;

	iPoint position1, position2;
	iPoint pos1_t1[ROT_STEPS], pos2_t1[ROT_STEPS];
	int circ;
	//int life = 3;
};

#endif // !_MODULE_SHIELD_
