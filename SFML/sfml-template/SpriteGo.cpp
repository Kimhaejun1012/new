#include "SpriteGo.h"

SpriteGo::SpriteGo(sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p)
	: GameObject(n, p)
{
	sprite.setPosition(p);
	SetTexture(tex, spriteDir);
}

SpriteGo::~SpriteGo()
{
}

void SpriteGo::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void SpriteGo::SetPosition(const sf::Vector2f& p)
{
	position = p;
	sprite.setPosition(position);
}

void SpriteGo::SetOrigin(Origins origin)
{
	Utils::SetOrigin(sprite, origin);
}

void SpriteGo::SetOrigin(float x, float y)
{
	sprite.setOrigin(x, y);
}

sf::Vector2f SpriteGo::GetSize() const
{
	sf::FloatRect rect = sprite.getLocalBounds();
	return sf::Vector2f(rect.width, rect.height);
}

void SpriteGo::SetTexture(sf::Texture& tex, sf::Vector2f spriteDir)
{
	sprite.setTexture(tex);
	this->spriteDir = spriteDir;
}

void SpriteGo::Init()
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Update(float dt)
{
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteGo::SetFlipX(bool flip)
{
	sf::Vector2f scale = sprite.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	if (spriteDir.x < 0.f)
	{
		scale.x *= -1.f;
	}
	sprite.setScale(scale);
}

void SpriteGo::SetFlipY(bool flip)
{
	sf::Vector2f scale = sprite.getScale();
	scale.y = flip ? -abs(scale.y) : abs(scale.y);
	if (spriteDir.y > 0.f)
	{
		scale.y *= -1.f;
	}
	sprite.setScale(scale);
}