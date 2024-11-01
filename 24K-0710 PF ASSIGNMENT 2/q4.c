#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sortstring(char str[]){
    int len=strlen(str);
    char temp;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(str[i]>str[j]){
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
        }
    }
}

void groupanagrams(char transactions[][100],int count){
    char sortedtransactions[100][100];
    int groupindex[100]={0};
    int anagramcounts[100]={0};
    int groupcount=0;

    for(int i=0;i<count;i++){
        strcpy(sortedtransactions[i],transactions[i]);
        sortstring(sortedtransactions[i]);
    }

    for(int i=0;i<count;i++){
        int found=0;
        for(int j=0;j<groupcount;j++){
            if(strcmp(sortedtransactions[i],sortedtransactions[groupindex[j]])==0){
                anagramcounts[j]++;
                found=1;
                break;
            }
        }
        if(!found){
            groupindex[groupcount]=i;
            anagramcounts[groupcount]=1;
            groupcount++;
        }
    }

    printf("\nGrouped Anagrams:\n");
    printf("[");
    for(int i=0;i<groupcount;i++){
        printf("[");
        int countingroup=0;
        for(int j=0;j<count;j++){
            if(strcmp(sortedtransactions[groupindex[i]],sortedtransactions[j])==0){
                if(countingroup>0)printf(", ");
                printf("'%s'",transactions[j]);
                countingroup++;
            }
        }
        printf("]");
        if(i<groupcount-1)printf(", ");
    }
    printf("]\n");
}

int main(){
    int count;
    printf("Welcome to the Anagram Grouping Program!\n");
    printf("Please enter the number of transactions you want to input: ");
    scanf("%d",&count);
    
    char transactions[100][100];
    for(int i=0;i<count;i++){
        printf("Enter transaction %d: ",i+1);
        scanf("%s",transactions[i]);
    }
    
    groupanagrams(transactions,count);
    return 0;
}
