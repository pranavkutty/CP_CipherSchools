//Count all possible paths from top left to bottom right of a mXn matrix, you can move right or down only

#include<bits/stdc++.h>

using namespace std;

vector<int> xMove = {0,+1};
vector<int> yMove = {+1,0};
void countPathsRecursive(vector<vector<int>> mat,int n,int m,int &count,int i,int j){
    if(i==n-1 && j==m-1){
        count++;
        return;
    }

    for(int k=0;k<xMove.size();k++){
        if(i+xMove[k]<n && j+yMove[k]<m){
            countPathsRecursive(mat,n,m,count,i+xMove[k],j+yMove[k]);
        }
    }
}

void countPathsIterative(vector<vector<int>> &mat,int n,int m,int &count){
    mat[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i-1>=0){
                mat[i][j] += mat[i-1][j];
            }
            if(j-1>=0){
                mat[i][j] += mat[i][j-1];
            }
        }
    }

    count = mat[n-1][m-1];
}

int main(){
    int n=19,m=71,count=0,i=0,j=0;
    vector<vector<int>> mat(n,vector<int>(m,0));
    countPathsRecursive(mat,n,m,count,i,j);
    cout<<count<<endl;

    count = 0;

    countPathsIterative(mat,n,m,count);

    cout<<count<<endl;

    return 0;
}
