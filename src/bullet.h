#ifndef GEUS_BULLET_H
#define GEUS_BULLET_H

class Bullet : public Sprite {
public:
	Bullet(const char* visual_string, const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);
	virtual ~Bullet();
};

#endif //GEUS_BULLET_H
