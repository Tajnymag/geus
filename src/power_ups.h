#ifndef GEUS_POWER_UPS_H
#define GEUS_POWER_UPS_H

class CPowerUp : public Sprite {
protected:
	int m_powerup_index;
public:
	CPowerUp(const int pos_x, const int pos_y);
	virtual ~CPowerUp();

	int getIndex() const;
	virtual void draw(const int timer);
};

class TriPowerUp : public CPowerUp {
public:
	TriPowerUp(const int pos_x, const int pos_y);
	~TriPowerUp();

	void draw(const int timer);
};

class HBPowerUp : public CPowerUp {
public:
	HBPowerUp(const int pos_x, const int pos_y);
	~HBPowerUp();

	void draw(const int timer);
};

class FPowerUp : public CPowerUp {
public:
	FPowerUp(const int pos_x, const int pos_y);
	~FPowerUp();

	void draw(const int timer);
};

#endif //GEUS_POWER_UPS_H
