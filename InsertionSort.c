#include<stdio.h>

void InsertionSortA(int arr[],int size)    //insertion sort in Ascending order
{
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}

void InsertionSortD(int arr[],int size)    //insertion sort in Descending order
{
    for(int i=0;i<size-1;i++){
        int max=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
}
void print(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {                                             
    int n, i, j, temp;                                   
    printf("Enter the number of elements: ");            
    scanf("%d", &n);                                     
    int arr[n];                                          
    printf("Enter the elements:\n");                     
    for (i = 0; i < n; i++) {                            
        scanf("%d", &arr[i]);                            
    }                                                    
    InsertionSortA(arr, n);                                 
    printf("The Ascending order of the elements is:\n"); 
    print(arr, n);                                       
    InsertionSortD(arr, n);                                 
    printf("\n");                                        
    printf("The Descending order of the elements is:\n");
    print(arr, n);                                       
}                                                        