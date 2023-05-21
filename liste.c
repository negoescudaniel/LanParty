#include"liste.h"
void addAtBeginning(Node **head, int v, char *name, struct Player *players)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->numberOfPlayers = v;
    newNode->teamName=name;
    newNode->gamers=players;
    newNode->next = *head;
    *head = newNode;
}

void display(Node *head,FILE *afisare)
{
    while (head!=NULL)
    {
        fprintf (afisare,"%s\n",head->teamName);
        head=head->next;
    }
}

void Delete(Node **head, int position){
    Node *headcopy=*head;
    if(position==0){
        *head=(*head)->next;
        free(headcopy->gamers);
        return;
    }
    for(int i=0;i<position-1;i++){
        headcopy=headcopy->next;
    }
    Node *delt=headcopy->next;
    headcopy->next=headcopy->next->next;
    free(delt);
}

void DeleteName(Node **head,char *name){
Node *headcopy=*head;
if(strcmp(headcopy->teamName,name)==0){
    *head=(*head)->next;
    free(headcopy);
    return;
}
Node *prev=*head;
while(headcopy!=NULL){
    if(strcmp(headcopy->teamName,name)!=0){
        prev=headcopy;
        headcopy=headcopy->next;
    }else{
        prev->next=headcopy->next;
        free(headcopy);
        return;
    }
}
}