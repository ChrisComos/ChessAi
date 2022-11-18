#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;



//get it working then refactor so not all a god file
//
string startBoard[8][8] = {
        {"1R", "1N", "1B", "1Q", "1K", "1B", "1N", "1R"},
        {"1P", "1P", "1P", "1P", "1P", "1P", "1P", "1P"},
           {"o", "o", "o", "o", "o", "o", "o", "o"},
           {"o", "o", "o", "o", "o", "o", "o", "o"},
           {"o", "o", "o", "o", "o", "o", "o", "o"},
           {"o", "o", "o", "o", "o", "o", "o", "o"},
        {"2P", "2P", "2P", "2P", "2P", "2P", "2P", "2P"},
        {"2R", "2N", "2B", "2Q", "2K", "2B", "2N", "2R"}
};
static int maxdepth = 8;


int main() {

    //while not endgame
      //player move
      //ai move(Number to indicate side)
    printBoard(startBoard);
    // printf("Begin game! \n");
    //string move = abSearch(board);

}

void printBoard(string board[8][8]) {
    //printboard;
    int i;
    int j = 0;
    for (i; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%s\t", board[i][j]);
        }
        printf("\n");
    }
}

int doMove(char* move) {
    //TODO
}

bool inCheck(vector<string> moves){
  // for each move in moves
  // check to see if 2nd position on board is king
    int i = 0;
    for( i = 0; i < moves.size(); i++) {
      string move[5] = moves[i];
      if (move[4] == "K") {
        return true;
    }
  }

}

bool checkmate(){
  // if checkmate return true, else false
  // if in check and cant make a move to get out of check

  //check if in check, if so, check moves resulting in non check, if none, checkmate true
  return false;
}

