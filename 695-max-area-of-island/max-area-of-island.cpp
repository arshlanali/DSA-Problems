class Solution {
public:
    int n, m;
    bool isValid(int row, int col){
        if(row<0 or col<0 or row>=n or col>=m) return false;
        return true;
    }
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& cnt){
        vis[row][col]=1;
        cnt++;
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            if(isValid(nrow, ncol) && grid[nrow][ncol] && !vis[nrow][ncol]) dfs(nrow, ncol, grid, vis, cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n= grid.size(), m= grid[0].size();
        int maxcnt=0;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(!vis[i][j] && grid[i][j]){
                    dfs(i, j, grid , vis, cnt);
                    maxcnt=max(cnt, maxcnt);
                }
            }
        }
        return maxcnt;
    }
};