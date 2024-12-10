#ifndef BODY_PART
#define BODY_PART
#include <iostream>
// This will be like the nodes in a linked list
class BodyPart
{
private:
    BodyPart *next;
    BodyPart *prev;
    int x, y, dir;

public:
    BodyPart(int x, int y, int dir, BodyPart *next = nullptr, BodyPart *prev = nullptr);
    ~BodyPart();
    void setNext(BodyPart *newNext);
    void setPrev(BodyPart *newPrev);
    void setCoords(int x, int y, int dir);
    BodyPart *getNext();
    BodyPart *getPrev();
    int getX();
    int getY();
    int getDir();

    void printPart();
};

#endif