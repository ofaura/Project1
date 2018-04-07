#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleStartMenu.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneLevel1.h"
#include "ModuleInput.h"

ModuleStartMenu::ModuleStartMenu()
{

	_background.x = 0;
	_background.y = 0;
	_background.w = 340;
	_background.h = 224;

	_blue.x = 9;
	_blue.y = 162;
	_blue.w = 208;
	_blue.h = 46;

	_logo.x = 7;
	_logo.y = 47;
	_logo.w = 240;
	_logo.h = 112;

	_visco.x = 40;
	_visco.y = 116;
	_visco.w = 167;
	_visco.h = 15;

}

ModuleStartMenu::~ModuleStartMenu()
{}

// Load assets
bool ModuleStartMenu::Start()
{
	LOG("Loading textures");
	background = App->textures->Load("Assets/Sprites/StartMenu/background.png");
	logo = App->textures->Load("Assets/Sprites/StartMenu/logo.png");
	visco = App->textures->Load("Assets/Sprites/StartMenu/visco_games.png");
	return true;
}

// UnLoad assets
bool ModuleStartMenu::CleanUp()
{
	LOG("Unloading Neo Geo logo scene");
	App->textures->Unload(background);
	App->textures->Unload(logo);
	App->textures->Unload(visco);
	return true;
}

// Update: draw background
update_status ModuleStartMenu::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, &_background, 0.75f);
	App->render->Blit(logo, 66, 72, &_blue, 0.75f);
	App->render->Blit(logo, 50, 40, &_logo, 0.75f);
	App->render->Blit(visco, 86, 168, &_visco, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_RETURN] == 1)
	{
		App->fade->FadeToBlack(App->start_menu, App->level1, 1.0f);
	}

	return UPDATE_CONTINUE;
}