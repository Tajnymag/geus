/**
 * \class CPowerUp
 * \class TriPowerUp
 * \class HBPowerUp
 * \class FPowerUp
 *
 * This header file hosts all of the power-ups at the same time.
 * I did it because of how small the differences between the power-ups are.
 *
 * CPowerUp acts as the parent's class. It inherits directly from Sprite.
 */

#ifndef GEUS_POWER_UPS_H
#define GEUS_POWER_UPS_H

class CPowerUp : public Sprite {
protected:
	/// Index of the power-up
	int m_powerup_index;
public:
	/**
	 * Creates a new instance of a basic power-up and sets it's own index.
	 *
	 * \note It's not really logical, but this power-up acts as a "power-down". It's the default shooting method player
	 * uses from the beginning. So it's quite slow and shoots only basic bullets.
	 *
	 * @param pos_x Point on the X axis where the power-up should be placed
	 * @param pos_y Point on the Y axis where the power-up should be placed
	 */
	CPowerUp(const int pos_x, const int pos_y);

	/// Default destructor
	virtual ~CPowerUp();

	/// Returns it's own index
	int getIndex() const;

	/**
	 * Draws itself on the standard screen.
	 * It's overriden because of the different hardcoded color and character it uses as identification.
	 *
	 * @param timer Current state of the game's timer.
	 */
	virtual void draw(const int timer);
};

class TriPowerUp : public CPowerUp {
public:
	/**
	 * Creates a new instance of a Triple-Bullet power-up and sets it's own index.
	 *
	 * @param pos_x Point on the X axis where the power-up should be placed
	 * @param pos_y Point on the Y axis where the power-up should be placed
	 */
	TriPowerUp(const int pos_x, const int pos_y);

	/// Default destructor
	~TriPowerUp();

	/**
	 * Draws itself on the standard screen.
	 * It's overriden because of the different hardcoded color and character it uses as identification.
	 *
	 * @param timer Current state of the game's timer.
	 */
	void draw(const int timer);
};

class HBPowerUp : public CPowerUp {
public:
	/**
	 * Creates a new instance of a Huge-Bullet power-up and sets it's own index.
	 *
	 * @param pos_x Point on the X axis where the power-up should be placed
	 * @param pos_y Point on the Y axis where the power-up should be placed
	 */
	HBPowerUp(const int pos_x, const int pos_y);

	/// Default destructor
	~HBPowerUp();

	/**
	 * Draws itself on the standard screen.
	 * It's overriden because of the different hardcoded color and character it uses as identification.
	 *
	 * @param timer Current state of the game's timer.
	 */
	void draw(const int timer);
};

class FPowerUp : public CPowerUp {
public:
	/**
	 * Creates a new instance of a Fast-Bullet power-up and sets it's own index.
	 *
	 * @param pos_x Point on the X axis where the power-up should be placed
	 * @param pos_y Point on the Y axis where the power-up should be placed
	 */
	FPowerUp(const int pos_x, const int pos_y);

	/// Default destructor
	~FPowerUp();

	/**
	 * Draws itself on the standard screen.
	 * It's overriden because of the different hardcoded color and character it uses as identification.
	 *
	 * @param timer Current state of the game's timer.
	 */
	void draw(const int timer);
};

#endif //GEUS_POWER_UPS_H
