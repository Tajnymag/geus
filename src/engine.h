#ifndef GEUS_ENGINE_H
#define GEUS_ENGINE_H

#include <list>
#include <memory>
#include "sprite.h"
#include "power_ups.h"

class EngineWrapper {
private:
	int m_screen_width;
	int m_screen_height;

	int m_refresh_rate;
public:
	EngineWrapper(const int refresh_target);
	~EngineWrapper();

	int getScreenWidth() const;
	int getScreenHeight() const;

	void drawAllObjects(const int timer, const int score, Sprite *player_ref, std::list<Sprite *> &bullets_ref, std::list<Sprite *> &enemies_ref, std::list<CPowerUp*>& power_ups_ref);
	void deleteInvisibleObjects(std::list<Sprite*>& bullets_ref, std::list<Sprite*>& enemies_ref, std::list<CPowerUp*>& power_ups_ref);
	void waitFPS();
	void endNcurses();
	void loadScreenDimensions();
};

#endif //GEUS_ENGINE_H
