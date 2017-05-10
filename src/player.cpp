#include "custom_ncurses.h"
#include <cmath>
#include "sprite.h"
#include "player.h"
#include "colors.h"

Player::Player(const int beg_x, const int beg_y) : Sprite("") {
	power_up = 0;

	m_x = beg_x;
	m_y = beg_y;
	m_drag = 0.2;
}
Player::~Player() {}

void Player::calculateNewPosition(const int timer) {
	const double EPSILON = 0.005;

	if (fabs(speedX) < EPSILON) {
		speedX = 0;
	} else if (speedX > 0) {
		m_x += round(speedX -= m_drag);
	} else {
		m_x += round(speedX += m_drag);
	}

	if (fabs(speedY) < EPSILON) {
		speedY = 0;
	} else if (speedY > 0) {
		m_y += round(speedY -= (m_drag * 2));
	} else {
		m_y += round(speedY += (m_drag * 2));
	}
}
void Player::draw(const int timer) {
	calculateNewPosition(timer);

	if (m_visible) {
		setColor(HRAC);
		mvprintw(m_y - 1, m_x, ".");
		mvprintw(m_y, m_x - 1, "/#\\");
		resetColor(HRAC);
	}
}
void Player::handleWindowCollision(const int screen_width, const int screen_height) {
	if (this->m_x + 1 >= screen_width) {
		this->m_x = screen_width - 2;
		this->speedX *= -1;
	} else if (this->m_x - 1 < 0) {
		this->m_x = 1;
		this->speedX *= -1;
	}

	if (this->m_y + 1 >= screen_height) {
		this->m_y = screen_height - 1;
		this->speedY *= -1;
	} else if (this->m_y - 1 < 0) {
		this->m_y = 1;
		this->speedY *= 1;
	}
}