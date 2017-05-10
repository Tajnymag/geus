#ifndef GEUS_BULLET_H
#define GEUS_BULLET_H

class Bullet : public Sprite {
public:
	Bullet(const char* visual_string, const int beg_x, const int beg_y);
	~Bullet();

	void calculateNewPosition(const int timer);
};

#endif //GEUS_BULLET_H
