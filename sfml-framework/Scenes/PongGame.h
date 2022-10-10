#pragma once
#include <vector>
#include "Scene.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"
#include "../GameObject/Pong/Ball.h"
#include "../GameObject/Pong/Bat.h"
#include "../GameObject/Pong/Block.h"

class PongGame : public Scene
{
private:	
	vector<pair<Block*, Vector2f>> blocksInfo;
	Ball* ball;
	Bat* bat;
	int score;
	int life;
	bool isPause;
	bool devMode;
	TextObj* hud;
	TextObj* textMessage;
	RectangleShape fireLine;

	SpriteObj* help;

public:
	PongGame();
	~PongGame();

	virtual void Enter() override;
	virtual void Exit() override;
	
	void Init();
	bool Win();

	virtual void Update(float dt);	
	virtual void Draw(RenderWindow& window);
};

