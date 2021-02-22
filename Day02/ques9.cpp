#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    bool isSafe(vector<vector<char>> &board,int i,int j){
        //check in row
        for(int k=j+1;k<9;k++){
            if(board[i][k]==board[i][j])
                return false;
        }
         //check in column
        for(int k=i+1;k<9;k++){
            if(board[k][j]==board[i][j]) 
                return false;
        }
        //check in sub-grid
        for(int k=3*(i/3);k<(3*(i/3)+3);k++){
            for(int l=3*(j/3);l<(3*(j/3)+3);l++){
                if(board[i][j]==board[k][l] && k!=i && l!=j)
                    return false;
            }
        }
        return true;        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isSafe(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};