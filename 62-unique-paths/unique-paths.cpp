class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n+1), curr(n+1);
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    curr[j]=0;
                    continue;
                }
                if(i==1 && j==1){
                    curr[j]=1;
                    continue;
                }
                int up= prev[j];
                int left= curr[j-1];
                curr[j]= up+left;
            }
            prev= curr;
        }
        return prev[n];
    }
};