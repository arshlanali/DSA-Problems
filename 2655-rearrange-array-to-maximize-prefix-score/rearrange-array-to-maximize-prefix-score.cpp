class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long sum=0;
        sort(rbegin(nums), rend(nums));
        int n= nums.size(), cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<=0) break;
            else cnt++;
        }
        return cnt;
    }
};