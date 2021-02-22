//N Queens Problem (Hard) /Print all configurations of it as H/W.
// https://leetcode.com/problems/n-queens/

bool isSafe(vector<string> &board,const int row,const int col,const int n){
        //check row
        for(int j=0;j<=col;j++){
            if(board[row][j]=='Q')
                return false;
        }
        //check upper diagonal
        for(int i=row, j=col;i>=0 && j>=0;i--, j--)
            if(board[i][j]=='Q')
                return false;
        //check lower diagonal
        for(int i=row,j=col;i<=n-1 && j>=0;i++,j--)
            if(board[i][j]=='Q')
                return false;
        
        return true;
    }
    
    void solveNQueensHelper(vector<vector<string>> &results,vector<string> board,int col,const int &n){
        if(col==n){
            results.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!isSafe(board,i,col,n))
                continue;
            board[i][col] = 'Q';
            solveNQueensHelper(results,board,col+1,n);
            board[i][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
        string str(n,'.');
        vector<string> board(n,str);
        vector<vector<string>> results;
        
        solveNQueensHelper(results,board,0,n);    
        return results;
    }