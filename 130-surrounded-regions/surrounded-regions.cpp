class Solution {
public:
    int n, m;
    bool isValid(int row, int col){
        if(row<n && col<m && row>=0 && col>=0) return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col]=1;
        int delrow[]= {-1,0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int nrow= row+ delrow[i];
            int ncol= col+ delcol[i];
            if(isValid(nrow, ncol) && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n= board.size(), m= board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        //1st row and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O') dfs(0, j, board, vis);
            if(!vis[n-1][j] && board[n-1][j]=='O') dfs(n-1, j, board, vis);
        }
        // 1st col and last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O') dfs(i, 0, board, vis);
            if(!vis[i][m-1] && board[i][m-1]=='O') dfs(i, m-1, board, vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};