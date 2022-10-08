#pragma once
#include "Object.h"
class ShapeObj : public Object
{
protected:
	Shape* shape;
public:
	ShapeObj();
	virtual ~ShapeObj();

	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;	
		
	virtual void SetOrigin(Origins origin);
	virtual void SetPos(const Vector2f& pos) override;
	virtual FloatRect GetGlobalBounds();	
	virtual void SetColor(Color color);		
};

