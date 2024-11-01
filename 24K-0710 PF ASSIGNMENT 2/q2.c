#include<stdio.h>
#include<string.h>
int char_frequency(char *s, char a);
int main(){
    char s1[20], s2[20], s3[20];
    printf("Enter slogan 1 : ");
    fgets(s1,20,stdin);
    printf("Enter slogan 2 : ");
    fgets(s2,20,stdin);
    printf("Enter slogan 3 : ");
    fgets(s3,20,stdin);
    int l1= strlen(s1);
    printf("For %s",s1);
    for (int j=0; j<l1; j++){
        int alreadyCounted=0;
        for (int k=0; k<j; k++) {
            if (s1[j]==s1[k]) {
                alreadyCounted=1;
                break;
            }
            
        }if (!alreadyCounted && s1[j]!='\n')
        char_frequency(s1, s1[j]);
    }
    int l2= strlen(s2);
    printf("\nFor %s",s2);
    for (int j=0; j<l2; j++){
        int alreadyCounted=0;
        for (int k=0; k<j; k++) {
            if (s2[j]==s2[k]) {
                alreadyCounted=1;
                break;
            }
            
        }if (!alreadyCounted && s2[j]!='\n')
        char_frequency(s2, s2[j]);
    }
   int l3= strlen(s3);
    printf("\nFor %s",s3);
    for (int j=0; j<l3; j++){
        int alreadyCounted=0;
        for (int k=0; k<j; k++) {
            if (s3[j]==s3[k]) {
                alreadyCounted=1;
                break;
            }
            
        }if (!alreadyCounted && s3[j]!='\n')
        char_frequency(s3, s3[j]);
    }
    
    return 0;
}
int char_frequency(char *s, char a){
    int length = strlen(s);
    int count = 0;
    for (int i=0; i<length; i++){
        if (s[i]==a) count+=1;
    }printf("{%c : %d}, ",a,count);
    return count;
}