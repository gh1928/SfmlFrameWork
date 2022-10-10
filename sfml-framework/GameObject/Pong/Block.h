#pragma once
#include "../ShapeObj.h"
#include "../../Framework/Constants.h"
#include "../../Framework/Utils.h"

class Block : public ShapeObj
{
protected:
	RectangleShape* block;
	int hp;
public:
	Block(int hp);
	~Block();

	virtual void Init() override;		
	virtual void Update(float dt);

	void SetHp(int hp);
	int GetHp();
};
