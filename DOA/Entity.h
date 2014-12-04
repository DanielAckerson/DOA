#pragma once
class Entity
{
public:
	Entity();
	~Entity();
	virtual void tick();
	virtual void draw(){}
};

