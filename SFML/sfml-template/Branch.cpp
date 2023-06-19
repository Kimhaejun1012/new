#include "Branch.h"

Branch::Branch(sf::Texture& tex,
    sf::Vector2f spriteDir,
    const std::string& n,
    const sf::Vector2f p)
    : SpriteGo(tex, spriteDir, n, p), side(Sides::None), tree(nullptr)
{
}

Branch::~Branch()
{
}

void Branch::Init()
{
    sf::Vector2f treeSize = tree->GetSize();
    sf::Vector2f branchSize = GetSize();
    sprite.setOrigin(-treeSize.x * 0.5f, branchSize.y * 0.5f);

    //SetPosition(tree->GetPosition());

}

void Branch::SetTree(SpriteGo* tree)
{
    this->tree = tree;
}

void Branch::SetSide(Sides side)
{
    this->side = side;
    switch (this->side)
    {
    case Sides::Left:
        SetFlipX(true);
        break;
    case Sides::Right:
        SetFlipX(false);
        break;
    }
}

Sides Branch::GetSide() const
{
    return side;
}
