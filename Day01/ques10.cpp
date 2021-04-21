// trapping rain water
// https://leetcode.com/problems/trapping-rain-water/

//approach-1: precompute right maximum height
int trap(vector<int>& height) {
    int n = height.size();
    if(n==1 || n==0) return 0;
    vector<int> rightMax(n);
    rightMax[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1],height[i+1]);
    }
    
    int totalWater = 0,leftMax = 0;
    
    for(int i=1;i<n-1;i++){
        leftMax = max(leftMax,height[i-1]);
        int currWater = min(rightMax[i],leftMax) - height[i];
        if(currWater>0) totalWater += currWater;
    }
    
    return totalWater;
}

//approach-2 : O(n) time and O(1) space

int trap(vector<int>& height) {
    int n = height.size();
    if(n<=1) return 0;
    int left = 0, right = n-1,leftMax=height[0],rightMax=height[n-1];
    int total = 0;
    
    while(left<right){
        if(height[left]<=height[right]){
            if(height[left]>=leftMax){
                leftMax = height[left];
            }
            else{
                total += (leftMax-height[left]);
            }
            left++;
        }
        else{
            if(height[right]>=rightMax){
                rightMax = height[right];
            }
            else{
                total += (rightMax-height[right]);
            }
            right--;
        }
    }
    
    return total;
    
}