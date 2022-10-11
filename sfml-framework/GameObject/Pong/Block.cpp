#include "Block.h"

Block::Block(int hp)
	:block(new RectangleShape), hp(hp), maxHp(hp)
{	
	shape = block;	
	block->setSize({ GAME_WIDTH / 5.f - 20, GAME_HEIGHT / 10.f - 20 });
	block->setPosition(position);
	Init();
}

Block::~Block()
{
}

void Block::Init()
{
	hp = maxHp;
	enabled = true;
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
}

void Block::Update(float dt)
{
	if (hp <= 0)
		enabled = false;
}

void Block::SetHp(int hp)
{
	this->hp += hp;
	switch (this->hp)
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
}

int Block::GetHp()
{
	return hp;
}
