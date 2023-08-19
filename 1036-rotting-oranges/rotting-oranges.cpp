class Solution {
public:
    int n, m;
    bool isValid(int row, int col){
        if(row<0 || col<0 || row>=n || col>= m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n= grid.size(), m= grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int cntfresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) q.push({{i, j},0});
                else if(grid[i][j]==1) cntfresh++;
            }
        }
        int maxtime= 0;
        int delrow[]= {-1, 0, 1, 0};
        int delcol[]= {0, 1, 0, -1};
        int cnt=0;
        while(q.size()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int time= q.front().second;
            q.pop();
            maxtime= max(maxtime, time);
            for(int i=0;i<4; i++){
                int nrow= row + delrow[i];
                int ncol= col+ delcol[i];
                if(isValid(nrow, ncol) && grid[nrow][ncol]==1) {
                    q.push({{nrow, ncol}, time+1});
                    grid[nrow][ncol]=2;
                }
            }
        }
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++) if(grid[i][j]==1) return -1;
        }
        return maxtime;
    }
};