#include "GameObject.h"

GameObject::GameObject(const std::string& n, const sf::Vector2f p)
	: name(n), position(p), isActive(true)
{
}

GameObject::~GameObject()
{
}

bool GameObject::GetActive() const
{
	return isActive;
}

void GameObject::SetActive(bool active)
{
	isActive = active;
}

std::string GameObject::GetName()
{
	return name;
}

void GameObject::SetName(const std::string& n)
{
	name = n;
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void GameObject::SetPosition(const sf::Vector2f& p)
{
	position = p;
}
