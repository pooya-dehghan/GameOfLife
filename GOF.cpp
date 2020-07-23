#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;
void bacteryMaker(char map[][60]); 
void printMap(char map[][60]);
void bacteriesLife(char map[][60]);
int main() {
  srand(time(0));

  //making our map ...
  char map[35][60];
  for(int i = 0; i < 35 ; i++) {
    for(int j = 0 ; j < 60 ; j++){
      map[i][j] = ' ';
    }
  }

  //printing out our map clean and with out any bactry ...
  

  //calling function and spread bactery all over our table :)) ...
  bacteryMaker(map);

  //printing map again with bactries in this time ...
  while(true){
    // the rules of gof apply in this function and bactries will die getback to life or wont feel a thing :)) ...
    printMap(map);
    bacteriesLife(map);
    Sleep(1000);
  }
  return 0;
}
void bacteriesLife (char map[][60]){
  int row    = 0;
  char newMap[35][60];
  for(int i = 0; i < 35 ; i++) {
    for(int j = 0 ; j < 60 ; j++){
      newMap[i][j] = ' ';
    }
  }
  for( ; row < 35 ; row++){
    // cout<<"first for is runing..."<<endl;
    for(int column = 0 ; column < 60 ; column++){
      // cout<<"seconde for is runing ... "<<endl;
      int neighbor = 0;
      for(int i = -1 ; i < 2 ; i++){
        // cout<<"third for is runing ... "<<endl;
        for(int j = -1 ; j < 2 ; j++){
          // cout<<"i: "<<i<<" j: "<<j<<endl;
          if(i != j || (i == j && i != 0)){
            if(row == 0 && i == -1){
              if(map[34][column + j] == 'X'){
              neighbor++;
              }
            }
            if(column == 0 && j == -1){
              if(map[row + i][59] == 'X'){
              neighbor++;
              }
            }
            if(row == 34 && i == 1){
              if(map[0][column + j] == 'X'){
              neighbor++;
              }
            }
            if(column == 59 && j == 1){
              if(map[row + i][0] == 'X'){
              neighbor++;
              }
            }
            if(map[row + i][column + j] == 'X'){
              neighbor++;
            }
          }
        }
      }
      //Any live cell with fewer than two live neighbours dies, as if by underpopulation.
      //Any live cell with more than three live neighbours dies, as if by overpopulation.
      if((neighbor > 3 || neighbor < 2) && map[row][column] == 'X' ){
        newMap[row][column] = ' ';
      }
      //Any live cell with two or three live neighbours lives on to the next generation.
      if((neighbor == 3 || neighbor == 2) && map[row][column] == 'X'){
        newMap[row][column] = 'X';
      }
      //Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
      if(neighbor == 3 && map[row][column] != 'X'){
        newMap[row][column] = 'X';
      }
    }
  }
  for(int i = 0; i < 35 ; i++) {
      for(int j = 0 ; j < 60 ; j++){
        map[i][j] = newMap[i][j];
      }
    }
}
void printMap(char map[][60]){
  system("cls");
  for(int i = 0; i < 35 ; i++) {
    for(int j = 0 ; j < 60 ; j++){
      printf("%c",map[i][j]);
    }
    cout<<endl;
  }
}

void bacteryMaker(char map[][60]){
  //random bacteries ... >>>>

  // int initialBacteries = rand() % (300 - 200 + 1) + 200;
  // do {
  //   int column = rand() % (35 - 0 + 1) + 0;
  //   int row = rand() % (60 - 0 + 1) + 0;
  //   map[column][row] = 'X';
  //   initialBacteries--;
  // } while (initialBacteries > 0);
  
  // Glider form bacteries... >>>
     map[2][3]='X';map[3][4]='X';map[3][5]='X';map[4][3]='X';map[4][4]='X';
  //Blinker
     map[6][6]='X';map[6][7]='X';map[6][8]='X';
  //Pulsar
     map[8][15]='X';map[8][16]='X';map[8][17]='X';        map[8][21]='X';map[8][22]='X';map[8][23]='X';
                                                    //blank
     map[10][13]='X';      map[10][18]='X';     map[10][20]='X';     map[10][25]='X';
     map[11][13]='X';      map[11][18]='X';     map[11][20]='X';     map[11][25]='X';
     map[12][13]='X';      map[12][18]='X';     map[12][20]='X';     map[12][25]='X';
     map[13][15]='X';map[13][16]='X';map[13][17]='X';        map[13][21]='X';map[13][22]='X';map[13][23]='X';
                                                    //blank
     map[15][15]='X';map[15][16]='X';map[15][17]='X';        map[15][21]='X';map[15][22]='X';map[15][23]='X';
     map[16][13]='X';      map[16][18]='X';     map[16][20]='X';     map[16][25]='X';
     map[17][13]='X';      map[17][18]='X';     map[17][20]='X';     map[17][25]='X';
     map[18][13]='X';      map[18][18]='X';     map[18][20]='X';     map[18][25]='X';
                                                    //blank
     map[20][15]='X';map[20][16]='X';map[20][17]='X';        map[20][21]='X';map[20][22]='X';map[20][23]='X';


          // :)))))))))))))))))))) 305 is the best :)))))))))))))
}






// + *   map[i][j]       map[i][j+1]   
// * *   map[i+1][j]     map[i+1][j+1]     

// * + *  map[i][j-1]     map[i][j]      map[i][j+1]
// * * *  map[i+1][j-1]   map[i+1][j]    map[i+1][j+1]

//  * +  map[i-1][j-1]    map[i][j]    
//  * *  map[i-1][j-1]    map[i+1][j]

// * * *  map[i-1][j-1]   map[i-1][j]    map[i-1][j+1]
// * + *  map[i][j-1]     map[i][j]      map[i+1][j+1]
// * * *  map[i+1][j-1]   map[i+1][j]    map[i+1][j+1]

//  * *  map[i-1][j-1]    map[i-1][j]    
//  * +  map[i-1][j-1]    map[i][j]      
//  * *  map[i-1][j-1]    map[i+1][j]

//  * *  map[i-1][j-1]    map[i-1][j]
//  * +  map[i][j-1]      map[i][j]

// * * *  map[i-1][j-1]   map[i-1][j]     map[i-1][j+1]
// * + *  map[i][j]       map[i][j]       map[i][j+1]

//  * *  map[i-1][j]      map[i-1][j+1]
//  + *  map[i][j]        map[i][j+1]

//  * *  map[i-1][j]      map[i-1][j+1]
//  + *  map[i][j]        map[i+1][j+1]
//  * *  map[i+1][j]      map[i+1][j+1]