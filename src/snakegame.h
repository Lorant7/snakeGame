#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "snake.h"
#include "food.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define BOARD_LENGTH 18
#define BOARD_WIDTH 28
#define DELAYSIZE 200
#define MAX_FOOD_ON_BOARD 2
#define POINTS_PER_PART 100

class SnakeGame
{
private:
    Snake *snake;
    Food *foodList;
    int foodSize;
    int score;

public:
    SnakeGame();
    ~SnakeGame();
    Snake *getSnake();
    bool checkCollision();
    bool checkEat();
    void drawBoard();
    void drawFrame();

    void addFood();
    void drawFoods();
    void updateScore();

    // TODO: implement losing screen
    void losingScreen();
    void reset();

    // TODO: implement storing high scores
    void recordScore();
};

#endif