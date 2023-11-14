class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.size();
        set<char> toCheck;
        vector<int> first(26, -1), last(26, -1);
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1) first[s[i]-'a']=i;
            else{
                last[s[i]-'a']=i;
                toCheck.insert(s[i]);
            }
        }
        int cnt=0;
        
        for(auto it:toCheck){
            unordered_set<char> st;
            int start= first[it-'a']+1;
            int end= last[it-'a']-1;
            for(int i= start;i<=end;i++) st.insert(s[i]);
            cnt+= st.size();
        }
        return cnt;
    }
};