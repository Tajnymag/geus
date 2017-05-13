#include "sprite.h"
#include "bullet.h"
#include "bullet_fast.h"

FastBullet::FastBullet(const int beg_x, const int beg_y, const int mom_x, const int mom_y) : Bullet("|", beg_x, beg_y, mom_x, mom_y) {
	m_update_freq = 1;
}
FastBullet::~FastBullet() {

}