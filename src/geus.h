#ifndef GEUS_GEUS_H
#define GEUS_GEUS_H

#include "engine.h"
#include "player.h"

class Geus {
private:
	EngineWrapper engine;

	Player* player = NULL;
	std::list<Sprite*> enemies;
	std::list<Sprite*> bullets;

	std::list<int> enemy_positions;

	bool is_running;

	void handleInput(Player* player);
	void loadEnemyPositions(const char* file_path);
	void loadLineOfEnemies();

	void checkDamage();
public:
	Geus();
	~Geus();

	int play();
};

#endif //GEUS_GEUS_H
