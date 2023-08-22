class Solution {
public:
int n, m;
    bool isvalid(int row, int col){
        if(row>=0 && col<m && row<n && col>=0) return true;
        return false;
    }
    void dfs(int row, int col, vector<vector<int>>& land, vector<vector<int>>& vis, int& ansi, int& ansj){
        vis[row][col]=1;
        int delrow[]={-1, 0, 1, 0}, delcol[]= {0, 1, 0, -1};
        for(int i=0;i<4; i++){
            int nrow= row + delrow[i];
            int ncol= col + delcol[i];
            if(isvalid(nrow, ncol) && land[nrow][ncol] && !vis[nrow][ncol]) {
                dfs(nrow, ncol, land, vis, ansi, ansj);
                ansi= max(ansi, nrow);
                ansj= max(ansj, ncol);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        n= land.size(), m= land[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                vector<int> vec;
                if(land[i][j] && !vis[i][j]){
                    vec.push_back(i);
                    vec.push_back(j);
                    int ansi=i, ansj=j;
                    dfs(i, j, land, vis, ansi, ansj);
                    vec.push_back(ansi);
                    vec.push_back(ansj);
                }
                if(vec.size()) res.push_back(vec);
            }
        }
        return res;
    }
};