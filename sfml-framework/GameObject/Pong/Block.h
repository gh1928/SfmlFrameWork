#pragma once
#include "../ShapeObj.h"
#include "../../Framework/Constants.h"
#include "../../Framework/Utils.h"

class Block : public ShapeObj
{
protected:
	RectangleShape* block;
public:
	Block();
	~Block();

	virtual void Init() override;		
};
