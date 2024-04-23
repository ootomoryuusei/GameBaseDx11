#include "Gauge.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"

Gauge::Gauge(GameObject* parent) : GameObject(parent),hGaugeBar_(-1),hGaugeFrame_(-1),hHuman_(-1), gaugeCrrVal_(0.0), gaugeMaxVal_(100.0)
{
}

void Gauge::Initialize()
{
	hGaugeBar_ = Image::Load("lifebar.png");
	assert(hGaugeBar_ >= 0);
	hGaugeFrame_ = Image::Load("lifeframe.png");
	assert(hGaugeFrame_ >= 0);
	hHuman_ = Image::Load("human.png");
	assert(hHuman_ >= 0);
	transform_.position_.x = 0.8f;
	transform_.position_.y = 0.7f;
	goaltime_ = 10.0;
	anitimer_ = 0.1;
	aniframe_ = 0;
	resettimer_ = 0.1;
	time_ = 1.0 / 60.0;
	transfm_ = transform_;
	transfm_.position_.y = 0.9;
	transfm_.position_.x = 0.66;
	x_ = (gaugeMaxVal_ / goaltime_) / 60.0;
}

void Gauge::Update()
{
	gaugeCrrVal_ += x_;
	goaltime_ -= time_;
	anitimer_ -= time_;
	transfm_.position_.x += 0.025/60.0;
	if (anitimer_ <= 0) {
		Image::SetTransform(hHuman_, transfm_);
		Image::SetRect(hHuman_, 64 * aniframe_, 0, 64, 98.5);
		anitimer_ = resettimer_;
		aniframe_++;
		if (aniframe_ > 3) {
			aniframe_ == 0;
		}
	}
	if (goaltime_ <=0) {
		SceneManager* cSM = (SceneManager*)(FindObject("SceneManager"));
		cSM->ChangeScene(SCENE_ID_CLEAR);
	}
}


void Gauge::Draw()
{
	
	Transform trans = transform_;
	trans.position_.x = 0.665f;
	trans.scale_.x = gaugeCrrVal_ / gaugeMaxVal_;
	Image::SetTransform(hGaugeBar_, trans);
	Image::Draw(hGaugeBar_);
	Image::SetTransform(hGaugeFrame_, transform_);
	Image::Draw(hGaugeFrame_);
	Image::Draw(hHuman_);
}

void Gauge::Release()
{
}
