#include <stdio.h>

static char*[8][8] board;
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


}




int isGoal(char[8][8] board){
  //if endgame return true
  //if checkmate
  //if only kings left

}

int inCheck(){
  //dont know how to do this one yet
  //check if in check
  //return true if in check

}

int evalFunc(int number){
  //evaluate board
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

void printBoard(char* [8][8] board){
  //printboard
  int i,j;
  for( i = 0, i < 8, i++){
    for (j = 0, j < 8, i++){
      printf("%s ", board[i][j]);
    }
    printf("\n");
  }
}

int abSearch(){}

int idabSearch(){}

int MinMaxSearch(){}

int monteCarlo(){}
