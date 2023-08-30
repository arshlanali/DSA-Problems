class Solution {
public:
int n;
    int solve(int ind, int target, vector<int> nums, vector<int>& dp){
        if(ind<0 || target<=0) return target==0;
        if(dp[target]!=-1) return dp[target];
        int skip= solve(ind-1, target, nums, dp);
        int take=0;
        if(nums[ind]<=target) take= solve(n-1, target-nums[ind], nums, dp);
        return dp[target]= skip+take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n= nums.size();
        vector<int> dp(target+1, -1);
        return solve(n-1, target, nums, dp);
    }
};