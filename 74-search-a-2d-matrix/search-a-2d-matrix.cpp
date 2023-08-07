class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // int rowl=0, rowh=matrix.size()-1, coll=0, colh= matrix[0].size();
        // while(rowl< rowh && coll< colh){
        //     int midr= (rowl+rowh)/2, midc= (coll+colh)/2;
            
        // }
        vector<int> vec;
        int n=mat.size(), m= mat[0].size();
        for(int i=0;i<n;i++){
            vec.push_back(mat[i][0]);
        }
        int lb= lower_bound(vec.begin(), vec.end(), target)- vec.begin();
        if(lb>n || lb<0) return false;
        if(lb<n && vec[lb]==target) return true;
        cout<<lb;
        if(lb>0) lb--;
        int l=0, h=m-1;
        while(l<=h){
            int mid= (l+h)/2;
            if(mat[lb][mid]==target) return true;
            else if(mat[lb][mid]<target) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};