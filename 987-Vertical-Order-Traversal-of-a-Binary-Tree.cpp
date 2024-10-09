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
    void preorder(TreeNode* root, int line, int level, map<int, vector<pair<int, int>>> &mp){
        if(!root)   return;

        mp[line].push_back({level, root->val});
        preorder(root->left, line-1, level+1, mp);
        preorder(root->right, line+1, level+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<pair<int, int>>> mp;
        preorder(root, 0, 0, mp);
        for (auto& line : mp) {
            vector<int> temp;
            sort(line.second.begin(), line.second.end());
            for(auto& level : line.second){
                temp.push_back(level.second);
            }
            res.push_back(temp);
        }
        return res;
    }
};