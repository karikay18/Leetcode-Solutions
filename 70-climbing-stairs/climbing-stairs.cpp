class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        int a=1, b=2, c;
        for(int i=3; i<=n; i++){
            c = a + b;
            a = b; b=c;
        }
        return c;
    }
};

// 0 1 2 3 5 8 13 21