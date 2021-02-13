// Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int start=-1,end=-1;
        int left = 0,right = n-1;
        
        while(left<=right){
            int mid = (left+right)/2;
            
            if(arr[mid]==x){
                start = mid;
                end = mid;
                break;
            }
            
            else if(arr[mid]<x){
                left = mid+1;
            }
            
            else{
                right = mid-1;
            }
        }
        
        if(start==-1){
            cout<<-1<<endl;
        }
        else{
            while(arr[start]==x){
                start--;
            }
            start++;
            
            while(arr[end]==x){
                end++;
            }
            end--;
            
            cout<<start<<" "<<end<<endl;
        }
    }
	return 0;
}