#include "NormalEnemy.h"

NormalEnemy::NormalEnemy()
{
}

NormalEnemy::~NormalEnemy()
{
	//safe_delete(obj);
}

void NormalEnemy::Initialize(XMFLOAT3 pos)
{
	objectMember = OBJECTMEMBER::NORMALENEMY;
	position = pos;
	rotation = { 0,180,0 };
	HP = 2;
	radius = 2;
<<<<<<< HEAD
	HP = 20;
	speed = 0.5;
	objectMember = OBJECTMEMBER::NORMALENEMY;
	//OBJ©ηff[^πΗέή
	model = Model::CreateModel(7);
	//3DIuWFNgΆ¬
=======
	model = Model::CreateModel(5);
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
	obj = Object3d::Create();
	obj->SetModel(model);
<<<<<<< HEAD
	obj->SetScale({ 1.5,1.5,1.5 });
=======
	obj->SetPosition(position);
	obj->SetRotation(rotation);
	obj->SetScale({ 0.7,0.7,0.7 });
	speed = 1;
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
}

void NormalEnemy::Update()
{
	Move();
<<<<<<< HEAD
=======
	Death();
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
}

void NormalEnemy::Draw()
{
<<<<<<< HEAD
	obj->SetPosition(position);
	obj->SetRotation(rotation);
=======
	obj->SetRotation(rotation);
	obj->SetPosition(position);
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
	obj->Update();
	obj->Draw();
}

void NormalEnemy::Create(int move)
{
	deathFlag == false;
<<<<<<< HEAD
	if (move == 0)
	{
		directionX = 1;
		directionY = 1;
	}
	else if (move == 1)
	{
		directionX = 2;
		directionY = 1;
	}
	else if (move == 2)
	{
		directionX = 1;
		directionY = 2;
	}
	else
	{
		directionX = 2;
		directionY = 2;
=======
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
		//JEgͺ0Θηz[~O·ι
		if (homingCount == 0)
		{
			dx = position.x - pos.x;//XΜ£ΜvZ
			dy = position.y - pos.y;//YΜ£ΜvZ
			dz = position.z - pos.z;//ZΜ£ΜvZ
			//[gΜΜvZ
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
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
	}
}

void NormalEnemy::Hit()
{
	HP -= 1;
}

void NormalEnemy::Death()
{
<<<<<<< HEAD
	if (HP <= 0)
	{
		deathFlag = true;
	}
}

void NormalEnemy::Move()
{

	XMFLOAT3 pos{};
	for (GameObject* gameobject : referenceGameObjects)
	{
		if (gameobject->GetObjectMember() != OBJECTMEMBER::PLAYER)continue;
		pos = gameobject->GetPosition();
		break;
	}
	radian_y = atan2(position.x - pos.x, position.z - pos.z);
	radian_x = -atan2(position.y - pos.y, position.z - pos.z);
	rotation.x = radian_x * (180 / M_PI);
	rotation.y = radian_y * (180 / M_PI);
	
	if (directionX == 1)
	{
		position.x -= speed;
	}
	else
	{
		position.x += speed;
	}
	if (directionY == 1)
	{
		position.y -= speed;
	}
	else
	{
		position.y += speed;
	}
	MoveLimit();
}

void NormalEnemy::MoveLimit()
{
	if (position.x > 90)
	{
		directionX = 1;
	}
	if (position.x < -90)
	{
		directionX = 2;
	}
	if (position.y > 60)
	{
		directionY = 1;
	}
	if (position.y < -55)
	{
		directionY = 2;
	}
=======
	if (HP < 0)
	{
		deathFlag = true;
	}
>>>>>>> parent of b914602 (γ­γ±γγγ’γγ«θΏ½ε )
}
