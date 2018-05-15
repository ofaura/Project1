#ifndef __ENEMY_WASP_H__
#define __ENEMY_WASP_H__

#include "Enemy.h"
#include "Path.h"

class Enemy_Wasp : public Enemy
{
private:
	float wave = -1.0f;
	int original_y = 0;
	int current_y = 0;

	Animation fly;
	Path path;

	uint lastTimeShoot = 0, currentTime;
	uint lastTimeChange = 0;

public:

	Enemy_Wasp(int x, int y);

	virtual void OnCollision(Collider* collider) override;
	void Move();
	bool dead = false;
	int score = 100;
};

#endif // __ENEMY_WASP_H__