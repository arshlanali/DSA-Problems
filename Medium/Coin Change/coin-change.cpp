//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
#define ll long long
  public:
    long long int count(int coins[], int n, int target) {
        vector<vector<long long>> dp(n, vector<ll>(target+1, 0));
        for(int t=0;t<=target;t++){
            if(t%coins[0]==0) dp[0][t]=1;
            else dp[0][t]=0;
        }
        for(int ind=0;ind<n;ind++) dp[ind][0]=1;
        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=target;t++){
                long long skip= dp[ind-1][t];
                long long take=0;
                if(coins[ind]<=t){
                    take= dp[ind][t-coins[ind]];
                }
                dp[ind][t]= skip+take;
            }
        }
        return dp[n-1][target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends