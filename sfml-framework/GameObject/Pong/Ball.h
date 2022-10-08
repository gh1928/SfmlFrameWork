#pragma once
#include "../ShapeObj.h"
#include "../../Framework/Constants.h"
#include "../../Framework/InputMgr.h"
#include "../../Framework/EnumClasses.h"
#include "Block.h"
#include "Bat.h"

using namespace sf;

class Ball : public ShapeObj
{
private:
	CircleShape* ball;
		
	float speed;
	Vector2f currDir;	
public:
	Ball();
	~Ball();

	void Fire(Vector2f dir, float speed);	
	float GetSpeed();	
	void SetSpeed(float speed);		

	virtual void Init() override;
	virtual void Update(float dt) override;
};
