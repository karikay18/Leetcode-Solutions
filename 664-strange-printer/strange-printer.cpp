class Solution {
public:
     int strangePrinter(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n, vector(n, INT_MAX));
        
        for(int i = n-1; i >= 0; i--){
            for(int dist = 0; i+dist < n; dist++){
                int j = i+dist;
                if(dist == 0){
                    //base case: one char
                    dp[i][j] = 1;
                }else if(dist == 1){
                    //base case: two chars
                    /*
                    if the two chars are the same, 
                    we need just one print,
                    o.w. we need two prints
                    */
                    dp[i][j] = 1 + (s[i] != s[j]);
                }else{
                    /*
                    split s[i...j] into s[i...k] and s[k+1...j]
                    note that k can be i!
                    */
                    for(int k = i; k <= j-1; k++){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - (s[k] == s[j]));
                    }
                }
            }
        }
        
        return dp[0][n-1];
     }
};