#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "snake.h"

#define BOARD_LENGTH 18
#define BOARD_WIDTH 28
#define DELAYSIZE 200

class SnakeGame
{
private:
    Snake *snake;

public:
    SnakeGame();
    ~SnakeGame();
    Snake *getSnake();
    bool checkCollision();
    void drawBoard();
    void drawFrame();

    // TOOD: implement scoring system
    void updateScore();
    void recordScore();
};

#endif