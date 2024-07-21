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
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& mp, int &ind, int i, int j){
        if(i > j){    return NULL;    }
        TreeNode *root = new TreeNode(postorder[ind]);
        ind--;
        int mid = mp[root->val];
        root->right = build(postorder, mp, ind, mid+1, j);
        root->left = build(postorder, mp, ind, i, mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int ind = n-1;
        TreeNode *root = build(postorder, mp, ind, 0, n-1);
        return root;
    }
};