// #include <curses.h>
#include "snakegame.h"

SnakeGame::SnakeGame()
{
    this->snake = new Snake(4);
    snake->draw();
    drawBoard();
}

SnakeGame::~SnakeGame()
{
    delete this->snake;
}

Snake *SnakeGame::getSnake() { return this->snake; }

void SnakeGame::drawBoard()
{
    for (int r = 1; r < BOARD_LENGTH - 1; r++)
    {
        mvprintw(r, 0, "H");
        mvprintw(r, BOARD_WIDTH, "H");
    }

    for (int c = 0; c < BOARD_WIDTH; c++)
    {
        mvprintw(0, c, "=");
        mvprintw(BOARD_LENGTH, c, "=");
    }
}

// TODO: the board look glitchy because it appears and disappears. Try to find a way to only erase the snake
void SnakeGame::drawFrame()
{
    napms(DELAYSIZE);
    snake->move();
    snake->draw();
    drawBoard();
    if (checkCollision())
    {
        std::cout << "collided" << std::endl;
    }
}

// TODO: run this function in a separate thread
bool SnakeGame::checkCollision()
{
    int snakeX = this->snake->getHead()->getX();
    int snakeY = this->snake->getHead()->getY();

    // Check collision with border
    if (snakeX == 0 || snakeX == BOARD_WIDTH - 1)
    {
        return true;
    }
    else if (snakeY == 0 || snakeY == BOARD_LENGTH - 1)
    {
        return true;
    }

    // Check collision with body
    BodyPart *current = snake->getHead()->getPrev();
    while (current != nullptr)
    {
        if (snakeX == current->getX() && snakeY == current->getY())
        {
            return true;
        }
        current = current->getPrev();
    }

    return false;
}