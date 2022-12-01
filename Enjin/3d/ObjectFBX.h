#pragma once

#include"ModelFBX.h"
#include"Camera.h"
#include"FbxLoader.h"

#include<Windows.h>
#include<wrl.h>
#include<d3d12.h>
#include<d3dx12.h>
#include<DirectXMath.h>
#include<string>

class ObjectFBX
{
protected://�G�C���A�X
	//Microsoft::WRL::���ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
	//DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://�T�u�N���X
	//�萔�o�b�t�@�p�f�[�^�\����(���W�ϊ��s��p)
	struct ConstBufferDataTransform
	{
		XMMATRIX voiewproj;//�r���[�v���W�F�N�V�����s��
		XMMATRIX world;//���[���h�s��
		XMFLOAT3 cameraPos;//�J�������W(���[���h���W)
	};

public://�ÓI�����o�֐�
	static void SetDevice(ID3D12Device* device) { ObjectFBX::device = device; }
	static void SetCamera(Camera* camera) { ObjectFBX::camera = camera; }
	/// <summary>
	/// �O���t�B�b�N�p�C�v���C���̐���
	/// </summary>
	static void CreateGraphicsPipeline();

private://�ÓI�����o�ϐ�
		//�f�o�C�X
	static ID3D12Device* device;
	//�J����
	static Camera* camera;

	//���[�g�V�O�l�`��
	static ComPtr<ID3D12RootSignature>rootsignature;
	//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
	static ComPtr<ID3D12PipelineState>pipelinestate;

public://�����o�֐�

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();
	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();
	/// <summary>
	/// ���f���̃Z�b�g
	/// </summary>
	/// <param name="model">���f��</param>
	void SetModel(ModelFBX* model) { this->model = model; }

	void Draw(ID3D12GraphicsCommandList* cmdList);


	/// <summary>
	/// �A�j���[�V�����J�n
	/// </summary>
	void PlayAnimation();

public://�萔
	//�{�[���̍ő吔
	static const int MAX_BONES = 32;

	//�萔�o�b�t�@�p�f�[�^�\����(�X�L�j���O)
	struct ConstBufferDataSkin
	{
		XMMATRIX bones[MAX_BONES];
	};



protected://�����o�ϐ�
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource>constBuffTransform;
	//�萔�o�b�t�@(�X�L��)
	ComPtr<ID3D12Resource>constBuffSkin;
private://�����o�ϐ�
	//���[�J���X�P�[��
	XMFLOAT3 scale = { 1,1,1 };
	//x,y,z������̃��[�J����]�p
	XMFLOAT3 rotation = { 0,0,0 };
	//���[�J�����W
	XMFLOAT3 position = { 0,0,0 };
	//���[�J�����[���h�ϊ��s��
	XMMATRIX matWorld;
	//���f��
	ModelFBX* model = nullptr;

	//1�t���[���̎���
	FbxTime frameTime;
	//�A�j���[�V�����J�n����
	FbxTime startTime;
	//�A�j���[�V�����I������
	FbxTime endTime;
	//���ݎ���(�A�j���[�V����)
	FbxTime currentTime;
	//�A�j���[�V�����Đ���
	bool isPlay = false;
};
