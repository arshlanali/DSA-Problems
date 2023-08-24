class Solution {
private:
    string formline(int i, int j, int eachslotspace, int extraspace, vector<string> words, int maxwidth){

        string line;
        for(int k=i; k<j; k++){
            line+= words[k];
            if(k==j-1) continue;
            for(int z=1; z<= eachslotspace; z++) line+=" ";
            if(extraspace>0) {
                line+= " ";
                extraspace--;
            }
        }
        while(line.size()<maxwidth) line+=" ";
        return line;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxwidth) {
        vector<string> res;
        int i=0;
        int n= words.size();
        while(i<n){
            int lenwords= words[i].size(), lenslots=0;
            int j=i+1;
            while(j<n && lenwords + lenslots + words[j].size() + 1<= maxwidth){
                lenwords+= words[j].size();
                lenslots++;
                j++;
            }
            int remainingslots= maxwidth - lenwords;
            int eachslotspace= lenslots==0?0:remainingslots/lenslots;
            int extraspace= lenslots==0?0: remainingslots%lenslots;
            if(j==n) {
                eachslotspace=1;
                extraspace=0;
            }
            res.push_back(formline(i, j, eachslotspace, extraspace, words, maxwidth));
            i=j;
        }
        return res;
    }
};