class Solution {
public:
    bool judgeCircle(string moves) {
        int up=0, left=0, n=moves.size();
        for(int i=0;i<n;i++){
            char c= moves[i];
            if(c=='U') up++;
            else if(c=='D') up--;
            else if(c=='L') left--;
            else if(c=='R') left++;
        }
        return up==0 && left==0;
    }
};