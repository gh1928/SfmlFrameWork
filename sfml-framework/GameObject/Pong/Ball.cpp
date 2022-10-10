#include "Ball.h"

Ball::Ball(Bat* bat, vector<pair<Block*, Vector2f>>& blocksInfo, int& score)
	:ball(new CircleShape), speed(0), bat(bat), blocksInfo(blocksInfo), score(score)
{
	enabled = true;
	shape = ball;
	ball->setRadius(10);	
	Utils::SetOrigin(*ball, Origins::MC);		
	fireDgree = 45.f;

	isCollision.assign(1024, true); //앞자리 index = objid , 뒤 임의 index

	FloatRect rect = ball->getGlobalBounds();
	RectangleShape collisionBox;
	collisionBox.setSize({ rect.width / 2.f, rect.height / 2.f });

	for (int i = (int)Collision::TL ; i < (int)Collision::BR + 1; i++)
	{	
		collision.push_back({ collisionBox, { 1.f - (i % 2) * 2, 1.f - (i / 2) * 2 } });		
		collision[i].first.setFillColor(Color::Yellow);
	}

	blockHeadId = blocksInfo.front().first->GetObjId();

	Init();	
}

Ball::~Ball()
{
}

void Ball::Fire(Vector2f dir, float speed)
{
	currDir = dir;
	this->speed = speed;	
}

float Ball::GetSpeed()
{
	return speed;
}

void Ball::SetSpeed(float speed)
{
	this->speed = speed;
}

bool Ball::GetAlive()
{
	return alive;
}

void Ball::SetAlive(bool alive)
{
	this->alive = alive;
}

void Ball::SetCollisionPos()
{
	FloatRect rect = ball->getGlobalBounds();
	float xpos = rect.width / 2;
	float ypos = rect.height / 2;

	for (int i = (int)Collision::TL; i < (int)Collision::BR + 1; i++)
	{		
		collision[i].first.setPosition
		(rect.left + xpos * (i % 2), rect.top + ypos * (i / 2));	
	}
}

void Ball::CollsionBugFix()
{
	FloatRect rect = GetGlobalBounds();

	for (int i = 0; i < blocksInfo.size(); i++)
	{
		if (rect.intersects(blocksInfo[i].first->GetGlobalBounds()))
		{
			if (isCollision[blockHeadId + i] && (blocksInfo[i].first->GetActive()))
			{
				BlockCollision(i);
				isCollision[blockHeadId + i] = false;
			}
		}
		else
			isCollision[blockHeadId + i] = true;
	}		

	if (rect.left <= 0 || GAME_WIDTH <= (rect.left + rect.width))
	{
		if(isCollision[1023])
			currDir.x *= -1;	
		isCollision[1023] = false;
	}
	else
		isCollision[1023] = true;
	
	if (rect.top <= 0)
	{
		if (isCollision[1022])
			currDir.y *= -1;
		isCollision[1022] = false;
	}
	else
		isCollision[1022] = true;

	if (rect.top >= GAME_HEIGHT)
	{
		alive = false;
		ballDown = true;
	}
	else
		ballDown = false;
	

	if (rect.intersects(bat->GetGlobalBounds()))
	{
		if (isCollision[1021])
			BatCollsion();
		isCollision[1021] = false;
	}
	else
		isCollision[1021] = true;
}

bool Ball::GetballDown()
{
	return ballDown;
}

float Ball::GetFireDegree()
{
	return fireDgree;
}

void Ball::BlockCollision(int num)
{
	Vector2f vector = { 0,0 };
	SetCollisionPos();
	for (int i = (int)Collision::TL; i < (int)Collision::BR + 1; i++)
	{
		if (collision[i].first.getGlobalBounds().intersects(blocksInfo[num].first->GetGlobalBounds()))
		{
			collision[i].first.setFillColor(Color::Red);
			vector.x += collision[i].second.x;
			vector.y += collision[i].second.y;
		}
		else
			collision[i].first.setFillColor(Color::Yellow);
	}

	if (vector.x)
	{
		vector.x /= abs(vector.x);
		currDir.x = abs(currDir.x) * vector.x;
	}		
	if (vector.y)
	{
		vector.y /= abs(vector.y);
		currDir.y = abs(currDir.y) * vector.y;
	}

	// ( 1,  1 ), ( -1,  1 )
    // ( 1, -1 ), ( -1, -1 )	

	SOUND_MGR->Play("sound/bound.wav");
	blocksInfo[num].first->SetHp(-1);
	score++;
}

void Ball::BatCollsion()
{
	FloatRect rect = bat->GetGlobalBounds();
	
	float degree = 90.f;
	if ((GetPos().x < rect.left))
		degree = 135.f;
	if ((GetPos().x > rect.left + rect.width))
		degree = 45.f;

	degree = 135.f - ((GetPos().x - rect.left) / rect.width) * 90.f;
	
	currDir.x = cos(degree * PI / 180);
	currDir.y = - sin(degree * PI / 180);
}

void Ball::ShowCollisionForDev(RenderWindow& window)
{		
	for (int i = (int)Collision::TL; i < (int)Collision::BR + 1; i++)
	{
		window.draw(collision[i].first);
	}
}

void Ball::Init()
{	
	alive = false;
}

void Ball::Update(float dt)
{
	CollsionBugFix();

	Vector2f pos;
	pos = alive ? (position += currDir * speed * dt) : bat->GetPos();
	SetPos(pos);
			
	fireDgree += -InputMgr::GetAxisRaw(Axis::Vertical) * 50 * dt;
	if (fireDgree < 45.f)
		fireDgree = 45.f;
	if (fireDgree > 135.f)
		fireDgree = 135.f;

	Vector2f degree;
	degree.x = cos(fireDgree * PI / 180);
	degree.y = -sin(fireDgree * PI / 180);

	cout << fireDgree << endl;

	if (!alive && InputMgr::GetKeyDown(Keyboard::Space))
	{
		Fire(degree, 750);
		alive = true;
	}
}
