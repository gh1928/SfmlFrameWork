#pragma once
#include "Object.h"
class SpriteObj : public Object
{
protected:
	Sprite sprite;
	

public:
	SpriteObj();
	virtual ~SpriteObj();

	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	
	void SetTexture(Texture& tex);
};

