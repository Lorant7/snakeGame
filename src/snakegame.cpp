// #include <curses.h>
#include <iostream>
#include <csignal>

#include "snake.h"

#define DELAYSIZE 200
#define BOARD_LENGTH 18
#define BOARD_WIDTH 28

void drawSnake(int **snake, int len, int direction = 0);
void moveSnake(int **snake, int len, int direction = 0);
void drawBoard();
bool checkCollision(int **snake, int len);

int main()
{
    Snake *s = new Snake(4);
    s->printSnake();
    delete s;

    // initscr();
    // nodelay(stdscr, TRUE);
    // noecho();
    // keypad(stdscr, TRUE); // This enables the user to use the arrows
    // curs_set(0);          // Hide the cursor

    // // Directions: up=0, right=1, down=2, left=3
    // int snake_dir = 0;
    // int num_numbody_parts = 4;

    // // Allocate the 2D array for the snake's body
    // int **snake = new int *[4];
    // for (int i = 0; i < 4; i++)
    // {
    //     snake[i] = new int[2];
    // }
    // // Initialize the snake's body
    // // Head
    // snake[0][0] = 5;
    // snake[0][1] = 11;

    // // Tail
    // snake[1][0] = 8;
    // snake[1][1] = 11;

    // for (int r = 2; r < num_numbody_parts; r++)
    // {
    //     // Each body part has the row, column, and direction
    //     // [r,c, d]
    //     // The first array in snake is the head and the second is the tail
    //     // [Head, Tail, Body, Body, ..., Body]
    //     snake[r][0] = 4 + r;
    //     snake[r][1] = 11;
    // }

    // drawSnake(snake, num_numbody_parts);
    // int ch;

    // // Loop until crtl + c
    // /*
    // Problem with library:
    // When I press the arrow keys I don't get the macros defined for KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT.
    // Instead, I get the macros for:
    //     KEY_A2 0x1c2 (UP)
    //     KEY_B1 0x1c4 (LEFT)
    //     KEY_B3 0x1c6 (RIGHT)
    //     KEY_C2 0x1c8 (DOWN)
    // */
    // while (true)
    // {
    //     ch = getch();
    //     std::cout << ch << std::endl;
    //     switch (ch)
    //     {
    //     case 450:
    //         snake_dir = (snake_dir == 2) ? 2 : 0;
    //         break;
    //     case 454:
    //         snake_dir = (snake_dir == 3) ? 3 : 1;
    //         break;
    //     case 456:
    //         snake_dir = (snake_dir == 0) ? 0 : 2;
    //         break;
    //     case 452:
    //         snake_dir = (snake_dir == 1) ? 1 : 3;
    //         break;
    //     }

    //     napms(DELAYSIZE);
    //     moveSnake(snake, num_numbody_parts, snake_dir);
    //     if (checkCollision(snake, num_numbody_parts))
    //     {
    //         std::cout << "Collided" << std::endl;
    //         // raise(SIGINT);
    //         // TODO: implement a "lossing window" for when the snake collides
    //     }
    // }

    // // Deallocate snake array
    // for (int i = 0; i < num_numbody_parts; i++)
    // {
    //     delete[] snake[i];
    // }
    // delete[] snake;

    // endwin();
    return 0;
}

// TODO: you don't need the direction here (I think...)
void drawSnake(int **snake, int len, int direction)
{
    erase();
    drawBoard();
    for (int r = 0; r < len; r++)
    {
        if (r == 0)
        {
            mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "^");
        }
        else if (r == 1)
        {
            mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "T");
        }
        else
        {
            mvprintw(*(*(snake + r)), *(*(snake + r) + 1), "|");
        }
    }
    refresh();
    curs_set(0);
    return;
}

// TODO: make the return type of this function a boolean
// return True if the snake is still alive after moving and False if it crashed
void moveSnake(int **snake, int len, int direction)
{
    int row_diff = 0;
    int col_diff = 0;

    if (direction == 0)
    {
        row_diff = -1;
    }
    else if (direction == 1)
    {
        col_diff = 1;
    }
    else if (direction == 2)
    {
        row_diff = 1;
    }
    else
    {
        col_diff = -1;
    }

    for (int i = 0; i < len; i++)
    {
        snake[i][0] = snake[i][0] + row_diff;
        snake[i][1] = snake[i][1] + col_diff;
    }
    drawSnake(snake, len, direction);
}

void drawBoard()
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

// TODO: run this function in a separate thread
bool checkCollision(int **snake, int len)
{
    int head[2] = {snake[0][0], snake[0][1]};

    // Check collision with border
    if (head[0] == 0 || head[0] == BOARD_WIDTH - 1)
    {
        return true;
    }
    else if (head[1] == 0 || head[1] == BOARD_LENGTH - 1)
    {
        return true;
    }

    // Check collision with body
    for (int i = 1; i < len; i++)
    {
        if (head[0] == snake[i][0] && head[1] == snake[i][1])
        {
            return true;
        }
    }

    return false;
}