class Solution {
public:
    bool possible(vector<int>v,int day,int m, int k)
    {
        int cnt=0;
        int n=v.size();
        int res=0;
        for(int i = 0; i < n; i++) {
    if(v[i] <= day) {
        cnt++;
    }
    else {
        res += (cnt/k);
        cnt = 0;
    }
}
        res+=(cnt/k);
        return res>=m;


    }
    int minDays(vector<int>& v, int m, int k) {
        long long val=m*1ll*k*1ll;
        int n=v.size();
        if(val>n)return -1;
        int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, v[i]);
        maxi = max(maxi, v[i]);
    }
    int l=mini;
    int r=maxi;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(possible(v,mid,m,k))
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    } return l;


        
    }
};