#include "Enemy.h"
#include "Bullet.h"

bool Enemy::isAlive = true;

Enemy::Enemy() {
	transform = Vec2();
	velocity = Vec2();
	direction = Vec2(cosf(0), sinf(0));
	radius = 30;
	speed = 10;
}

Enemy::Enemy(Vec2 position) {
	transform = position;
	velocity = Vec2();
	direction = Vec2(cosf(0),sinf(0));
	radius = 30;
	speed = 10;
}

Enemy::~Enemy() {
	
}

void Enemy::Init(Vec2 position) {
	transform = position;
	velocity = Vec2();
	direction = Vec2(cosf(0), sinf(0));
	radius = 30;
	speed = 10;
}

void Enemy::Update() {

	if (isAlive) {

		velocity = direction * speed;

		transform += velocity;

		if (transform.x < -640 + radius || transform.x > 640 - radius) {
			speed = -speed;
		}

	}

}

void Enemy::Draw(Screen& screen) {
	if (isAlive) {
		screen.DrawEllipse(transform, radius, radius, 0.0f, RED, kFillModeSolid);
	}
}