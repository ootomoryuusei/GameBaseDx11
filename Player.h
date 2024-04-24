#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Player : public GameObject
{
private:
	int hModel_;
	bool isAlive_;
	bool blockhit_; 
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void OnCollision(GameObject* pTarget) override;
};
