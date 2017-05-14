/**
 * \class Enemy
 *
 * This class serves purpose of being a basic enemy type.
 * It basically inherits everything from it's parent class - Sprite.
 * We only change it's movement direction inside the constructor.
 */

#ifndef GEUS_ENEMY_H
#define GEUS_ENEMY_H

class Enemy : public Sprite {
public:
	/**
	 * Creates a new instance of a basic enemy
	 *
	 * @param visual_string String of characters which represents the enemy on the screen.
	 * @param beg_x Starting point on X axis for the enemy
	 * @param beg_y Starting point on Y axis for the enemy
	 */
	Enemy(const char *visual_string, const int beg_x = 0, const int beg_y = 0);

	/// Default destructor
	virtual ~Enemy();
};

#endif //GEUS_ENEMY_H
