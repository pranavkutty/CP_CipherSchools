// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


int binarySearchFirst(vector<int> &nums,int target,int start,int end){
    int mid;
    
    while(start<=end){
        mid = start + (end-start)/2;
        if(nums[mid]<target)
            start = mid+1;
        else if(nums[mid]==target && (mid==0 || nums[mid-1]!=target))
            return mid;
        else
            end = mid-1;
    }
    
    return start;
}

int binarySearchLast(vector<int> &nums,int target,int start,int end){
    int mid;
    
    while(start<=end){
        mid = start + (end-start)/2;
        if(nums[mid]>target)
            end = mid-1;
        else if(nums[mid]==target && (mid==nums.size()-1 || nums[mid+1]!=target))
            return mid;
        else
            start = mid+1;
    }
    
    return start;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int start=0,end=nums.size()-1;
    
    int mid,first=-1,last=-1;
    
    while(start<=end){
        mid = start + (end-start)/2;
        if(nums[mid]<target)
            start = mid+1;
        else if(nums[mid]==target){
            first = binarySearchFirst(nums,target,start,mid);
            last = binarySearchLast(nums,target,mid,end);
            break;
        }
        else
            end = mid-1;
    }
    
    return {first,last};
}