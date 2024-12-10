#include "snake.h"

Snake::Snake(int length)
{
    // Initialize snake's values and allocate memory for the body.
    this->length = length;
    this->direction = 0;
    // Allocate the 2D array for the snake's body
    this->body = new int *[length];
    for (int i = 0; i < length; i++)
    {
        body[i] = new int[3];
    }

    /*
    SNAKE FORMAT:
    Each element in snake is a body part.
    Each body part has the row, column, and direction: [r,c,d].
    The first array in snake is the head and the second is the tail ([Head, Tail, Body, Body, ..., Body]).
    Directions: up=0, right=1, down=2, left=3
    */

    // INITIALIZE SNAKE'S BODY

    // Head
    body[0][0] = 5;
    body[0][1] = 11;
    body[0][2] = 0;

    // Tail
    body[1][0] = 8;
    body[1][1] = 11;
    body[1][2] = 0;

    for (int r = 2; r < length; r++)
    {
        body[r][0] = 4 + r;
        body[r][1] = 11;
        body[r][2] = 0;
    }
}