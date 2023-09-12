class Solution {
int n, m, sz;
public:
    bool isValid(int row, int col){
        if(row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }
    bool dfs(int ind, int row, int col, vector<vector<char>>& board, string word, vector<vector<int>>& vis){
        if(ind==sz) return true;
        vis[row][col]=1;
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        for(int i=0;i<4; i++){
            int nrow= row+ delrow[i];
            int ncol= col+ delcol[i];
            if(isValid(nrow, ncol) && word[ind]== board[nrow][ncol] && !vis[nrow][ncol]){
                if(dfs(ind+1, nrow, ncol, board, word, vis)) return true;
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        sz= word.size();
        n= board.size(), m= board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<vector<int>> vis(n, vector<int>(m));
                if(board[i][j]== word[0]){
                    if(dfs(1, i, j, board, word, vis)) return true;
                }
            }
        }
        return false;
    }
};