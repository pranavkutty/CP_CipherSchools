#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> vec(n);
    for(long long i=0;i<n;i++)
        cin>>vec[i];
    sort(vec.begin(),vec.end());

    long long Max=0,curr=0;

    for(long long i=0;i<n;i++){
        Max = max(Max,vec[i]*(n-i));
    }

    cout<<Max;
    return 0;
}