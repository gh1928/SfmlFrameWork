#include "SceneDev2.h"
#include "SceneMgr.h"
#include "../Framework/InputMgr.h"
#include "../Framework/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player5.png"));
	objList.push_back(obj);

	TextObj* texobj = new TextObj();
	texobj->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	texobj->SetPosition({ 1080, 200 });
	texobj->SetSize(75);
	texobj->SetString("Dev2");
	uiObjList.push_back(texobj);
}

SceneDev2::~SceneDev2()
{

}

void SceneDev2::Enter()
{
}

void SceneDev2::Exit()
{
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev1);
	}

	Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}
