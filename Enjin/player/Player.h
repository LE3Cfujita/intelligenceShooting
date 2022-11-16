#pragma once
#include"GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	//初期化
	void Initialize();

	void Update();

	void Draw();

	void Move();
	//敵の攻撃が当たった時
	void Hit();
	//敵の突進攻撃が当たった時
	void RushHit();
	void GetKey();

private://メンバ変数

	Mouse* mouse = nullptr;

	Model* modelPlayer = nullptr;
	Object3d* player = nullptr;
};

