class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h= nums.size()-1;
        while(l<=h){
            int mid= (l+h)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){ // left part sorted
                if(target>=nums[l]  && target<=nums[mid]){// element must be present in left
                    h=mid-1;
                }
                else{// target present in right unsorted part
                    l= mid+1; 
                }
            }
            else{// right part  of mid is sorted
             if(target>= nums[mid] && target<= nums[h]){ // present in the right sorted par
                 l=mid+1;
             }
                else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};