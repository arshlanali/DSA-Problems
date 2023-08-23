//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//     int n, m;
//     bool isvalid(int row, int col){
//         if(row<0 or col<0 or row>=n or col>=m) return false;
//         return true;
//     }
//     bool dfs(int row, int col, int ind, vector<vector<char>> grid, string word, vector<vector<int>>&  vis){
//         if(ind==word.size()-1) return true;
//         vis[row][col]=1;
//         for(int i=-1;i<=1; i++){
//             for(int j=-1 ; j<=1; j++){
//                 if(i==0 && j==0) continue;
//                 int nrow= row+i;
//                 int ncol= col+ j;
//                 if(isvalid(nrow, ncol,) && !vis[nrow][ncol] && grid[nrow][ncol]==word[ind]){
//                     if(dfs(nrow, ncol,ind+1, grid, word, vis)) return true;
//                 }
//             }
//         }
//         return false;
//     }
// 	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
// 	    vector<vector<int>> res;
// 	    n= grid.size(), m= grid[0].size();
	    
// 	    for(int i=0;i<n;i++){
// 	        for(int j=0;j<m;j++){
// 	            if(grid[i][j]==word[0]){
// 	                vector<vector<int>> vis(n, vector<int>(m, 0));
// 	                if(dfs(i, j, 1,grid, word, vis)){
// 	                    res.push_back({i, j});
// 	                }
// 	            }
// 	        }
// 	    }
// 	    return res;
// 	}
 bool dfs(int i, int j, vector<vector<char>> &grid, string &word, int k, int n, int m, int d1, int d2) {
        k++;
        if(k==word.size()) return true;
        int ni=i+d1, nj=j+d2;
        if(ni>=0 and ni<n and nj>=0 and nj<m and grid[ni][nj]==word[k]) return dfs(ni,nj,grid,word,k,n,m,d1,d2);
        return false;
    }
    
public:
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        // Code here
        vector<vector<int>> res;
        int n=grid.size(), m=grid[0].size(), o=word.size()-1;
        int dx[] = {-1,-1,1,1,0,0,-1,1};
        int dy[] = {-1,1,1,-1,-1,1,0,0};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==word[0]) {
                    for(int it=0; it<8; it++) {
                        if(dfs(i,j,grid,word,0,n,m,dx[it],dy[it])) {
                            res.push_back({i,j});
                            break;
                        }
                    }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends