#include "GSPlay.h"

#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "SpriteAnimation.h"
#include "GameConfig.h"
#include "U_Math.h"




extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
extern int screenLand;
extern int screenSky;
int playSound;

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("backgroundCity");

	//BackGround1
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, 257);
	m_listSprite2D.push_back(m_BackGround);

	//Background2
	auto shader2 = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround2 = std::make_shared<Sprite2D>(model, shader2, texture);
	m_BackGround2->Set2DPosition(1.5f*screenWidth - 1,screenHeight / 2);
	m_BackGround2->SetSize(screenWidth, 257);
	m_listSprite2D.push_back(m_BackGround2);

	//button back
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	std::shared_ptr<GameButton> button2 = std::make_shared<GameButton>(model, shader, texture);
	button2->Set2DPosition(screenWidth* 2/3, 200);
	button2->SetSize(200, 50);
	button2->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		//GameStateMachine::GetInstance()->PopState();
	});
	m_listButton2.push_back(button2);

	//button replay
	texture = ResourceManagers::GetInstance()->GetTexture("button_replay");
	std::shared_ptr<GameButton> button3 = std::make_shared<GameButton>(model, shader, texture);
	button3->Set2DPosition(screenWidth / 3, 200);
	button3->SetSize(200, 50);
	button3->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Play);
		//GameStateMachine::GetInstance()->PopState();
	});
	m_listButton2.push_back(button3);

	

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, "score:"+ std::to_string(score), TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//text game over
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font2 = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_gameOver = std::make_shared< Text>(shader, font2, "GAME OVER", TEXT_COLOR::RED, 5.0);
	m_gameOver->Set2DPosition(screenWidth / 4, screenSky);

	// Animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("ani4");
	std::shared_ptr<SpriteAnimation> obj = std::make_shared<SpriteAnimation>(model, shader, texture, 14, 0.07f);
	obj->Set2DPosition(screenWidth / 4, screenLand);
	obj->SetSize(100, 100);
	m_listSpriteAnimations.push_back(obj);
	//playSound = ResourceManagers::GetInstance()->PlaySound("background", true);

	//ResourceManagers.PlaySound("background", true);

	//Enemy
	texture = ResourceManagers::GetInstance()->GetTexture("ghidorah");
	std::shared_ptr<Enemy> enm1 = std::make_shared<Enemy>(model, shader2, texture);
	enm1->Set2DPosition(1.1f*screenWidth, screenSky);
	enm1->SetSize(100, 100);
	m_listEnemy.push_back(enm1);

	texture = ResourceManagers::GetInstance()->GetTexture("muto");
	std::shared_ptr<Enemy> enm2 = std::make_shared<Enemy>(model, shader2, texture);
	enm2->Set2DPosition(1.1f*screenWidth, screenLand);
	enm2->SetSize(100, 100);
	m_listEnemy.push_back(enm2);

	texture = ResourceManagers::GetInstance()->GetTexture("ghidorah");
	std::shared_ptr<Enemy> enm3 = std::make_shared<Enemy>(model, shader2, texture);
	enm3->Set2DPosition(1.1f*screenWidth, screenSky);
	enm3->SetSize(100, 100);
	m_listEnemy.push_back(enm3);

	texture = ResourceManagers::GetInstance()->GetTexture("muto");
	std::shared_ptr<Enemy> enm4 = std::make_shared<Enemy>(model, shader2, texture);
	enm4->Set2DPosition(1.1f*screenWidth, screenLand);
	enm4->SetSize(100, 100);
	m_listEnemy.push_back(enm4 );

	texture = ResourceManagers::GetInstance()->GetTexture("ghidorah");
	std::shared_ptr<Enemy> enm5 = std::make_shared<Enemy>(model, shader2, texture);
	enm5->Set2DPosition(1.1f*screenWidth, screenSky);
	enm5->SetSize(100, 100);
	m_listEnemy.push_back(enm5);

	texture = ResourceManagers::GetInstance()->GetTexture("muto");
	std::shared_ptr<Enemy> enm6 = std::make_shared<Enemy>(model, shader2, texture);
	enm6->Set2DPosition(1.1f*screenWidth, screenLand);
	enm6->SetSize(100, 100);
	m_listEnemy.push_back(enm6);

	texture = ResourceManagers::GetInstance()->GetTexture("ghidorah");
	std::shared_ptr<Enemy> enm7 = std::make_shared<Enemy>(model, shader2, texture);
	enm7->Set2DPosition(1.1f*screenWidth, screenSky);
	enm7->SetSize(100, 100);
	m_listEnemy.push_back(enm7);

	texture = ResourceManagers::GetInstance()->GetTexture("muto");
	std::shared_ptr<Enemy> enm8 = std::make_shared<Enemy>(model, shader2, texture);
	enm8->Set2DPosition(1.1f*screenWidth, screenLand);
	enm8->SetSize(100, 100);
	m_listEnemy.push_back(enm8);
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
	if (key == KEY_UP && bIsPressed && keyCheck == false && m_listSpriteAnimations[0]->Get2DPosition().y <= screenLand + 5 && m_listSpriteAnimations[0]->Get2DPosition().y >= screenLand - 5)
	{
		isJump = true;
		keyCheck = true;
		m_time = 0;
		
	}
	else if(key == KEY_UP && !bIsPressed) {
		keyCheck = false;
		isJump = false;
		
	}
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	if (!bIsPressed)
	{
		for (auto it : m_listButton2) {
			(it)->HandleTouchEvents(x, y, bIsPressed);
			if ((it)->IsHandle()) break;
		}
	}

}

