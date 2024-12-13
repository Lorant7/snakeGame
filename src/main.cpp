#include "snakegame.h"

int main()
{
    // Snake *s = new Snake(4);
    // s->printSnake();
    SnakeGame *game = new SnakeGame();

    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    keypad(stdscr, TRUE); // This enables the user to use the arrows
    curs_set(0);          // Hide the cursor

    int ch;
    bool addF = true;

    // Loop until crtl + c
    /*
    Problem with library:
    When I press the arrow keys I don't get the macros defined for KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT.
    Instead, I get the macros for:
        KEY_A2 0x1c2 (UP)
        KEY_B1 0x1c4 (LEFT)
        KEY_B3 0x1c6 (RIGHT)
        KEY_C2 0x1c8 (DOWN)
    */
    while (true)
    {
        ch = getch();
        switch (ch)
        {
        case 450:
            if (game->getSnake()->getHead()->getDir() != 2)
            {
                game->getSnake()->setSnakeDir(0);
            }

            break;
        case 454:
            if (game->getSnake()->getHead()->getDir() != 3)
            {
                game->getSnake()->setSnakeDir(1);
            }
            break;
        case 456:
            if (game->getSnake()->getHead()->getDir() != 0)
            {
                game->getSnake()->setSnakeDir(2);
            }
            break;
        case 452:
            if (game->getSnake()->getHead()->getDir() != 1)
            {
                game->getSnake()->setSnakeDir(3);
            }
            break;
        }

        if (addF)
        {
            addF = false;
            game->addFood();
        }

        game->drawFrame();
    }

    endwin();
    delete game;
    return 0;
}