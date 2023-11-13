class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c== 'i'|| c=='o' || c=='u' || c=='A' || c=='E' || c== 'I' || c== 'O' || c== 'U') return true;
        return false;
    }
    string sortVowels(string s) {
        int n= s.size();
        vector<int> vow;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])) vow.push_back(s[i]);
        }
        sort(vow.begin(), vow.end());
        int ind=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])) s[i]= vow[ind++];
        }
        return s;
    }
};