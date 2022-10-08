#include "Bat.h"
#include "../../Framework/InputMgr.h"

Bat::Bat()
	:bat(new RectangleShape), speed(1000.f)
{
	shape = bat;
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
	bat->setSize({ 100, 10 });
	FloatRect rect = ShapeObj::GetGlobalBounds();
	SetPos({ WIN_WIDTH * 0.5f, WIN_HEIGHT - 35.f });
	bat->setOrigin(rect.width * 0.5f, -10.f);
}

void Bat::Update(float dt)
{
	if (InputMgr::GetAxisRaw(Axis::Horizontal) == -1.f
		&& bat->getPosition().x <= 50)
		return;

	if (InputMgr::GetAxisRaw(Axis::Horizontal) == 1.f
		&& bat->getPosition().x >= (WIN_WIDTH - 50))
		return;

	currDir.x = InputMgr::GetAxisRaw(Axis::Horizontal);
	position += currDir * speed * dt;
	ShapeObj::SetPos(position);
}
