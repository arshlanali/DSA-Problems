class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int> hash, kash;
            for(int j=0;j<9;j++){
                if(hash.find(board[i][j])!=hash.end()){
                    cout<<i<<" "<<j;
                    return false;
                }
                if(board[i][j]!='.') hash[board[i][j]]++;
                if(kash.find(board[j][i])!=kash.end()){
                    cout<<i<<" "<<j;
                    return false;
                }
                if(board[j][i]!='.') kash[board[j][i]]++;
            }
        }
        int delrow[]={1, 2, 3};
        int delcol[]= {1, 2, 3};
        // cout<<delrow[0]<<" ";
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                int n= 3*delrow[r];
                int m= 3*delcol[c];
                unordered_map<int,int> hash;
                for(int i=n-3; i<n;i++){
                    for(int j=m-3;j<m;j++){
                        // cout<<n<<" "<<m<<" "<<endl;
                        if(hash.find(board[i][j])!=hash.end()){
                    // cout<<i<<" "<<j;
                    return false;
                }
                if(board[i][j]!='.') hash[board[i][j]]++;
                    }
                }
            }
        }
        return true;
    }
};