#include "Camera.h"
#include "keyInput.h"
#include "Function.h"
#include "Rand.h"

void Camera::Init() {

}

void Camera::Update() {

	if (PressKey(DIK_UP)) {
		translate.y += move_speed;
	}
	else if (PressKey(DIK_DOWN)) {
		translate.y += -move_speed;
	}

	if (PressKey(DIK_RIGHT)) {
		translate.x += move_speed;
	}
	else if (PressKey(DIK_LEFT)) {
		translate.x += -move_speed;
	}

	CameraShake();

	worldMatrix = Matrix3x3::MakeWorldMatrix(1.0f, 1.0f, 0, translate);

	Function::Vector2ScreenPrintf(0, 0, translate);

}

void Camera::CameraShake() {

	if (isShake == true) {
		shake.x = Random(shakeMin, shakeMax);
		shake.y = Random(shakeMin, shakeMax);

		shakeMin += 0.1f;
		shakeMax -= 0.1f;

		if (shakeMin >= 0 && shakeMax <= 0) {
			isShake = false;
		}

	}

	if (isShake == false) {
		shakeMin = -10.0f;
		shakeMax = 10.0f;
		shake = Vec2(0, 0);
	}

}