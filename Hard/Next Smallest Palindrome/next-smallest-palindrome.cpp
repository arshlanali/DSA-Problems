//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int nums[], int n) {
	    // code here
	    bool change=1;
	    for(int i=0;i<n/2;i++){
	        if(nums[i]<nums[n-1-i]) change=1;
	        else if(nums[i]>nums[n-1-i]) change=0;
	        nums[n-i-1]=nums[i];
	    }
	    vector<int> ans(nums, nums+n);
	    bool carry=change;
	    int ind=n/2;
	    while(carry and ind < n){
            if(ans[ind] == 9){
               ans[ind] = 0;
               ans[n - ind - 1] = 0;
            }
            else{
               ++ans[ind];
               ans[n - ind - 1] = ans[ind];
               carry = 0;
            }
            
            ++ind;
        }
        
        if(carry){
           ans[0] = 1;
           ans.push_back(1);
        }
            
        return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends