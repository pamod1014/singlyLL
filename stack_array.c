#include<stdio.h>
#define N 5
int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if(top==N-1){
        printf("overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void pop(){
    int item;
    if(top==-1){
        printf("underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("%d",item);
    }
}

void peek(){
    if(top==-1){
        printf("underflow");
    }
    else{
        printf("peek element is %d",stack[top]);
    }
}

void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d  ",stack[i]);
    }
}

void main(){
    push();
    printf("\n");
    display();
     printf("\n");
    push();
     printf("\n");
    display();
     printf("\n");
    push();
     printf("\n");
    display();
     printf("\n");
    push();
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