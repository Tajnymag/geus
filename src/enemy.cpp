#include "sprite.h"
#include "enemy.h"

Enemy::Enemy(const char* visual_string, const int beg_x, const int beg_y) : Sprite(visual_string) {
	m_visible = true;

	m_update_freq = 40;
	m_x = beg_x;
	m_y = beg_y;
	m_direction_x = 0;
	m_direction_y = 1;
}
Enemy::~Enemy() {

}