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

void TextObj::SetOrigin(Origins origin)
{
	Utils::SetOrigin(tex, origin);
}

void TextObj::SetSize(int size)
{
	tex.setCharacterSize(size);
}

void TextObj::SetPos(Vector2f pos)
{
	Object::SetPos(pos);
	tex.setPosition(pos);
}

void TextObj::SetString(String string)
{
	tex.setString(string);
}

void TextObj::SetFont(Font& font)
{
	tex.setFont(font);
}

void TextObj::SetColor(Color color)
{
	tex.setFillColor(color);
}
