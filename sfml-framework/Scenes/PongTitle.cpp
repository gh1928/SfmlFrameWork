#include "PongTitle.h"
#include "SceneMgr.h"

PongTitle::PongTitle()
	:Scene(Scenes::PongTitle)
{
	TitleMessage = new TextObj;
	TitleMessage->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	TitleMessage->SetSize(150);
	TitleMessage->SetPos({ WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.3f });
	TitleMessage->SetString("Pong");
	TitleMessage->SetOrigin(Origins::MC);
	uiObjList.push_back(TitleMessage);

	textMessage = new TextObj;
	textMessage->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	textMessage->SetSize(50);
	textMessage->SetPos({ WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.6f });
	textMessage->SetString("press enter to start");
	textMessage->SetOrigin(Origins::MC);	
	uiObjList.push_back(textMessage);
}

PongTitle::~PongTitle()
{
}

void PongTitle::Enter()
{
}

void PongTitle::Exit()
{
}

void PongTitle::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Return)) 
	{
		SCENE_MGR->ChangeScene(Scenes::PongGame);
	}
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		exit(1);
	}

	Scene::Update(dt);
}

//void PongTitle::Draw(RenderWindow& window)
//{	
//	Scene::Draw(window);
//}
