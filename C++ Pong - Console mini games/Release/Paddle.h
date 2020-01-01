#pragma once

class Paddle {
public:
	int posX, posY;
public:
	Paddle() = default;
	Paddle(int positionX, int positionY) : posX(positionX), posY(positionY) {
		
	}
	~Paddle() {

	}
	void moveUp() {
		posY--;
	}
	void moveDown() {
		posY++;
	}
	void moveLeft() {
		posX--;
	}
	void moveRight() {
		posX++;
	}
};