#include "Scene.h"

Scene::Scene(Scenes type)
	:type(type)
{
}

Scene::~Scene()
{
	//for (auto obj : objList)
	//{
	//	delete obj;
	//}
	//for (auto uiobj : uiObjList)
	//{
	//	delete uiobj;
	//}
}

void Scene::Update(float dt)
{
	for (const auto& obj : objList)
	{
		if (obj->GetActive())
		{
			obj->Update(dt);
		}
	}

	for (const auto& obj : uiObjList)
	{
		if (obj->GetActive())
		{
			obj->Update(dt);
		}
	}
}

void Scene::Draw(RenderWindow& window)
{
	for (const auto& obj : objList)
	{
		if (obj->GetActive())
		{
			obj->Draw(window);
		}
	}

	for (const auto& obj : uiObjList)
	{
		if (obj->GetActive())
		{
			obj->Draw(window);
		}
	}
}
