//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > mat, int n)
    {
        vector<int> sum;
        for(int i=0; i<n; i++){
            int rowsum=0;
            int colsum=0;
             for(int j=0; j<n; j++) {
                 rowsum += mat[i][j];
                 colsum += mat[j][i];
             }
             sum.push_back(rowsum);
             sum.push_back(colsum);
        }
        int maxi= *max_element(sum.begin(), sum.end());
        int res=0;
        for(auto it: sum) res+= maxi-it;
        return res/2;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends