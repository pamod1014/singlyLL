//SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
  struct Node
 {
     int data;
     struct Node*next;

 };
 
 struct LinkedList{
 struct Node*head;
 struct Node*tail;
 struct Node*temp;
 };
void CreateNode(struct LinkedList *list, int value){

    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    if(list->head==NULL)
    {
        list->head=list->temp=newNode;
    }
    else
    {
        list->temp->next=newNode;
        list->temp=newNode;
    }

}
// print the linked list
void PrintList(struct LinkedList *list)
{
    list->temp=list->head;
    printf("Linked List:");
    while(list->temp!=NULL)
    {
        printf("%d ",list->temp->data);
        list->temp=list->temp->next;
    }
    printf("\n");
}

int getlength(struct LinkedList *list)
{
    int count=0;
    list->temp=list->head;
    while(list->temp!=NULL)
    {
        count++;
        list->temp=list->temp->next;
    }
    return count;
}
//insert the node at the beginning of the linked list
void InsertAtBeg(struct LinkedList *list)
{
    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at beginning:");
    scanf("%d",&newNode->data);
    newNode->next=list->head;
    list->head=newNode;
}

// insert the node at the end of the linked list
void InsertAtEnd(struct LinkedList *list)
{
    struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at end:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    list->temp=list->head;
    while(list->temp->next!=NULL)
    {
        list->temp=list->temp->next;
    }
    list->temp->next=newNode;
}

//insert the node at the given position of the linked list
void InsertAtPos(struct LinkedList *list)
{
    int pos,i=1;
    printf("enter the position do u want to insert a value:");
    scanf("%d",&pos);
    if(pos>getlength(list)||pos<1)
    {
        printf("invalid position");
    }
    else if(pos==1)
    {
        InsertAtBeg(list);
    }
    else if(pos==getlength(list)+1)
    {
        InsertAtEnd(list);
    }
    else
    {
        struct Node*newNode;
    newNode=malloc(sizeof(struct Node));
    printf("Enter the data u want to insert at the position:");
    scanf("%d",&newNode->data);
        list->temp=list->head;
        while(i<pos-1)
        {
            list->temp=list->temp->next;
            i++;
        }
        newNode->next=list->temp->next;
        list->temp->next=newNode;
    }
}



// delete the node at the end of the linked list
void DeleteAtBeg(struct LinkedList *list)
{
    if(list->head==NULL)
    {
        printf("No data");
    }
    else
    {
    list->temp=list->head;
    list->head=list->temp->next;
    free(list->temp);
    }
}



// delete the node at the end of the linked list
void DeleteAtEnd(struct LinkedList *list)
{
    struct Node*prevNode;
    list->temp=list->head;
    while(list->temp->next!=NULL)
    {
        prevNode=list->temp;
        list->temp=list->temp->next;
    }
    if(list->temp==list->head)
    {
        list->head=0;
        free(list->temp);
    }
    else
    {
        prevNode->next=NULL;
        free(list->temp);
    }
}

//delete the node at the given position of the linked list
void DeleteAtPos(struct LinkedList *list)
{
    int pos,i=1;
    struct Node*nextNode;
    list->temp=list->head;
    printf("enter position u want to delete:");
    scanf("%d",&pos);
     if(pos>getlength(list)||pos<1)
    {
        printf("invalid position");
    }
    else if(pos==1)
    {
        DeleteAtBeg(list);
    }
    else if(pos==getlength(list))
    {
        DeleteAtEnd(list);
    }
    else{
     while(i<pos-1)
     {
        list->temp=list->temp->next;
        i++;
     }
    }
    nextNode=list->temp->next;
    list->temp->next=nextNode->next;
    free(nextNode);
}
void Reversed(struct LinkedList *list)
{
    struct Node*prevNode,*nextNode,*currentNode;
    prevNode=0;
    currentNode=nextNode=list->head;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    list->head=prevNode;
}

void update(struct LinkedList *list){
    int pos,i=1;
    int newvalue;
    list->temp=list->head;
    printf("enter the position you want to update:");
    scanf("%d",&pos);
    if(pos>getlength(list) || pos<1)
    {
        printf("invalid position");
    }
    printf("enter the value u want to enter:");
    scanf("%d",&newvalue);

    for(i = 1; i < pos; i++ ) {

        list -> temp = list -> temp -> next;
    }

    list->temp->data=newvalue;
}


//main function
int main(){
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.temp = NULL;
    int choice=1;
    int choose;
    int con=1;
    while(choice!=0)
    {
    int data;
    int count=0;
    printf("enter the data:");
    scanf("%d",&data);
    CreateNode(&list, data);
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
        printf("\n9.update the value");
        printf("\n10.exit");
        printf("\nenter your choose:");
        scanf("%d",&choose);
    
    switch(choose)
    {
        case 1:
            PrintList(&list);
            break;
        case 2:
            InsertAtBeg(&list);
            PrintList(&list);
            break;
        case 3:
            InsertAtEnd(&list);
            PrintList(&list);
            break;
        case 4:
            InsertAtPos(&list);
            PrintList(&list);
            break;
        case 5:
            DeleteAtBeg(&list);
            PrintList(&list);
            break;
        case 6:
            DeleteAtEnd(&list);
            PrintList(&list);
            break;
        case 7:
            DeleteAtPos(&list);
            PrintList(&list);
            break;
        case 8:
            Reversed(&list);
            PrintList(&list);
            break;
        case 9:
            update(&list);
            PrintList(&list);
            break;
        case 10:
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
