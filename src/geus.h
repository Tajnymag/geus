/**
 * \class Geus
 *
 * This class serves as the main game class. Here is where all the magic happens.
 * Some of the work is offloaded to the Engine.h. That's done solely to make the corresponding .cpp file for this class
 * smaller and a bit easier to read.
 */

#ifndef GEUS_GEUS_H
#define GEUS_GEUS_H

#include "engine.h"
#include "player.h"
#include "power_ups.h"

class Geus {
private:
	/// Instance of the engine
	EngineWrapper engine;

	/// Single instance of the player's object
	Player* player = NULL;
	/// List with pointers to all visible enemies
	std::list<Sprite*> enemies;
	/// List with pointers to all visible bullets
	std::list<Sprite*> bullets;

	/**
	 * List with pointers to all visible power_ups
	 * \note For some reason it couldn't be a general Sprite* type because of it's own additional member functions.
	 */
	std::list<CPowerUp*> power_ups;

	/**
	 * List with enemy positions on the X axis. Number "-1" serves purpose as a newline
	 * It gets populated at the beginning of the game from a file.
	 */
	std::list<int> enemy_positions;

	int highest_score; ///< Highest score loaded from a file
	int score; ///< Current score
	bool is_running; ///< A boolean variable controlling the main game loop

	/// Function used to check the currently pressed key and link it to a corresponding action.
	void handleInput();

	/**
	 * Function which loads enemy positions from a given file and saves it to our list with enemy positions.
	 * \note In the current state, the file has to exist and be accessible to the program, otherwise an exception is thrown.
	 *
	 * @param file_path Path to a file with enemy positions
	 */
	void loadEnemyPositions(const char* file_path);

	/**
	 * Loads one line of enemies from our list with enemy positions,
	 * creates new enemies,
	 * saves them to the corresponding "enemies" list.
	 */
	void loadLineOfEnemies();

	/**
	 * \brief Drops a random power-up based on hardcoded probability
	 *
	 * Whenever it's called, it generates a number and checks whether it's a zero.
	 * If it is a zero, it continues and generates another number with a number of power-up to be dropped.
	 *
	 * @param pos_x Position on X axis of the eventually dropped power-up
	 * @param pos_y Position on Y axis of the eventually dropped power-up
	 */
	void randomDropPowerUp(const int pos_x, const int pos_y);

	/// Loads the highest achieved score from a hardcoded file
	void loadHighestScore();
	/// Saves the current score as the new Highest Score to a hardcoded file
	void saveHighestScore();

	/// Iterates through all of our objects and maps their overlaps between each other to corresponding actions
	void checkDamage();

	/**
	 * \brrief Displays a message with current score and highest score.
	 *
	 * It's being used the last message of the game and can be opened
	 * with either a death of the player or press of the ESC key
	 *
	 * It automatically saves the current score if it's higher than the highest score.
	 *
	 * @param message Message to be displayed
	 */
	void endOfTheGameScreen(const char* message);
public:
	/**
	 * \brief Default constructor
	 *
	 * On creation,
	 *  creates an instance of EngineWrapper (engine),
	 *  calculates terminal size,
	 *  creates an instance of Player,
	 *  resets current score.
	 */
	Geus();

	/**
	 * \brief Default destructor
	 *
	 * Deletes and cleans out three lists of pointers + player
	 */
	~Geus();

	/**
	 * Begins the game and contains the main (only) game loop
	 */
	int play();
};

#endif //GEUS_GEUS_H
