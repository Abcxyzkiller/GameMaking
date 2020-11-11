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



extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine
extern int screenLand;
extern int screenSky;

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
	button2->Set2DPosition(screenWidth / 2, 300);
	button2->SetSize(200, 50);
	button2->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		//GameStateMachine::GetInstance()->PopState();
	});
	m_listButton2.push_back(button2);

	//text game title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// Animation
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("ani4");
	std::shared_ptr<SpriteAnimation> obj = std::make_shared<SpriteAnimation>(model, shader, texture, 14, 0.07f);
	obj->Set2DPosition(screenWidth / 4, screenLand);
	obj->SetSize(100, 100);
	m_listSpriteAnimations.push_back(obj);
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
	
	if (key == KEY_UP && bIsPressed)
	{
		keyCheck = key;
		
	}
	else {
		keyCheck = 0;
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

void GSPlay::Update(float deltaTime)
{
	if (keyCheck) {
		
			m_listSpriteAnimations[0]->Set2DPosition(screenWidth / 4, screenLand + 100 );
	}

	deltamove = 100 * deltaTime;
	for (auto bg : m_listSprite2D)
	{
		if (bg->Get2DPosition().x >= -screenWidth/2)
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
}

void GSPlay::SetNewPostionForBullet()
{
}