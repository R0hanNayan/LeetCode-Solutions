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
    void inorder(TreeNode* root, int k, int &cnt, int &el){
        if(!root || cnt >= k){
            return;
        }
        inorder(root->left, k, cnt, el);
        cnt++;
        if(cnt == k){
            el = root->val;
            return;
        }
        inorder(root->right, k, cnt, el);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int el = -1;
        inorder(root, k, cnt, el);
        return el;
    }
};