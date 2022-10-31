class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        
        long long ans = 0, pow = 1;
        int sum = 0;
        for(char ch : s)
            sum += ch - '0';
        
        int idx = 0;
        while(idx < s.length() && s[idx] == '0')
            ++idx, pow *= 10;
        while(sum > target) {
            ans += pow * (10 - (s[idx] - '0'));
            sum -= s[idx] - '0';
            s[idx++] = '0';
            pow *= 10;
            while(idx < s.length() && s[idx] == '9')
                sum -= 9, s[idx++] = '0', pow *= 10;
            if(idx < s.length())
                s[idx]++;
            else
                s += '1';
            ++sum;
        }
        
        return ans;
    }
};
