#pragma once
#include"Player.h"
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Gauge : public GameObject
{
private:
	int hGaugeBar_;
	int hGaugeFrame_;
	int hHuman_;
	int hlife_;
	float gaugeMaxVal_; //ゲージの最大値
	float gaugeCrrVal_; //カレントの値(現在の値)

	float goaltime_;
	float anitimer_;
	int aniframe_;
	float resettimer_;
	float time_;
	float gtime_;
	float x_;
	Transform transfm_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Gauge(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};
