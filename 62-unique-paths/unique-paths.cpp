class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp){
        if(i==0 or j==0) return 0;
        if(i==1 && j==1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=  helper(i-1, j, dp);
        int left= helper(i, j-1, dp);
        return dp[i][j]= left+up; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }
                if(i==1 && j==1){
                    dp[i][j]=1;
                    continue;
                }
                int up= dp[i-1][j];
                int left= dp[i][j-1];
                dp[i][j]= up+left;
            }
        }
        return dp[m][n];
    }
};