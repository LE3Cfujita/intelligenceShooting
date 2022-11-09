#include "Rock.h"

Rock::Rock()
{
}

Rock::~Rock()
{
	safe_delete(model);
	safe_delete(rock);
}

void Rock::Initialize(Mouse* mouse)
{
	this->mouse = mouse;

	model = Model::LoadFormOBJ("aim");

	//�Ə�
	rock = Object3d::Create();
	rock->SetModel(model);
	rock->SetPosition(position);
	rock->SetRotation(rotation);
	rock->SetScale({ 3,3,3 });
}

void Rock::Update()
{

	XMFLOAT2 mouseM{ mouse->GetMouseVelocityX() ,mouse->GetMouseVelocityY() };

	position.x += mouseM.x / sensi;
	position.y -= mouseM.y / sensi;


	rock->SetPosition(position);
	rock->Update();
}

void Rock::Draw()
{
	rock->Draw();
}