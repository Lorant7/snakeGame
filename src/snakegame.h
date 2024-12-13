#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "snake.h"
#include "food.h"
#include <cstdlib>
#include <ctime>

#define BOARD_LENGTH 18
#define BOARD_WIDTH 28
#define DELAYSIZE 200
#define MAX_FOOD_ON_BOARD 2

class SnakeGame
{
private:
    Snake *snake;
    Food *foodList;
    int foodSize;

public:
    SnakeGame();
    ~SnakeGame();
    Snake *getSnake();
    bool checkCollision();
    void drawBoard();
    void drawFrame();

    void addFood();
    void drawFoods();

    // TOOD: implement scoring system
    void updateScore();
    void recordScore();
};

#endif