#include "ShapeObj.h"
#include <iostream>
ShapeObj::ShapeObj()    
{
}

ShapeObj::~ShapeObj()
{
    if (shape != nullptr)
        delete shape;
    shape = nullptr;    
}

void ShapeObj::Init()
{
    
}

void ShapeObj::Update(float dt)
{
}

void ShapeObj::Draw(RenderWindow& window)
{
    window.draw(*shape);
}

void ShapeObj::SetOrigin(Origins origin)
{
    Utils::SetOrigin(*shape, origin);
}

void ShapeObj::SetPos(const Vector2f& pos)
{
    Object::SetPos(pos);
    shape->setPosition(pos);
}

FloatRect ShapeObj::GetGlobalBounds()
{    
    return shape->getGlobalBounds();
}

void ShapeObj::SetColor(Color color)
{
    shape->setFillColor(color);
}
