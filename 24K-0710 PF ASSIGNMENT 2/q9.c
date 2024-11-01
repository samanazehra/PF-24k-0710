#include <stdio.h>
#include <stdlib.h>
void displayGrid(char grid[5][5]) {
    printf("Current Grid:\n");
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}
void movePlayer(char grid[5][5],int *playerX,int *playerY,char direction) {
    int newX=*playerX;
    int newY=*playerY;
    if(direction=='W'||direction=='w') {
        newX--;
    } else if(direction=='S'||direction=='s') {
        newX++;
    } else if(direction=='A'||direction=='a') {
        newY--;
    } else if(direction=='D'||direction=='d') {
        newY++;
    } else if(direction=='Q'||direction=='q') {
        printf("Thank you for playing! Exiting the game.\n");
        exit(0);
    } else {
        printf("Invalid input! Please enter W, S, A, D, or Q.\n");
        return;
    }
    if(newX<0||newX>=5||newY<0||newY>=5) {
        printf("Invalid move! You are trying to move out of bounds.\n");
        return;
    }
    if(grid[newX][newY]=='X') {
        printf("Oops! You hit an obstacle and cannot move there.\n");
        return;
    }
    if(grid[newX][newY]=='I') {
        printf("Congratulations! You collected an item!\n");
    }
    grid[*playerX][*playerY]=' ';
    *playerX=newX;
    *playerY=newY;
    grid[*playerX][*playerY]='P';
}
int main() {
    char grid[5][5]={{
        ' ',' ','I','X',' '},
        {' ','X',' ',' ',' '},
        {'I',' ','X','X',' '},
        {' ',' ',' ','I','X'},
        {' ','X',' ',' ','P'}
    };
    int playerX=4,playerY=4;
    char move;
    printf("Welcome to the Adventure Game!\nYou can collect items, avoid obstacles, and navigate through the grid.\nYour goal is to collect as many items as possible!\n");
    while(1) {
        displayGrid(grid);
        printf("Enter your move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c",&move);
        movePlayer(grid,&playerX,&playerY,move);
    }
    return 0;
}

