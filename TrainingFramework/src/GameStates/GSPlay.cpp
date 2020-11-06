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

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


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
	obj->Set2DPosition(screenWidth / 4, 500);
	obj->SetSize(200, 200);
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
	if (key == KEY_UP && !bIsPressed)
	{
		m_listSpriteAnimations[0]->Set2DPosition(screenWidth / 4, m_listSpriteAnimations[0]->Get2DPosition().y - 100);
		printf_s("da nhan nut \n");
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
	m_BackGround->Update(deltaTime);
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
	m_BackGround->Draw();
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