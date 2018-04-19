#include "Application.h"
#include "Enemy_FirstEnemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_FirstEnemy::Enemy_FirstEnemy(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 0,3,18,12 });
	fly.PushBack({ 19,3,18,12 });
	fly.PushBack({ 39,3,18,13 });
	fly.PushBack({ 59,1,18,17 });
	fly.PushBack({ 79,0,18,20 });
	fly.PushBack({ 101,0,19,19 });
	fly.PushBack({ 0,22,18,20 });
	fly.PushBack({ 22,23,18,17 });
	fly.PushBack({ 44,24,18,17 });
	fly.PushBack({ 67,26,19,13 });
	fly.PushBack({ 92,27,18,12 });
//	fly.loop = true;
	fly.speed = 0.4f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 18, 17 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_FirstEnemy::Move()
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

	position.y = int(float(original_y) + (20.0f * sinf(wave)));
	position.x -= 1;
}
