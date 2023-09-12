class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for(auto c:s) freq[c-'a']++;
        sort(begin(freq), end(freq));
        int del=0;
        for(int i=24;i>=0 && freq[i]>0;i--){
            if(freq[i]>=freq[i+1]){
                del+= freq[i]- max(0,freq[i+1]-1);
                freq[i]= max(0,freq[i+1]-1);
            }
        }
        return del;
    }
};