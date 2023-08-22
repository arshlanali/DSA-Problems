class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n!=0){
            bool flag= (n%10)&1==1;
            if(flag)cnt++;
            n= n>>1;
        }
        return cnt;
    }
};