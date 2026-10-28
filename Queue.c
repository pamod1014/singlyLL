#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

}