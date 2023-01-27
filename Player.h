#pragma once
#include "Vec2.h"
#include "Screen.h"
#include "Matrix3x3.h"
#include "Bullet.h"

class Player
{
private:
	Vec2 m_transform;
	int m_speed;
	int m_radius;
	Screen* m_screen;
	Bullet* m_bullet;

public:

	Player(Screen* screen);
	~Player();

	void Update();
	void Draw();

	Bullet& GetBullet() { return *m_bullet; }

};

