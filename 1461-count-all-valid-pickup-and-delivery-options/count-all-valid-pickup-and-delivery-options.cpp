class Solution {
public:
    int countOrders(int n) {
        if(n==1) return 1;
        int mod= 1e9+7;
        long long res=1;
        for(int i=2;i<=n;i++){
            int spaces= 2*i-1;
            int curres= (spaces*(spaces+1)/2)%mod;
            res*= (long long)curres;
            res%=mod;
        }
        return res;
    }
};