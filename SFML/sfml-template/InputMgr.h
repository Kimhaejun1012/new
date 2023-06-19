#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downList;
	static std::list<sf::Keyboard::Key> upList;
	static std::list<sf::Keyboard::Key> ingList;

public:
	static void Clear();
	static void Update(const sf::Event& ev);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
};

