/**
 * \class HugeBullet
 *
 * This class serves purpose of being the default bullet for HBPowerUp.
 * Compared to basic Bullet, it is increased in size by a factor of three.
 */

#ifndef GEUS_BULLET_HUGE_H
#define GEUS_BULLET_HUGE_H

class HugeBullet : public Bullet {
public:
	/**
	 * Creates a new instance of a large sized bullet
	 * \note Compared to Bullet, it doesn't use a visual_string parameter as it is hardcoded into the class.
	 *
	 * @param beg_x Starting point on X axis for the bullet
	 * @param beg_y Starting point on Y axis for the bullet
	 * @param mom_x Momentum of the bullet on X axis
	 * @param mom_y Momentum of the bullet on Y axis
	 */
	HugeBullet(const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);

	/// Default destructor
	~HugeBullet();

	/**
	 * Checks, whether it doesn't overlap with given coordinates
	 * \note Yes, it doesn't check overlapping of rectangels but rather only a single block.
	 *
	 * @param other_sprite Different graphical element of whose coordinates we want to compare ourselves with
	 * @return Returns true on found overlap, false otherwise
	 */
	bool overlapsWith(Sprite* other_sprite) const;

	/**
	 * Draws itself onto the standard canvas.
	 *
	 * @param timer Current state of the games timer
	 */
	void draw(const int timer);
};

#endif //GEUS_BULLET_HUGE_H
