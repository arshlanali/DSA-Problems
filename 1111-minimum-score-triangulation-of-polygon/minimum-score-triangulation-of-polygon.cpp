class Solution {
public:
int n;
    int solve(int i, int j, vector<int> values, vector<vector<int>> & dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini= INT_MAX;
        for(int k=i;k<=j-1;k++){
            int ans= solve(i, k, values, dp) + values[i-1]*values[k]*values[j] + solve(k+1, j, values, dp);
            mini=min(ans, mini);
        }
        return dp[i][j]=mini;
    }
    int minScoreTriangulation(vector<int>& values) {
        n= values.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(1, n-1, values, dp);
    }
};