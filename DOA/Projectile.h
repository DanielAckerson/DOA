#pragma once
#include "Entity.h"
class Projectile :
	public Entity
{
public:
	Projectile();
	~Projectile();
	virtual void tick();
	virtual void draw();
};

