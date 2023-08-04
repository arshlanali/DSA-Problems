class Solution {
public:
    int n, m;
    bool isValid(int row, int col){
        if(row>=0 && col>=0 && col<m && row<n) return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size(), m= mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    vis[i][j]=1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while(q.size()){
            auto p= q.front();
            q.pop();
            int row= p.first.first;
            int col= p.first.second;
            int step= p.second;
            dis[row][col]=step;
            int delrow[]={-1, 0, 1, 0};
            int delcol[]= {0, 1,  0, -1};
            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol= col+ delcol[i];
                if(isValid(nrow, ncol) && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, step+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return dis;
    }
};