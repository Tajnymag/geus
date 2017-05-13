#include "custom_ncurses.h"
#include "sprite.h"
#include "bullet.h"
#include "bullet_huge.h"

HugeBullet::HugeBullet(const int beg_x, const int beg_y, const int mom_x, const int mom_y) : Bullet("@@@", beg_x, beg_y, mom_x, mom_y) {

}
HugeBullet::~HugeBullet() {

}

bool HugeBullet::overlapsWith(Sprite *other_sprite) const {
	if (other_sprite->positionX() >= m_x - 1 && other_sprite->positionX() <= m_x + 1) {
		if (other_sprite->positionY() >= m_y - 1 && other_sprite->positionY() <= m_y + 1) {
			return true;
		}
	}
	return false;
}

void HugeBullet::draw(const int timer) {
	calculateNewPosition(timer);

	if (m_visible) {
		mvprintw(m_y - 1, m_x - 1, m_visual_string);
		mvprintw(m_y, m_x - 1, m_visual_string);
	}
}