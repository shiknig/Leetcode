class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="")
            return "";
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=1;
        }
        int ans=1,start=0,end=0;
        for(int i=0;i<s.size()-1;i++)
        {
             if(s[i]==s[i+1])
                 dp[i][i+1]=1;
             else
                 dp[i][i+1]=0;
            if(dp[i][i+1]>0)
                    {
                        if(2>ans){
                        ans=max(ans,2);
                        start=i;end=i+1;
                        }
                    } 
        }
        
        for(int k=3;k<=s.size();k++)
        {
            for(int i=0;i<s.size()-k+1;i++)
            {
                int j=i+k-1;
                
                
                    //cout<<i<<" "<<j<<endl;
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                    else
                        dp[i][j]=0;
                    if(dp[i][j]>0)
                    {
                        if(j-i+1>ans){
                            
                        ans=max(ans,(j-i+1));
                        start=i;end=j;
                        }
                    } 
                        
                
            }
        }
        cout<<start<<" "<<end<<endl;
        string t="";
        for(int i=start;i<=end;i++)
            t+=s[i];
        return t;
    }
};