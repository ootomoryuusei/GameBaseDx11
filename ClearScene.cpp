#include "ClearScene.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

ClearScene::ClearScene(GameObject* parent):GameObject(parent), hPict_(-1)
{
}

void ClearScene::Initialize()
{
	hPict_ = Image::Load("clear.png");
	assert(hPict_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsMouseButtonUp(0))
	{
		SceneManager* tSM = (SceneManager*)(FindObject("SceneManager"));
		tSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

void ClearScene::Release()
{
}
