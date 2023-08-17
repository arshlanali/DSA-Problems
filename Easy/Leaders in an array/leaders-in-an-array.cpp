//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    vector<int> leaders(int a[], int n){
        stack<int> st;
        st.push(a[n-1]);
        vector<int> vec;
        vec.push_back(a[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size() && a[i]>=st.top()) st.pop();
            if(st.empty()) vec.push_back(a[i]);
            st.push(a[i]);
        }
        reverse(vec.begin(), end(vec));
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends