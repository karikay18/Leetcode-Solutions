class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        int prefix_n[n+1];
        int postfix_y[n+1];
        prefix_n[0] = 0;
        postfix_y[n] = 0;
        for(int i=1;i<n+1;i++)
        {
            prefix_n[i]=prefix_n[i-1];
            if(customers[i-1]=='N')
            {
                prefix_n[i]+=1;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            postfix_y[i]=postfix_y[i+1];
            if(customers[i]=='Y')
            {
                postfix_y[i]+=1;
            }
        }
        int min_p=INT_MAX;
        int idx=0;
       
        for(int i=0;i<n+1;i++)
        {
           int penalty=postfix_y[i]+prefix_n[i];
           if(penalty<min_p)
           {
               min_p=penalty;
               idx=i;
           }
        }
        return idx;
    }
};