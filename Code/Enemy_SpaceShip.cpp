#include "Application.h"
#include "Enemy_SpaceShip.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"
#include "ModuleUserInterface.h"
#include "ModuleSceneLevel5.h"
#include "ModuleAudio.h"

Enemy_SpaceShip::Enemy_SpaceShip(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 0,104,29,13 });
	fly.PushBack({ 30,103,29,16 });
	fly.PushBack({ 60,104,29,17 });
	fly.PushBack({ 90,104,29,14 });

	//	fly.loop = true;
	fly.speed = 0.08f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 32, 17 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);


	original_y = y;
}

void Enemy_SpaceShip::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.05f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.05f;
	}

	position.y = int(float(original_y) + (10.0f * sinf(wave)));
	position.x -= 2;
}

void Enemy_SpaceShip::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->enemy_explosion, position.x, position.y, COLLIDER_NONE);
	App->audio->PlayFx(App->level5->small_enemy_death);

	if (dead == false)
	{

		if (collider->type == COLLIDER_PLAYER_SHOT)
		{
			App->user_interface->score1 += score;
		}
		if (collider->type == COLLIDER_PLAYER2_SHOT)
		{
			App->user_interface->score2 += score;
		}
	}

	dead = true;
}