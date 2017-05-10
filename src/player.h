#ifndef GEUS_PLAYER_H
#define GEUS_PLAYER_H

class Player : public Sprite {
private:
	int power_up;

	double m_drag;
public:
	Player(const int beg_x = 1, const int beg_y = 1);
	~Player();

	double speedX;
	double speedY;

	void draw(const int timer);
	void calculateNewPosition(const int timer);
	void handleWindowCollision(const int screen_width, const int screen_height);
};

#endif //GEUS_PLAYER_H
