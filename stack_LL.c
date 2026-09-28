#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push(int x){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}

void display(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("empty list");
    }
    else{
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
}

void peek(){
    if(top==NULL){
        printf("list is empty");
    }
    else{
        printf("Top element is %d",top->data);
    }
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("underflow");
    }
    else{
        top=top->link;
        free(temp);
    }
}

void main(){
    push(10);
    printf("\n");
    display();
     printf("\n");
    push(20);
     printf("\n");
    display();
     printf("\n");
    push(30);
     printf("\n");
    display();
     printf("\n");
    push(40);
     printf("\n");
    display();
     printf("\n");
    pop();
     printf("\n");
    display();
     printf("\n");
    peek();
     printf("\n");
    display();
}