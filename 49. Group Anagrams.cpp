class Solution {

public:

    string stringsorting(string a)

    {

        sort(a.begin(),a.end());

        return a;

    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string> >ans;

        map<string,vector<string> >mp;

        int len=strs.size();

        for(int i=0;i<len;i++)

        {

            string key=stringsorting(strs[i]);

            mp[key].push_back(strs[i]);

        }

        for(auto i : mp)

        {

            ans.push_back(i.second);

        }

        return ans;

    }

};