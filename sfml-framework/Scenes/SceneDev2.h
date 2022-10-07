#pragma once
#include "Scene.h"
class SceneDev2 : public Scene
{
protected:
	

public:
	SceneDev2();
	virtual ~SceneDev2();

	// Scene을(를) 통해 상속됨
	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

