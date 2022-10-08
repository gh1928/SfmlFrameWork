#include "PongTest.h"
#include "../GameObject/TextObj.h"
#include "../Framework/ResourceMgr.h"

PongTest::PongTest()
	: Scene(Scenes::PongTest),
	score(0), life(3), isPause(false)
{
	ball = new Ball;
	bat = new Bat;

	objList.push_back(ball);
	objList.push_back(bat);

	Block dummy;
	FloatRect rect = dummy.GetGlobalBounds();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			blockInfos.push_back({ new Block, {10 + (20 + rect.width) * j, 10 + (20 + rect.height) * i} });
			blockInfos.back().first->SetPos(blockInfos.back().second);
			objList.push_back(blockInfos.back().first);
		}
	}

	hud = new TextObj;
	hud->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	hud->SetSize(75);
	hud->SetPos({ 20, 20 });
	hud->SetActive(true);
	uiObjList.push_back(hud);
	 
	textMessage = new TextObj;
	textMessage->SetFont(*RESOURCE_MGR->GetFont("fonts/DS-DIGI.ttf"));
	textMessage->SetSize(75);
	textMessage->SetPos({ WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.4f });
	textMessage->SetString("GAME PASUED");
	textMessage->SetOrigin(Origins::MC);
	textMessage->SetActive(true);
	uiObjList.push_back(textMessage);
}

PongTest::~PongTest()
{

}

void PongTest::Enter()
{
	Init();
}

void PongTest::Exit()
{
}

void PongTest::Init()
{
	score = 0;
	life = 3;
	for (auto obj : objList)
	{
		obj->Init();
	}
}

void PongTest::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		if (life <= 0 || score >= 25)
		{
			Init();
			textMessage->SetString("GAME PASUED");			
			textMessage->SetOrigin(Origins::MC);
		}
		isPause = !isPause;
	}
	if (isPause)
		return;
	ScoreCount();
	string hudText = "score: " + to_string(score) + "\tLife: " + to_string(life);
	hud->SetString(hudText);
	ball->Update(dt);
	bat->Update(dt);
	for (int i = 0; i < blockInfos.size(); i++)
	{
		if(blockInfos[i].first->GetActive())
			blockInfos[i].first->Update(dt);		
	}
	//if (ball.OnCollisionBottom())
	//{
	//	life -= 1;
	//}
	if (life <= 0)
	{
		textMessage->SetString("GAME OVER");
		textMessage->SetOrigin(Origins::MC);
		isPause = true;
	}

	if (score >= 25)
	{
		textMessage->SetString("YOU WIN");
		textMessage->SetOrigin(Origins::MC);
		isPause = true;
	}
}

void PongTest::Draw(RenderWindow& window)
{
	for (int i = 0; i < 25; i++)
	{
		blockInfos[i].first->Draw(window);
	}
	ball->Draw(window);
	bat->Draw(window);
	hud->Draw(window);
	if (isPause)
		textMessage->Draw(window);
}

void PongTest::ScoreCount()
{
	score = 0;
	for (int i = 0; i < blockInfos.size(); i++)
	{
		if (!blockInfos[i].first->GetActive())
			score += 1;			
	}
}