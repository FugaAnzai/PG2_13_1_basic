#pragma once
#include "Vec2.h"
#include "Screen.h"

class Enemy
{
private:
	Vec2 transform;
	Vec2 velocity;
	Vec2 direction;
	float radius;
	float speed;
public:

	static bool isAlive;

	/// <summary>
	/// 初期値固定(0,0)
	/// </summary>
	Enemy();
	/// <summary>
	/// 初期値指定
	/// </summary>
	Enemy(Vec2 position);
	~Enemy();

	void Init(Vec2 position);
	void Update();
	void Draw(Screen& screen);

	Vec2 GetTransform() { return transform; }
	void SetTransform(Vec2 transform) { this->transform = transform; }
	float GetSpeed() { return speed; }
	void SetSpeed(float speed) { this->speed = speed; }
	bool GetIsAlive() { return isAlive; }
	void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }


};

