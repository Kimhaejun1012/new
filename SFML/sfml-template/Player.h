#pragma once
#include "SpriteGo.h"
#include "Defines.h"
//사운드는 인클루드 따로
#include <SFML/Audio.hpp>
class Tree;

class Player : public SpriteGo
{
protected:
	Tree* tree;
	Sides side;

	sf::Texture texAxe;
	SpriteGo* axe;

	float offsetX;
	sf::Vector2f playerPositions[2];

	bool isChopping;

	sf::SoundBuffer soundBufferChop;
	sf::SoundBuffer soundBufferDeath;
	sf::SoundBuffer soundBufferOuttime;
	sf::Sound soundChop;
	sf::Sound soundDeath;
	sf::Sound soundTime;
	sf::Texture texRip;
	sf::Texture& texPlayer;

public:
	bool isAlive;
	Player(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });
	~Player();
	bool adduitimer;
	void SetTree(Tree* tree);
	int AddChop();

	void GetsoundTime();
	void SetSide(Sides side);
	Sides GetSide() const;

	void Chop(Sides side);
	void Die();
	void DieSounde();
	void IsCollide();
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f& p);

	virtual void Init();
	virtual void Release();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};

