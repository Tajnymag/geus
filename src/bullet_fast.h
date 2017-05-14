/**
 * \class FastBullet
 *
 * This class serves purpose of being the default bullet for FPowerUp.
 * Compared to basic Bullet, it has an increase speed of movement,
 * accomplished by being redrawn every tick of the game's timer.
 * It inherits heavily from it's parent class - Bullet and differs only in the default constructor.
 */

#ifndef GEUS_BULLET_FAST_H
#define GEUS_BULLET_FAST_H

class FastBullet : public Bullet {
public:
	/**
	 * Creates a new instance of a fast travelling bullet
	 * \note Compared to Bullet, it doesn't use a visual_string parameter as it is hardcoded into the class.
	 *
	 * @param beg_x Starting point on X axis for the bullet
	 * @param beg_y Starting point on Y axis for the bullet
	 * @param mom_x Momentum of the bullet on X axis
	 * @param mom_y Momentum of the bullet on Y axis
	 */
	FastBullet(const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);

	/// Default destructor
	~FastBullet();
};

#endif //GEUS_BULLET_FAST_H
