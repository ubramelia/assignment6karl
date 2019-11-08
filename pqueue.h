// CSCI 2530
// Assignment: 6
// Author:     Amelia Hernandez
// File:       pqueue.h
// Tab stops:  4

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
struct PriorityQueue
{
    PQCell* firstCell;
    PriorityQueue()
    {
        firstCell = NULL;
    }
};

// This prototype is for the isEmpty() function in
// pqueue.cpp which is meant to test whether a 
// variable, q, is empty or not.
bool isEmpty(const PriorityQueue& q);

// This prototype is for the insert() function in
// pqueue.cpp which inserts an data (x) with its
// priority (p) into a PriorityQueue object (q) 
// by calling on the insertCell() function.
void insert(PriorityQueue& q, ItemType x, PriorityType p);

// This prototype is for the printPriorityQueue() 
// function in pqueue.cpp which prints to the
// the screen for debugging purposes.
void printPriorityQueue(const PriorityQueue& q, ItemPrinter printItem, PriorityPrinter printPriority);

// This prototype is for the remove() function in
// pqueue.cpp which removes the data from q that 
// has the smallest priority.
void remove(PriorityQueue& q, ItemType& item, PriorityType& p);
