#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "PongGame.h"
#include "SFML/Graphics.hpp"

SceneMgr::~SceneMgr()
{
    //for (auto it : sceneMap)
    //{
    //    delete it.second;
    //}
}

bool SceneMgr::Init()
{
    sceneMap[Scenes::Dev1] = new SceneDev1();
    sceneMap[Scenes::Dev2] = new SceneDev2();
    sceneMap[Scenes::PongGame] = new PongGame();

    currScene = Scenes::PongGame;
    sceneMap[currScene]->Enter();

    return true;
}

Scenes SceneMgr::GetCurrScene() const
{
    return currScene;
}

Scene* SceneMgr::GetScene(Scenes scene)
{
    return sceneMap[scene];
}

void SceneMgr::ChangeScene(Scenes scene)
{
    sceneMap[currScene]->Exit();  
    currScene = scene;
    sceneMap[currScene]->Enter();
}

void SceneMgr::Update(float dt)
{
    sceneMap[currScene]->Update(dt);
}

void SceneMgr::Draw(RenderWindow& window)
{
    sceneMap[currScene]->Draw(window);
}
