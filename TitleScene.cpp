#include "TitleScene.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (Input::IsMouseButtonUp(0))
	{
		SceneManager* tSM = (SceneManager*)(FindObject("SceneManager"));
		tSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
}

void TitleScene::Release()
{
}
