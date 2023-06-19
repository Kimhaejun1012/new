#include "EffectGo.h"

EffectGo::EffectGo(sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p)
	: SpriteGo(tex, spriteDir, n, p), gravity(0.f, 2000.f), duration(3.f), timer(0.f)
{
	SetOrigin(Origins::BC);
}

EffectGo::~EffectGo()
{
}

void EffectGo::Fire(sf::Vector2f v)
{
	velocity = v;
}

void EffectGo::Init()
{
	SpriteGo::Init();
	
	timer = 0.f;
}

void EffectGo::Release()
{
	SpriteGo::Release();
}

void EffectGo::Update(float dt)
{
	timer += dt; // 한 프레임 넘어가기까지 걸리는 시간
	if (timer > duration)
	{
		SetActive(false);
		return;
	}

	SpriteGo::Update(dt);
	velocity += gravity * dt;
	SetPosition(position + velocity * dt);
}

void EffectGo::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}
