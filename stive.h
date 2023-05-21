#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stakk{
char *numeEchipa;
struct stakk *next;
};
typedef struct stakk Sode;
void push(Sode**top, char *v);
char* pop(Sode**top);
int isEmpty(Sode*top);
void deleteStack(Sode**top);