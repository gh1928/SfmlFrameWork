#include "SceneDev1.h"
#include "SceneMgr.h"
#include "../Framework/InputMgr.h"
#include "../Framework/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"
#include "../Framework/SoundMgr.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{	
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player3.png"));
	objList.push_back(obj);

	TextObj* texobj = new TextObj();
	texobj->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	texobj->SetPosition({ 1080, 200 });
	texobj->SetSize(75);
	texobj->SetString("Dev1");
	uiObjList.push_back(texobj);	
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{		
	SOUND_MGR->Play("sound/normal_bgm.wav", true);
}

void SceneDev1::Exit()
{
	SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		SOUND_MGR->Play("sound/fusrodah.wav", true);
	}

	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev2);
	}

	Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
	Scene::Draw(window);	
}
