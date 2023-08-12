//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> dp;
        dp.push_back(arr[0]);
        for(int i=0;i<n;i++){
                if(arr[i]<=dp.back()){
                    int pos= lower_bound(dp.begin(), dp.end(), arr[i])- begin(dp);
                    if(pos<n) dp[pos]=arr[i];
                }
                else dp.push_back(arr[i]);
        }
       return dp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends