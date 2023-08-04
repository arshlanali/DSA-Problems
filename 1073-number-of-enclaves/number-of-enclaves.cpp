class Solution {
public:
    int n, m;
    bool isValid(int row, int col){
        if(row<n && row>=0 && col<m && col>=0) return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col]=1;
        int delrow[]={-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            if(isValid(nrow, ncol) && !vis[nrow][ncol] && grid[nrow][ncol]) dfs(nrow, ncol, grid, vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n= grid.size(), m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // 1st row and last row
        for(int j=0;j<m ;j++){
            if(!vis[0][j] && grid[0][j]==1) dfs(0, j, grid, vis);
            if(!vis[n-1][j] && grid[n-1][j]==1) dfs(n-1, j, grid, vis);
        }
        //1st col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1) dfs(i, 0, grid, vis);
            if(!vis[i][m-1] && grid[i][m-1]==1) dfs(i, m-1, grid, vis);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                if(grid[i][j] && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};