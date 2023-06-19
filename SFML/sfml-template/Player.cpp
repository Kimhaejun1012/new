#include "Player.h"
#include "Tree.h"
#include "InputMgr.h"
#include "EffectGo.h"

Player::Player(sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p)
	: SpriteGo(tex, spriteDir, n, p), offsetX(100.f), isChopping(false), texPlayer(tex)
{
	texAxe.loadFromFile("graphics/axe.png");
	axe = new SpriteGo(texAxe);
	SetOrigin(Origins::BC);
	for (auto& position : playerPositions)
	{
		position = p;
	}

	texRip.loadFromFile("graphics/rip.png");

	soundBufferChop.loadFromFile("sound/chop.wav");
	soundBufferDeath.loadFromFile("sound/death.wav");
	soundBufferOuttime.loadFromFile("sound/out_of_time.wav");
	soundChop.setBuffer(soundBufferChop);
	soundDeath.setBuffer(soundBufferDeath);
	soundTime.setBuffer(soundBufferOuttime);

}

void Player::GetsoundTime()
{
	soundTime.play();
}
Player::~Player()
{
}

void Player::SetTree(Tree* tree)
{
	this->tree = tree;
}

void Player::SetSide(Sides side)
{
	this->side = side;

	SetPosition(playerPositions[(int)this->side]);
	SetFlipX(this->side == Sides::Right);

	axe->SetPosition(GetPosition());
	axe->SetFlipX(this->side == Sides::Right);
}

Sides Player::GetSide() const
{
	return side;
}

void Player::Chop(Sides side)
{
	SetSide(side);
	isChopping = true;
	tree->ShowEffectLog(side, sf::Vector2f(tree->GetPosition().x, tree->GetSize().y));
	tree->UpdateBranches();
	adduitimer = true;
	soundChop.play();
	// 통나무 날리는 연출
}

void Player::Die()
{
	isAlive = false;
	isChopping = false;

	SetTexture(texRip);
	SetOrigin(Origins::BC);
	SetFlipX(true);

}

void Player::DieSounde()
{
	soundDeath.play();
}

void Player::SetPosition(float x, float y)
{
	SpriteGo::SetPosition(x, y);
}

void Player::SetPosition(const sf::Vector2f& p)
{
	SpriteGo::SetPosition(p);
}

void Player::Init()
{
	isAlive = true;
	SetTexture(texPlayer);
	SetOrigin(Origins::BC);

	isChopping = false;

	SpriteGo::Init();

	sf::Vector2f playerSize = GetSize();

	float treeHalfWidth = tree->GetSize().x * 0.5f;
	float playerHalfWidth = playerSize.x * 0.5f;
	float delta = treeHalfWidth + playerHalfWidth + offsetX;

	playerPositions[(int)Sides::Left].x = tree->GetPosition().x - delta;
	playerPositions[(int)Sides::Right].x = tree->GetPosition().x + delta;

	sf::Vector2f axeSize = axe->GetSize();
	axe->SetOrigin(axeSize.x + playerHalfWidth, playerSize.y * 0.45f);

	axe->Init();
	axe->SetPosition(GetPosition());

	SetSide(Sides::Right);
}

void Player::Release()
{
	delete axe;
	axe = nullptr;

	SpriteGo::Release();
}

void Player::Update(float dt)
{
	adduitimer = false;

	if (InputMgr::GetKeyDown(sf::Keyboard::Num3))
	{
		Die();
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Num4))
	{
		Init();
	}

	if (!isAlive)
		return;

	SpriteGo::Update(dt);

	if (!isChopping)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			
			Chop(Sides::Left);
			IsCollide();

		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			Chop(Sides::Right);
			IsCollide();
		}
	}
	else
	{
		if (GetSide() == Sides::Left &&
			InputMgr::GetKeyUp(sf::Keyboard::Left))
		{
			isChopping = false;
		}
		if (GetSide() == Sides::Right &&
			InputMgr::GetKeyUp(sf::Keyboard::Right))
		{
			isChopping = false;
		}
	}

	axe->Update(dt);
}

void Player::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);

	if (isChopping)
	{
		axe->Draw(window);
	}
}

void Player::IsCollide()
{
	if (tree->GetbranchSide() != side)
	{
		Die();
		
	}
}