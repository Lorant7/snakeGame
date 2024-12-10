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

BodyPart *BodyPart::getNext() { return this->next; }
BodyPart *BodyPart::getPrev() { return this->prev; }
int BodyPart::getX() { return this->x; }
int BodyPart::getY() { return this->y; }
int BodyPart::getDir() { return this->dir; }

void BodyPart::printPart()
{
    std::cout << this->x << " " << this->y << " " << this->dir << std::endl;
    this->prev->printPart();
}