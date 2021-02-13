// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

int majorityElement(int arr[], int n)
{
    if(n==1) return arr[0];
    int count=1;
    int cand = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==cand)
            count++;
            
        else{
            count--;
            if(count<=0){
                count=1;
                cand = arr[i];
            }
        }
    }
    
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==cand)
            count++;
    }
    if(count>n/2)return cand;
    else return -1;
    
}