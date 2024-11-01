#include<stdio.h>
int find_first_move(int N);
int main(){
    int N;
    printf("Welcome to the Matchstick Game!\nTwo players will take turns picking between 1 and 4 matchsticks.\nThe player who picks the last matchstick wins.\n\n");
    printf("Enter the total number of matchsticks on the table: ");
    scanf("%d",&N);
    int result=find_first_move(N);
    if(result==-1){
        printf("Sorry, it's impossible for the first player (A) to guarantee a win with %d matchsticks.\n",N);
    } else {
        printf("To guarantee a win, A should pick %d matchstick(s) on the first turn.\n",result);
    }
    printf("Good luck and enjoy the game!\n");
    return 0;
}
int find_first_move(int N){
    if(N%5==0)return -1;
    else return N%5;
}
