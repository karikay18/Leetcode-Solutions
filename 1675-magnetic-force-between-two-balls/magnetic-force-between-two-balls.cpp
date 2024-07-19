class Solution {
public:
bool  distisokay(vector<int>& position, int m,int mid)
{
    int cnt=1;
    int previd=0;
    for(int i=1;i<position.size();i++)
    {
        if(position[i]-position[previd]>=mid)
        {
            cnt++;
            previd=i;
        }
    }

    return cnt>=m;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1;
        int r=position[position.size()-1];
        int ans=-1;
        while(r>=l)
        {
            int mid=(r+l)/2;
            if(distisokay(position,m,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};