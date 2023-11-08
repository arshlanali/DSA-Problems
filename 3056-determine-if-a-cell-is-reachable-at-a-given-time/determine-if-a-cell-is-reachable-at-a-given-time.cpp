class Solution {
public:
    bool isValid(int row, int col, int sx, int sy, int fx, int fy){
        if(row<=fx && row>=sx && col>=sy && col<=fy) return true;
        return false;
    }
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x= abs(fx-sx);
        int y= abs(fy-sy);
        int g= max(x, y);
        if(g>t || (g==0 && (t<2 && t>0))) return false;
        return true;
    }
};