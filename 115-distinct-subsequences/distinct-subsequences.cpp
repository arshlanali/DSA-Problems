class Solution {
public:
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]= solve(i-1, j-1, s, t, dp)+ solve(i-1, j, s, t, dp);
        else return dp[i][j]= solve(i-1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n= s.size(), m= t.size();
        // vector<vector<double>> dp(n+1, vector<double>(m+1,0));
        // return solve(n-1, m-1, s, t, dp);
        // for(int i=0;i<=n;i++) dp[i][0]=1;
        // for(int j=1;j<=m;j++) dp[0][j]=0;
        vector<double> prev(m+1,0), curr(m+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]= prev[j-1]+ prev[j];
                else curr[j]= prev[j];
            }
            prev= curr;
        }
        return (int)prev[m];
    }
};