#include "snakegame.h"

int main()
{
    SnakeGame *game = new SnakeGame();

    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    keypad(stdscr, TRUE); // This enables the user to use the arrows
    curs_set(0);          // Hide the cursor

    int ch;
    bool addF = true;

    /*
    Problem with library:
    When I press the arrow keys I don't get the macros defined for KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT.
    Instead, I get the macros for:
        KEY_A2 0x1c2 (UP)
        KEY_B1 0x1c4 (LEFT)
        KEY_B3 0x1c6 (RIGHT)
        KEY_C2 0x1c8 (DOWN)

    This issue came up only when running the the executable file in the powershell within visual studio.
    */
    while (true)
    {
        ch = getch();
        switch (ch)
        {
        case 259:
            if (game->getSnake()->getHead()->getDir() != 2)
            {
                game->getSnake()->setSnakeDir(0);
            }

            break;
        case 261:
            if (game->getSnake()->getHead()->getDir() != 3)
            {
                game->getSnake()->setSnakeDir(1);
            }
            break;
        case 258:
            if (game->getSnake()->getHead()->getDir() != 0)
            {
                game->getSnake()->setSnakeDir(2);
            }
            break;
        case 260:
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

        if (game->drawFrame())
        {
            nodelay(stdscr, FALSE);
            int keyInput = getch();
            while (keyInput != 121 && keyInput != 113)
            {
                keyInput = getch();
            }
            if (keyInput == 121)
            {
                nodelay(stdscr, FALSE);
                free(game);
                game = new SnakeGame();
                nodelay(stdscr, TRUE);
                addF = true;
            }
            else if (keyInput == 113)
            {
                exit(0);
            }
        }
    }

    endwin();
    delete game;
    return 0;
}