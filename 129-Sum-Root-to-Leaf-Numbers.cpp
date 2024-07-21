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
    void getPath(TreeNode *root, vector<string> &ans, string res){
        if(!root){  return; }
        if(root->left || root->right){  res += to_string(root->val); }
        else if(!root->left && !root->right){
            res += to_string(root->val);
            ans.push_back(res);
        }
        getPath(root->left, ans, res);
        getPath(root->right, ans, res);
    }
    int sumNumbers(TreeNode* root) {
        if(!root){    return 0;   }
        vector<string> nums;
        getPath(root, nums, \\);
        int sum = 0;
        for(auto it : nums){
            sum += stoi(it);
        }
        return sum;
    }
};