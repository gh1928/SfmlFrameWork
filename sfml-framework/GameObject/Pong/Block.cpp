#include "Block.h"

Block::Block(int hp)
	:block(new RectangleShape), hp(hp)
{	
	shape = block;	
	block->setSize({ WIN_WIDTH / 5.f - 20, WIN_HEIGHT / 10.f - 20 });
	block->setPosition(position);
	switch (hp)
	{
	case 1:
		block->setFillColor(Color::Green);
		break;
	case 2:
		block->setFillColor(Color::Blue);
		break;
	case 3:
		block->setFillColor(Color::Magenta);
		break;
	}
	
	enabled = true;
	Init();
}

Block::~Block()
{
}

void Block::Init()
{
	enabled = true;
}

void Block::Update(float dt)
{
	if (hp <= 0)
		enabled = false;
}

void Block::SetHp(int hp)
{
	this->hp += hp;
}

int Block::GetHp()
{
	return hp;
}
