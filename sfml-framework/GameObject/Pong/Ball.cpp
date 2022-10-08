#include "Ball.h"

Ball::Ball()
	:ball(new CircleShape), speed(0)
{
	shape = ball;	
	enabled = false;
	ball->setRadius(10);	
	Utils::SetOrigin(*ball, Origins::MC);
	Init();
}

Ball::~Ball()
{
}

void Ball::Fire(Vector2f dir, float speed)
{
	currDir = dir;
	this->speed = speed;
	enabled = false;
}

float Ball::GetSpeed()
{
	return speed;
}

void Ball::SetSpeed(float speed)
{
	this->speed = speed;
}

void Ball::Init()
{
	SetPos({ WIN_WIDTH * 0.5f, WIN_HEIGHT - 25.f - ball->getRadius()});
	speed = 0;
}

void Ball::Update(float dt)
{
	if (!enabled && InputMgr::GetKeyDown(Keyboard::Space))
	{
		Fire(Utils::Normalize(Vector2f(1, -1)), 750);
		enabled = true;

		//if (!enabled)
			//SetPos() 바 위로 잡아주기
	}
	if (enabled)
	{
		position += currDir * speed * dt;
		ball->setPosition(position);
	}

}
