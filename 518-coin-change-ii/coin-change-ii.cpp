class Solution {
public:
    int solve(int ind, int target, vector<int> coins, vector<vector<int>>& dp){
        if(target==0) return 1;
        if(ind==0){
            if(target%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int skip= solve(ind-1, target, coins, dp);
        int take=0;
        if(coins[ind]<=target){
            take= solve(ind, target-coins[ind], coins, dp);
        }
        return dp[ind][target]=skip+take;
    }
    int change(int amt, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amt+1, -1));
        return solve(n-1, amt, coins , dp);
    }
};