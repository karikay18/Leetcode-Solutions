class Solution {
public:
    int helper(int k,vector<int>& piles)
    {
        int p=0;
        for(auto it:piles)
        {
            p+=ceil((double)it/k);
        }
        return p;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        if(h==n-1)return piles[n-1];
        sort(piles.begin(),piles.end());
        int l=1;
        int r=piles[n-1];
        int mid=-1;
        while(r>l)
        {
            mid=(l+r)/2;
            if(helper(mid,piles)>h)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;


    }
};