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

	//狙って撃ってくる攻撃
	void Attack1();
	void Attack1Move();

	//弾幕攻撃
	void Attack2();
	void Attack2Move();

	//弾幕攻撃
	void Attack3();
	void Attack3Move();

	//getter
	XMFLOAT3 GetPosition() { return enemy.rotation; }

	int GetCount() { return enemy.attackFlag3; }

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

	};
	ENEMY enemy;

#define BULLET_MAX 50
	//攻撃フラグ
	struct BULLET
	{
		int flag = 0;

		XMFLOAT3 position = { 100,100,0 };
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

private://メンバ変数



	Model* modelBoss = nullptr;
	Object3d* boss = nullptr;

	//狙って撃ってくる
	Model* modelBullet = nullptr;
	Object3d* bullet = nullptr;


	//弾幕
	Object3d* bulletBarrage[BULLET_MAX];

	Player* player = nullptr;

};

