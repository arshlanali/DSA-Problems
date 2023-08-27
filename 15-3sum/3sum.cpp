class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n= nums.size();
        sort(begin(nums), end(nums));
        int i=0;
        for(int i=0;i< n;i++){
            // if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k = n-1;
            while(j<k){
                int sum= nums[i]+ nums[j]+ nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp= {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    while (j<k && nums[j]==nums[j-1]) j++;
                    while (j< k && nums[k]== nums[k+1]) k--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};