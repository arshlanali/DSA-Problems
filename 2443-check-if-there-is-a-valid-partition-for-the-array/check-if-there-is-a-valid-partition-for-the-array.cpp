class Solution {
public:
    bool solve(int ind,vector<int>& nums,vector<int> &dp)
    {
        if(ind<0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        bool a=0,b=0,c=0;
        if(ind-1>=0 && nums[ind]==nums[ind-1]) a=solve(ind-2,nums,dp);
         if(ind-2>=0 && nums[ind]==nums[ind-1] && nums[ind-1]==nums[ind-2]) b=solve(ind-3,nums,dp);
          if(ind-2>=0 && nums[ind]==nums[ind-1]+1 && nums[ind-1]==nums[ind-2]+1) c=solve(ind-3,nums,dp);
          return dp[ind]=a|b|c;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(n-1,nums,dp);
    }
};