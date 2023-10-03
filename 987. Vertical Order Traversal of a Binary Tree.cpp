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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> sol;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            
            TreeNode* node = q.front().first;
            int vert = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            m[vert][level].insert(node->val);
            if(node->left != NULL) q.push({node->left,{vert-1,level+1}});
            if(node->right != NULL) q.push({node->right,{vert+1,level+1}});   
        }
        for(auto p : m)
        {
            vector<int> col;
            for(auto q : p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            sol.push_back(col);
        } 
        return sol;
    }
};
