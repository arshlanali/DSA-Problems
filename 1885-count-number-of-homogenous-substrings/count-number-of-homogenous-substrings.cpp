class Solution {
public:
    int countHomogenous(string s) {
        int i=0, j=0;
        int n= s.size(), mod= 1e9+7;
        long long res=0;
        while(j<n){
            char c= s[i];
            while(j<n && c==s[j]) j++;
            int len= j-i;
            res += (len*1ll*(len+1)/2)%mod;
            i=j;
        }
        return res;
    }
};