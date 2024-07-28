class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(j>i)
        {
            int sum =numbers[j]+numbers[i];
            if(sum==target)
            {
                break;
            }
            if(sum>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {i+1,j+1};
    }
};