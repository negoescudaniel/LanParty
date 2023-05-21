#include"cozi.h"
Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;
	q->front=q->rear=NULL;
	return q;
}

 void enQueue(Queue*q, char *name1, char *name2)
{
	Code* newNode=(Code*)malloc(sizeof(Code));
	newNode->t1=name1;
	newNode->t2=name2;
	newNode->next=NULL;
	if (q->rear==NULL) q->rear=newNode;
	else{
		(q->rear)->next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear;
}

Code* deQueue(Queue*q) {
	Code* aux;
	if (isEmpty(q))
        return INT_MIN;
	aux=q->front;
	q->front=(q->front)->next;
	return aux;
}

int isEmpty1(Queue*q){
	return (q->front==NULL);
}

void deleteQueue(Queue*q){
	Code* aux;
	while (!isEmpty(q)){
		aux=q->front;
		q->front=q->front->next;
		free(aux);
	}
	free(q);
}