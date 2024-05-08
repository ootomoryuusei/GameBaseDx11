#pragma once
#include"Player.h"
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Gauge : public GameObject
{
private:
	int hGaugeBar_;
	int hGaugeFrame_;
	int hHuman_;
	int hlife_;
	float gaugeMaxVal_; //�Q�[�W�̍ő�l
	float gaugeCrrVal_; //�J�����g�̒l(���݂̒l)

	float goaltime_;
	float anitimer_;
	int aniframe_;
	float resettimer_;
	float time_;
	float gtime_;
	float x_;
	Transform transfm_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Gauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};
