#include "Enemy.h"

Enemy::Enemy(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
	isActive = false;
}

Enemy::~Enemy()
{

}

void Enemy::setActive()
{
	isActive = !isActive;
 }

bool Enemy::getActive()
{
	return isActive;
}