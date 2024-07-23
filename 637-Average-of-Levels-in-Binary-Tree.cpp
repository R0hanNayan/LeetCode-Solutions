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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root){  return res; }
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int k = q.size();
            double avg = 0;
            int i = 0;
            while(i < k){
                TreeNode *front = q.front();
                q.pop();
                avg += front->val;
                if(front->left){    q.push(front->left);    }
                if(front->right){   q.push(front->right);   }
                i++;
            }
            res.push_back(avg/(double)k);
        }
        return res;        
    }
};