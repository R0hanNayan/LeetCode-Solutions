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
    bool solve(TreeNode* root, int t, int sum){
        if(!root){    return false;   }
        sum += root->val;
        if(!root->left && !root->right) {
            return sum == t;
        }
        return solve(root->left, t, sum) || solve(root->right, t, sum);
    }
    bool hasPathSum(TreeNode* root, int t) {
        return solve(root, t, 0);
    }
};