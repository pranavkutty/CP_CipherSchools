// There are two people that start from two different positions, let’s say x1 and x2. Both can jump v1 and v2 meters ahead respectively. We have to find if both will ever meet given that the number of jumps taken by both has to be same.
#include<bits/stdc++.h>

using namespace std;


string checkMeet(int x1,int v1,int x2, int v2){
    if(x1==x2) return "Yes";
    if(x2>x1 && v1>v2){
        swap(x1,x2);
        swap(v1,v2);
    }
    else if((x2>x1 && v1<v2) || (x1>x2 && v2<v1)){
        return "No";
    }
    while(x2<x1){
        x2 += v2;
        x1 += v1;
        if(x2==x1)
            return "Yes";
    }
    return "No";
}

int main(){
    int x1,x2,v1,v2;
    cin>>x1>>v1>>x2>>v2;

    cout<<checkMeet(x1,v1,x2,v2);

    return 0;
}