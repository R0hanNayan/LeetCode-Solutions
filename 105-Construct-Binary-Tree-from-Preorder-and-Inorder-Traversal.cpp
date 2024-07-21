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
    TreeNode* build(vector<int>& preorder, unordered_map<int, int> &mp, int &ind, int i, int j){
        if(i > j){
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[ind]);
        ind++;
        int mid = mp[root->val];
        root->left = build(preorder, mp, ind, i, mid-1);
        root->right = build(preorder, mp, ind, mid+1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int n = inorder.size();
        int ind = 0;
        TreeNode *root = build(preorder, mp, ind, 0, n-1);
        return root;
    }
};