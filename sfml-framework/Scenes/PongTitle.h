#pragma once
#include "Scene.h"
#include "../GameObject/TextObj.h"
class PongTitle :  public Scene
{
protected:	
	TextObj* TitleMessage;
	TextObj* textMessage;
public:
	PongTitle();
	~PongTitle();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float dt) override;
	//virtual void Draw(RenderWindow& window) override;
};

