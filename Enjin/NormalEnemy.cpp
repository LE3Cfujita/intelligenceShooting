#include "NormalEnemy.h"

NormalEnemy::NormalEnemy()
{
}

NormalEnemy::~NormalEnemy()
{
	safe_delete(obj);
}

void NormalEnemy::Initialize(XMFLOAT3 pos)
{
	objectMember = OBJECTMEMBER::NORMALENEMY;
	position = pos;
	rotation = { 0,180,0 };
	HP = 2;
	radius = 2;
	model = Model::CreateModel(5);
	obj = Object3d::Create();
	obj->SetModel(model);
	obj->SetPosition(position);
	obj->SetRotation(rotation);
	obj->SetScale({ 0.7,0.7,0.7 });
	speed = 1;
}

void NormalEnemy::Update()
{
	Move();
	Death();
}

void NormalEnemy::Draw()
{
	obj->SetRotation(rotation);
	obj->SetPosition(position);
	obj->Update();
	obj->Draw();
}

void NormalEnemy::Create(int move)
{
	deathFlag == false;
	moveCount = move;
}

void NormalEnemy::Move()
{
	MoveLimit();

	XMFLOAT3 pos{};
	for (GameObject* gameobject : referenceGameObjects)
	{
		if (gameobject->GetObjectMember() != OBJECTMEMBER::PLAYER)continue;
		pos = gameobject->GetPosition();
		break;
	}
	if (speed >= 0)
	{
		if (moveCount == 0)
		{
			position.x += speed;
		}
		else
		{
			position.x -= speed;
		}
		speed -= 0.02;
		radian_y = atan2(position.x - pos.x, position.z - pos.z);
		radian_x = -atan2(position.y - pos.y, position.z - pos.z);
		rotation.x = radian_x * (180 / M_PI);
		rotation.y = radian_y * (180 / M_PI);
	}
	else
	{
		homingTime++;
		if (homingTime >= 10)
		{
			homingTime = 0;
			homingCount = 1;
		}
		//カウントが0ならホーミングする
		if (homingCount == 0)
		{
			dx = position.x - pos.x;//Xの距離の計算
			dy = position.y - pos.y;//Yの距離の計算
			dz = position.z - pos.z;//Zの距離の計算
			//ルートの中の計算
			da = dx * dx + dy * dy + dz * dz;
			L = sqrt(da);
		}

		position.x -= (dx / L) * 2;
		position.y -= (dy / L) * 2;
		position.z -= (dz / L) * 2;
		if (pos.z - 30 >= position.z)
		{
			deathFlag = true;
		}
	}

}

void NormalEnemy::MoveLimit()
{
	if (position.x > 90)
	{
		moveCount = 1;
	}
	if (position.x < -90)
	{
		moveCount = 0;
	}
}

void NormalEnemy::Hit()
{
	HP -= 1;
}

void NormalEnemy::Death()
{
	if (HP < 0)
	{
		deathFlag = true;
	}
}
