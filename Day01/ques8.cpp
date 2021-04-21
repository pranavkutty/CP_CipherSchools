// Kth smallest element

int findPosition(vector<int> &nums,int l,int r){
    int n = r-l+1;
    int pivot = l+(rand()%n);
    swap(nums[pivot],nums[r]);
    int i=l-1;

    for(int j=l;j<l+n-1;j++){
        if(nums[j]>nums[r]){
            i++;
            swap(nums[i],nums[j]);
        }
    }
    i++;
    swap(nums[i],nums[r]);
    return i;
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    int pos, l = 0,r = n-1;

    while(l<r){
        pos = findPosition(nums,l,r);
        for(int x:nums)
            cout<<x<<" ";
        cout<<endl;
        if(pos+1==k){
            return nums[pos];
        }
        else if(pos+1<k){
            l = pos+1;
        }
        else{
            r = pos-1;
        }
    }   
    return nums[l];
}