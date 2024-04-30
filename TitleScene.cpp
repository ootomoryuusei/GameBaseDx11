#include "TitleScene.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
#include"Engine/Image.h"

TitleScene::TitleScene(GameObject* parent):GameObject(parent,"TitleScene"),hPict_(-1)
{
}

void TitleScene::Initialize()
{
	hPict_ = Image::Load("title.png");
	assert(hPict_ >= 0);
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
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void TitleScene::Release()
{
}
