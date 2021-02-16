// Write a program to print all permutations of a given string

#include<bits/stdc++.h>

using namespace std;

void stringPermutation(vector<string> &results,string &str,const int &n,int index){
    if(index==n-1){
        results.push_back(str);
        return;
    }

    stringPermutation(results,str,n,index+1);
    for(int i=index+1;i<n;i++){
        swap(str[index],str[i]);
        stringPermutation(results,str,n,index+1);
        swap(str[index],str[i]);
    } 
}

int main(){
    vector<string> results;
    string str="ABC";

    const int n=str.length();
    int index=0;

    stringPermutation(results,str,n,index);

    sort(results.begin(),results.end()); //for lexicographical ordering 
    for(string res : results)
        cout<<res<<endl;
    
    return 0;

}