/**
 * \class EngineWrapper
 *
 * Mainly a helper class to hide some NCurses specific functions and settings
 */

#ifndef GEUS_ENGINE_H
#define GEUS_ENGINE_H

#include <list>
#include <memory>
#include "sprite.h"
#include "power_ups.h"

class EngineWrapper {
private:
	int m_screen_width; ///< Variable to store current screen's width
	int m_screen_height; ///< Variable to store current screen's height

	/// How long in milliseconds the engine should wait between each frame (gets calculated automatically)
	int m_refresh_rate;
public:
	/**
	 * Creates a new instance of out engine
	 *
	 * @param refresh_target Target amount of frames per second the engine should try to accomplish
	 */
	EngineWrapper(const int refresh_target);

	/// Default destructor
	~EngineWrapper();

	/**
	 * Returns currently stored screen's width
	 *
	 * @return Lastly gotten screen's width in character blocks
	 */
	int getScreenWidth() const;
	/**
	 * Returns currently stored screen's height
	 *
	 * @return Lastly gotten screen's height in character blocks
	 */
	int getScreenHeight() const;

	/**
	 * \brief Draws all given objects onto the canvas (calls their draw() methods)
	 * \note Yes, it's a bit cumbersome to have so many of our case specific arguments.
	 *
	 * Goes through all the given lists and calls draw() on each of its members. Plus it draws current score of the player.
	 * Handy to remind that the draw() method also recalculates the objects new location.
	 *
	 * @param timer Current state of the game's timer
	 * @param score Current player's score
	 * @param player_ref Pointer to the player object
	 * @param bullets_ref Reference to the list of visible bullets
	 * @param enemies_ref Reference to the list of visible enemies
	 * @param power_ups_ref Reference to the list of visible power-ups
	 */
	void drawAllObjects(const int timer, const int score, Sprite *player_ref, std::list<Sprite *> &bullets_ref, std::list<Sprite *> &enemies_ref, std::list<CPowerUp*>& power_ups_ref);

	/**
	 * Goes though each given list, removes and deletes any invisible object it finds
	 *
	 * @param bullets_ref Reference to the list of (in)visible bullets
	 * @param enemies_ref Reference to the list of (in)visible enemies
	 * @param power_ups_ref Reference to the list of (in)visible power-ups
	 */
	void deleteInvisibleObjects(std::list<Sprite*>& bullets_ref, std::list<Sprite*>& enemies_ref, std::list<CPowerUp*>& power_ups_ref);

	/// Waits for the 1000/targeted_framerate milliseconds
	void waitFPS();

	/// Tells NCurses to end and close the created drawing canvas
	void endNcurses();

	/// Loads screen's dimensions in character blocks (just a wrapper around ncurses call)
	void loadScreenDimensions();
};

#endif //GEUS_ENGINE_H
