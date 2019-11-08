// CSCI 2530
// Assignment: 6
// Author:     Amelia Hernandez
// File:       pqueue.cpp
// Tab stops:  4

//This program can support an application by
//providing / implementing priority queues
//which are collections of items which each have a
//priority.  It can create a variable q of the type
//PriorityQueue and use debugging functions.
//It also supports three other primary functions:
//
//1. It lets you ask if a priority queue is empty,
//2. It lets you insert an item (with a priority/
//  weight) into the priority queue,
//3. It lets you remove an Pritem from the
//  priority queue, assuming that the item has
//  the smallest priority number in said queue

#include <cstdio>
#include <cstdlib>
#include "pqueue.h"
using namespace std;

// An object of type PQCell is a cell in a linked list.
// It holds an item, a priority, and a pointer to the
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
    PQCell* nextCell;
    PriorityType weightVar;
    ItemType data;

    PQCell(PQCell* q, ItemType x, PriorityType p)
    {
        item = x;
        priorityNum = p;
        nextCell = q;
    }
};

//The isEmpty() function is meant to test whether
//a variable, q, is empty or not. It returns
//either a "true" (if q is empty) or "false" (if
//q is not empty).
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

// The insert() function inserts an item (x) with
// its priority (p) into a PriorityQueue object
// (q) by calling on the insertCell() function.
void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
    insertCell(q.firstCell, x, p);
}

// The insertCell() function inserts item x with
// priority p into linked list L (made of PQCells).
// It assumes that L is in nondescending order by
// priority, and it inserts the new item into the
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

//printPriorityQueue() documentation
void printPriorityQueue(const PriorityQueue& q, ItemPrinter printItem, PriorityPrinter printPriority);
{
    //change to for loop
    PQCell* firstCell = q.firstCell;
    while (firstCell != NULL)
    {
        printf("\n");
        printItem(firstCell->item);
        printf("\t");
        printPriority(firstCell->priorityNum);
        firstCell = firstCell->nextCell;
    }
}

// remove()
void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
    PQCell* newPointer = q.firstCell;
    if (isEmpty(q) == false)
    {
        x = newPointer->item;
        p = newPointer->priorityNum;
        q.firstCell = q.firstCell->nextCell;
        delete newPointer;
    }
    else
    {
        exit(1);
    }
}
