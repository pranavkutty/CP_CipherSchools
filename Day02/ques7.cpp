// Rat in a Maze Problem - I

#include<bits/stdc++.h>

using namespace std;

vector<int> xMove = {-1,+1,0,0};
vector<int> yMove = {0,0,-1,+1};
vector<char> direction = {'U','D','L','R'};

bool ratMaze(vector<vector<int>> &maze,const int n,const int m,int i,int j,vector<string> &res,string str){
    if(i==n-1 && j==m-1){
        res.push_back(str);
        return true;
    }
        
    
    for(int k=0;k<xMove.size();k++){
        if(i+xMove[k]>=0 && j+yMove[k]>=0 && i+xMove[k]<n && j+yMove[k]<m && maze[i+xMove[k]][j+yMove[k]] == 1){
            maze[i+xMove[k]][j+yMove[k]] = 0;
            str+direction[k];
            if(!ratMaze(maze,n,m,i+xMove[k],j+yMove[k],res,str)){
                str.pop_back();
                maze[i+xMove[k]][j+yMove[k]] = 1;
            }
            else{
                return true;
            }
        }
    }

    return false;

}

int main(){
    int n=3,m=3,i=0,j=0;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> res;
    string str="";

    ratMaze(maze,n,m,i,j,res,str);

    for(string result : res){
        cout<<result<<endl;
    }

    return 0;
}