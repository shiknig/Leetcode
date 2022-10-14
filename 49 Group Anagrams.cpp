class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> m;
        int n=strs.size();
        for(int i=0;i<n;i++)
        {
            string s1,s2;
            s1=strs[i];
            s2=s1;
            sort(s2.begin(),s2.end());
            m[s2].push_back(s1);
        }
        vector<vector<string>> v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        return v;
    }
};
