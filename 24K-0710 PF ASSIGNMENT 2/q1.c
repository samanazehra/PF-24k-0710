#include<stdio.h>
int main()
{
    int size;
    printf("Enter the size of your array: ");
    scanf("%d",&size);
    int array[size];
    int i, j, temp;
    
    for (i=0;i<size;i++){
        do {
        printf("Enter element %d (less than 9999) = ",i+1);
        scanf("%d",&array[i]);
        if (array[i]>9999){
            printf("Invalid input. Make sure number is less than 9999.\n");
        }
    }while (array[i]>9999);
    }
    for (i=1;i<size;i++){
        for (j=0;j<size-i;j++){
            if (array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("The smallest element is %d\n",array[0]);
    printf("The second smallest element is %d",array[1]);
    return 0;
}
