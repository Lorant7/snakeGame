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
    this->head->drawPart();
    return;
}

void Snake::move()
{
    this->head->step();
}

void Snake::grow()
{
    for (int i = 0; i < GROWTH_RATE; i++)
    {
        BodyPart *newPart = new BodyPart(this->tail->getX(), this->tail->getY(), this->tail->getDir(), this->tail->getNext(), this->tail);
        newPart->getNext()->setPrev(newPart);
        this->tail->setNext(newPart);
    }
}

Snake::~Snake()
{
    delete this->head;
}