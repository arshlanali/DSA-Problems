//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
int N;
    long long solve(int ind, int last, int r[], int g[], int b[], vector<vector<long long>>& dp){
        if(ind>=N) return (long long)0;
        if(dp[ind][last]!=-1) return dp[ind][last];
        int mincost= INT_MAX;
        if(last==3){
            return dp[ind][last]= min(r[0]+ solve(1, 0, r, g, b, dp), min(g[0] + solve(1, 1, r, g, b, dp), b[0]+ solve(1, 2, r, g, b, dp)));
        }
        else if(last==0){
            return dp[ind][last]= min(g[ind]+ solve(ind+1, 1,r, g, b, dp), b[ind] +  solve(ind+1, 2,r, g, b, dp));
        }
        else if(last==1){
            return dp[ind][last]= min(r[ind]+solve(ind+1, 0,r, g, b, dp), b[ind] + solve(ind+1, 2,r, g, b, dp));
        }
        else if(last==2){
            return dp[ind][last]= min(r[ind]+solve(ind+1, 0,r, g, b, dp), g[ind] + solve(ind+1, 1,r, g, b, dp));
        }
    }
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        N=n;
        vector<vector<long long>> dp(n, vector<long long>(4, (long long)(-1)));
        return solve(0, 3, r, g, b, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends