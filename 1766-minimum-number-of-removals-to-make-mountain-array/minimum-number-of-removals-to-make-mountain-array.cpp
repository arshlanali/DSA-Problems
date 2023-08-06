class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n= arr.size();
        vector<int> dp(n,1);
        for(int ind=1;ind<n;ind++){
            for(int prev=0; prev<ind; prev++){
                if(arr[ind]>arr[prev] && dp[ind]< dp[prev]+1) dp[ind] = dp[prev]+1;
            }
        }
        int maxlen=0;
        vector<int> cp(n,1);
        for(int ind=n-2;ind>=0;ind--){
            for(int prev=n-1; prev>=ind; prev--){
                if(arr[ind]>arr[prev] && cp[ind]< cp[prev]+1) cp[ind] = cp[prev]+1;
            }
            if(dp[ind]>1 && cp[ind]>1)
            maxlen= max(maxlen, dp[ind]+cp[ind]-1);
        }
        return n-maxlen;
    }
};