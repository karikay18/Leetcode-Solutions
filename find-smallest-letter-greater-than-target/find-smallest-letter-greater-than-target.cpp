class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int s=0;
        int n=letters.size()-1;
        int e=n;
        int mid=-1;
        char ans=0;
        if(target<letters[0])
        {
            return letters[0];
        }
        else if(target>=letters[n])
        {
  
            return letters[0];
        }
        while(
            e>=s
        )
        {
            mid=(e+s)/2;
            if(target<letters[mid])
            {
                ans=letters[mid];
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
            return ans;

    }
};