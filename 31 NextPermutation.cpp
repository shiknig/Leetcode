class Solution {
public:
    void swap(vector<int>&nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),ix=n-1;
        int mx=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<mx)
            {
                ix=i;
                break;
            }
            mx=nums[i];
        }
        if(ix==n-1)
        {
            reverse(nums.begin(),nums.end());
        }
        int idx=ix;
        int tmp=nums[ix];
        int mn=INT_MAX;
        
        for(int i=ix+1;i<n;i++)
        {
            if(nums[i]>tmp && nums[i]-tmp<=mn)
            {
                mn=nums[i]-tmp;
                idx=i;
            }
        }
        //cout<<ix<<idx;
        //swap(nums[ix],nums[idx]);
        swap(nums,ix,idx);
        reverse(nums.begin()+ix+1,nums.end());
        
    }
     
};
