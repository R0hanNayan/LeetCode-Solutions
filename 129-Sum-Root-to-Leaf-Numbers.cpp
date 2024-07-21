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
    int pathSum(TreeNode *root, int sum){
        if(!root){    return 0;   }
        sum = sum * 10 + root->val;
        if(!root->left && !root->right){    return sum;    }
        int lSum = pathSum(root->left, sum);
        int rSum = pathSum(root->right, sum);
        return lSum + rSum;
    }
    int sumNumbers(TreeNode* root) {
        int sum = pathSum(root, 0);
        return sum;
    }
};