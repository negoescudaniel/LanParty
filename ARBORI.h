#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nod{
char *tName;
float scr;
struct nod *left, *right;
};
typedef struct nod Aode;
Aode* insert(Aode* node, float scor1, char *nume);
Aode* newAode(float scor,char *s);
void inordine(Aode *rut,FILE *afisare);
void inordine111(Aode *rut);
BstToVect(Aode* rut,char **vect, int *p);

struct nood{
char *nume;
int cheie;
int height;
struct nood *left, *right;
};
typedef struct nood Mode;
int nodeHeight(Mode *root);
Mode* RightRotation(Mode *z);
Mode* insert2(Mode *node,int key,char *s);
int max(int a, int b);
