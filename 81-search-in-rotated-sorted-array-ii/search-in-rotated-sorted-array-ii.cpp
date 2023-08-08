class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l= 0, h= nums.size()-1;
        while(l<=h){
            int mid= (l+h)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[l] && nums[mid]==nums[h]) l++, h--;
            else if(nums[mid]>=nums[l]){// left part sorted
                if(nums[l]<=target && nums[mid]>=target) h=mid-1;
                else l=mid+1;
            }
            else{// right part sorted
                if(nums[h]>=target && nums[mid]<=target) l= mid+1;
                else h=mid-1;
            }
            cout<<mid<<" ";
        }
        return false;
    }
};