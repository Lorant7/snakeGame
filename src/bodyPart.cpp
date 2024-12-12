#include "bodyPart.h"

BodyPart::BodyPart(int x, int y, int dir, BodyPart *next, BodyPart *prev)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->next = next; // The body part in front
    this->prev = prev; // The body part behind
}

BodyPart::~BodyPart()
{
    if (this->prev != nullptr)
    {
        delete this->prev;
    }
    delete this->next;
    delete this->prev;
}

void BodyPart::setNext(BodyPart *newNext)
{
    this->next = newNext;
}

void BodyPart::setPrev(BodyPart *newPrev)
{
    this->prev = newPrev;
}

void BodyPart::setCoords(int x, int y, int dir)
{
    this->x = x;
    this->y = y;
    this->dir = dir;
}

void BodyPart::setDir(int dir) { this->dir = dir; }

BodyPart *BodyPart::getNext() { return this->next; }
BodyPart *BodyPart::getPrev() { return this->prev; }
int BodyPart::getX() { return this->x; }
int BodyPart::getY() { return this->y; }
int BodyPart::getDir() { return this->dir; }

void BodyPart::printPart()
{
    if (this->prev != nullptr)
    {
        this->prev->printPart();
    }
    return;
}

// partType: the type of body part this part is (head: 0, body: 1, tail: 2)
void BodyPart::drawPart()
{
    short partType;
    if (this->next == nullptr)
    {
        partType = 0; // Head
    }
    else if (this->prev == nullptr)
    {
        partType = 2; // Tail
    }
    else
    {
        partType = 1; // Body
    }

    switch (partType)
    {
    case 0:
        if (this->dir == 0)
        {
            mvprintw(this->y, this->x, "^");
        }
        else if (this->dir == 1)
        {
            mvprintw(this->y, this->x, ">");
        }
        else if (this->dir == 2)
        {
            mvprintw(this->y, this->x, "v");
        }
        else
        {
            mvprintw(this->y, this->x, "<");
        }

        break;
    case 1:
        if (this->dir % 2 == 0)
        {
            mvprintw(this->y, this->x, "|");
        }
        else
        {
            mvprintw(this->y, this->x, "-");
        }
        break;
    case 2:
        mvprintw(this->y, this->x, "o");
        break;
    }

    if (this->prev != nullptr)
    {
        this->prev->drawPart();
    }

    return;
}

void BodyPart::step()
{
    if (this->prev != nullptr)
    { // So it updates the body parts starting from the tail
        this->prev->step();
    }

    if (this->next == nullptr)
    { // If this body part is the head
        short xDisplacement = 0, yDisplacement = 0;

        if (this->getDir() == 0)
        {
            yDisplacement = -1;
        }
        else if (this->getDir() == 1)
        {
            xDisplacement = 1;
        }
        else if (this->getDir() == 2)
        {
            yDisplacement = 1;
        }
        else
        {
            xDisplacement = -1;
        }

        this->x = this->x + xDisplacement;
        this->y = this->y + yDisplacement;
    }
    else
    { // Set the current body part properties equal to the next one's
        this->x = this->next->x;
        this->y = this->next->y;
        this->dir = this->next->dir;
    }
    return;
}