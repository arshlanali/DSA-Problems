class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        for(int t=0;t<=target;t++){
            if(t%coins[0]==0) dp[0][t]=1;
            else dp[0][t]=0;
        }
        for(int ind=0;ind<n;ind++) dp[ind][0]=1;
        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=target;t++){
                int skip= dp[ind-1][t];
                int take=0;
                if(coins[ind]<=t){
                    take= dp[ind][t-coins[ind]];
                }
                dp[ind][t]= skip+take;
            }
        }
        return dp[n-1][target];
    }
};