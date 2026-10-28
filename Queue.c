#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    struct Node *next;
    int data;
};

struct queue{
    struct Node *rear;
    struct Node *front;
};

struct Node *createNode(int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->next=NULL;
    newNode->data=value;

}
struct queue *createQueue(struct queue *q){
    q->rear=NULL;
    q->front=NULL;
}

bool isEmpty(struct queue *q ){
    if(q->rear==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int value){
    struct Node *newNode=createNode(value);
    if(newNode==NULL){
        return;
    }
    else if(isEmpty(q)){
        q->front=q->rear=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

void dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is empty\n");
    }
    else{
        struct Node *temp=q->front;
        q->front=q->front->next;
        free(temp);
    }
}

void display(struct queue *q){
    if(isEmpty(q)){                
        printf("queue is empty\n");
    }   
    else{
       struct Node *temp=q->front;
       while(temp->next!=NULL){
        printf("%d => ",temp->data);
        temp=temp->next;
       } 
    }                           
}

void peek(struct queue *q){
    if(isEmpty(q)){                
        printf("queue is empty\n");
    }   
    else{
        printf("\nThe peek element is %d",q->front->data);
    }
}                              



int main(){
    struct queue *q=createQueue(q);

    bool check=isEmpty(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    display(q);
    printf("\n");
    dequeue(q);
    dequeue(q);
    display(q);
    peek(q);

    return 0;
}