class Solution {
public:
int n;
    void solve(int ind,int target,vector<int>& nums,vector<int>& temp, vector<vector<int>>& res){
        if(target==0){
            res.push_back(temp);
            return ;
        }
        if(target<0) return ;
        for(int i=ind; i<n; i++){
            if(i!= ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1, target-nums[i], nums, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(begin(candidates), end(candidates));
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, target, candidates, temp, res);
        
        return res;
    }
};