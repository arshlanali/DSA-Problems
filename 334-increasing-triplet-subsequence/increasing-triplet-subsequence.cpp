class Solution {
public: 
    int n;
    int helper(vector<int>& nums, int ind, int prevind, vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prevind+1]!=-1) return dp[ind][prevind+1];
        int skip= 0+ helper(nums, ind+1, prevind,dp);
        int take= -1e9;
        if(prevind==-1 || nums[ind]>nums[prevind]){
            take= 1+helper(nums, ind+1, ind, dp);
        }
        return dp[ind][prevind+1]= max(skip, take);
    }
    bool increasingTriplet(vector<int>& nums) {
        n= nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // int len= helper(nums, 0, -1,  dp);
        // // int len= solve(0, -1, nums, dp);
        // // cout<<len<<" ";
        // return len>=3;
        int prev= INT_MAX, prev2= INT_MAX;
        for(auto i: nums){
            if(i<= prev) prev=i;
            else if(i<=prev2) prev2=i;
            else return true;
        }
        return false;
    }
};