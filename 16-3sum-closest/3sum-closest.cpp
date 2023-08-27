class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        if(n<3) return 0;
        sort(begin(nums), end(nums));
        int closest=nums[0]+ nums[1] + nums[2];
        int res=0;
        for(int i=0; i<n-2; ){
            int j=i+1, k= n-1;
            while(j<k){
                int sum= nums[i]+ nums[j] + nums[k];
                if(abs(target-sum)<abs(target-closest)) {
                    closest = sum;
                }
                if(sum> target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else return target;
                // cout<<sum<<" "<<mindiff<<" "<<res<<endl;
            }
            i= upper_bound(begin(nums), end(nums), nums[i])- begin(nums);
        }
        return closest;
    }
};