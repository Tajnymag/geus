#include "custom_ncurses.h"
#include "sprite.h"

Sprite::Sprite(const char* visual_string, const int beg_x, const int beg_y) : m_visual_string(visual_string){
	m_visible = true;

	m_update_freq = 0;
	m_x = beg_x;
	m_y = beg_y;
}
Sprite::~Sprite() {}

void Sprite::calculateNewPosition(const int timer) {

}
bool Sprite::getVisibility() const {
	return m_visible;
}
void Sprite::setVisibility(const bool new_visibility) {
	m_visible = new_visibility;
}
int Sprite::positionX() const {
	return m_x;
}
int Sprite::positionY() const {
	return m_y;
}

bool Sprite::overlapsWith(Sprite* other_sprite) const {
	return m_x == other_sprite->positionX() && m_y == other_sprite->positionY();
}

void Sprite::draw(const int timer) {
	calculateNewPosition(timer);

	if (m_visible) {
		mvprintw(m_y, m_x, m_visual_string);
	}
}
void Sprite::handleWindowCollision(const int screen_width, const int screen_height) {
	if (this->m_x >= screen_width) {
		m_visible = false;
	} else if (this->m_x < 0) {
		m_visible = false;
	}

	if (this->m_y >= screen_height) {
		m_visible = false;
	} else if (this->m_y < 0) {
		m_visible = false;
	}
}
