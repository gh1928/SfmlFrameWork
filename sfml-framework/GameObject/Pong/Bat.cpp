#include "Bat.h"
#include "../../Framework/InputMgr.h"

Bat::Bat()
	:bat(new RectangleShape), speed(1000.f)
{	
	shape = bat;
	bat->setSize({ 100, 10 });
	FloatRect rect = GetGlobalBounds();
	bat->setOrigin(rect.width * 0.5f, -10.f);
	Init();
}

Bat::~Bat()
{
}

float Bat::GetSpeed() const
{
	return speed;
}

void Bat::SetSpeed(float speed)
{
	this->speed = speed;
}

void Bat::Init()
{
	enabled = true;
	SetPos({ GAME_WIDTH * 0.5f, GAME_HEIGHT - 35.f });
}

void Bat::Update(float dt)
{
	float batHalfWidth = (bat->getSize().x)/2.f;

	if (InputMgr::GetAxisRaw(Axis::Horizontal) == -1.f
		&& bat->getPosition().x <= batHalfWidth)
		return;

	if (InputMgr::GetAxisRaw(Axis::Horizontal) == 1.f
		&& bat->getPosition().x >= (GAME_WIDTH - batHalfWidth))
		return;

	currDir.x = InputMgr::GetAxisRaw(Axis::Horizontal);
	position += currDir * speed * dt;
	ShapeObj::SetPos(position);
}
