class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cos=0;
        int start=0;
        int n=cost.size();
        int cg=0;
        int cc=0;
        for(int i=0;i<n;i++)
        {
            cg+=gas[i];
            cc+=cost[i];
        }
        if(cc>cg)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            int dif=gas[i]-cost[i];
            cos+=dif;
            if(cos<0)
            {
                start=i+1;
                cos=0;
            }
        }
        return start;
    }
};