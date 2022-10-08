#include "Block.h"

Block::Block()	
	:block(new RectangleShape)
{	
	shape = block;	
	block->setSize({ WIN_WIDTH / 5.f - 20, WIN_HEIGHT / 10.f - 20 });
	block->setPosition(position);
	block->setFillColor(Color::Green);
	Init();
}

Block::~Block()
{
}

void Block::Init()
{
	enabled = true;
}
