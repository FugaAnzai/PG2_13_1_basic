#include "Bullet.h"

Bullet::Bullet() {

}

Bullet::Bullet(Screen* screen,Vec2 pos) {

	m_translate = pos;
	m_speed = 8.0f;
	m_screen = screen;
	isShot = false;

}

Bullet::~Bullet() {

}

void Bullet::Init(Vec2 pos) {

	if (isShot == false) {
		m_translate = pos;
		isShot = true;
	}
}

void Bullet::Update() {

	if (isShot) {
		m_translate.y += m_speed;

		if (m_translate.y > 400) {
			isShot = false;
		}

	}

}

void Bullet::Draw() {

	if (isShot) {
		m_screen->DrawEllipse(m_translate, 7, 7, 0.0f, RED, kFillModeSolid);

	}


}