#pragma once
#include "Object.h"
class TextObj :   public Object
{
protected:
	Text tex;
public:

	TextObj();
	virtual ~TextObj();
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
		
	void SetSize(int size);
	void SetPosition(Vector2f size);
	void SetString(String string);
	void SetFont(Font& font);
};

