class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        int x=time%(n+(n-2));
        if(x<n) return x+1;
        else return 2*n-x-1;
        return -1;
        
    }
};