#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class Road : public GameObject
{
private:
	int hRoad_;
	int hWall_;
	float speed_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Road(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	int GetWallModelHandle() { return hWall_; }
};
