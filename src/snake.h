#ifndef SNAKE_H
#define SNAKE_H
#include "curses.h"
#include "bodyPart.h"

class Snake
{
private:
    BodyPart *head;
    BodyPart *tail;
    int direction, length;

public:
    // Define the functions
    Snake(int length);
    // TODO: I don't think you need to pass it those parameters
    // since they are part of the object
    void draw(int **snake, int len, int direction);
    void step(int **snake, int len, int direciton);
    bool checkCollision(int **snake, int len);

    void printSnake();

    ~Snake();
};

#endif