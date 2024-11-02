/*
37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the 
grid.
The '.' character indicates empty cells.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	bool isSafe(vector<vector<char>>& board, int r, int c, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == num) return false;
            if (board[i][c] == num) return false;
        }

        int x = (r / 3) * 3;
        int y = (c / 3) * 3;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }
	
	bool solve(vector<vector<char> >&board , int r , int c){
		if(r == 9) return true;
		if(c == 9) return solve(board , r + 1 , 0);
        if (board[r][c] != '.') return solve(board, r, c + 1);
		for(char j = '1'; j <= '9' ; j++){
			if( isSafe(board , r , c , j)) {
				board[r][c] = j;
				bool temp = solve(board , r , c + 1);
				if(temp) return true;
				board[r][c] = '.';
			}
		}
        return false;	
	}
	
    void solveSudoku(vector<vector<char>>& board) {
    	solve(board , 0 , 0);   
    }
};

int main(){
	
}
