#ifndef GEUS_SPRITE_H
#define GEUS_SPRITE_H

class Sprite {
protected:
	const char* m_visual_string;
	bool m_visible;

	int m_update_freq;
	double m_x;
	double m_y;
	int m_direction_x;
	int m_direction_y;
public:
	Sprite(const char* visual_string, const int beg_x = 0, const int beg_y = 0);
	virtual ~Sprite();

	virtual void calculateNewPosition(const int timer);
	bool getVisibility() const;
	void setVisibility(const bool new_visibility);
	int positionX() const;
	int positionY() const;

	virtual bool overlapsWith(Sprite* other_sprite) const;

	virtual void draw(const int timer);
	virtual void handleWindowCollision(const int screen_width, const int screen_height);
};

#endif //GEUS_SPRITE_H
