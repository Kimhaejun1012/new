#pragma once
#include "SpriteGo.h"

class EffectGo : public SpriteGo
{
protected:
	sf::Vector2f velocity;
	sf::Vector2f gravity;

	float duration;
	float timer;

public:
	EffectGo(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });
	~EffectGo();

	void Fire(sf::Vector2f v);

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};

