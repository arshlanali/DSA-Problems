class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.size();
        for(int l= n/2; l>=1; l--){
            if(n%l==0){
                int times= n/l;
                string sub= s.substr(0,l);
                string formed="";
                while(times--) formed+= sub;
                if(formed==s) return true;
            }
        }
        return false;
    }
};