/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int n;
    unordered_map<int, int> d, h, par, x;
    unordered_map<int, TreeNode*> mp; 
    
    void setP(TreeNode* root, TreeNode* p) {
        if(root == nullptr)
            return;
        mp[root->val] = root;
        if(p)
            par[root->val] = p->val;
        
        setP(root->left, root);
        setP(root->right, root);
    }
    
    void setD(TreeNode* root, int depth) {
        if(root == nullptr)
            return;
        d[root->val] = depth;
        setD(root->left, depth + 1);
        setD(root->right, depth + 1);
    }
    
    int setH(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int l = setH(root->left);
        int r = setH(root->right);
        return h[root->val] = max(l, r) + 1;
    }
    
    void setOtherH(TreeNode* root, TreeNode* p) {
        if(root == nullptr)
            return;
        
        
        if(p == nullptr) {
            x[root->val] = 0;
        }
        else {
            int t = x[p->val];
            t = max(t, d[p->val]);
            if(p->left && p->left != root)
                t = max(t, d[p->val] + h[p->left->val]);
            else if(p->right && p->right != root)
                t = max(t, d[p->val] + h[p->right->val]);
            x[root->val] = t;
        }
        
        setOtherH(root->left, root);
        setOtherH(root->right, root);
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        setP(root, nullptr);
        setD(root, 0);
        setH(root);
        setOtherH(root, nullptr);
        
        vector<int> res;
        for(int t : queries) 
            res.push_back(x[t]);
        
        return res;
    }
};