bool GSPlay::CheckCollision(std::shared_ptr<Enemy> enm, std::shared_ptr<SpriteAnimation> player)
{
	Vector2 enmPos = enm->Get2DPosition();
	Vector2 playerPos = player->Get2DPosition();
	float distance = sqrt((enmPos.x - playerPos.x)*(enmPos.x - playerPos.x) + (enmPos.y - playerPos.y)*(enmPos.y - playerPos.y));
	if (distance <= 60)
	{
		return true;
	}
	else return false;

}

void GSPlay::Update(float deltaTime)
{
	if (!isGameOver)
	{
		score++;
		deltamove = 140 * deltaTime;
		//radomDistance = rand() % 50 + 130;

		//random enm
		if (Distance >= radomDistance)
		{
			radomDistance = rand() % 50 + 130;
			randomEnemy = rand() % 8;
			Distance = 0;
		}

		//randomEnemy = rand() % 4;

		if (!m_listEnemy[randomEnemy]->getActive())
		{
			m_listEnemy[randomEnemy]->setActive();
		}


		Distance += deltamove;
		for (auto enm : m_listEnemy)
		{
			if (enm->getActive())
			{
				if (enm->Get2DPosition().x >= 0)
				{
					enm->Set2DPosition(enm->Get2DPosition().x - deltamove, enm->Get2DPosition().y);

				}
				else
				{
					enm->Set2DPosition(1.1f*screenWidth, enm->Get2DPosition().y);
					enm->setActive();
				}
				if (CheckCollision(enm, m_listSpriteAnimations[0]))
				{
					isGameOver = true;
					printf("Game Over \n");
				}
				enm->Update(deltaTime);
			}

		}

		//nhan vat nhay
		v0 = isJump ? -20 : 0;
		m_time += deltaTime;
		t0 = 50 * deltaTime;
		Vector2 oldPos = m_listSpriteAnimations[0]->Get2DPosition();
		Vector2 newPos = Vector2(0, 0);
		if (oldPos.y + v0*t0 + g*t0*t0 / 2 < screenSky)
		{
			newPos = Vector2(screenWidth / 4, screenSky);
		}
		else if (oldPos.y + v0*t0 + g*t0*t0 / 2 > screenLand)
		{
			newPos = Vector2(screenWidth / 4, screenLand);
		}
		else
		{
			newPos = Vector2(screenWidth / 4, oldPos.y + v0*t0 + g*t0*t0 / 2);
		}


		if (isJump && m_listSpriteAnimations[0]->Get2DPosition().y >= screenSky)
		{

			m_listSpriteAnimations[0]->Set2DPosition(newPos);
			if (m_listSpriteAnimations[0]->Get2DPosition().y <= screenSky && m_time > 0.6)
			{
				isJump = false;

			}
		}
		else if (oldPos.y <= screenLand)
		{
			m_listSpriteAnimations[0]->Set2DPosition(newPos);
		}



		//background chuyen dong

		for (auto bg : m_listSprite2D)
		{
			if (bg->Get2DPosition().x >= -screenWidth / 2)
			{
				bg->Set2DPosition(bg->Get2DPosition().x - deltamove, screenHeight / 2);
			}
			else
			{
				bg->Set2DPosition(1.5f*screenWidth - 5, screenHeight / 2);
			}
			bg->Update(deltaTime);

		}

		for (auto obj : m_listSpriteAnimations)
		{

			obj->Update(deltaTime);
		}
		for (auto it : m_listButton2)
		{
			it->Update(deltaTime);
		}
		m_score->setText("score:" + std::to_string(score));

	}
	m_gameOver->Update(deltaTime);
	
}

void GSPlay::Draw()
{
	
	
	for (auto bg : m_listSprite2D)
	{
		bg->Draw();
	}
	for (auto it : m_listButton2)
	{
		it->Draw();

	}
	m_score->Draw();
	for (auto obj : m_listSpriteAnimations)
	{
		obj->Draw();
	}
	for (auto enm : m_listEnemy)
	{
		enm->Draw();
	}
	if (isGameOver) m_gameOver->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}