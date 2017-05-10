#ifndef GEUS_ENEMY_H
#define GEUS_ENEMY_H

class Enemy : public Sprite {
protected:
	double virt_y;
public:
	Enemy(const char *visual_string, const int beg_x = 0, const int beg_y = 0);
	virtual ~Enemy();

	virtual void calculateNewPosition(const int timer);
};

#endif //GEUS_ENEMY_H
