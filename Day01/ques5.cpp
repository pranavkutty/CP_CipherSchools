// The binary array contains only 0  and 1. The task is to arrange the array in increasing order.
// https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/1

void binSort(int arr[], int N)
{
    int i=-1,j=0;
    
    while(j<N){
        if(arr[j]==0){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
}