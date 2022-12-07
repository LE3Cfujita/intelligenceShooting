#include "rocket.h"

rocket::rocket()
{
}

rocket::~rocket()
{
	safe_delete(obj);
}

void rocket::Initialize(XMFLOAT3 pos)
{
	objectMember = OBJECTMEMBER::ENEMYROCKET;
	position = pos;
	HP = 2;
	radius = 2;
	rotation.y = 180;
	model = Model::CreateModel(6);
	obj = Object3d::Create();
	obj->SetModel(model);
	/*obj->SetPosition(position);
	obj->SetRotation(rotation);*/
	obj->SetScale({ 1,1,0.7 });
	speed = 1;
}

void rocket::Update()
{
	Move();
	Death();
}

void rocket::Draw()
{
	obj->SetRotation(rotation);
	obj->SetPosition(position);
	obj->SetColor({ 1,0,0,1 });
	obj->Update();
	obj->Draw();
	}

		void rocket::Create(int move)
	{
		deathFlag == false;
		moveCount = move;

	}

	void rocket::Move()
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
			//�J�E���g��0�Ȃ�z�[�~���O����
			if (homingCount == 0)
			{
				dx = position.x - pos.x;//X�̋����̌v�Z
				dy = position.y - pos.y;//Y�̋����̌v�Z
				dz = position.z - pos.z;//Z�̋����̌v�Z
				//���[�g�̒��̌v�Z
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

	void rocket::MoveLimit()
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

	void rocket::Hit()
	{
		HP -= 1;
	}

	void rocket::Death()
	{
		if (HP < 0)
		{
			deathFlag = true;
		}
	}