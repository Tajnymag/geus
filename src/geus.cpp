#include "custom_ncurses.h"
#include <fstream>
#include "geus.h"
#include "bullet.h"
#include "enemy.h"

Geus::Geus() : engine(30) {
	player = new Player(20, 20);
}

Geus::~Geus() {
	delete player;

	while (!enemies.empty()) {
		delete enemies.front();
		enemies.pop_front();
	}

	while (!bullets.empty()) {
		delete bullets.front();
		bullets.pop_front();
	}
}

int Geus::play() {
	loadEnemyPositions("positions.txt");

	is_running = true;
	int timer;

	while (is_running) {
		engine.loadScreenDimensions();

		if (timer % 20 == 0) {
			loadLineOfEnemies();
		}

		handleInput(player);

		checkDamage();

		engine.deleteInvisibleObjects(bullets, enemies);
		engine.drawAll(timer, player, bullets, enemies);
		engine.waitFPS();

		timer = ++timer % INT_MAX;
	}

	engine.endNcurses();

	return 0;
}

void Geus::handleInput(Player *player) {
	int key = getch();

	switch (key) {
		case 'w':
		case KEY_UP:
			player->speedY -= 1;
			break;
		case 's':

		case KEY_DOWN:
			player->speedY += 1;
			break;

		case 'a':
		case KEY_LEFT:
			player->speedX -= 1;
			break;

		case 'd':
		case KEY_RIGHT:
			player->speedX += 1;
			break;

		case 32:
			bullets.push_back(new Bullet("|", player->positionX(), player->positionY() - 1));
			break;

		case 27:
			is_running = false;
			break;
		default:
			break;
	}
}

void Geus::loadEnemyPositions(const char *file_path) {

	std::fstream pos_file(file_path, std::ios_base::in);

	if (!pos_file.is_open()) {
		engine.endNcurses();
		throw "Couldn't load a file with enemies!";
	}

	int pos_x = 0;
	char character;

	while (pos_file >> std::noskipws >> character) {
		if (character == '\n') {
			pos_x = 0;
			enemy_positions.push_back(-1);
		} else if (character == ' ') {
			pos_x++;
			continue;
		} else if (character == '\t') {
			pos_x += 4;
			continue;
		} else {
			enemy_positions.push_back(pos_x++);
		}
	}
}
void Geus::loadLineOfEnemies() {
	if (enemy_positions.front() == -1) {
		enemy_positions.pop_front();
	}

	while (!enemy_positions.empty()) {
		if (enemy_positions.front() == -1) {
			enemy_positions.pop_front();
			break;
		}
		enemies.push_back(new Enemy("@", enemy_positions.front() + 3, 0));
		enemy_positions.pop_front();
	}
}
void Geus::checkDamage() {
	for (auto enemy : enemies) {
		for (auto bullet : bullets) {
			if (enemy->overlapsWith(bullet)) {
				enemy->setVisibility(false);
			}
		}
		if (enemy->overlapsWith(player)) {
			player->setVisibility(false);
		}
	}
}