class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    } 
    int maxVowels(string s, int k) {
        int n= s.size();
        int vcnt=0, maxvcnt=0;
        int i=0, j=0;
        while(j<n){
            if(isVowel(s[j])) vcnt++;
            while(j-i+1>k){
                if(isVowel(s[i])) vcnt--;
                i++;
            }
            maxvcnt= max(maxvcnt, vcnt);
            j++;
        }
        return maxvcnt;
    }
};