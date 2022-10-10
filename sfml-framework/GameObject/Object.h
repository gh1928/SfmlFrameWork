#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Framework/Utils.h"
#include "../Framework/SoundMgr.h"
#include "../Framework/ResourceMgr.h"

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

	static int objCount;

public:
	Object();
	virtual ~Object();

	int GetObjId() const;

	virtual void SetActive(bool active);
	virtual bool GetActive() const;

	virtual void Init();
	virtual void Release();

	virtual void SetPos(const Vector2f& pos);
	virtual const Vector2f& GetPos() const;
	virtual void Translate(const Vector2f& delta);
	virtual void SetOrigin(Origins origin);

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

};
