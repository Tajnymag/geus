/**
 * \class Bullet
 *
 * This class serves purpose of being a basic bullet type used for further inheritance.
 * It inherits heavily from class Sprite and differs basically only in the default constructor.
 */

#ifndef GEUS_BULLET_H
#define GEUS_BULLET_H

class Bullet : public Sprite {
public:
	/**
	 * Creates a new instance of a basic bullet
	 *
	 * @param visual_string String of characters which represents the bullet on the screen.
	 * @param beg_x Starting point on X axis for the bullet
	 * @param beg_y Starting point on Y axis for the bullet
	 * @param mom_x Momentum of the bullet on X axis
	 * @param mom_y Momentum of the bullet on Y axis
	 */
	Bullet(const char* visual_string, const int beg_x, const int beg_y, const int mom_x = 0, const int mom_y = -1);

	/// Default destructor
	virtual ~Bullet();
};

#endif //GEUS_BULLET_H
