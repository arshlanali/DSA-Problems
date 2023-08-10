class Solution {
public:
    int solve(int ind, int target, vector<int> nums, vector<vector<int>>& dp){
        if(target==0) return 0;
        if(ind==0){
            if(target%nums[ind]==0) return target/nums[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int skip= solve(ind-1, target, nums, dp);
        int take=1e9;
        if(nums[ind]<= target) take= 1+solve(ind, target-nums[ind],nums, dp);
        return dp[ind][target]= min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        if(n==0) return -1;
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans= solve(n-1, amount, coins, dp);
        return ans>=1e9?-1:ans;
    }
};