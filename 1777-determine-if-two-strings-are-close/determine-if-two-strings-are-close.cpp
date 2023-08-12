class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> firsthash(26,0), secondhash(26, 0);
        for(auto c:word1) firsthash[c-'a']++;
        for(auto c: word2) secondhash[c-'a']++;
        for(int i=0;i<26;i++){
            if(firsthash[i] && !secondhash[i]){
                return false;
            }
            else if(!firsthash[i] && secondhash[i]) return false;
        }
        sort(begin(firsthash), end(firsthash));
        sort(begin(secondhash), end(secondhash));
        for(int i=0;i<26;i++){
            if(firsthash[i]!=secondhash[i]){
                return false;
            }
        }
        return true;
    }
};