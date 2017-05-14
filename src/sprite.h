/**
 * \class Sprite
 *
 * Our main parent class for all of the graphical objects.
 */

#ifndef GEUS_SPRITE_H
#define GEUS_SPRITE_H

class Sprite {
protected:
	/// String of characters representing the sprite on the screen
	const char* m_visual_string;

	/**
	 * Boolean variable to store sprite's state.
	 * In current implementation of the game, any object that becomes invisible, will be destroyed
	 * and removed from a list that it's memeber of.
	 */
	bool m_visible;

	int m_update_freq; ///< Basically stores a position in timer, when the position of the sprite shall be recalculated
	double m_x; ///< Position on the X axis of the screen for the sprite
	double m_y; ///< Position on the Y axis of the screen for the sprite

	int m_direction_x; ///< Basically momentum of the sprite on the X axis
	int m_direction_y; ///< Basically momentum of the sprite on the Y axis
public:
	/**
	 * Creates a new instance of a basic sprite type
	 *
	 *	update_frequency is set to zero
	 *	visible is set to true
	 *
	 * @param visual_string String of characters which represents the sprite on the screen.
	 * @param beg_x Starting point on X axis for the bullet
	 * @param beg_y Starting point on Y axis for the bullet
	 */
	Sprite(const char* visual_string, const int beg_x = 0, const int beg_y = 0);

	/// Default destructor
	virtual ~Sprite();

	/**
	 * Recalculates the current position based on the m_direction and current state of the game's timer
	 *
	 * @param timer Current state of the game's timer
	 */
	virtual void calculateNewPosition(const int timer);

	/**
	 * Returns current visibilty of the sprite
	 *
	 * @return Returns true if the sprite is visible, otherwise returns false
	 */
	bool getVisibility() const;

	/**
	 * Sets a new visibility value
	 *
	 * @param new_visibility New state of the sprite's visibility
	 */
	void setVisibility(const bool new_visibility);

	/**
	 * Returns current position on the screen's X axis of the sprite
	 *
	 * @return current position on the screen's X axis of the sprite
	 */
	int positionX() const;

	/**
	 * Returns current position on the screen's Y axis of the sprite
	 *
	 * @return current position on the screen's Y axis of the sprite
	 */
	int positionY() const;

	/**
	 * Checks, whether it doesn't overlap with given coordinates
	 * \note Yes, it doesn't check overlapping of rectangels but rather only a single block.
	 *
	 * @param other_sprite Different graphical element of whose coordinates we want to compare ourselves with
	 * @return Returns true on found overlap, false otherwise
	 */
	virtual bool overlapsWith(Sprite* other_sprite) const;

	/**
	 * Draws itself onto the standard canvas.
	 *
	 * @param timer Current state of the games timer
	 */
	virtual void draw(const int timer);

	/**
	 * Function to check, whether the sprite got out of the viewport. If so, it sets it's visibility to false
	 *
	 * @param screen_width Current width of the screen in character blocks
	 * @param screen_height Current height of the screen in character blocks
	 */
	virtual void handleWindowCollision(const int screen_width, const int screen_height);
};

#endif //GEUS_SPRITE_H
