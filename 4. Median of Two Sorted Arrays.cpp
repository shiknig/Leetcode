class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // int n1,n2;
        if(nums2.size()<nums1.size())
        {
            swap(nums1,nums2);
        }
        
        int l=0;int r=nums1.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            int mid1=(nums1.size()+nums2.size()+1)/2-mid;
           // cout<<1<<endl;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
           // cout<<1<<endl;
            if((mid-1)>=0)
            l1=nums1[mid-1];
            if((mid1-1)>=0)
            l2=nums2[mid1-1];
            if(mid<nums1.size())
            r1=nums1[mid];
            if(mid1<nums2.size())
            r2=nums2[mid1];
            //cout<<1<<endl;
            if(r2>=l1 && l2<=r1)
            {
                if((nums1.size()+nums2.size())%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2);
            }
            else if(l1>r2)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
            
        }
        return 0.0;
        
        
    }
};