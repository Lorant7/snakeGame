// #include <curses.h>
#include "snakegame.h"

SnakeGame::SnakeGame()
{
    this->snake = new Snake(4);
    this->foodList = (Food *)std::malloc(MAX_FOOD_ON_BOARD * sizeof(Food));
    this->foodSize = 0;
    this->score = 0;
    snake->draw();
    drawBoard();
}

SnakeGame::~SnakeGame()
{
    delete this->snake;
    free(foodList);
}

Snake *SnakeGame::getSnake() { return this->snake; }

void SnakeGame::drawBoard()
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

// TODO: the board look glitchy because it appears and disappears. Try to find a way to only erase the snake
void SnakeGame::drawFrame()
{
    napms(DELAYSIZE);
    snake->move();
    erase();
    drawBoard();
    drawFoods();
    if (checkCollision())
    {
        std::cout << "collided score: " << (this->score) << std::endl;
        mvprintw(15, 5, "press key to restart");
        nodelay(stdscr, FALSE);
        int temp = getch();
        std::cout << "key pressed: " << temp << std::endl;
        if (temp == 121)
        {
            nodelay(stdscr, TRUE);
            reset();
        }
        else
        {
            exit(0);
        }
    }
    if (checkEat())
    {
        updateScore();
        snake->grow();
    }
    snake->draw();
    refresh();
    curs_set(0);
}

// TODO: run this function in a separate thread
bool SnakeGame::checkCollision()
{
    int snakeX = this->snake->getHead()->getX();
    int snakeY = this->snake->getHead()->getY();

    // Check collision with border
    if (snakeX == 0 || snakeX == BOARD_WIDTH)
    {
        return true;
    }
    else if (snakeY == 0 || snakeY == BOARD_LENGTH)
    {
        return true;
    }

    // Check collision with body
    BodyPart *current = snake->getHead()->getPrev();
    while (current != nullptr)
    {
        if (snakeX == current->getX() && snakeY == current->getY())
        {
            std::cout << "collided body" << std::endl;
            return true;
        }
        current = current->getPrev();
    }

    return false;
}

// TODO: run this function is a separate thread
// TODO: with only two foods this is simple, but if it increased a linked list is better to add and remove foods to the game
bool SnakeGame::checkEat()
{
    int snakeX = this->snake->getHead()->getX();
    int snakeY = this->snake->getHead()->getY();

    for (int i = 0; i < foodSize; i++)
    {
        if (snakeX == (foodList + (i * sizeof(Food)))->getX() && snakeY == (foodList + (i * sizeof(Food)))->getY())
        {
            std::cout << "ate food" << std::endl;

            // This shifts the food in the food list to the left if the food removed is not the last one.
            if (i + 1 < foodSize)
            {
                for (int n = i + 1; n < foodSize; n++)
                {
                    *(foodList + ((n - 1) * sizeof(Food))) = *(foodList + (n * sizeof(Food)));
                }
            }
            foodSize--;
            addFood();
            return true;
        }
    }

    return false;
}

void SnakeGame::addFood()
{
    if (foodSize < MAX_FOOD_ON_BOARD)
    {
        srand(time(0));

        int randX = (rand() % (BOARD_WIDTH - 1)) + 1;
        int randY = (rand() % (BOARD_LENGTH - 1)) + 1;

        Food *f = new Food(randX, randY);
        *(foodList + foodSize * sizeof(Food)) = *f;
        foodSize++;
    }
    return;
}

void SnakeGame::drawFoods()
{
    for (int i = 0; i < foodSize; i++)
    {
        Food *f = foodList + i * sizeof(Food);
        f->drawFood();
    }
    return;
}

void SnakeGame::reset()
{
    // Free memory to later replace it with new memory
    delete this->snake;
    free(foodList);

    // Allocate new memory space
    this->snake = new Snake(4);
    this->foodList = (Food *)std::malloc(MAX_FOOD_ON_BOARD * sizeof(Food));
    foodSize = 0;
    score = 0;
}

void SnakeGame::updateScore()
{
    std::cout << "added score" << std::endl;
    this->score = this->score + POINTS_PER_PART;
}