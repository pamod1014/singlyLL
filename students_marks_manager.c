//ARRAYS
#include <stdio.h>

void traverse(int marks[], int *size)//print the marks array case1
{
    int i;
    for (i = 0; i < *size; i++)
    {
        printf("%d index marks is %d\n", i, marks[i]);
    }
}

void searchByValue(int marks[], int *size, int value)// search the marks array by value 
{
    int found=0;
    for (int i = 0; i < *size; i++)
    {
        if (marks[i] == value)
        {
            printf("value is found at the %d index\n", i);
            found=1;
            
        }
    }
    if(found==0)
    {
        printf("value is not found\n");
    }
}


void updateByValue(int marks[], int *size, int index, int newValue)//update the marks array by index case3
{
    int found=0;
    for (int i = 0; i < *size; i++)
    {
        if (i == index)
        {
            marks[i] = newValue;
            printf("value is updated at the %d index\n", i);
            found=1;
        }
    }
    if(found==0)
    {
        printf("value is not found\n");
    }
}


void insertAt(int marks[], int *size, int capacity, int position, int value)//insert the marks array by position case4
{
    if (*size == capacity || position > (*size)+1 || position <= 0)
    {
        printf("cannot insert!");
    }
    else if (position == (*size)+1)
    {
        marks[position] = value;
        printf("\nvalue is added at the %d position", position);
        (*size)++;
    }
    else
    {
        for (int i = *size; i >= position; i--)
        {
            marks[i] = marks[i - 1];
        }
        marks[position-1] = value;
        printf("\nvalue is added at the %d position", position);
        (*size)++;
    }
}


void deleteAt(int marks[],int*size,int position)  //delete the marks array by position case5
{
    if(*size==0||position>*size||position<=0)
    {
        printf("cannot delete!");
    }
    else if(position==*size)
    {
        printf("\n value is deleted the %d position",position);
        (*size)--;
    }
    else
    {
        for(int i=position-1;i<*size;i++)
        {
            marks[i]=marks[i+1];
        }
        printf("\n value is deleted the %d position",position);
        (*size)--;
    }
}



int main()
{
    int i;
    int position;
    int value;
    int marks[100];
    int size;
    int capacity = 100;
    int choose;
    int choice;

    printf("enter the size of the array:");
    scanf("%d", &size);
    if (size > capacity || size < 0)
    {
        printf("invalid size");
    }
    else
    {
        printf("enter the marks of the students:");
        for (i = 0; i < size; i++)
        {
            scanf("%d", &marks[i]);
            if (marks[i] < 0 || marks[i] > 100)
            {
                printf("invalid marks");
                break;
            }
        }
        
    }//choose list eka print krnn oone
    while(choice!=0)
    {
        printf("\n1.traverse the array");
        printf("\n2.search the array by value");
        printf("\n3.update the array by index");
        printf("\n4.insert the array by position");
        printf("\n5.delete the array by position");
        printf("\n6.exit");
    printf("\nenter the choose:");
    scanf("%d", &choose);
    switch (choose)
    {
        case 1:
            traverse(marks, &size);
            break;
            
        case 2:
            printf("enter the value u want to search:");
            scanf("%d", &value);
            searchByValue(marks, &size, value);
            traverse(marks, &size);
            break;

        case 3:
            printf("enter the index u want to update:");
            scanf("%d", &position);
            printf("enter the new value u want to insert:");
            scanf("%d", &value);
            updateByValue(marks, &size, position, value);
            traverse(marks, &size);
            break;

        case 4:
            printf("enter the position u want to insert:");
            scanf("%d", &position);
            printf("enter the value u want to insert:");
            scanf("%d", &value);
            insertAt(marks, &size, capacity, position, value);
            traverse(marks, &size);
            break;

        case 5:
            printf("enter the position u want to delete:");
            scanf("%d", &position);
            deleteAt(marks, &size, position);
            traverse(marks, &size);
            break;

        case 6:
            printf("you are exit from the program");

        default:
            printf("your choose is invalid");
            break;
    }
    printf("\nif u want to continue press 1 or else press 0:");
    scanf("%d",&choice);
    }
    return 0;

