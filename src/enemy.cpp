#include "sprite.h"
#include "enemy.h"

Enemy::Enemy(const char* visual_string, const int beg_x, const int beg_y) : Sprite(visual_string) {
	m_visible = true;

	m_update_freq = 20;
	m_x = beg_x;
	m_y = beg_y;
}
Enemy::~Enemy() {}

void Enemy::calculateNewPosition(const int timer) {
	if (timer % m_update_freq == 0) {
		m_y++;
	}
}