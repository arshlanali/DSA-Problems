class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> fc;
        for(auto c: s) fc[c]++;
        unordered_set<int> st;
        int del=0;
        for(auto it: fc){
            while(st.find(it.second)!= st.end() && it.second!=0){
                del++;
                it.second--;
            }
            if(it.second!=0) st.insert(it.second);
        }
        return del;
    }
};