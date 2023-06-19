#pragma once
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include "SpriteGo.h"
#include "Branch.h"
#include "EffectGo.h"

class Tree : public SpriteGo
{
protected:
	const int countOfBranches;
	std::vector<Branch*> branches;
	std::vector<sf::Vector2f> branchPositions;
	int currentBranch;
	sf::Texture texBranch;

	std::list<EffectGo*> logPool;
	std::list<EffectGo*> logEffects;

	sf::Texture texLog;

	Sides branchSide;

public:
	Tree(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });
	~Tree() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
	Sides GetbranchSide();
	void UpdateBranches();
	void ShowEffectLog(Sides side, sf::Vector2f position);
};

