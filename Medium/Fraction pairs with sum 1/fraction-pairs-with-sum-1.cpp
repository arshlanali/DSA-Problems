//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<string,int> hash;
        int cnt=0;
        for(int i=0;i<n;i++){
            int k= gcd(numerator[i], denominator[i]);
            int num= numerator[i]/k;
            int den= denominator[i]/k;
            string key= to_string(num)+"/"+to_string(den);
            string tofind= to_string(den-num)+"/"+to_string(den);
            if(hash.find(tofind)!=hash.end()){
                cnt+= hash[tofind];
            }
            hash[key]++;
        }  
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends