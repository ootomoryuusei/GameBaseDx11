#include "road.h"
#include"Engine/Model.h"

Road::Road(GameObject* parent)
	:GameObject(parent,"Road"),hRoad_(-1),hWall_(-1)
{
	/*transform_.position_ = { -1.2,0,0 };*/
}

void Road::Initialize()
{
	hRoad_ = Model::Load("Model\\Road.fbx");
	assert(hRoad_ >= 0);
	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hWall_ >= 0);
}

void Road::Update()
{
}

void Road::Draw()
{
	Model::SetTransform(hRoad_, transform_);
	Model::Draw(hRoad_);
	Model::SetTransform(hWall_, transform_);
	Model::Draw(hWall_);
}

void Road::Release()
{
}
