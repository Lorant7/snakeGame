#include "snake.h"

Snake::Snake(int length)
{
    // Initialize snake's values and allocate memory for the body.
    this->length = length;
    this->direction = 0;
    this->head = new BodyPart(11, 5, 0);

    BodyPart *current = this->head;
    for (int i = 1; i < length; i++)
    {
        BodyPart *temp = new BodyPart(11, 5 + i, 0, current);
        current->setPrev(temp);
        current = temp;
    }

    this->tail = current;
}

BodyPart *Snake::getHead()
{
    return this->head;
}

BodyPart *Snake::getTail()
{
    return this->tail;
}

void Snake::setSnakeDir(int dir)
{
    this->head->setDir(dir);
    return;
}

void Snake::printSnake()
{
    this->head->printPart();
}

void Snake::draw()
{
    erase();
    // drawBoard();
    this->head->drawPart();
    refresh();
    curs_set(0);
    return;
}

void Snake::move()
{
    this->head->step();
}

Snake::~Snake()
{
    delete this->head;
}