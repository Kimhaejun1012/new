#pragma once
#include "SpriteGo.h"

class MovingBgObj : public SpriteGo
{
protected:
	float speed;
	sf::Vector2f speedRange;
	sf::Vector2f leftPos;
	sf::Vector2f rightPos;
	sf::Vector2f posXRange;
	sf::Vector2f posYRange;
	sf::Vector2f direction;

	float widthY;
	float heightY;
	float accumTime;

	sf::Vector2f originalPos;

public:
	MovingBgObj(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });

	~MovingBgObj() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetSpeedRange(sf::Vector2f sRange);

	void SetLRPos(sf::Vector2f left, sf::Vector2f right);
	void SetPosXRange(float min, float max);
	void SetPosYRange(float min, float max);
	void SetMoveY(float w, float h);
};

