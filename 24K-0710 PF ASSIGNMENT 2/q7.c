#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int rows=6,cols=5,studentID,score=0;
    char array[6][5],input[20];

    void populateArray(char arr[6][5],int studentID) {
        srand(time(NULL));
        for(int i=0;i<rows-1;i++)
            for(int j=0;j<cols;j++)
                arr[i][j]='A'+(rand()%26);
        arr[rows-1][0]=(studentID/1000%10)+'0';
        arr[rows-1][1]=(studentID/100%10)+'0';
        arr[rows-1][2]=(studentID/10%10)+'0';
        arr[rows-1][3]=(studentID%10)+'0';
        for(int j=4;j<cols;j++)
            arr[rows-1][j]='A'+(rand()%26);
    }

    void printArray(char arr[6][5]) {
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++)
                printf("%c  ",arr[i][j]);
            printf("\n");
        }
    }

    int searchString(char arr[6][5],char *str) {
        int len=strlen(str),k;
        for(int i=0;i<rows;i++)
            for(int j=0;j<=cols-len;j++) {
                for(k=0;k<len&&arr[i][j+k]==str[k];k++);
                if(k==len) return 1;
            }
        for(int j=0;j<cols;j++)
            for(int i=0;i<=rows-len;i++) {
                for(k=0;k<len&&arr[i+k][j]==str[k];k++);
                if(k==len) return 1;
            }
        return 0;
    }

    printf("Enter last four digits of your student ID: ");
    scanf("%d",&studentID);
    while(1) {
        populateArray(array,studentID);
        printf("\nGenerated Array:\n");
        printArray(array);
        while(1) {
            printf("\nEnter a string to search (or type 'END' to reset): ");
            scanf("%s",input);
            if(strcmp(input,"END")==0) break;
            if(searchString(array,input)) {
                score++;
                printf("%s is present. Score: %d\n",input,score);
            } else {
                score--;
                printf("%s is not present. Score: %d\n",input,score);
            }
        }
    }
    return 0;
}
