#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct elem{
    char *t1, *t2;
    struct elem *next;
};
typedef struct elem Code;
struct Q{
Code *front ,*rear ;
};
typedef struct Q Queue ;
Queue* createQueue();
void enQueue(Queue*q, char *name1, char *name2);
Code* deQueue(Queue*q);
int isEmpty1(Queue*q);
void deleteQueue(Queue*q);