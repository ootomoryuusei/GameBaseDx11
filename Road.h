#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Road : public GameObject
{
private:
	int hRoad_;
	int hWall_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Road(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetWallModelHandle() { return hWall_; }
};
