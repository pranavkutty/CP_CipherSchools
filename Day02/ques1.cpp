// Write a function to generate all possible n pairs of balanced parentheses. 
#include<bits/stdc++.h>

using namespace std;


void helper(vector<string> &res,string str,int open,int close,int n,int index){
    if(open+close==2*n){
        if(open==close)
            res.push_back(str);
        return ;
    }

    helper(res,str+'(',open+1,close,n,index+1);
    if(close<open)
        helper(res,str+')',open,close+1,n,index+1);
}

int main(){

    int index = 0,open=0,close=0,n=3;
    vector<string> res;
    string str="";
    
    helper(res,str,open,close,n,index);
    
    for(string x : res){
        cout<<x<<endl;
    }

    return 0;
}