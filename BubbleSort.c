#include <stdio.h>

void BubbleSortA(int arr[],int size){   //Ascending order Algorithm
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }

}

void BubbleSortD(int arr[],int size){   //Descending order Algorithm
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
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
    BubbleSortA(arr, n);
    printf("The Ascending order of the elements is:\n");
    print(arr, n);
    BubbleSortD(arr, n);
    printf("\n");
    printf("The Descending order of the elements is:\n");
    print(arr, n);
}