bool isGoal(string board[8][8]) {
  //if endgame return true
  //if checkmate
  //if only kings left
  int onlyKings, kingDown;
  int i,j;
  for( i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      if((board[i][j] == "1K")|| (board[i][j] == "2K")){
        kingDown++;
      }
      if(board[i][j] == "o"){
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

int abevalFunc(string board[8][8], int number){
  //evaluate board, number for if we have more than one eval function
  // do simple k = 20 q = 9 brk = 5 p = 1
  int pts = 0;
  int i, j;
  for( i = 0 ; i < 8 ; i++ ){
    for( j = 0 ; j < 8 ; j++ ){
      string piece = board[i][j];
      if( piece[0] == '1'){
          if(piece[1]=='K') { pts += 20; }
          if(piece[1]=='Q') { pts += 9; }
          if(piece[1]=='N') { pts += 5; }
          if(piece[1]=='B') { pts += 5; }
          if(piece[1]=='R') { pts += 5; }
          if(piece[1]=='P') { pts += 1; }
      }
      else if(piece[0]=='2') {
        if(piece[1] == 'K') { pts -= 20; }
        if(piece[1] == 'Q') { pts -= 9; }
        if(piece[1] == 'N') { pts -= 5; }
        if(piece[1] == 'B') { pts -= 5; }
        if(piece[1] == 'R') { pts -= 5; }
        if(piece[1] == 'P') { pts -= 1; }
      }

    }
  }



  if(pts > 0){
    //favors p1
    return 1;
  }
  else if ( pts < 0){
    //favors p2
    return -1;
  }
  else{
    //favors no one
    return 0;
  }



}

char* printMoves(vector<string> moves){

  int i = 0;
  for( i = 0; i < moves.size(); i++) {
    printf("%s\t", moves[i]);
  }


}

vector<string> checkValidMoves(string board[8][8]) {
    //for each position
      //check valid moves for pieces
      //add moves to the arraylist of moves
      //P = pawn
      //R = rook
      //B = Bishop
      //N = kNight
      //Q = Queen
      //K = King
      //o = open space
    vector<string> moves;
    // move stored as location 1 move to location 2
    // PREVIOUSLOCATION,NEWLOCATION
    // 13,36
    //position 1,3 move to 3,6
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {

            string num = board[i][j];
            string move;

            //pawn
            if (num[1] == 'P') {
                if (num[0] == '1') {
                    if (j + 1 < 8) {
                        if (board[i][j + 1]== "o") {
                            move = to_string(i) + to_string(j) + "," +to_string(i) + to_string(j + 1);
                                moves.push_back(move);
                        }
                        if (i - 1 >= 0) {
                            if (board[i - 1][j + 1] == "o") {
                                move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j + 1);
                                    moves.push_back(move);
                            }
                        }
                        if (i + 1 < 8) {
                            if (board[i + 1][j + 1] == "o") {
                                move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j + 1);
                                moves.push_back(move);
                            }
                        }
                    }
                }
            }
            //rook
            if (num[1] == 'R') {
                int k = 0;
                //forward for 1 back for 2
                for (k = j; k < 8; k++) {
                    //if board at i k is open add pos to move list
                    if (board[i][j] == "o") {
                        move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                        moves.push_back(move);
                    }
                    //if not empty stop checking for spaces
                    else { k = 8; }
                }
                //backward for 1 forward for 2
                for (k = j; k >= 0; k--) {
                    //if board at i k is open add pos to move list
                    if (board[i][j] =="o") {
                        move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                        moves.push_back(move);
                    }
                    //if not empty stop checking for spaces
                    else { k = -1; }
                }
                //left for 1 right for 2
                for (k = i; k < 8; k++) {
                    //if board at i k is open add pos to move list
                    if (board[i][j] == "o"){
                        move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                        moves.push_back(move);
                    }
                    //if not empty stop checking for spaces
                    else { k = 8; }
                }
                //right for 1 left for 2
                for (k = i; k >= 0; k--) {
                    //if board at i k is open add pos to move list
                    if (board[i][j]== "o") {
                        move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                        moves.push_back(move);
                    }
                    //if not empty stop checking for spaces
                    else { k = -1; }
                }
            }
            //bishop
            if (num[1]== 'B') {
                int k = 0;
                for (k = 0; k < 8; k++) {
                    //if board at i k is open add pos to move list
                    if (i + k < 8 && j + k < 8) {
                        if (board[i + k][j + k]== "o") {
                            move = to_string(i) + to_string(j) +","+to_string(i + k) + to_string(j + k);
                            moves.push_back(move);
                        }
                        else { k = 8; }
                    }
                }
                for (k = 0; k < 8; k++) {
                    //forward diagonal
                    if (i - k >= 0 && j + k < 8) {
                        if (board[i + k][j + k]=="o") {
                            move = to_string(i)+ to_string(j) + "," + to_string(i - k) + to_string(j + k);
                            moves.push_back(move);
                        }
                        else { k = 8; }
                    }
                }

                for (k = 0; k < 8; k++) {
                    //if board at i k is open add pos to move list
                    if (i + k < 8 && j - k >= 0) {
                        if (board[i + k][j - k] == "o") {
                            move = to_string(i) + to_string(j) + "," + to_string(i + k) + to_string(j - k);
                            moves.push_back(move);
                        }
                        else { k = -1; }
                    }
                }
                for (k = 0; k < 8; k++) {
                    //if board at i k is open add pos to move list
                    if (i - k < 8 && j - k < 8) {
                        if (board[i - k][j - k]== "o") {
                            move = to_string(i) + to_string(j) + "," + to_string(i - k) + to_string(j - k);
                            moves.push_back(move);
                        }
                        else { k = -1; }
                    }
                }
            }
            //knight
            if (num[1] == 'N') {

              //Front
              if( i + 2 <= 8) {
                  if(j + 1 <= 8){
                    if(num[0] != (board[i+2][j+1])[0]){
                      move = to_string(i) + to_string(j) + "," + to_string(i + 2) + to_string(j + 1);
                      moves.push_back(move);
                    }
                  }
                  if (j - 1 >= 0){
                    if(num[0] != (board[i+2][j-1])[0]){
                      move = to_string(i) + to_string(j) + "," + to_string(i + 2) + to_string(j - 1);
                      moves.push_back(move);
                    }
                  }
                }

              //Back
              if( i - 2 >= 0) {
                if(j + 1 <= 8){
                    if(num[0] != (board[i-2][j+1])[0]){
                      move = to_string(i) + to_string(j) + "," + to_string(i - 2) + to_string(j + 1);
                      moves.push_back(move);
                    }
                }
                if (j - 1 >= 0){
                    if(num[0] != (board[i-2][j-1])[0]){
                      move = to_string(i) + to_string(j) + "," + to_string(i - 2) + to_string(j - 1);
                      moves.push_back(move);
                    }
                }
              }

              //Left
              if( j + 2 <= 8) {
                if(i + 1 <= 8){
                  if(num[0] != (board[i+1][j+2])[0]){
                    move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j + 2);
                    moves.push_back(move);
                  }
                }
                if (i - 1 >= 0){
                  if(num[0] != (board[i-1][j+2])[0]){
                    move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j + 2);
                    moves.push_back(move);
                  }
                }
              }

              //Right
              if( j - 2 >= 0) {
                if(i + 1 <= 8){
                  if(num[0] != (board[i+1][j-2])[0]){
                    move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j - 2);
                    moves.push_back(move);
                  }
                }
                if (i - 1 >= 0){
                  if(num[0] != (board[i-1][j-2])[0]){
                    move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j - 2);
                    moves.push_back(move);
                  }
                }
              }

            }
            //queen
            if (num[1] == 'Q') {
              //combination of bishop and rook
              //rook
              int k = 0;
              //forward for 1 back for 2
              for (k = j; k < 8; k++) {
                  //if board at i k is open add pos to move list
                  if (board[i + k][j + k]== "o") {
                      move = to_string(i) + to_string(j) + "," + to_string(i), to_string(k);
                      moves.push_back(move);
                  }
                  //if not empty stop checking for spaces
                  else { k = 8; }
              }
              //backward for 1 forward for 2
              for (k = j; k >= 0; k--) {
                  //if board at i k is open add pos to move list
                  if (board[i + k][j + k]== "o") {
                      move = to_string(i) + to_string(j) + "," + to_string(i), to_string(k);
                      moves.push_back(move);
                  }
                  //if not empty stop checking for spaces
                  else { k = -1; }
              }
              //left for 1 right for 2
              for (k = i; k < 8; k++) {
                  //if board at i k is open add pos to move list
                  if (board[i + k][j + k]== "o") {
                      move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                      moves.push_back(move);
                  }
                  //if not empty stop checking for spaces
                  else { k = 8; }
              }
              //right for 1 left for 2
              for (k = i; k >= 0; k--) {
                  //if board at i k is open add pos to move list
                  if (board[i + k][j + k]== "o") {
                      move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(k);
                      moves.push_back(move);
                  }
                  //if not empty stop checking for spaces
                  else { k = -1; }
              }

              //Bishop
              int k = 0;
              for (k = 0; k < 8; k++) {
                  //if board at i k is open add pos to move list
                  if (i + k < 8 && j + k < 8) {
                      if (board[i + k][j + k]== "o") {
                          move = to_string(i) + to_string(j) + "," + to_string(i + k) + to_string(j + k);
                          moves.push_back(move);
                      }
                      else { k = 8; }
                  }
              }
              for (k = 0; k < 8; k++) {
                  //forward diagonal
                  if (i - k >= 0 && j + k < 8) {
                      if (board[i + k][j + k]== "o") {
                          move = to_string(i) + to_string(j) + "," + to_string(i - k) + to_string(j + k);
                          moves.push_back(move);
                      }
                      else { k = 8; }
                  }
              }

              for (k = 0; k < 8; k++) {
                  //if board at i k is open add pos to move list
                  if (i + k < 8 && j - k >= 0) {
                      if (board[i + k][j + k]== "o") {
                          move = to_string(i) + to_string(j) + "," + to_string(i + k) + to_string(j - k);
                          moves.push_back(move);
                      }
                      else { k = -1; }
                  }
              }
              for (k = 0; k < 8; k++) {
                  //if board at i k is open add pos to move list
                  if (i - k < 8 && j - k < 8) {
                      if (board[i + k][j + k] == "o") {
                          move = to_string(i) + to_string(j) + "," + to_string(i - k) + to_string(j - k );
                          moves.push_back(move);
                      }
                      else { k = -1; }
                  }
              }

            }
            if (num[1] == 'K') {
              //check
                if (i + 1 <= 8){
                  if(j+1 < 8){
                    move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j + 1);
                    moves.push_back(move);
                  }
                  if(j < 8){
                    move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j);
                    moves.push_back(move);
                  }
                  if(j-1 >=0){
                    move = to_string(i) + to_string(j) + "," + to_string(i + 1) + to_string(j - 1);
                    moves.push_back(move);
                  }
                }
                if(i < 8){
                  if(j+1 < 8 ){
                    move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(j + 1);
                    moves.push_back(move);
                  }
                  //current location is i,j
                  if(j-1 >=0){
                    move = to_string(i) + to_string(j) + "," + to_string(i) + to_string(j - 1);
                    moves.push_back(move);
                  }
                }
                if(i-1 >= 0){
                  if(j+1 < 8){
                    move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j + 1);
                    moves.push_back(move);
                  }
                  if(j < 8){
                    move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j);
                    moves.push_back(move);
                  }
                  if(j-1 >=0){
                    move = to_string(i) + to_string(j) + "," + to_string(i - 1) + to_string(j + 1);
                    moves.push_back(move);
                  }
                }
            }
            // //   queen but one space
            // //   cant move into check
            // // }
          }
        }
      }

