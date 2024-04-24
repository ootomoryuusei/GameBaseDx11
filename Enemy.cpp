#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1),speed_(0.0)
{
	/*transform_.position_ = { 0,0,200 };*/
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Stone.fbx");
	/*hModel_ = Model::Load("Model\\pole.fbx");*/
	assert(hModel_ >= 0);
	SphereCollider* collision = new SphereCollider(XMFLOAT3(-0.5,0.3, 0), 0.4);
	AddCollider(collision);

}

void Enemy::Update()
{
	speed_ = speed_+1.0 * 1.0 / 60.0;
	transform_.position_.z -= speed_;
	if (transform_.position_.z < -5) {
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
	
}