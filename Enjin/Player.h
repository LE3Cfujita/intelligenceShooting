#pragma once
#include"GameObject.h"
#include"PlayerBullet.h"

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

	void Attack();
	//敵の攻撃が当たった時
	void Hit();
	//敵の突進攻撃が当たった時
	void RushHit();
	void GetKey();
	
	void Efect();

private://メンバ変数


	Model* modelPlayer = nullptr;
	Object3d* player = nullptr;

	int efectFlag = false;
	int efectTime = 0;
};

