#pragma once
#include "Paddle.h"

class Ball : public Paddle {
public:
	bool movingUp;
	bool movingDown;
	bool movingLeft;
	bool movingRight;
public:
	Ball(int positionX, int positionY) : movingUp(false), movingDown(false), movingLeft(false), movingRight(false) {
		this->posX = positionX;
		this->posY = positionY;
	}
	~Ball() {

	}
};