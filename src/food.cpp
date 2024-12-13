#include "food.h"

Food::Food(int x, int y)
{
    this->x = x;
    this->y = y;
}

Food::~Food()
{
}

int Food::getX()
{
    return this->x;
}

int Food::getY()
{
    return this->y;
}

void Food::drawFood()
{
    mvprintw(this->y, this->x, "X");
}