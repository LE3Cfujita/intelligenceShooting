#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	safe_delete(modelPlayer);
	safe_delete(player);
}

void Player::Initialize(Input* input, Mouse* mouse, OptionKey* key)
{
	this->input = input;
	this->mouse = mouse;
	this->key = key;
	//OBJからモデルデータを読み込む
	modelPlayer = Model::LoadFormOBJ("player");
	modelBullet = Model::LoadFormOBJ("bullet");
	modelAim = Model::LoadFormOBJ("aim");
	//3Dオブジェクト生成
	player = Object3d::Create();
	//オブジェクトにモデルを紐付ける
	player->SetModel(modelPlayer);

	player->SetPosition(position);
	player->SetRotation(rotation);
	player->SetScale({ 0.5,0.7,0.5 });

	GetKey();
	//弾
	for (int i = 0; i < PBULLET_MAX; i++)
	{
		bullet[i] = Object3d::Create();
		bullet[i]->SetModel(modelBullet);
		bullet[i]->SetPosition(b[i].position);
		bullet[i]->SetRotation(b[i].rotation);
		bullet[i]->SetScale({ 0.7,0.7,0.7 });
	}
	//照準
	aim = Object3d::Create();
	aim->SetModel(modelAim);
	rock.position.z = 80;
	aim->SetPosition(rock.position);
	aim->SetRotation(rock.rotation);
	aim->SetScale({ 3,3,3 });


}

void Player::Update()
{

	Move();
	Attack();
	AttackMove();
	player->Update();
	for (int i = 0; i < PBULLET_MAX; i++)
	{
		bullet[i]->Update();
	}
	aim->Update();
}

void Player::Draw()
{
	player->Draw();

	for (int i = 0; i < PBULLET_MAX; i++)
	{
		if (b[i].flag == 1)
		{
			bullet[i]->Draw();
		}
	}
	aim->Draw();
}

void Player::Move()
{
	if (input->PushKey(moveLeft) == true)
	{
		if (position.x >= -20)
		{
			position.x -= 0.3;
			rotation.x = 5;
		}
	}
	else if (input->PushKey(moveRight) == true)
	{
		if (position.x <= 20)
		{
			position.x += 0.3;
			rotation.x = -5;
		}
	}
	else
	{
		rotation.x = 0;
	}
	if (input->PushKey(moveUp) == true)
	{
		if (position.y <= 13)
		{
			position.y += 0.3;
		}
	}
	else if (input->PushKey(moveDown) == true)
	{
		if (position.y >= -7)
		{
			position.y -= 0.3;
		}
	}

	XMFLOAT2 mouseM{ mouse->GetMouseVelocityX() ,mouse->GetMouseVelocityY() };

	rock.position.x += mouseM.x / sensi;
	rock.position.y -= mouseM.y / sensi;


	player->SetPosition(position);
	player->SetRotation(rotation);
	aim->SetPosition(rock.position);
}

void Player::Attack()
{
	if (attackCT == 0)
	{
		if (input->PushKey(attackKey) == true || mouse->PushMouseLeft() == true)
		{
			for (int i = 0; i < PBULLET_MAX; i++)
			{
				if (b[i].flag == 0)
				{
					b[i].flag = 1;
					b[i].position = position;
					attackCT = 1;
					break;
				}
			}
		}
	}
	else
	{
		attackCT += 1;
		if (attackCT >= 10)
		{
			attackCT = 0;
		}
	}
}

void Player::AttackMove()
{
	for (int i = 0; i < PBULLET_MAX; i++)
	{

		if (b[i].flag == 1)
		{
			b[i].homingTime++;
			if (b[i].homingTime >= 5)
			{
				b[i].homingTime = 0;
				b[i].homingCount = 1;
			}
			//カウントが0ならホーミングする
			if (b[i].homingCount == 0)
			{
				b[i].dx = b[i].position.x - rock.position.x;//Xの距離の計算
				b[i].dy = b[i].position.y - rock.position.y;//Yの距離の計算
				b[i].dz = b[i].position.z - rock.position.z;//Zの距離の計算
				//ルートの中の計算
				b[i].da = b[i].dx * b[i].dx + b[i].dy * b[i].dy + b[i].dz * b[i].dz;
				//da = dx * dx + dy * dy;
				b[i].L = sqrt(b[i].da);
			}
			//弾の移動
			b[i].position.x -= (b[i].dx / b[i].L) * b[i].speed;
			b[i].position.y -= (b[i].dy / b[i].L) * b[i].speed;
			b[i].position.z -= (b[i].dz / b[i].L) * b[i].speed;
		}

		if (b[i].position.z >= 100)
		{
			b[i].flag = 0;
			b[i].homingCount = 0;
		}
		bullet[i]->SetPosition(b[i].position);
	}
}

void Player::PlusNumber()
{
	bulletNumber += 1;
	if (bulletNumber > PBULLET_MAX)
	{
		bulletNumber = 0;
	}

}

void Player::Hit()
{
	HP -= 1;
}

void Player::RushHit()
{
	HP -= 10;
}

void Player::PHit()
{
	b[bulletNumber].flag = 0;
	b[bulletNumber].homingCount = 0;
	b[bulletNumber].position.x = 1000;
}

void Player::GetKey()
{
	moveLeft = key->GetLeftKey();
	moveRight = key->GetRightKey();
	moveUp = key->GetUpKey();
	moveDown = key->GetDownKey();
	attackKey = key->GetAttackKey();
}
