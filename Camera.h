#pragma once
#include "Vec2.h"
#include "Matrix3x3.h"

class Camera
{
private:
	Vec2 translate;
	Vec2 shake;
	Matrix3x3 worldMatrix;
	float move_speed;
	float shakeMin;
	float shakeMax;

public:
	bool isShake;

	Camera() {
		translate = Vec2(0, 0);
		worldMatrix = Matrix3x3::MakeWorldMatrix(1.0f, 1.0f, 0,translate);
		move_speed = 5.0f;
		isShake = false;
		shakeMin = -10.0f;
		shakeMax = 10.0f;
	}

	void Init();
	void Update();

	void CameraShake();

	Vec2 GetTranslate() { return translate; }
	Vec2 GetShake() { return shake; }
	Matrix3x3 GetMatrix() { return worldMatrix; }


};

