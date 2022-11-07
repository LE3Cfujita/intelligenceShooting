#include"Object3d.h"
#include"Model.h"
#include"SafeDelete.h"
#include"Player.h"
#pragma once
class Enemy
{

private:
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	Enemy();
	~Enemy();

	//初期化
	void Initialize(Player* player);

	void Update();

	void Draw();

	void Move();
	void MoveLimit();

	//狙って撃ってくる攻撃
	void Attack1();
	void Attack1Move();

	//弾幕攻撃
	void Attack2();
	void Attack2Move();

	//弾幕攻撃
	void Attack3();
	void Attack3Move();

	//通常弾ヒット
	void BHit();
	void BarrageHit();

	//突進攻撃ヒット
	void RushHit();

	//プレイヤー弾ヒット
	void PHit();


public:
	struct ENEMY
	{
		//変数
		XMFLOAT3 position = { 0,0,100 };
		XMFLOAT3 rotation = { 0,180,0 };
		XMFLOAT3 scale = { 3,3,3 };

		int attackFlag = 0;//狙って撃ってくる
		int attackFlag2 = 0;//弾幕
		int attackFlag3 = 0;//突進

		int ct = 300;//突進攻撃のクールタイム	

		int barrageTime = 0;
		int rotCount = 0;

		float speed = 1;

		int directionX = 0;
		int directionY = 0;


		float dx = 0;
		float dy = 0;
		float dz = 0;
		float da = 0;
		float L = 0;

		int homingTime = 0;
		int homingCount = 0;

		int HP = 50;

		int rushCount = 0;

	};
	ENEMY enemy;

#define EBULLET_MAX 50
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

		float speed = 1.5;

		int homingTime = 0;
		int homingCount = 0;
		float directionX = 0;
		float directionY = 0;
		XMFLOAT3 direction = { 0,0,0 };
	};
	BULLET b;//狙って撃ってくる
	BULLET barrage[EBULLET_MAX];//弾幕

	int barrageNumber = 0;

	void PlusNumber();

	XMFLOAT3 pPosition = { 0,0,0 };

	int coolTime = 0;
	int coolCount = 0;


	struct AIM
	{
		XMFLOAT3 rPosition = { 0,0,0 };

		float dx = 0;
		float dy = 0;
		float da = 0;
		float L = 0;

		int directionCount = 0;
		int directionTime = 0;

		int getTime = 0;
	};
	AIM rock;


	//getter
	XMFLOAT3 GetPosition() { return enemy.position; }

	XMFLOAT3 GetBPosition() { return b.position; }
	int GetBFlag() { return b.flag; }

	XMFLOAT3 GetBarragePosition() { return barrage[barrageNumber].position; }
	int GetBarrageFlag() { return barrage[barrageNumber].flag; }

	int GetCount() { return enemy.attackFlag3; }

	int GetHP() { return enemy.HP; }

	int GetRushCount() { return enemy.rushCount; }

private://メンバ変数



	Model* modelBoss = nullptr;
	Object3d* boss = nullptr;

	//狙って撃ってくる
	Model* modelBullet = nullptr;
	Object3d* bullet = nullptr;


	//弾幕
	Object3d* bulletBarrage[EBULLET_MAX];

	Player* player = nullptr;

};

