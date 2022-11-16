#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
	safe_delete(model);
	safe_delete(bullet);
}

void PlayerBullet::Initialize()
{
	speed = 7;
	objectMember = OBJECTMEMBER::PLAYERBULLET;
	rotation = { 0,-90,0 };
	model = Model::LoadFormOBJ("bullet");
	//弾
	bullet = Object3d::Create();
	bullet->SetModel(model);
	bullet->SetRotation(rotation);
	bullet->SetScale({ 0.7,0.7,0.7 });
}

void PlayerBullet::Update()
{
	Move();
}

void PlayerBullet::Draw()
{
	bullet->Update();
	bullet->Draw();
}

void PlayerBullet::Move()
{

	if (deathFlag == false)
	{
		homingTime++;
		if (homingTime >= 5)
		{
			homingTime = 0;
			homingCount = 1;
		}
		//カウントが0ならホーミングする
		if (homingCount == 0)
		{
			for (GameObject* gameobject : referenceGameObjects)
			{
				if (gameobject->GetObjectMember() == GameObject::OBJECTMEMBER::ROCK)
				{
					dx = position.x - gameobject->GetPosition().x;//Xの距離の計算
					dy = position.y - gameobject->GetPosition().y;//Yの距離の計算
					dz = position.z - gameobject->GetPosition().z;//Zの距離の計算
					//ルートの中の計算
					da = dx * dx + dy * dy + dz * dz;
					//da = dx * dx + dy * dy;
					L = sqrt(da);
				}
			}
		}
		//弾の移動
		position.x -= (dx / L) * speed;
		position.y -= (dy / L) * speed;
		position.z -= (dz / L) * speed;
	}

	if (position.z >= 100)
	{
		deathFlag = true;
		homingCount = 0;
	}
	bullet->SetPosition(position);
}

void PlayerBullet::Create()
{
	for (GameObject* gameobject : referenceGameObjects)
	{
		if (gameobject->GetObjectMember() != GameObject::OBJECTMEMBER::PLAYERBULLET)continue;
		if (deathFlag == true)
		{
			deathFlag = false;
			position = gameobject->GetPosition();;
			attackCT = 1;
		}
	}

}


void PlayerBullet::Hit()
{
	deathFlag = true;
	homingCount = 0;
	position.x = 1000;
}