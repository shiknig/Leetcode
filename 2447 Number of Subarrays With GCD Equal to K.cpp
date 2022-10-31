class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            int x = nums[i];
            for(int j = i; j < n; ++j) {
                x = gcd(x, nums[j]);
                if(x == k)
                    ++ans;
            }
        }
        
        return ans;
    }
};
