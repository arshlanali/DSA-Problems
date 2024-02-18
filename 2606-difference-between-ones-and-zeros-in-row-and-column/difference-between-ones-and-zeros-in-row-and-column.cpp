#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<pair<int,int>> rows, cols;
        for(int i=0;i<n;i++){
            int ones=0, zeroes=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]) ones++;
                else zeroes++;
            }
            rows.push_back({ones, zeroes});
        }
        for(int j=0;j<m;j++){
            int ones=0, zeroes=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]) ones++;
                else zeroes++;
            }
            cols.push_back({ones, zeroes});
        }
        vector<vector<int>> diff(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int orr= rows[i].first, zr= rows[i].second;
                int oc= cols[j].first, zc= cols[j].second;
                diff[i][j]= orr+oc- zr-zc;
            }
        }
        return diff;

    }
};