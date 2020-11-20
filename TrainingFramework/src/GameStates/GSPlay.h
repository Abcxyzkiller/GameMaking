#pragma once
#include "gamestatebase.h"
#include "GameButton.h"
#include "Enemy.h"

class Sprite2D;
class Sprite3D;
class Text;
class SpriteAnimation;
class GameButton;
class Enemy;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void Init();
	void Exit();

	void Pause();
	void Resume();

	void HandleEvents();
	void HandleKeyEvents(int key, bool bIsPressed);

	void HandleTouchEvents(int x, int y, bool bIsPressed);
	void Update(float deltaTime);
	void Draw();

	
	void SetNewPostionForBullet();
	bool CheckCollision(std::shared_ptr<Enemy> enm, std::shared_ptr<SpriteAnimation> player);

private:
	bool isPause = false;
	int score = 0;
	bool isGameOver = false;
	int radomDistance;
	int Distance = 0;
	int randomEnemy = 1;
	bool keyCheck = false;
	float g = 9.8;
	float v0 = 0;
	float t0 = 0;
	bool isJump = false;
	bool isOnland = true;
	double deltamove;
	float m_time = 0;
	std::shared_ptr<Sprite2D> m_BackGround;
	std::shared_ptr<Sprite2D> m_BackGround2;
	std::shared_ptr<Text>  m_score;
	std::shared_ptr<Text>  m_gameOver;
	std::shared_ptr<GameButton> buttonPause;
	std::shared_ptr<GameButton> buttonResume;
	std::list<std::shared_ptr<GameButton>>	m_listButton2;
	std::vector < std::shared_ptr<Sprite2D>> m_listSprite2D;
	std::vector < std::shared_ptr<SpriteAnimation>> m_listSpriteAnimations;
	std::vector < std::shared_ptr<Enemy>> m_listEnemy;
	

};

