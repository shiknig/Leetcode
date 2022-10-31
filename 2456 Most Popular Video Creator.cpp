class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cr, vector<string>& ids, vector<int>& views) {
        int n = cr.size();
        
        int mx = 0;
        set<string> se;
        
        unordered_map<string, long long> mp, mxv;
        unordered_map<string, string> best;
        
        for(int i = 0; i < n; ++i) {
            mp[cr[i]] += views[i];
            if(best.count(cr[i]) == 0 || views[i] > mxv[cr[i]])
                mxv[cr[i]] = views[i], best[cr[i]] = ids[i];
            else if(views[i] == mxv[cr[i]] && ids[i] < best[cr[i]])
                best[cr[i]] = ids[i];
                
            if(mp[cr[i]] == mx)
                se.insert(cr[i]);
            else if(mp[cr[i]] > mx) {
                mx = mp[cr[i]];
                se.clear();
                se.insert(cr[i]);
            }
        }
        
        vector<vector<string>> ans;
        for(auto& t : se) {
            ans.push_back({ t, best[t] });
        }
        
        return ans;
    }
};
