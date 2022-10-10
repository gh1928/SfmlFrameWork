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
	bool alive;		
	float speed;
	Vector2f currDir;
	Bat* bat;

	int blockHeadId;
	vector<bool> isCollision; //마지막 3자리는 사이드 탑 배트
	
	vector <pair<RectangleShape, Vector2f>> collision;
	vector<pair<Block*, Vector2f>>& blocksInfo;

public:
	Ball(Bat* bat, vector<pair<Block*, Vector2f>>& blocksInfo);
	~Ball();

	void Fire(Vector2f dir, float speed);	
	float GetSpeed();	
	void SetSpeed(float speed);		
	bool GetAlive();
	void SetAlive(bool alive);	
	bool Collisiondetection();
	void SetCollisionPos();

	void CollsionBugFix();
	void BlockCollision(int num);	
	void BatCollsion();

	void ShowCollisionForDev(RenderWindow& window);

	virtual void Init() override;
	virtual void Update(float dt) override;
};
