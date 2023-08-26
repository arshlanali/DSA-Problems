class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        int n= pairs.size();
        vector<int> dp(n, 1);
        for(int ind=1;ind<n; ind++){
            for(int prev=0; prev<ind;prev++){
                int take=-1e9;
                if(pairs[prev][1]<pairs[ind][0]) take= 1+dp[prev];
                dp[ind]= max(dp[ind], take);
            }
        }
        return dp[n-1];
    }
};