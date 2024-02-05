//Maze path 2d right and down

// from 0,0 to m,n

#include<iostream>
using namespace std;

int maze(int sr, int sc, int er, int ec){
    if(sr>er || sc>ec)  return 0;
    if(sr==er && sc==ec)  return 1;
    int rightWays = maze(sr, sc+1, er, ec); 
    int downWays = maze(sr+1, sc, er, ec);  
    int totalWays = rightWays + downWays;
    return totalWays;
}

int main(){
    cout << maze(1, 1, 5, 4);
    return 0; 
}
