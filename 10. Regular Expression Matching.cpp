class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.size(), m=s.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, 0));
        dp[0][0]=1;
        
        for(int i=2;i<=n;i++) {
            if(p[i-1]=='*' && dp[i-2][0]) dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    if(i-2>=0 && p[i-2]!='.' && p[i-2]!=s[j-1]) dp[i][j]=dp[i-2][j];
                    else dp[i][j]=((i-2>=0 && (dp[i-2][j] || dp[i-2][j-1])) || dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};