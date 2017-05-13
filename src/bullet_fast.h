#ifndef GEUS_BULLET_FAST_H
#define GEUS_BULLET_FAST_H

class FastBullet : public Bullet {
public:
	FastBullet(const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);
	~FastBullet();
};

#endif //GEUS_BULLET_FAST_H
