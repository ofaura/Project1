#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL\include\SDL.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 100
#define DEAD_ZONE 0.2f

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	KEY_STATE gamepad[MAX_BUTTONS];
	SDL_GameController* controller = NULL;

	bool use_controller = false;
	int controller_index = 0;

	Uint8 buttons[MAX_BUTTONS];

	SDL_Event keyboardEvent;
};

#endif // __ModuleInput_H__