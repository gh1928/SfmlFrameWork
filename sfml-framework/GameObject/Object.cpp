#include "Object.h"

Object::Object()
{
    Init();
}

Object::~Object()
{
    Release();
}

void Object::SetActive(bool active)
{
    enabled = active;
}

bool Object::GetActive() const
{
    return enabled;
}

void Object::Init()
{
}

void Object::Release()
{
}

void Object::SetPosition(const Vector2f& pos)
{
    position = pos;
}

const Vector2f Object::GetPosition() const
{
    return position;
}

void Object::Update(float dt)
{

}

void Object::Draw(RenderWindow& window)
{
    
}
