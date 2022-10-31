class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 1e9));
        dp[n][m-1]=1;
        dp[n-1][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j]=max(1, min(dp[i][j+1], dp[i+1][j])-a[i][j]);
            }
        }
        return dp[0][0];
    }
};