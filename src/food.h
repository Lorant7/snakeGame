#ifndef FOOD_H
#define FOOD_H

#include "curses.h"

class Food
{
private:
    int x, y;

public:
    Food(int x, int y);
    ~Food();
    int getX();
    int getY();
    void drawFood();
};

#endif