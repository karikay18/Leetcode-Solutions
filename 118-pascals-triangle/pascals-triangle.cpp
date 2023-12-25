class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>>res;
     int n=0;
     for(int j=1;j<=numRows;j++)
     {
        vector<int>v;
         v.push_back(1);
         long long ans=1;
         for(int i=1;i<j;i++)
         {
            ans=ans*(j-i);
            ans=ans/i;
            v.push_back(ans);
         }
         res.push_back(v);
         n++;
     }
        


     
     
     return res;       
    }
};