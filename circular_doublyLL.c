#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *temp=NULL;


void CreateNode(int value){  //create a linked list
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL)
    {
        head=temp=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}

void PrintList(){  //print the linkedlist
    if(head==NULL){
        printf("List is empty");
    }
    else{
    temp=head;
    printf("Linked List:");
    while(temp!=tail){
        printf("%d ",temp->data);
        temp=temp->next;
        }
    }
    printf("%d",temp->data);
    printf("\n");
}

int getlength(){  //get the length of the linked list
    int count=0;
    temp=head;
    while(temp->next!=head){
        count++;
        temp=temp->next;
    }
    count++;
    return count;
}

void InsertAtBeg(){  //insert to the beginning
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter the data u want insert at the beginning:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}

void InsertAtEnd(){ //insert at the end of the list
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter the data u want insert at the end:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
    head=tail=newnode;
    newnode->prev=tail;
    newnode->next=head;
    }
    else{
        newnode->prev=tail;
        newnode->next=head;
        tail->next=newnode;
        head->prev=newnode;
        tail=newnode;
    }
}

void InsertAtpos(){  //insert to the given position
    int pos,i=1;
    struct node*newnode;
    printf("enter the position u want to insert the data:");
    scanf("%d",&pos);
    if(pos>getlength()+1||pos<1){
    printf("Invalid position");
}
    else if(pos==1)
        {
            InsertAtBeg();
        }
    else if(pos==getlength()+1){
        InsertAtEnd();
    }
    else{
            newnode=malloc(sizeof(struct node));
            temp=head;
            printf("enter the value u want to insert at the pos:");
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            newnode->prev=NULL;
             if(head==NULL)
                {
                    head=tail=newnode;
                    newnode->prev=tail;
                    newnode->next=head;
                }
            else{
                    while(i<pos-1){
                        temp=temp->next;
                        i++;
                    }
                    newnode->prev=temp;
                    newnode->next=temp->next;
                    temp->next->prev=newnode;
                    temp->next=newnode;
                }
            }
}

void deleteatbeg(){ 
    temp=head;           //delete from beginning
    if(head==NULL)
 {
     printf("list is empty");
 }
 else if(head->next==head){
    head=tail=0;
    free(temp);
 }
 else{
    head=head->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
 }
}


void deleteatend(){  //delete at end of the linked list
    temp=head;
       if(head==NULL)
{
    printf("list is empty");
}
 else if(head->next==head){
    head=tail=0;
    free(temp);
 }
else{
    tail=tail->prev;
    head->prev=tail;
    tail->next=tail;
    free(temp);
}
}


void deleteatpos(){       //delete from given position
    int pos,i=1;
printf("enter the position u want to delete:");
scanf("%d",&pos);
if(pos>getlength()||pos<1){
    printf("invalid position");
}
else if(pos==1){
    deleteatbeg();
    
}
else if(pos==getlength()){
    deleteatend();
    
}
else{
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
}
}

void reverse()
{
    struct node *current, *nextnode;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    current=temp=head;

    do
    {
        nextnode= current->next;
        current->next = current->prev;
        current->prev =current;

        current=nextnode;

    } while (current != head);

    temp = head;
    head = tail;
    tail = temp;
}
    

int main(){
    int choice=1;
    int con=1;
    int choose;
    while(choice!=0)
    {
    int data;
    printf("enter the data:");
    scanf("%d",&data);
    CreateNode(data);
    printf("do you want to continue?(1/0):");
    scanf("%d",&choice);
    }
     while(con!=0)
 {
     printf("\n1.print the linked list");
     printf("\n2.insert the node at the beginning of the linked list");
     printf("\n3.insert the node at the end of the linked list");
     printf("\n4.insert the node at the given position of the linked list");
     printf("\n5.delete the node at the beginning of the linked list");
     printf("\n6.delete the node at the end of the linked list");
     printf("\n7.delete the node at the given position of the linked list");
     printf("\n8.reverse the linked list");
     printf("\n9.exit");
     printf("\nenter your choose:");
     scanf("%d",&choose);
 
 switch(choose)
 {
     case 1:
         PrintList();
         break;
     case 2:
         InsertAtBeg();
         PrintList();
         break;
     case 3:
         InsertAtEnd();
         PrintList();
         break;
     case 4:
         InsertAtpos();
         PrintList();
         break;
     case 5:
         deleteatbeg();
         PrintList();
         break;
     case 6:
         deleteatend();
         PrintList();
         break;
     case 7:
         deleteatpos();
         PrintList();
         break;
     case 8:
         reverse();
         PrintList();
         break;
     case 9:
         printf(" you are exit from the linked list");
         break;
     default:
         printf("invalid choose");
 } 
 printf("do you want to continue?(1/0):");
 scanf("%d",&con);
}  
 return 0;
}