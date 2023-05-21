#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Player
{
    char* firstName;
    char* secondName;
    int points;
};
struct Echipa{
    int numberOfPlayers;
    char* teamName;
    struct Player *gamers;
    struct Echipa *next;
};
typedef struct Echipa Node;
void addAtBeginning(Node **head, int v, char *name, struct Player *players);
void display(Node *head,FILE *afisare);
void Delete(Node **head, int position);
void DeleteName(Node **head,char *name);