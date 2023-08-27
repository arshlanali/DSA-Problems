class Solution {
public:
int n;
    void solve(int ind, vector<int> nums, vector<int> output, vector<vector<int>>& res){
        res.push_back(output);
        for(int i=ind; i<n; i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(i+1, nums, output, res);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n= nums.size();
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        vector<int> output;
        solve(0, nums, output, res); 
        return res;
    }
};