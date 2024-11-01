#include<stdio.h>
#include<string.h>
void remove_duplicate_letters(char *s);
int main(){
    char string[20];
    printf("Enter your word: ");
    scanf("%s",string);
    remove_duplicate_letters(string);
    printf("Final result: %s",string);
    
}
void remove_duplicate_letters(char *s){
    int length= strlen(s);
    int originallength= length;
    for (int i=0; i<length; i++){
        for (int j=i+1; j<length; ){
            if (s[i]==s[j]){
            for (int k=j; k<length; k++){
                s[k]=s[k+1];
            }length--;
            }else j++;
        }
    }int lettersremoved=originallength-length;
    printf("\n%d characters were removed during compression\n",lettersremoved);
}