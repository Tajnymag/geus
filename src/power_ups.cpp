#include "custom_ncurses.h"
#include "sprite.h"
#include "power_ups.h"
#include "colors.h"

CPowerUp::CPowerUp(const int pos_x, const int pos_y) : Sprite("C", pos_x, pos_y) {
	m_powerup_index = 0;
}
CPowerUp::~CPowerUp() {

}
int CPowerUp::getIndex() const {
	return m_powerup_index;
}
void CPowerUp::draw(const int timer) {
	if (m_visible) {
		setColor(CYAN);
		mvprintw(m_y, m_x, m_visual_string);
		resetColor(CYAN);
	}
}

TriPowerUp::TriPowerUp(const int pos_x, const int pos_y) : CPowerUp(pos_x, pos_y) {
	m_visual_string = "T";
	m_powerup_index = 1;
}
TriPowerUp::~TriPowerUp() {

}
void TriPowerUp::draw(const int timer) {
	if (m_visible) {
		setColor(YELLOW);
		mvprintw(m_y, m_x, m_visual_string);
		resetColor(YELLOW);
	}
}

HBPowerUp::HBPowerUp(const int pos_x, const int pos_y) : CPowerUp(pos_x, pos_y) {
	m_visual_string = "H";
	m_powerup_index = 2;
}
HBPowerUp::~HBPowerUp() {

}
void HBPowerUp::draw(const int timer) {
	if (m_visible) {
		setColor(GREEN);
		mvprintw(m_y, m_x, m_visual_string);
		resetColor(GREEN);
	}
}

FPowerUp::FPowerUp(const int pos_x, const int pos_y) : CPowerUp(pos_x, pos_y) {
	m_visual_string = "F";
	m_powerup_index = 3;
}
FPowerUp::~FPowerUp() {

}
void FPowerUp::draw(const int timer) {
	if (m_visible) {
		setColor(MAGENTA);
		mvprintw(m_y, m_x, m_visual_string);
		resetColor(MAGENTA);
	}
}