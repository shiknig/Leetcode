class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int mn=0;
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++)
        {
            l[i]=mn;
            mn=max(mn,height[i]);
            
        }
        
        mn=0;
         for(int i=n-1;i>=0;i--)
        {
            r[i]=mn;
            mn=max(mn,height[i]);
            
        }
        int ans=0;
         for(int i=0;i<n;i++)
        {
            if(height[i]<min(l[i],r[i]))
            {
                ans+=min(l[i],r[i])-height[i];
            }
            
        }
        return ans;
    }
};
