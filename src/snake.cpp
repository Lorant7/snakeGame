#include "snake.h"

Snake::Snake(int length)
{
    // Initialize snake's values and allocate memory for the body.
    this->length = length;
    this->direction = 0;
    this->head = new BodyPart(5, 11, 0);

    BodyPart *current = this->head;
    for (int i = 1; i < length; i++)
    {
        BodyPart *temp = new BodyPart(5 + i, 11, 0, this->head);
        current->setPrev(temp);
        temp = current;
    }

    this->tail = current;
}

void Snake::printSnake()
{
    this->head->printPart();
}

// void Snake::draw(int **snake, int len, int direction)
// {
//     erase();
//     drawBoard();
//     for (int r = 0; r < len; r++)
//     {
//         if (r == 0)
//         {
//             mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "^");
//         }
//         else if (r == 1)
//         {
//             mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "T");
//         }
//         else
//         {
//             mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "|");
//         }
//     }
//     refresh();
//     curs_set(0);
//     return;
// }

// void Snake::step(int **snake, int len, int direction)
// {
//     int row_diff = 0;
//     int col_diff = 0;

//     if (direction == 0)
//     {
//         row_diff = -1;
//     }
//     else if (direction == 1)
//     {
//         col_diff = 1;
//     }
//     else if (direction == 2)
//     {
//         row_diff = 1;
//     }
//     else
//     {
//         col_diff = -1;
//     }

//     for (int i = 0; i < len; i++)
//     {
//         snake[i][0] = snake[i][0] + row_diff;
//         snake[i][1] = snake[i][1] + col_diff;
//     }
//     draw(snake, len, direction);
// }

// // TODO: run this function in a separate thread
// bool Snake::checkCollision(int **snake, int len)
// {
//     int head[2] = {snake[0][0], snake[0][1]};

//     // Check collision with border
//     if (head[0] == 0 || head[0] == BOARD_WIDTH - 1)
//     {
//         return true;
//     }
//     else if (head[1] == 0 || head[1] == BOARD_LENGTH - 1)
//     {
//         return true;
//     }

//     // Check collision with body
//     for (int i = 1; i < len; i++)
//     {
//         if (head[0] == snake[i][0] && head[1] == snake[i][1])
//         {
//             return true;
//         }
//     }

//     return false;
// }

Snake::~Snake()
{
    delete this->head;
}