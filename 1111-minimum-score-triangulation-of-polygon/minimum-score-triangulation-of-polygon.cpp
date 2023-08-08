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
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=1;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini= INT_MAX;
                for(int k=i;k<=j-1;k++){
                    int ans= solve(i, k, values, dp) + values[i-1]*values[k]*values[j] + solve(k+1, j, values, dp);
                    mini=min(ans, mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n-1];
    }
};