#ifndef __MODULESCENELEVEL5_H__
#define __MODULESCENELEVEL5_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneLevel5 : public Module
{
public:
	ModuleSceneLevel5();
	~ModuleSceneLevel5();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_texture = nullptr;
	SDL_Texture* ground_texture = nullptr;
	SDL_Texture* background2_texture = nullptr;
	SDL_Texture* background3_texture = nullptr;
	SDL_Texture* moon_tex = nullptr;
	SDL_Texture* mars_tex = nullptr;

	SDL_Rect ground;
	SDL_Rect background;
	SDL_Rect background2;
	SDL_Rect background3;
	SDL_Rect moon;
	SDL_Rect mars;

	int background_pos_x = 0;
	int ground_pos_x = 0;
	float background_pos_y = 0;
	float ground_pos_y = 0;
	long int pos_x = 0;
	int t = 0;
	bool GodMode = false;
};

#endif // __MODULESCENELEVEL5_H__