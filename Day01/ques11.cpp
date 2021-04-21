// stock buy sell to maximise profit - single transaction allowed in whole (Easy)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int minIndex=0,maxIndex=-1,diff=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex = i;
            continue;
        }
        
        diff = max(diff,arr[i]-arr[minIndex]);
    }
    return diff;
}

// multiple transactions allowed but not simultaneously
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    
    int minIndex = 0,profit = 0,currProfit=0;
    
    for(int i=1;i<n;i++){
        if(arr[i-1]<arr[i]){
            profit += (arr[i]-arr[i-1]);
        }
    }
    
    return profit;
}

// at most 2 transactions which and no simultaneous transactions
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
