#include "Player.h"
#include "keyInput.h"

Player::Player(Screen* screen) {

	m_transform.x = 200;
	m_transform.y = 200;
	m_radius = 30;
	m_speed = 10;
	m_screen = screen;

	Bullet bullet(m_screen, m_transform);

	m_bullet = new Bullet(m_screen, m_transform);

}

Player::~Player() {

}

void Player::Update() {

	if (PressKey(DIK_W)) {

		m_transform.y += m_speed;

	}
	else if (PressKey(DIK_S)) {

		m_transform.y -= m_speed;

	}

	if (PressKey(DIK_D)) {

		m_transform.x += m_speed;

	}
	else if (PressKey(DIK_A)) {

		m_transform.x -= m_speed;

	}

	if (TriggerKey(DIK_SPACE)) {

		m_bullet->Init(m_transform);

	}

	m_bullet->Update();

}

void Player::Draw() {

	m_bullet->Draw();
	m_screen->DrawEllipse(m_transform,m_radius,m_radius,0.0f,WHITE,kFillModeSolid);

}