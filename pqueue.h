// CSCI 2530
// Assignment: 6
// Author:     Amelia Hernandez
// File:       pqueue.h
// Tab stops:  4

#ifndef pqueue_h
#define pqueue_h
typedef const char* ItemType;
typedef double PriorityType;
typedef void (*ItemPrinter)(ItemType);
typedef void (*PriorityPrinter)(PriorityType);

struct PQCell;

// An object of type PriorityQueue is represented
// by a linked list that is in nondescending order
// by priority / weight.  It contains a field
// called firstCell that points to the first cell
// in the linked list.  It also contains a
// constructor by the same name that sets firstCell
// to NULL.
Struct PriorityQueue
{
    PQCell* firstCell;
    PriorityQueue()
    {
        firstCell = NULL;
    }
};

bool isEmpty(const PriorityQueue& q);
void insert(PriorityQueue& q, ItemType x, PriorityType p);
void printPriorityQueue(const PriorityQueue& q, ItemPrinter printItem, PriorityPrinter printPriority);
void remove(PriorityQueue& q, ItemType& item, PriorityType& p);

#endif
