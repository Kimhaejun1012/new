#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Utils.h"

class GameObject
{
protected:
	std::string name;
	sf::Vector2f position;
	bool isActive;	// È°¼ºÈ­: Update(), Draw()

public:
	GameObject(const std::string& n = "", const sf::Vector2f p = { 0, 0 });
	virtual ~GameObject();

	bool GetActive() const;
	void SetActive(bool active);

	std::string GetName();
	virtual void SetName(const std::string& n);

	sf::Vector2f GetPosition();

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f& p);

	virtual void SetOrigin(Origins origin) {}
	virtual void SetOrigin(float x, float y) {}

	virtual void Init() = 0;
	virtual void Release() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};

