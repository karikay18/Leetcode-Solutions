class Solution {
public:
    int maxArea(vector<int>& height) {
     int j=height.size()-1;
     int i=0;
     int maxa=INT_MIN;
     while(i<j) 
     {
        int a=(j-i)*min(height[i],height[j]);
        maxa=max(maxa,a);
        if(height[i]>height[j])
        {
            j--;
        }
        else
        {
            i++;
        }
     }  
     return maxa;
    }
};