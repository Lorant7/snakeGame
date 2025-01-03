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

// When the function returns TRUE, it means that the player lost
bool SnakeGame::drawFrame()
{
    napms(DELAYSIZE);
    snake->move();
    erase();
    drawBoard();
    drawFoods();
    if (checkCollision())
    {
        std::cout << "collided score: " << (this->score) << std::endl;
        losingScreen();
        return TRUE;
    }
    if (checkEat())
    {
        updateScore();
        snake->grow();
    }
    snake->draw();
    refresh();
    curs_set(0);
    return FALSE;
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

void SnakeGame::updateScore()
{
    std::cout << "added score" << std::endl;
    this->score = this->score + POINTS_PER_PART;
    std::cout << "current score: " << this->score << std::endl;
}

void SnakeGame::losingScreen()
{
    // TODO: MAKE THIS PRETTY
    int scoreLineLength = 25;
    char *scoreLine = new char[scoreLineLength];
    char start[] = "#  Score: ";
    const char *charScore = std::to_string(this->score).c_str();
    int scoreLen = std::to_string(this->score).length();
    int scoreIndex = 0;
    for (int i = 0; i < scoreLineLength; i++)
    {
        if (i < 10)
        {
            scoreLine[i] = start[i];
        }
        else if (i < 24)
        {
            if (scoreIndex < scoreLen)
            {
                scoreLine[i] = *(charScore + scoreIndex);
            }
            else
            {
                char space[] = " ";
                scoreLine[i] = space[0];
            }
            scoreIndex++;
        }
        else
        {
            char last[] = "#";
            scoreLine[i] = last[0];
        }
    }

    mvprintw(BOARD_LENGTH / 2 - 2, 2, "#########################");
    mvprintw(BOARD_LENGTH / 2 - 1, 2, scoreLine);
    mvprintw(BOARD_LENGTH / 2, 2, "#  Y:NEW GAME / Q:QUIT  #");
    mvprintw(BOARD_LENGTH / 2 + 1, 2, "#########################");
}