#pragma once
#include "Mob.h"
class Player :
	public Mob
{
public:
	Player();
	~Player();
	void tick();
	void draw();
};

