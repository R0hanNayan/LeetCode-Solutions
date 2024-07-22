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
    int solve(TreeNode *root, int &maxi){
        if(!root){    return 0;   }

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        int path1 = root->val;
        int path2 = max(left, right) + root->val;
        int path3 = left + right + root->val;

        maxi = max({path1, path2, path3, maxi});

        return max(path1, path2);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};