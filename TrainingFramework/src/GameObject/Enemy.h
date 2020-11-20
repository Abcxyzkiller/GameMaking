#pragma once
#include "Sprite2D.h"

class Enemy : public Sprite2D
{
public:
	Enemy(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~Enemy();
	void setActive();
	bool getActive();
	
private:
	bool isActive;
};