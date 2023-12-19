class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        double res=1;
        if(nn<0)
        {
            nn=nn*(-1);
        }
        while(nn)
        {
            if(nn%2==0)
            {
                nn=nn/2;
                x=x*x;

            }
            else
            {
                nn=nn-1;
                res=res*x;
            }
        }
        if(n<0)res=1/res;
        return res;

    }
};