#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Player : public GameObject
{
private:
	int hModel_;
	int life_;
	bool isAlive_;
	bool blockhit_; 
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	Player();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void OnCollision(GameObject* pTarget) override;

	void SetLife(int _life) { life_ = _life; }
	int GetLife() { return life_; }
};
