#include "Player.h"
#include"Road.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Camera.h"
#include"Engine/Debug.h"
#include"Engine/SphereCollider.h"
#include"Engine/SceneManager.h"

namespace {
	float vibrationtime_ = 0.3;
	float time_ = 1.0 / 60.0;
	float resettime_ = vibrationtime_;
	bool vibration_ = false;
}
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
	transform_.position_ = { 0.5,0,0 };
	isAlive_ = true;
	blockhit_ = false;
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >=0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0), 0.4f);
	AddCollider(collision);
}

void Player::Update()
{
	if (Input::IsKey(DIK_A) && transform_.position_.x>-0.9) {
		transform_.position_.x -= 0.1;
	}
	if (Input::IsKey(DIK_D) && transform_.position_.x <1.9) {
		transform_.position_.x += 0.1;
	}
	/*if (this->isAlive_ == false) {
		SceneManager* cSM = (SceneManager*)(FindObject("SceneManager"));
		cSM->ChangeScene(SCENE_ID_GAMEOVER);
	}*/
	if (blockhit_ == true) {
			if (vibrationtime_ >= 0) {
				float cameraposx;
				float cameraposy;
				float cameraposz;
				float x_ = (float)rand() / RAND_MAX;
				x_ = 2.0 * x_;
				float y_ = (float)rand() / RAND_MAX;
				y_ = 2.0 * y_;
				float z_ = (float)rand() / RAND_MAX;
				z_ = 2.0 * z_;

				cameraposx = (rand() % 3 + 1.0) * ((x_ - 1.0) / 100);
				cameraposy = (rand() % 3 + 1.0) * ((y_ - 1.0) / 100);
				cameraposz = (rand() % 3 + 1.0) * ((z_ - 1.0) / 100);
				Camera::SetPosition(XMFLOAT3(0 + cameraposx, 4 + cameraposy, -8.5 + cameraposz));
				Camera::SetTarget(XMFLOAT3(cameraposx, cameraposy, cameraposz));
				vibrationtime_ -= time_;
			}
			else {
				vibrationtime_ = resettime_;
				blockhit_ = false;
			}
	}
	else {
		Camera::SetPosition(XMFLOAT3(0, 4, -8.5));
		Camera::SetTarget(XMFLOAT3(0, 0, 0));
		
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
		/*this->KillMe();*/
		this->isAlive_ = false;
		blockhit_ = true;
		pTarget->KillMe();
	}
}
