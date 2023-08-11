class Solution {
public:
    int change(int target, vector<int>& coins) {
        int n= coins.size();
        vector<int> prev(target+1, 0), curr(target+1, 0);
        for(int t=0;t<=target;t++) prev[t]= t%coins[0]==0;
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=target;t++){
                int skip= prev[t];
                int take=0;
                if(coins[ind]<=t){
                    take= curr[t-coins[ind]];
                }
                curr[t]= skip+take;
            }
            prev=curr;
        }
        return prev[target];
    }
};