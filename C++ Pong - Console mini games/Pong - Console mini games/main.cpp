#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
#include <conio.h>
#include <ctime>
#include "Paddle.h"
#include "Ball.h"

constexpr int Width = 20;
constexpr int Height = 12;
constexpr int n = 15;

Paddle paddle(Width / 2, (Height / 2) + 5);
Ball ball(Width / 2, (Height / 2) + 4);

bool gameRunning = false;
bool ballStartMoving = false;
bool ifHitPaddle = false;
bool ifHitGround = false;

int score = 0;
int randomNumber = 0;
int enemyX[n];
int enemyY[n];

void LOADING() {

	std::string username;
	char password[32];
	for (int i = 0; i < 32; i++) {
		password[i] = ' ';
	}
	std::cout << "\n\n\n\n\n\t\t\t\t\tusername: ";
	std::cin >> username;
	std::cout << "\t\t\t\t\tpassword: ";
	char getPassword = ' ';
	int j = -1;
	while (true) {
		getPassword = _getch();
		for (int i = 32; i < 127; i++) {
			if (getPassword == (char)i) {
				std::cout << "*";
				j++;
				password[j] = (char)i;
			}
		}
		if (getPassword == '\b' && j != -1) {
			std::cout << "\b \b";
			j--;
		}
		if (getPassword == '\r') {
			if (username == "Admin" && password[0] == 'A' && password[1] == 'd' && password[2] == 'm' && password[3] == 'i' && password[4] == 'n') {
				for (int i = 1; i <= 50; i++) {
					system("cls");
					std::cout << "\n\n\n\n\n\n\t\t\t\t   Loading .....";
					std::cout << "\n\t " << 2 * i << "%\t";
					for (int j = 0; j <= i; j++) {
						std::cout << "²";
					}
					if (i < 10) {
						std::cout << "\n\t\tAccessing Files";
					}
					else if (i < 20) {
						std::cout << "\n\t\tReading Files";
					}
					else if (i < 30) {
						std::cout << "\n\t\tScanning for Malware";
					}
					else if (i < 40) {
						std::cout << "\n\t\tScanning for Virus";
					}
					else if (i < 50) {
						std::cout << "\n\t\tConnecting to Game";
					}
					if (i == 50) {
						std::cout << "\n\t\tSuccessfully Connected";
					}
					Sleep(200);
				}
			}
			else {
				if (username != "Admin") {
					std::cout << "\nIncorrect username\n";
				}
				else {
					std::cout << "\nIncorrect password\n";
				}
				j = 0;
				system("PAUSE");
				system("cls");
				LOADING();
			}
			std::cout << "\n\n";
			system("PAUSE");
			break;
		}

	}
}
int getRandomNumber() {
	int r = 0;
	srand(unsigned(time(NULL)));
	r = 1 + rand() % 3;
	return r;
}
void initEnemy() {
	srand(unsigned(time(NULL)));
	for (int i = 0; i < n; i++) {
		enemyX[i] = rand() % Width - 2;
		enemyY[i] = rand() % Height / 2;
		if (enemyX[i] >= Width || enemyX[i] <= 0) {
			i--;
			continue;
		}
		else if (enemyY[i] >= Height || enemyY[i] <= 0) {
			i--;
			continue;
		}
	}
	ball.movingUp = true;
	ball.movingLeft = true;
	ball.movingRight = true;
	randomNumber = getRandomNumber();
}
void ifBallHitEnemy() {
	while(true)
		for (int i = 0; i < n; i++) {
			if (ball.posX == enemyX[i] && ball.posY == enemyY[i]) {
				enemyX[i] = EOF;
				enemyY[i] = EOF;
				score++;
				if (ball.movingUp == true && ball.movingDown == false) {
					ball.movingUp = false;
					ball.movingDown = true;
					ball.movingLeft = true;
					ball.movingRight = true;
					randomNumber = getRandomNumber();
					break;
				}
				if (ball.movingUp == false && ball.movingDown == true) {
					ball.movingDown = false;
					ball.movingUp = true;
					ball.movingLeft = true;
					ball.movingRight = true;
					randomNumber = getRandomNumber();
					break;
				}
			}
		}
}
void drawMap() { // Draw paddle,map and enemy
	if (score == 15) {
		std::cout << "Congratulations you won!\n";
		system("PAUSE");
		gameRunning = true;
	}
	printf("Score: %d\n", score);
	for (int i = 0; i < Width; i++) {
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			if (j == 0) {
				printf("#");
			}
			else if (j == Width - 1) {
				printf("#");
			}
			else if (j == paddle.posX && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == ball.posX && i == ball.posY) {
				printf("O");
			}
			else if (j == paddle.posX + 1 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == paddle.posX + 2 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == paddle.posX + 3 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == paddle.posX - 1 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == paddle.posX - 2 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == paddle.posX - 3 && i == paddle.posY) {
				printf("\x1");
			}
			else if (j == enemyX[0] && i == enemyY[0]) {
				printf("*");
			}
			else if (j == enemyX[1] && i == enemyY[1]) {
				printf("*");
			}
			else if (j == enemyX[2] && i == enemyY[2]) {
				printf("*");
			}
			else if (j == enemyX[3] && i == enemyY[3]) {
				printf("*");
			}
			else if (j == enemyX[4] && i == enemyY[4]) {
				printf("*");
			}
			else if (j == enemyX[5] && i == enemyY[5]) {
				printf("*");
			}
			else if (j == enemyX[6] && i == enemyY[6]) {
				printf("*");
			}
			else if (j == enemyX[7] && i == enemyY[7]) {
				printf("*");
			}
			else if (j == enemyX[8] && i == enemyY[8]) {
				printf("*");
			}
			else if (j == enemyX[9] && i == enemyY[9]) {
				printf("*");
			}
			else if (j == enemyX[10] && i == enemyY[10]) {
				printf("*");
			}
			else if (j == enemyX[11] && i == enemyY[11]) {
				printf("*");
			}
			else if (j == enemyX[12] && i == enemyY[12]) {
				printf("*");
			}
			else if (j == enemyX[13] && i == enemyY[13]) {
				printf("*");
			}
			else if (j == enemyX[14] && i == enemyY[14]) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < Width; i++) {
		printf("#");
	}
}
void controlPaddle() {
	if (GetAsyncKeyState(VK_LEFT) && ifHitGround == false) {
		ballStartMoving = true;
		if (paddle.posX != 4 ) {
			paddle.moveLeft();
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) && ifHitGround == false) {
		ballStartMoving = true;
		if (paddle.posX != Width - 5) {
			paddle.moveRight();
		}
	}
}
void ballAutoMove() {	
	if (ballStartMoving == true) {	
		// going up
		if (ball.movingUp == true) {
			if (randomNumber == 1) {
				if (ball.posY != 0) {
					ball.moveUp();
				}
				else {
					ball.movingDown = true;
					ball.movingUp = false;
					randomNumber = getRandomNumber();
				}
			}
			if (randomNumber == 2) {
				if (ball.posY != 0) {
					ball.moveUp();
				}
				else {
					ball.movingDown = true;
					ball.movingUp = false;
					ball.movingLeft = true;
					randomNumber = getRandomNumber();
				}
				if (ball.posX != 1 && ball.movingLeft == true) {
					ball.moveLeft();
				}
				else {
					ball.movingLeft = false;
					ball.moveRight();
				}
			}
			if (randomNumber == 3) { 
				if (ball.posY != 0) {
					ball.moveUp();
				}
				else {
					ball.movingDown = true;
					ball.movingUp = false;
					ball.movingRight = true;
					randomNumber = getRandomNumber();
				}
				if (ball.posX != Width - 2 && ball.movingRight == true) {
					ball.moveRight();
				}
				else {
					ball.movingRight = false;
					ball.moveLeft();
				}
			}
		}
		// going down
		else if (ball.movingDown == true) {
			if (randomNumber == 1) {
				if (ball.posY != Height) {
					ball.moveDown();
				}
				else {
					ball.movingDown = false;
					ball.movingUp = true;
					randomNumber = getRandomNumber();
				}
			}
			if (randomNumber == 2) {
				if (ball.posY != Height) {
					ball.moveDown();
				}
				else {
					ball.movingDown = false;
					ball.movingUp = true;
					ball.movingLeft = true;
					randomNumber = getRandomNumber();
				}
				if (ball.posX != 1 && ball.movingLeft == true) {
					ball.moveLeft();
				}
				else {
					ball.movingLeft = false;
					ball.moveRight();
				}
			}
			if (randomNumber == 3) {
				if (ball.posY != Height) {
					ball.moveDown();
				}
				else {
					ball.movingDown = false;
					ball.movingUp = true;
					ball.movingRight = false;
					randomNumber = getRandomNumber();
				}
				if (ball.posX != Width - 2 && ball.movingRight == true) {
					ball.moveRight();
				}
				else {
					ball.movingRight = false;
					ball.moveLeft();
				}
			}
		}
	}
	if (ifHitPaddle == true) {
		ball.movingUp = true;
		ifHitPaddle = false;
	}
	if (ball.posY == Height) {
		ballStartMoving = false;
		ifHitGround = true;
		std::cout << "\nPress NUMPAD1 to play again";
		std::cout << "\nPress NUMPAD2 to exit\n";
		system("PAUSE");
		if (GetAsyncKeyState(VK_NUMPAD1)) {
			ball.posX = paddle.posX;
			ball.posY = paddle.posY - 1;
			ball.movingDown = false;
			ball.movingUp = false;
			ball.movingLeft = false;
			ball.movingRight = false;
			ifHitGround = false;
			score = 0;
			initEnemy();
		}
		if (GetAsyncKeyState(VK_NUMPAD2)) {
			gameRunning = true;
		}
		
	}
}
void ifBallHitPaddle() {
	if (ballStartMoving == true) {
		for (int i = 0; i <= 3; i++) {
			if (ball.posX == paddle.posX + i && ball.posY == paddle.posY - 1) {
				ifHitPaddle = true;
				ball.movingDown = false;
				ball.movingLeft = true;
				ball.movingRight = true;
				randomNumber = getRandomNumber();
				break;
			}
			else if (ball.posX == paddle.posX - i && ball.posY == paddle.posY - 1) {
				ifHitPaddle = true;
				ball.movingDown = false;
				ball.movingLeft = true;
				ball.movingRight = true;
				randomNumber = getRandomNumber();
				break;
			}
		}
	}
}

int main() {
	
	LOADING();
	std::thread t1(ifBallHitEnemy);
	initEnemy();
	t1.detach();
	while (!gameRunning) {
		system("cls");
		drawMap();
		Sleep(15);
		controlPaddle();
		ballAutoMove();
		ifBallHitPaddle();
	}

	system("PAUSE");
	return 0;
}