// Given an array of integers. Find a peak element in it. An array element is a peak if it is NOT smaller than its neighbours. For corner elements, we need to consider only one neighbour. 


int peakElement(int arr[], int n)
{
    int begin = 0,end = n-1;
    while(begin<=end)
    {
        int mid = begin + (end-begin)/2;
        
        if((arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])||(mid==0 && arr[mid]>=arr[mid+1])||(mid==n-1 && arr[mid]>=arr[mid-1]))
        {
            return mid;
        }
        if(arr[mid]<arr[mid-1])
        end = mid-1;
        else if(arr[mid]<arr[mid+1])
        begin = mid+1;
    }
}