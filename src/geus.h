#ifndef GEUS_GEUS_H
#define GEUS_GEUS_H

#include "engine.h"
#include "player.h"
#include "power_ups.h"

class Geus {
private:
	EngineWrapper engine;

	Player* player = NULL;
	std::list<Sprite*> enemies;
	std::list<Sprite*> bullets;
	std::list<CPowerUp*> power_ups;

	std::list<int> enemy_positions;

	int highest_score;
	int score;
	bool is_running;

	void handleInput(Player* player);
	void loadEnemyPositions(const char* file_path);
	void loadLineOfEnemies();

	void randomDropPowerUp(const int pos_x, const int pos_y);

	void loadHighestScore();
	void saveHighestScore();

	void checkDamage();
	void endOfTheGameScreen();
public:
	Geus();
	~Geus();

	int play();
};

#endif //GEUS_GEUS_H
