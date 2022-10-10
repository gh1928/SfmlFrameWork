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
	virtual void SetOrigin(Origins origin);
	virtual void SetPos(Vector2f pos);
		
	void SetSize(int size);
	void SetString(String string);
	void SetFont(Font& font);
	void SetColor(Color color);
};

