class Solution {
public:
    int solve( int ind, int prev, vector<int>& arr,vector<vector<int>>& dp, int n){
        if(ind==n-1){
            if(prev==-1 || arr[prev]< arr[ind]) return 1; 
            else return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int skip= solve(ind+1, prev, arr, dp, n);
        int take=0;
        if(prev==-1 || arr[prev]< arr[ind]) take= 1+solve(ind+1, ind, arr, dp, n);
        return dp[ind][prev+1]= max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0, -1,nums, dp, n);
    }
};