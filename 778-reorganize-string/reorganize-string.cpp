class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> hash;
        for(auto c: s) hash[c]++;
        priority_queue<pair<int, char>> pq;
        int n= s.size();
        for(auto it:hash) {
            if(it.second>(n/2+n%2)) return "";
            pq.push({it.second, it.first});
        }
        string form="";
        while(pq.size()>=2){
            char c= pq.top().second;
            int val= pq.top().first;
            pq.pop();
            char bc= pq.top().second;
            int bval= pq.top().first;
            pq.pop();
            if(val-1) pq.push({val-1, c});
            if(bval-1) pq.push({bval-1, bc});
            form+=c;
            form+= bc;
        }
        if(pq.size()) form+= pq.top().second;
        return  form;
    }
};