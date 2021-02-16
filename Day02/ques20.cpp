// Count trailing zeroes in factorial of a number

#include<bits/stdc++.h>

using namespace std;

/* Recursive approach
void countZeroDigit(const int &n, int &count){
        if(n<5)
            return;
        int temp = n;
        while(temp%5==0){
            count++;
            temp /= 5;
        }
    
        countZeroDigit(n-5,count);
        
    }
    int trailingZeroes(int n)
    {
        int count=0;
        while(n%5!=0) n--;
        countZeroDigit(n,count);
        
        return count;
    }
*/

//efficient solution using maths
void countZeroDigit(int n, int &count){
    if(n<5)
        return;
    int temp = n;
    while(temp%5==0){
        count++;
        temp /= 5;
    }

    countZeroDigit(n-1,count);
    
}

int trailingZeroes(int n)
{
    int count=0;
    
    for(int i=5;(n/i)>=1;i*=5){
        count += n/i;
    }
    
    return count;
}

int main(){
    int n=100,count=0;

    countZeroDigit(n,count);

    cout<<count;
    return 0;
}