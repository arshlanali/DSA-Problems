class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n= garbage.size();
        vector<int> preSum;
        vector<int> mpg(3, -1);
        int g=0, t=0;
        preSum.push_back(travel[0]);
        for(int i=0;i<n;i++){
            g+= garbage[i].size();

            if(i<n-1 && i>0){
                int sum= preSum.back()+ travel[i];
                preSum.push_back(sum);
            }
            for(int j=0;j<garbage[i].size();j++){
                char c= garbage[i][j];
                if(c=='M') mpg[0]=i;
                else if(c=='P') mpg[1]=i;
                else mpg[2]=i;
                }
        }
        for(int i=0;i<3;i++){
            if(mpg[i]!=-1 && mpg[i]!=0) t+= preSum[mpg[i]-1];
        }
        int res= g+t;
        return res;

    }
};