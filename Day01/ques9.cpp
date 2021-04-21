//counting inversions
#include<bits/stdc++.h>

using namespace std;

long long Count;

void merge(long long arr[],long long l,long long r,long long m){
    long long n1 = m-l+1,n2 = r-m,a=0,b=0;
    
    long long arr1[n1],arr2[n2];
    
    for(long long i=0;i<n1;i++)
        arr1[i] = arr[l+i];
    
    for(long long i=0;i<n2;i++)
        arr2[i] = arr[m+i+1];
    
    while(a<n1 && b<n2){
        if(arr1[a]<=arr2[b]){
            arr[l] = arr1[a];
            a++;
        }
        else{
            Count += n1-a;
            arr[l] = arr2[b];
            b++;
        }
        l++;
    }
    
    while(a<n1){
        arr[l] = arr1[a];
        a++; l++;
    }
    
    while(b<n2){
        arr[l] = arr2[b];
        b++; l++;
    }
    
}

void mergeSort(long long arr[], long long l,long long r){
    if(l>=r){
        return;
    }
    long long mid = l+(r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r,mid);
}

int main()
{
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++)
        cin>>arr[i];
    Count = 0;
    mergeSort(arr,0,n-1);
    
    cout<<Count<<endl;
    for(long long x : arr){
        cout<<x<<" ";
    }
}