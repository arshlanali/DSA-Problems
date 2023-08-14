class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>, greater<int>> minheap;
        for(int i=0;i<k;i++) minheap.push(nums[i]);
        for(int i=k;i<n;i++){
            if(nums[i]>minheap.top()){
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
        return minheap.top();
    }
};