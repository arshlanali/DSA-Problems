class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n= dist.size();
        vector<double> time;
        for(int i=0;i<n;i++){
            double t= (double)dist[i]/(double)speed[i];
            time.push_back(t);
        }
        sort(time.begin(), time.end());
        for(auto it:time) cout<<it<<" ";
        int kills=1;
        double t=1;
        for(int i=1;i<n;i++){
            if(t>=time[i]) break;
            else t++;
        }
        return (int)t;

    }
};