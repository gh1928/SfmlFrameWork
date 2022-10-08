#pragma once
#include "../ShapeObj.h"
#include "../../Framework/Utils.h"
#include "../../Framework/Constants.h"

using namespace sf;
class Bat : public ShapeObj
{
protected:
	RectangleShape* bat;
	float speed;
	Vector2f currDir;
public:
	Bat();
	~Bat();

	float GetSpeed() const;
	void SetSpeed(float speed);

	virtual void Init() override;
	virtual void Update(float dt);
};


