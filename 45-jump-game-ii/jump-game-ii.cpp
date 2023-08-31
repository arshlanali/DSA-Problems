class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        int currend=0, maxend= nums[0], jump=0;
        for(int i=1;i<n;i++){
            if(i>maxend) return -1;
            if(i>currend){
                jump++;
                currend=maxend;
            }
            maxend= max(maxend, nums[i]+i);
        }
        return jump;
    }
};