#include "custom_ncurses.h"
#include <fstream>
#include <cstring>
#include <zconf.h>
#include "geus.h"
#include "bullet.h"
#include "enemy.h"
#include "power_ups.h"

Geus::Geus() : engine(30) {
	player = new Player(20, 20);

	score = 0;
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
	loadHighestScore();

	is_running = true;
	int timer;

	while (is_running) {
		engine.loadScreenDimensions();

		if (timer % 41 == 0) {
			loadLineOfEnemies();
		}

		handleInput(player);

		checkDamage();

		engine.deleteInvisibleObjects(bullets, enemies, power_ups);
		engine.drawAllObjects(timer, score, player, bullets, enemies, power_ups);
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
			player->shoot(bullets);
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
	pos_file.close();
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
		enemies.push_back(new Enemy("#", enemy_positions.front() + 3, 0));
		enemy_positions.pop_front();
	}
}

void Geus::randomDropPowerUp(const int pos_x, const int pos_y) {
	int power_up_index;

	if (rand() % 5 == 0) {
		power_up_index = rand() % 4;

		if (power_up_index == 0) {
			power_ups.push_back(new CPowerUp(pos_x, pos_y));
		} else if (power_up_index == 1) {
			power_ups.push_back(new TriPowerUp(pos_x, pos_y));
		} else if (power_up_index == 2) {
			power_ups.push_back(new HBPowerUp(pos_x, pos_y));
		} else {
			power_ups.push_back(new FPowerUp(pos_x, pos_y));
		}
	}
}

void Geus::loadHighestScore() {
	std::fstream score_file("highest_score.txt", std::ios_base::in);

	if (!score_file.is_open()) {
		engine.endNcurses();
		throw "Couldn't load a file with the Highest Score";
	}

	score_file >> highest_score;
	score_file.close();
}
void Geus::saveHighestScore() {
	std::fstream score_file;

	score_file.open("highest_score.txt");
	score_file << highest_score;
	score_file.close();
}

void Geus::checkDamage() {
	for (auto enemy : enemies) {
		for (auto bullet : bullets) {
			if (bullet->overlapsWith(enemy)) {
				enemy->setVisibility(false);
				bullet->setVisibility(false);
				randomDropPowerUp(enemy->positionX(), enemy->positionY());
				score++;
			}
		}
		if (enemy->overlapsWith(player)) {
			player->setVisibility(false);
			endOfTheGameScreen();
		}

		if (enemy->positionY() >= engine.getScreenHeight()) {
			endOfTheGameScreen();
		};
	}

	for (auto power_up : power_ups) {
		if (power_up->overlapsWith(player)) {
			power_up->setVisibility(false);
			player->setPowerUp(power_up->getIndex());
		}
	}
}
void Geus::endOfTheGameScreen() {
	const char* message = "Game Over";

	if (score > highest_score) {
		highest_score = score;
		saveHighestScore();
	}

	clear();
	mvprintw((engine.getScreenHeight() / 2) - 1, (engine.getScreenWidth() - strlen(message)) / 2, message);
	mvprintw(engine.getScreenHeight() / 2, (engine.getScreenWidth() - 23) / 2, "Your highest score: %d", highest_score);
	mvprintw((engine.getScreenHeight() / 2) + 1, (engine.getScreenWidth() - 20) / 2, "Your last score: %d", score);
	refresh();

	getchar();
	is_running = false;
}