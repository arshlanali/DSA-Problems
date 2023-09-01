class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxlen=0, n= words.size();
        vector<int> bits(n);
        for(int i=0;i<n;i++){
            for(auto c:words[i]){
                bits[i]|= 1<<(c-'a');
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n; j++){
                if((bits[i] & bits[j])==0){
                    maxlen= max(maxlen, (int)(words[i].size()*words[j].size()));
                }
            }
        }
        return maxlen;
    }
};