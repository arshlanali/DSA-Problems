//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
int n, m;
     bool isvalid(int row, int col){
         if(row>=0 && col>=0 && col<m && row<n) return true;
         return false;
     }
    int Count(vector<vector<int> >& matrix) {
        n= matrix.size(), m= matrix[0].size();
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0) continue;
                int cnt=0;
                for(int d=-1; d<=1; d++){
                    for(int e=-1; e<=1; e++){
                        int row= i+d;
                        int col= j+e;
                        if(isvalid(row, col) && matrix[row][col]==0) cnt++;
                    }
                }
                if(!(cnt&1) && cnt){
                    res++;
                } 
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends