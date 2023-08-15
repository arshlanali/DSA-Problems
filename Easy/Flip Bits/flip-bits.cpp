//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
         int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                cnt++;
                a[i]=-1;
            }else{
                a[i]=1;
            }
        }
        int mx=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum<0){
                sum=0;
            }
            mx=max(mx,sum);
        }
        return cnt+mx;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends