class Solution {
public:
int n;
    int solve(int ind, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp){
        if(ind==n-1){
            if(prev==-1) return 1;
            if(pairs[ind][0]>pairs[prev][1]) return 1;
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int skip= 0+ solve(ind+1, prev, pairs, dp);
        int take= -1e9;
        if(prev==-1 || pairs[ind][0]>pairs[prev][1]) take= 1+ solve(ind+1, ind, pairs, dp);
        return dp[ind][prev+1]= max(skip, take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        n= pairs.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(0, -1, pairs, dp);
    }
};