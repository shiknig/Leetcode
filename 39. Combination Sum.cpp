class Solution {
public:
    vector<vector<int>> a;
    vector<int> c;
    vector<vector<int>> check(vector<int>& b,int i,int sum, int t)
    {
        if(sum>t)
        return {{NULL}};
        
        if(sum==t)
        {a.push_back(c);
        return a;}
        if(i==b.size())
            return {{NULL}};
        
        c.push_back(b[i]);
        check(b,i,sum+b[i],t);
        
        c.pop_back();
        check(b,i+1,sum,t);
        return a;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        check(candidates,0,0,target);
        return a;
        
    }
};