#include "GameOverScene.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"
#include"Engine/Image.h"



GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene"),hPict_(-1)
{
	
}

void GameOverScene::Initialize()
{
	hPict_ = Image::Load("gameover.png");
	assert(hPict_ >= 0);
}

void GameOverScene::Update()
{
	/*if (Input::IsMouseButtonUp(0))
	{
		SceneManager* tSM = (SceneManager*)(FindObject("SceneManager"));
	    tSM->ChangeScene(SCENE_ID_TITLE);
	}*/
}

void GameOverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void GameOverScene::Release()
{
}
