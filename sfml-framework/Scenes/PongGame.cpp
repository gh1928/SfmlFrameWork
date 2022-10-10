#include "PongGame.h"
#include "../GameObject/TextObj.h"
#include "../Framework/ResourceMgr.h"

PongGame::PongGame()
	: Scene(Scenes::PongGame),
	score(0), life(3), isPause(false), devMode(false)
{
	Block dummy(1);
	FloatRect rect = dummy.GetGlobalBounds();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			blocksInfo.push_back({ new Block(3), {10 + (20 + rect.width) * j, 10 + (20 + rect.height) * i}});
			blocksInfo.back().first->SetPos(blocksInfo.back().second);
			objList.push_back(blocksInfo.back().first);
		}
	}

	bat = new Bat;
	ball = new Ball(bat, blocksInfo, score);

	objList.push_back(bat);
	objList.push_back(ball);

	hud = new TextObj;
	hud->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	hud->SetSize(50);
	hud->SetPos({ GAME_WIDTH + 13, 15 });	
	uiObjList.push_back(hud);
	 
	textMessage = new TextObj;
	textMessage->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	textMessage->SetSize(75);
	textMessage->SetPos({ GAME_WIDTH * 0.5f, GAME_HEIGHT * 0.4f });
	textMessage->SetString("GAME PASUED");
	textMessage->SetOrigin(Origins::MC);
	textMessage->SetActive(false);
	uiObjList.push_back(textMessage);

	help = new SpriteObj;
	help->SetTexture(*RESOURCE_MGR->GetTexture("graphics/border.png"));
	help->SetPos({ GAME_WIDTH , 0 });
	uiObjList.push_back(help);

	fireLine.setFillColor(Color::Red);
	fireLine.setSize({ 50,1 });	
}

PongGame::~PongGame()
{

}

void PongGame::Enter()
{
	Init();
}

void PongGame::Exit()
{
}

void PongGame::Init()
{
	score = 0;
	life = 3;
	for (auto obj : objList)
	{
		obj->Init();
	}
}

bool PongGame::Win()
{
	for (int i = 0; i < blocksInfo.size(); i++)
	{
		if (blocksInfo[i].first->GetActive())
			return false;
	}
	return true;
}

void PongGame::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Escape))
	{
		exit(1);
	}	

	if (InputMgr::GetKeyDown(Keyboard::Add))
	{
		devMode = !devMode;
	}

	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		if (life <= 0 || Win())
		{			
			ball->SetPos({ -10,-10 });
			Init();
			textMessage->SetString("GAME PASUED");	
			textMessage->SetOrigin(Origins::MC);
		}
		isPause = !isPause;
	}

	textMessage->SetActive(isPause == true ? true : false);

	if (isPause)
		return;

	Scene::Update(dt);
	
	fireLine.setPosition(ball->GetPos());
	fireLine.setRotation(-ball->GetFireDegree());

	if (ball->GetballDown())
		--life;

	if (life <= 0)
	{
		textMessage->SetString("GAME OVER");
		textMessage->SetOrigin(Origins::MC);
		isPause = true;
	}

	if (Win())
	{
		textMessage->SetString("YOU WIN");
		textMessage->SetOrigin(Origins::MC);
		isPause = true;
	}

	string hudText = "score: " + to_string(score) + "\nLife: " + to_string(life);
	hud->SetString(hudText);
}

void PongGame::Draw(RenderWindow& window)
{
	Scene::Draw(window);	
	if(devMode)
		ball->ShowCollisionForDev(window);	
	if(!ball->GetAlive())
		window.draw(fireLine);	
}
