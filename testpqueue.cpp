#include <cstdio>
#include "pqueue.h"
using namespace std;

typedef const char *CSTRING;
const int maxItemLength = 20;

void showopn(CSTRING opn, CSTRING x, double pri, int num)
{
    char show[maxItemLength];

    if (snprintf(show, maxItemLength, "\"%s\"", x) < maxItemLength)
    {
        sprintf(show, "\"%s\"", x);
        printf("%s(queue %d): %-20s: %10.2lf\n", opn, num, show, pri);
    }
    else
    {
        printf("%s(queue %d): item %-40s priority %10.2lf\n", opn, num, x, pri);
    }
}

void doinsert(PriorityQueue &q, CSTRING x, double pri, int num)
{
    showopn("Insert", x, pri, num);
    insert(q, x, pri);
}

void doremove(PriorityQueue &q, CSTRING &x, double &pri, int num)
{
    x = NULL;
    pri = 0.0;
    remove(q, x, pri);
    showopn("Remove", x, pri, num);
}

void mypi(CSTRING s)
{
    printf("%s", s);
}

void mypp(double x)
{
    printf("%0.2lf", x);
}

void test(PriorityQueue &s, PriorityQueue &t)
{
    CSTRING item = NULL;
    double pri = 0.0;

    printf("----------------------------------------------\n");
    printf("\nBeginning a round of insertions and removals\n");
    printf("\nInitially, queue 1 holds\n");
    printPriorityQueue(s, mypi, mypp);
    printf("\nInitially, queue 2 holds\n");
    printPriorityQueue(t, mypi, mypp);
    printf("\n");

    CSTRING first = "first";
    CSTRING second = "second";
    CSTRING third = "third";
    CSTRING fourth = "fourth";
    CSTRING fifth = "fifth";
    CSTRING sixth = "sixth";
    CSTRING grape = "grape";
    CSTRING peach = "peach";
    CSTRING orange = "orange";
    CSTRING pear = "pear";

    printf("Begin insertions\n\n");
    doinsert(s, second, 10, 1);
    doinsert(s, fourth, 20, 1);
    doinsert(s, first, 5, 1);
    doinsert(s, third, 15, 1);
    doinsert(s, sixth, 30, 1);
    doinsert(s, fifth, 25, 1);
    doinsert(t, grape, 2, 2);
    doinsert(t, peach, 3, 2);
    doinsert(t, orange, 4, 2);
    doinsert(t, pear, 1, 2);

    printf("\nAfter insertions, queue 1 holds\n");
    printPriorityQueue(s, mypi, mypp);
    printf("\nAfter insertions, queue 2 holds\n");
    printPriorityQueue(t, mypi, mypp);
    printf("\n");

    printf("Begin removals\n\n");
    for (int i = 0; i < 6; i++)
    {
        if (isEmpty(s))
        {
            printf("Nonempty queue 1 is reported to be empty!\n");
        }
        doremove(s, item, pri, 1);
    }
    if (!isEmpty(s))
    {
        printf("Final queue 1 is not empty!\n");
    }
    printf("\n");
}

int main()
{
    int x = 100;

    {
        PriorityQueue s, t;

        if (x == 100)
        {
            if (!isEmpty(s))
            {
                printf("Initial queue 1 is not empty!\n");
            }
            if (!isEmpty(t))
            {
                printf("Initial queue 2 is not empty!\n");
            }
        }

        test(s, t);
        test(s, t);
    }

    return 0;
}