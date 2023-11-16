class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        int n= nums.size();
        for(int i=0;i<n;i++){
            char c= nums[i][i];
            res+= c=='0'?'1':'0';
        }
        return res;
    }
};