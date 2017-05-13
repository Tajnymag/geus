#ifndef GEUS_BULLET_HUGE_H
#define GEUS_BULLET_HUGE_H

class HugeBullet : public Bullet {
public:
	HugeBullet(const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);
	~HugeBullet();

	bool overlapsWith(Sprite* other_sprite) const;
	void draw(const int timer);
};

#endif //GEUS_BULLET_HUGE_H
