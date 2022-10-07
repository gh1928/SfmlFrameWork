#include "TextObj.h"

TextObj::TextObj()
{
}

TextObj::~TextObj()
{
}

void TextObj::Init()
{
}

void TextObj::Update(float dt)
{
}

void TextObj::Draw(RenderWindow& window)
{
	window.draw(tex);
}

void TextObj::SetSize(int size)
{
	tex.setCharacterSize(size);
}

void TextObj::SetPosition(Vector2f size)
{
	tex.setPosition(size);	
}

void TextObj::SetString(String string)
{
	tex.setString(string);
}

void TextObj::SetFont(Font& font)
{
	tex.setFont(font);
}
