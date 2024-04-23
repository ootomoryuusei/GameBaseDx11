#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Road.h"
#include"Gauge.h"
#include"Engine/Debug.h"

namespace {
	int RoadLine = 3;
	int SafeLine = 1;
	int SponeEnemy = RoadLine - SafeLine;
	int RoadNum = 10;
	float sponetimer = 1.0;
	float timer = 0.0;
	float resettimer = 0.0;
	float seconds = 1.0 / 60.0;
}
//コンストラクタ
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Instantiate<Gauge>(this);
	Instantiate<Player>(this);
	for (int i = 0; i < RoadNum; i++) {
		Road* road = Instantiate<Road>(this);
		road->SetPosition(XMFLOAT3(-1.2, 0, 0 + 20 * i));
	}
	
	
}

//更新
void PlayScene::Update()
{
	if (sponetimer <timer) {
		float x = rand() % RoadLine;
		for (int i = 0; i <= SponeEnemy; i++) {
			if (i != x) {
				Enemy* enemy = Instantiate<Enemy>(this);
				enemy->SetPosition(XMFLOAT3(1.06 * i, 0, 200));
			}
		}
		timer = resettimer;
	}
	timer += seconds;
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}
