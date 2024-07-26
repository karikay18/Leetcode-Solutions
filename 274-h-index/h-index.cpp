class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        
        for(int i = 0; i < n; i++) {
            int remainingPapers = n - i; // papers with citations >= citations[i]
            if(citations[i] >= remainingPapers) {
                h = remainingPapers;
                break;
            }
        }
        
        return h;
    }
};
