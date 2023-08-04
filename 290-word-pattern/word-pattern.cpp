class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=s.size();
        unordered_map<string,char> hash;
        unordered_map<char,string> kash;
        int ind=0;
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && s[i]!=' ') temp+= s[i++];
            // cout<<temp<<" ";
            if(hash.find(temp)!=hash.end()){
                if(hash[temp]!=pattern[ind]) return false;
            }
            else{
                hash[temp]=pattern[ind];
                // cout<<ind<<" ";
            }
            if(kash.find(pattern[ind])!=kash.end()){
                if(kash[pattern[ind]]!=temp) return false;
            }
            else{
                kash[pattern[ind]]=temp;
                // cout<<ind<<" ";
            }
            ind++;
        }

        return ind<pattern.size()?false:true;
    }
};