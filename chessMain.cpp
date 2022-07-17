#include <stdio.h>
#include<vector>

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
      if((strcmp(board[i][j], "1K") == 0 )|| (strcmp(board[i][j], "2K") == 0)){
        kingDown++;
      }
      if(!(strcmp(board[i][j], "o") == 0)){
        onlyKings++;
      }
    }
  }
  if(checkmate()){
    return true;
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

boolean checkmate(){
  // if checkmate return true, else false
  // if in check and cant make a move to get out of check
}

int doMove(char* move){

}

int abevalFunc(int number){
  //evaluate board
}

char* printMoves(char* board[8][8], char* piece){
  //print all moves for specified pieces
  //if piece = "" then print all moves

}

vector<string> checkValidMoves(char* board[8][8]){
  //for each position
    //check valid moves for pieces
    //P = pawn
    //R = rook
    //B = Bishop
    //N = kNight
    //Q = Queen
    //K = King
    //o = open space
    vector<string> moves;
    // move stored as location 1 move to location 2
    // 13,36
    //position 1,3 move to 3,6
    int i,j;
    for( i = 0, i < 8, i++){
      for (j = 0, j < 8, j++){
        char[] num = board[i][j];
        char[] move;
        //pawn
        if (num[1] == 'P'){
          if (num[0] == '1'){
             if(j+1 < 8){
               if(!strcmp(board[i][j+1], "o"){
                 move = {i,j,',',i,j+1};
                 moves.push_back(move);
             }
               if(i-1 >= 0){
                 if(strcmp(board[i-1][j+1], "o") == 0){
                   move = {i,j,',',i-1,j+1};
                   moves.push_back(move);
                 }

               }
               if(i+1 < 8){
                 if(strcmp(board[i+1][j+1], "o") == 0){
                   move = {i,j,',',i+1,j+1};
                   moves.push_back(move);
                 }
               }
             }
         }
       }
       //rook
        if (num[1] =='R'){
          if(num[0] == '1'){
            
          }

          if(num[0] == '2'){

          }
        }

      //   if (num[1] =='B'){
      //   diagonal any direction
      // }
      //   if (num[1] =='N'){
      //   F2 - l1,r1
      //   B2 - l1,r1
      //   L2 - f1,b1
      //   R2 - f1,b1
      //
      // }
      //   if (num[1] =='Q'){
      //   any dierection any amount
      // }
      //   if (num[1] =='K'){
      // //   anydirection 1 spaces
      // //   cant move into check
      // // }

}}

void printBoard(char*  board[8][8]){
  //printboard
  int i,j;
  for( i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      printf("%s\t", board[i][j]);
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

int idabSearch(int n,char* state[8][8]){
  int i = 0;
  for(i; i < n; i++){
    abSearch(state);
  }
}

int MinMaxSearch(){}

int monteCarlo(){}
