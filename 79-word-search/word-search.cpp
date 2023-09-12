class Solution {
int n, m, sz;
public:
    bool isValid(int row, int col){
        if(row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }
    bool dfs(int ind, int row, int col, vector<vector<char>>& board, string word){
        if(ind==sz) return true;
        if(!isValid(row, col) || word[ind]!=board[row][col]) return false;
        char ori= board[row][col];
        board[row][col]=' ';
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        bool found= false;
        for(int i=0;i<4;i++){
            int nrow= row+delrow[i];
            int ncol= col+ delcol[i];
            found|= dfs(ind+1, nrow, ncol, board, word);
        }
        board[row][col]=ori;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        sz= word.size();
        n= board.size(), m= board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]== word[0]){
                    if(dfs(0, i, j, board, word)) return true;
                }
            }
        }
        return false;
    }
};