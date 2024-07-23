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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){  return res; }

        queue<TreeNode*> q;
        int i = 0;
        q.push(root);

        while(!q.empty()){
            int k = q.size();
            vector<int> temp;
            while(k--){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){     q.push(node->left);    }
                if(node->right){    q.push(node->right);   }
            }
            if(i % 2 == 0){
                res.push_back(temp);
            }else{
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
            }
            i++;
        }
        return res;
    }
};