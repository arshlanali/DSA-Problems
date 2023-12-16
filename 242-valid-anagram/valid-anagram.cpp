class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26);
        for(auto it: s) hash[it-'a']++;
        for(auto it:t) hash[it-'a']--;
        for(auto it: hash) if(it) return false;
        return true;
    }
};