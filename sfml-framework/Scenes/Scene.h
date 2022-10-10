#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <list>
#include "../GameObject/Object.h"
#include "../Framework/EnumClasses.h"
#include "../Framework/Constants.h"
#include "../Framework/InputMgr.h"

using namespace std;
using namespace sf;

class Scene
{
private:
protected:
	Scenes type;
	list<Object*> objList;
	list<Object*> uiObjList;

public:
	Scene(Scenes type);
	virtual ~Scene();

	virtual void Enter() = 0;
	virtual void Exit() = 0;
	

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

