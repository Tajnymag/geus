#include "sprite.h"
#include "bullet.h"

Bullet::Bullet(const char* visual_string, const int beg_x, const int beg_y, const int mov_x, const int mov_y) : Sprite(visual_string, beg_x, beg_y) {
	m_visible = true;

	m_update_freq = 2;

	m_direction_x = mov_x;
	m_direction_y = mov_y;
}
Bullet::~Bullet() {

}