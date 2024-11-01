#include <stdio.h>
void function(int a[], int count);
int main() {
    int count;
    printf("Enter the size of array: ");
    scanf("%d", &count);
    int b[count];
    function(b, count);
    return 0;
}

void function(int a[], int count) {
    for (int i=0;i<count;i++) {
        printf("Enter value %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Horizontal Histogram:\n");
    for (int i=0;i<count;i++) {
        printf("Value %d: ",i+1);
        for (int j=0;j<a[i];j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("Vertical Histogram:\n");
    int max=0;
    for (int i=0;i<count;i++) {
        if (a[i]>max) {
            max=a[i];
        }
    }
    for (int i=max;i>0;i--) {
        for (int j=0;j<count;j++) {
            if (a[j]>=i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i=0;i<count;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