string** result(string state[8][8], string action) {
    // 12,34
    string childState[8][8] = state;
    //take piece
    string pieceToMove = childState[action[0]][action[1]];
    //put to new location
    childState[action[3]][action[4]] = pieceToMove;
    //set old position to "o"
    childState[action[0]][action[1]] = "o";

    return childState;


}

double maxVal(string[8][8] state, double alpha, double beta, int depth) {
    //if goal or max depth
    // return evaluation

    double v = DBL_MIN;
    vector<string> actions;
        int i;
        for (i = 0; i < actions.size(); i++) {
            v = max(v, minVal(result(state, action), alpha, beta, depth + 1));
            if (v >= beta) {
                return v;
            }
            alpha = max(alpha, v);
        }
    }
}

double minVal(string[8][8] state, double alpha, double beta, int depth) {
    //if goal or max depth
    // return evaluation

    double v = DBL_MIN;
    vector<string> actions;
    int i;
    for (i = 0; i < actions.size(); i++) {
        v = min(v, maxVal(result(state, action), alpha, beta, depth + 1));
        if (v >= alpha) {
            return v;
        }
        beta = min(beta, v);
    }
}
}



string abSearch(string state[8][8]){
  double alpha = DBL_MIN;
  string maxActVal;
  vector<string> actions; // = printMoves(board);
  int k;
  for( k = 0; k < sizeof(actions); k++){
    double v = minVal(result(state,actions[k]),alpha, DBL_MAX,0);
    if(v > alpha){
      alpha = v;
      maxActVal = actions[k];
    }
  }
  return maxActVal;

}

int idabSearch(int n,string state[8][8]){
  int i = 0;
  for(i; i < n; i++){
    abSearch(state);
  }
}

int MinMaxSearch(){}

int monteCarlo(){}





