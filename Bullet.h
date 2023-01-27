#pragma once
#include "Vec2.h"
#include "Screen.h"
#include "Matrix3x3.h"

class Bullet
{
private:
	Vec2 m_translate;
	int m_speed;
	bool isShot;
	Screen* m_screen;
public:

	Bullet();
	Bullet(Screen* screen, Vec2 pos);
	~Bullet();

	void Init(Vec2 pos);
	void Update();
	void Draw();

	Vec2 GetTransform() { return m_translate; }

};

