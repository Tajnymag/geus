/**
 * \class Player
 *
 * This class serves purpose of being the main player type.
 * Inherits a lot from it's parent class - Sprite, but compared to the other Sprite's children,
 * it features it's own (simplified) physics engine.
 */

#ifndef GEUS_PLAYER_H
#define GEUS_PLAYER_H

#include <list>

class Player : public Sprite {
private:
	/// Index of the currently used power-up (method of shooting)
	int power_up;

	/// Drag which is applied on every frame
	double m_drag;
public:
	/**
	 * Creates a new instance of the player.
	 * It sets up m_drag to a hardcoded value and
	 * resets index of current power-up.
	 *
	 * @param beg_x Starting point on X axis for the player
	 * @param beg_y Starting point on Y axis for the player
	 */
	Player(const int beg_x = 1, const int beg_y = 1);

	/// Default destructor
	~Player();

	double speedX; ///< Speed of the rocket on X axis
	double speedY; ///< Speed of the rocket on Y axis

	/**
	 * \brief Makes the rocket shoot using the current shooting method (power-up)
	 *
	 * Checks the current shooting method and adds a bullet to the game's bullet list accordingly.
	 *
	 * @param bullets_ref Reference to the game's list with bullets
	 */
	void shoot(std::list<Sprite*>& bullets_ref);

	/**
	 * Overrides parent's drawign function because of it's specific shape.
	 *
	 * @param timer Current state of the game's timer
	 */
	void draw(const int timer);

	/**
	 * Setter for the player's shooting method (index of the power-up)
	 *
	 * @param power_up_index New shooting method
	 */
	void setPowerUp(const int power_up_index);

	/**
	 * Overrides parent's calculatoin method because of it's own movement mechanics.
	 * Uses speed, current position and drag to calculate it's new position.
	 *
	 * @param timer Current state of the game's timer
	 */
	void calculateNewPosition(const int timer);

	/**
	 * Stops the player from going out of window
	 *
	 * @param screen_width Current width of the screen in character blocks
	 * @param screen_height Current height of the screen in character blocks
	 */
	void handleWindowCollision(const int screen_width, const int screen_height);
};

#endif //GEUS_PLAYER_H
