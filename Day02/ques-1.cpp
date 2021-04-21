#include<bits/stdc++.h>

using namespace std;

int Max;
unordered_map<int,pair<int,int>> mymap;


void countZeroOne(vector<string> &str){     //0,1
    for(int i=0;i<str.size();i++){
        int zero=0,one=0;
        for(char x:str[i]){
            if(x=='0')
                zero++;
            else
                one++;
        }
        mymap[i] = {zero,one};            
    }
}

void findMaxHelper(vector<string> &str,int index,const int &m,const int &n,int &count0,int &count1,int size){
    int N = str.size();
    if(index==N || (count0==m && count1==n)){
        Max = max(Max,size);
        return;
    }
    
    pair<int,int> p = mymap[index];   
    
    count0 += p.first;
    count1 += p.second;
    
    if(count0<=m && count1<=n)
        findMaxHelper(str,index+1,m,n,count0,count1,size+1);
    
    count0 -= p.first;
    count1 -= p.second;
    
    findMaxHelper(str,index+1,m,n,count0,count1,size);       
        
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int count0=0,count1=0,size=0,index=0;
    Max=0,mymap.clear();  //reset
    countZeroOne(strs);
    findMaxHelper(strs,index,m,n,count0,count1,size);
    
    return Max;
}



int main(){
    vector<string> strs = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
    int m = 9,n=80;
    cout<<findMaxForm(strs,m,n);
}

