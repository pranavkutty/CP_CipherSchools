// Given an array arr[] of N distinct integers, output the array in such a way that the first element is first maximum and the second element is the first minimum, and so on
// https://practice.geeksforgeeks.org/problems/alternative-sorting1311/1#


#include<bits/stdc++.h>

using namespace std;

vector<int> alternateSort(int arr[], int n)
{
    vector<int> res(n);
    sort(arr,arr+n);
    int k=0;
    for(int i=0,j=n-1;i<=j;i++,j--){
        res[k] = arr[j];
        if(i==j) break;
        res[k+1] = arr[i];
        
        k += 2;
    }
    
    return res;
    
}