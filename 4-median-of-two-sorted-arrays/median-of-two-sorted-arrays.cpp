class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        int ele1 = -1;
        int ele2 = -1;
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                if (cnt == ind1) ele1 = nums2[j];
                if (cnt == ind2) ele2 = nums2[j];
                j++;
            } else {
                if (cnt == ind1) ele1 = nums1[i];
                if (cnt == ind2) ele2 = nums1[i];
                i++;
            }
            cnt++;
        }
        while (i < nums1.size()) {
            if (cnt == ind1) ele1 = nums1[i];
            if (cnt == ind2) ele2 = nums1[i];
            i++;
            cnt++;
        }
        while (j < nums2.size()) {
            if (cnt == ind1) ele1 = nums2[j];
            if (cnt == ind2) ele2 = nums2[j];
            j++;
            cnt++;
        }
        
        if (n % 2 == 1) {
            return ele1;
        }
        return (double)((double)ele1 + ele2) / 2;
    }
};
