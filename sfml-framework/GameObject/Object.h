#pragma once
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Object
{
protected:
	int id;
	string name;
	bool enabled;

	Vector2f position;
	float rotation;
	Vector2f scale;


public:
	Object();
	virtual ~Object();

	virtual void SetActive(bool active);
	virtual bool GetActive() const;

	virtual void Init();
	virtual void Release();

	virtual void SetPosition(const Vector2f& pos);
	virtual const Vector2f GetPosition() const;

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
	 
};

