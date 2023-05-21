#include"stive.h"
void push(Sode**top, char *v)
{
    Sode* newNode=(Sode*)malloc(sizeof(Sode));
    newNode->numeEchipa=v;
    newNode->next=*top;
    *top=newNode;
}

char* pop(Sode**top)
{
    if (isEmpty(*top)) return INT_MIN;
    Sode *temp=(*top);
    char *aux=temp->numeEchipa;
    *top=(*top)->next;
    free(temp);
    return aux;
}

int isEmpty(Sode*top)
{
    return top==NULL;
}

int numberOfElements(Sode *top){
    int l=0;
    while(top!=NULL)
    {
        l++;
        top=top->next;
    }
    return l;
}


void deleteStack(Sode**top)
{
    Sode  *temp;
    while (!isEmpty(*top))
        temp=*top;
    *top=(*top)->next;
    free(temp);
}