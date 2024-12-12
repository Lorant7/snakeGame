#ifndef SNAKE_H
#define SNAKE_H
// #include "curses.h"
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
    BodyPart *getHead();
    BodyPart *getTail();
    void setSnakeDir(int dir);
    void draw();
    void move();
    bool checkCollision(int **snake, int len);

    void printSnake();

    ~Snake();
};

#endif