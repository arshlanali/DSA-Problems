class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // vector<int> col;
        int n= matrix.size(), m= matrix[0].size();
        // for(int i=0; i<n;i++){
        //     col.push_back(matrix[i][0]);
        // }
        // if(n==1 && m==1) return matrix[0][0]==target;
        // // for(auto it: col) cout<<it<<" ";
        // int i= lower_bound(begin(col), end(col) , target)- begin(col);
        // cout<<"i "<< i<<" ";
        // if(i>=n) return false;
        // if(col[i]==target) return true;
        // int pos=pos= lower_bound(begin(matrix[i]), end(matrix[i]), target)- begin(matrix[i]);;
        // while(i>=0 && matrix[i][pos]!=target){
        //     i--;
        //     pos= lower_bound(begin(matrix[i]), end(matrix[i]), target)- begin(matrix[i]);
        // }
        
        // cout<<"pos "<< pos<<" ";
        // return pos<n && matrix[i][pos]==target;

        int row = 0, col= m-1;
        while(row<n && col>=0){
            if(target==matrix[row][col]) return true;
            else if(target<matrix[row][col]) col--;
            else row++;
        }
        return false;
    }
};