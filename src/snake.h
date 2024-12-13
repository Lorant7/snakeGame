#ifndef SNAKE_H
#define SNAKE_H
// #include "curses.h"
#include "bodyPart.h"
#define GROWTH_RATE 1

class Snake
{
private:
    BodyPart *head;
    BodyPart *tail;
    int direction, length;

public:
    // Define the functions
    Snake(int length);
    BodyPart *getHead();
    BodyPart *getTail();
    void setSnakeDir(int dir);
    void draw();
    void move();
    void grow();

    void printSnake();

    ~Snake();
};

#endif