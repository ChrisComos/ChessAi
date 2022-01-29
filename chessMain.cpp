#include <stdio.h>

static char* board[8][8];
static int maxdepth = 8;
int main(){
  board = {
      {"1R", "1N", "1B", "1Q", "1K", "1B", "1N", "1R"},
			{"1P", "1P", "1P", "1P", "1P", "1P", "1P", "1P"},
			{"o", "o", "o", "o", "o", "o", "o", "o"},
			{"o", "o", "o", "o", "o", "o", "o", "o"},
			{"o", "o", "o", "o", "o", "o", "o", "o"},
			{"o", "o", "o", "o", "o", "o", "o", "o"},
      {"2P", "2P", "2P", "2P", "2P", "2P", "2P", "2P"},
      {"2R", "2N", "2B", "2Q", "2K", "2B", "2N", "2R"}
  };
//while not endgame
  //player move
  //ai move(Number to indicate side)
  printBoard(board);
  printf("Begin game! \n");
  char* move = absearch(board);

}




boolean isGoal(char* board[8][8]){
  //if endgame return true
  //if checkmate
  //if only kings left
  int onlyKings, kingDown;
  int i,j;
  for( i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      if((strcmp(board[i][j], "1K") == 0 )|| (strcmp(board[i][j], "1K") == 0)){
        kingDown++;
      }
      if(!(strcmp(board[i][j], "o") == 0)){
        onlyKings++;
      }
    }
  }
  if(kingDown < 2  || onlyKings == 0){
    return true;
  }
  return false;
}


boolean inCheck(){
  //dont know how to do this one yet
  //check if in check
  //return true if in check

}

int abevalFunc(int number){
  //evaluate board
}

char* printMoves(char* board[8][8]){

}

int checkValidMoves(int num, char* board[8][8]){
  //for each position begining with num
    //check valid moves for pieces
    //P = pawn
    //R = rook
    //B = Bishop
    //N = kNight
    //Q = Queen
    //K = King
    //o = open space


    /*
    int i,j;
    for( i = 0, i < 8, i++){
      for (j = 0, j < 8, i++){

        if(board[i][j] contains num){
          if (board[i][j] contains P){
            forward - left, right, center 1 space, 2 if first move of P
        }
          if (board[i][j] contains R){
            forward Back
            left - right
            All up to 8 spaces

        }
          if (board[i][j] contains B){
          diagonal any direction
        }
          if (board[i][j] contains N){
          F2 - l1,r1
          B2 - l1,r1
          L2 - f1,b1
          R2 - f1,b1

        }
          if (board[i][j] contains Q){
          any dierection any amount
        }
          if (board[i][j] contains K){
          anydirection 1 spaces
          cant move into check
        }




        }

      }
    }
  }
    */
}

void printBoard(char*  board[8][8]){
  //printboard
  int i,j;
  for( i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      printf("%s ", board[i][j]);
    }
    printf("\n");
  }
}

int abSearch(char* state[8][8]){
  double alpha = DBL_MIN;
  char* maxActVal;
  char* actions[] = printMoves(board);
  int k;
  for( k = 0; k < sizeof(actions); k++){
    double v = minOf(result(board,action[k]),alpha, DBL_MAX,0);
    if(v > alpha){
      alpha = v;
      memcpy(action[k], maxActVal);
    }
  }
  return maxActVal;

}

int idabSearch(){}

int MinMaxSearch(){}

int monteCarlo(){}
