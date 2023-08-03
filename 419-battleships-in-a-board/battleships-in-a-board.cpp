class Solution {
public:
    int n, m;
    bool isvalid(int i, int j){
        if(i<n && j<m && j>=0 && i>=0) return true;
        return false;
    }
    void vdfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        if(isvalid(i+1, j) && board[i+1][j]=='X') vdfs(board, vis, i+1, j);
    }
    void hdfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        if(isvalid(i, j+1) && board[i][j+1]=='X') hdfs(board, vis, i, j+1);
    }
    int countBattleships(vector<vector<char>>& board) {
        n= board.size();
        m= board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    cnt++;
                    if(isvalid(i+1, j) && board[i+1][j]=='X') vdfs(board, vis, i, j);
                    else if(isvalid(i, j+1) && board[i][j+1]=='X') hdfs(board, vis, i, j);
                    else vis[i][j]=1;
                    cout<<cnt<<" "<< i<<" "<<j<<endl;
                }
            }
        }
        return cnt;
    }
};