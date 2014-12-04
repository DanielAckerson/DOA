#pragma once
#include "Entity.h"
class Mob :
	public Entity
{
public:
	Mob();
	~Mob();
	virtual void tick();
	virtual void draw();
};

