#include "Player.h"
#include"Road.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Engine/SphereCollider.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
	transform_.position_ = { 0.5,0,0 };
}

void Player::Initialize()
{
	/*hModel_ = Model::Load("Model\\psycho-pass.fbx");*/
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >=0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0), 0.4f);
	AddCollider(collision);
	Camera::SetPosition(XMFLOAT3(0,3,-10));
	Camera::SetTarget(XMFLOAT3(0,0,0));
}

void Player::Update()
{
	if (Input::IsKey(DIK_A) && transform_.position_.x>-0.9) {
		transform_.position_.x -= 0.1;
	}
	if (Input::IsKey(DIK_D) && transform_.position_.x <1.9) {
		transform_.position_.x += 0.1;
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		this->KillMe();
		pTarget->KillMe();
	}
}
