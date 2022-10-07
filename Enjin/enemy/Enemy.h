#include"Player.h"
#include"Aim.h"
#pragma once
class Enemy : public GameManager
{
public:
	Enemy();
	~Enemy();

	//初期化
	void Initialize(Player* player);

	void Update();

	void Draw();

	

	//通常弾ヒット
	void BHit();
	void BarrageHit();

	//突進攻撃ヒット
	void RushHit();

	//プレイヤー弾ヒット
	void PHit();
private:
	void Move();

	//狙って撃ってくる攻撃
	void Attack1();
	void Attack1Move();

	//弾幕攻撃
	void Attack2();
	void Attack2Move();

	//弾幕攻撃
	void Attack3();
	void Attack3Move();
public:

	//攻撃フラグ
	struct BULLET
	{
		int flag = 0;

		XMFLOAT3 position = { 100,100,100 };
		XMFLOAT3 rotation = { 0,90,0 };

		float dx = 0;
		float dy = 0;
		float dz = 0;
		float da = 0;
		float L = 0;

		float speed = 3;
		
		XMFLOAT3 direction = { 0,0,0 };
	};
	BULLET b;//狙って撃ってくる
	BULLET barrage[BULLET_MAX];//弾幕

	int barrageNumber = 0;

	void PlusNumber();

	XMFLOAT3 pPosition = { 0,0,0 };

	int homingTime = 0;
	int homingCount = 0;

	struct AIM
	{
		XMFLOAT3 rPosition = { 0,0,0 };

		float dx = 0;
		float dy = 0;
		float da = 0;
		float L = 0;

		int directionCount = 0;
		int directionTime = 0;
	};
	AIM rock;

	XMFLOAT3 GetBPosition() { return b.position; }
	int GetBFlag() { return b.flag; }

	XMFLOAT3 GetBarragePosition() { return barrage[barrageNumber].position; }
	int GetBarrageFlag() { return barrage[barrageNumber].flag; }


private://メンバ変数

	Model* modelBoss = nullptr;
	Object3d* boss = nullptr;

	//狙って撃ってくる
	Model* modelBullet = nullptr;
	Object3d* bullet = nullptr;


	//弾幕
	Object3d* bulletBarrage[BULLET_MAX];

	Player* player = nullptr;
	Aim* aim = nullptr;

};

