class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n= dist.size();
        vector<float> time;
        for(int i=0;i<n;i++){
            float t= (float)dist[i]/(float)speed[i];
            time.push_back(t);
        }
        sort(time.begin(), time.end());
        for(auto it:time) cout<<it<<" ";
        int kills=1;
        float t=1;
        for(int i=1;i<n;i++){
            if(t>=time[i]) break;
            t++;
        }
        return (int)t;

    }
};