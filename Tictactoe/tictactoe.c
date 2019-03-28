#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_NUM 9
#define ROWS 3
#define COLS 3

int board[9] = {0,0,0,0,0,0,0,0,0};

int in(int num, int* board){
  for(int i = 0; i<MAX_NUM;i++){
    if(board[i] == num){
      return 1;
    }
  }
  return 0;
}


void printBoard(){
  for(int i = 0;i<MAX_NUM;i++){
    if(board[i] == 0){
      printf("   ");
    }
    if(board[i]== 1){
      printf(" X ");
    }
    if(board[i] == 2){
      printf(" O ");
    }
    if(i%3==2 && i<6){
      printf("\n------------\n");
    }else if(i%3 !=2){
      printf("|");
    }
  }
  printf("\n\n");
}


void apply(int mark, int x, int y){
  x -= 1;
  y -= 1;
  if(board[(y*3)+(x%3)] == 0){
    board[(y*3)+(x%3)] = mark;
  }else{
    printf("Invalid move!\n");
  }
}

int isValid(int x,int y){
  x -= 1;
  y -= 1;
  if (board[(y*3)+(x%3)] == 0 && (x< 3 && y < 3)){
    return 1;
  }else{
    return 0;
  }
}

int winner(int* boarded){

//Checking diagonal to right
  if(boarded[0] == boarded[4] && boarded[0]== boarded[8] && boarded[0] != 0){
  return boarded[0];
}
//Checking diagonal to left
  if(boarded[2] == boarded[4] && boarded[2]== boarded[6] && boarded[2] != 0){
  return boarded[2];
}
//checking rows
  for(int i = 0; i< ROWS;i+=3){
    if(boarded[i] == boarded[i+1] && boarded[i]== boarded[i+2] && boarded[i] != 0){
    return boarded[i];
  }
}
//Checking cols
  for (int j = 0; j<COLS;j++){
    if(boarded[j] == boarded[j+3] && boarded[j]== boarded[j+6] && boarded[j] != 0){
    return boarded[j];
  }
}
  if(in(0,boarded) == 0){
  for(int k = 0; k<9;k++){
    if (boarded[k] != 0){
      return 2;
    }
  }
}
  return 0;
}

void print_winner(int winner){
  if (winner == 1){
    printf("******* PLAYER WINS!!! ******\n");
  }else if(winner == 2){
    printf("******* COMPUTER WINS!!! ******\n");
  }else{
    printf("******** DRAW ********\n");
  }
}


int
main(){
  //Player always X(1), Computer always O(2)
  srand(time(NULL));
  int x,y;
  int player = 1, comp =2;
  int theWinner;
  printBoard();
  theWinner = winner(board);
  while(theWinner == 0){
    int valid_p = 0,valid_c = 0;
    while(valid_p ==0){
      printf("YOUR TURN: ");
      scanf("%d %d",&x,&y);
      valid_p = isValid(x,y);
      if(valid_p == 1){
        apply(player,x,y);
      }
    }
    /*
    theWinner = winner(board);
    if(theWinner != 0){
      break
    }
    */
    valid_p = 0;
    while(valid_c ==0){
      printBoard();
      printf("COMPUTER TURN...\n");
      int xC = rand()%3+1, yC = rand()%3+1;
      valid_c = isValid(xC,yC);
      if(valid_c == 1){
        apply(comp,xC,yC);
      }
      printBoard();
  }
  valid_c = 0;
  theWinner = winner(board);
}
  print_winner(theWinner);

  return 0;
}
