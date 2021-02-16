// Last non-zero digit of a factorial

#include<bits/stdc++.h>

using namespace std;

int countNonZeroDigit(int n,int digit, int count2){
    if(n<=1){
        return digit;
    }
    int prod = digit*n;
    while(prod%5==0){
        prod /=5;
        count2++;
    }
    while(count2-- && (prod%2)==0){
        prod /= 2;
    }
    return countNonZeroDigit(n-1,prod%10,count2);
}

int main(){
    int n=33,digit=1,count2=0;

    cout<<countNonZeroDigit(n,digit,count2);
}