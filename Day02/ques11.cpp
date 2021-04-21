// Combination Of Number (Medium): Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// https://leetcode.com/problems/combinations/

#include<bits/stdc++.h>

using namespace std;

void combineHelper(vector<vector<int>> &results,vector<int> &res,const int &n,const int &k,int index,int count){
    if(count==k){
        results.push_back(res);
        return;
    }
    
    if(index<=n){
        combineHelper(results,res,n,k,index+1,count);
        res.push_back(index);
        combineHelper(results,res,n,k,index+1,count+1);
        res.pop_back();
    }
}

int main() {
    int n=20,k=16;
    vector<vector<int>> results;
    vector<int> res;
    int index=1,count=0;
    combineHelper(results,res,n,k,index,count);

    for(vector<int> result : results){
        for(int x:result){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    return 0;       
}

