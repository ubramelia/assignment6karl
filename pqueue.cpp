// CSCI 2530
// Assignment: 6
// Author:     Amelia Hernandez
// File:       pqueue.cpp
// Tab stops:  4

// This program can support an application by
// providing / implementing priority queues
// which are collections of items which each have a
// priority.  It can create a variable q of the type
// PriorityQueue and use debugging functions.
// It also supports three other primary functions:
//
// 1. It lets you ask if a priority queue is empty,
// 2. It lets you insert an data (with a priority/
//  weight) into the priority queue,
// 3. It lets you remove an Pritem from the
//  priority queue, assuming that the data has
//  the smallest priority number in said queue

#include <cstdio>
#include <cstdlib>
#include "pqueue.h"
using namespace std;

typedef const char* ItemType;
typedef double PriorityType;

void insertCell(PQCell*& q, ItemType x, PriorityType p);

// An object of type PQCell is a cell in a linked list.
// It holds an data, a priority, and a pointer to the
// next cell in the list.

// The fields are as follows:
// 1. (PQCell *nextCell) A pointer to the next
// cell/node,
// 2. (PriorityType weightVar) The weight, or
// priority, of the cell,
// 3. (ItemType data) The data inside the cell.

// PQCell has a constructor that's also called
// PQCell and takes the parameters that were
// declared immediatley before it.
struct PQCell
{
    PriorityType priorityNum;
    ItemType data;
	PQCell* nextCell;

    PQCell(PQCell* q, ItemType x, PriorityType p)
    {
        priorityNum = p;
		data = x;
        nextCell = q;
    }
};

// The isEmpty() function is meant to test whether
// a variable, q, is empty or not. It returns
// either a "true" (if q is empty) or "false" (if
// q is not empty).
bool isEmpty(const PriorityQueue& q)
{
    if (q.firstCell == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// The insert() function inserts an data (x) with
// its priority (p) into a PriorityQueue object
// (q) by calling on the insertCell() function.
void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
    insertCell(q.firstCell, x, p);
}

// The insertCell() function inserts data x with
// priority p into linked list L (made of PQCells).
// It assumes that L is in nondescending order by
// priority, and it inserts the new data into the
// correct spot so that the list is still in
// nondescending order by priority.
void insertCell(PQCell*& q, ItemType x, PriorityType p)
{
    if (q == NULL || p < q->priorityNum)
    {
        q = new PQCell(q, x, p);
    }
    else
    {
        insertCell(q->nextCell, x, p);
    }
}

// The printPriorityQueue() function prints to
// the screen for debugging purposes.
void printPriorityQueue(const PriorityQueue& q, ItemPrinter printItem, PriorityPrinter printPriority)
{
	PQCell* firstCell = q.firstCell;
    while (firstCell != NULL)
    {
        printf("\n");
        printItem(firstCell->data);
        printf(" Priority: ");
        printPriority(firstCell->priorityNum);
        firstCell = firstCell->nextCell;
    }
}

// The remove() function removes the data from
// q that has the smallest priority.  If two or
// more items have the same priority, it removes
// one of them.
void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
    PQCell* newPointer = q.firstCell;
    if (isEmpty(q) == false)
    {
        x = newPointer->data;
        p = newPointer->priorityNum;
        q.firstCell = q.firstCell->nextCell;
        delete newPointer;
    }
    else
    {
        exit(1);
    }
}
