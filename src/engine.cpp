#include "custom_ncurses.h"
#include <thread>
#include "sprite.h"
#include "engine.h"
#include "colors.h"

EngineWrapper::EngineWrapper(const int refresh_target) {
	m_refresh_rate = 1000 / refresh_target;

	initscr();
	clear();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	start_color();
	initPairs();
}
EngineWrapper::~EngineWrapper() {

}

int EngineWrapper::getScreenWidth() const {
	return m_screen_width;
}
int EngineWrapper::getScreenHeight() const {
	return m_screen_height;
}

void EngineWrapper::drawAll(const int timer, Sprite* player_ref, std::list<Sprite*>& bullets_ref, std::list<Sprite*>& enemies_ref) {
	clear();

	player_ref->handleWindowCollision(m_screen_width, m_screen_height);
	player_ref->draw(timer);

	for (auto bullet : bullets_ref) {
		bullet->handleWindowCollision(m_screen_width, m_screen_height);
		bullet->draw(timer);
	}

	for (auto enemy : enemies_ref) {
		enemy->handleWindowCollision(m_screen_width, m_screen_height);
		enemy->draw(timer);
	}

	//refresh();
}
void EngineWrapper::deleteInvisibleObjects(std::list<Sprite*>& bullets_ref, std::list<Sprite*>& enemies_ref) {
	for (auto bullet = bullets_ref.begin(); bullet != bullets_ref.end(); ++bullet) {
		if (!(*bullet)->getVisibility()) {
			delete *bullet;
			bullet = bullets_ref.erase(bullet);
		}
	}

	for (auto enemy = enemies_ref.begin(); enemy != enemies_ref.end(); ++enemy) {
		if (!(*enemy)->getVisibility()) {
			delete *enemy;
			enemy = enemies_ref.erase(enemy);
		}
	}
}
void EngineWrapper::waitFPS() {
	std::this_thread::sleep_for(std::chrono::milliseconds(m_refresh_rate));
}
void EngineWrapper::endNcurses() {
	endwin();
}
void EngineWrapper::loadScreenDimensions() {
	getmaxyx(stdscr, m_screen_height, m_screen_width);
}