// Rat in a Maze Problem - I

#include<bits/stdc++.h>

using namespace std;

vector<int> xMove = {-1,+1,0,0};
vector<int> yMove = {0,0,-1,+1};
vector<char> direction = {'U','D','L','R'};


void ratMaze(vector<vector<bool>> &maze,const int &n,const int &m,vector<vector<bool>> visited, int i,int j,string str,vector<string> &res){
    if(i==n-1 && j==m-1){
        res.push_back(str);
        return ;
    }
    
    for(int k=0;k<xMove.size();k++){
        if(i+xMove[k]>=0 && i+xMove[k]<n && j+yMove[k]>=0 && j+yMove[k]<m && maze[i+xMove[k]][j+yMove[k]]==1 && visited[i+xMove[k]][j+yMove[k]] == false){
            visited[i+xMove[k]][j+yMove[k]] = true;
            str.push_back(direction[k]);
            ratMaze(maze,n,m,visited,i+xMove[k],j+yMove[k],str,res);
            visited[i+xMove[k]][j+yMove[k]] = false;
            str.pop_back();
        }
    }

    return;

}

int main(){
    vector<vector<bool>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n=maze.size();
    if(n==0) return 0;
    int m=maze[0].size(),i=0,j=0;

    
    vector<vector<bool>> visited(n,vector<bool>(m,0));

    vector<string> res;
    string str="";

    ratMaze(maze,n,m,visited,i,j,str,res);

    for(string result : res){
        cout<<result<<endl;
    }

    return 0;
}