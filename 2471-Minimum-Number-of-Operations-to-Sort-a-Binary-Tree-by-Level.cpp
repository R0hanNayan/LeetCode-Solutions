/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size(), count = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            if (vec[i].first != arr[i]) {
                swap(vec[vec[i].second], vec[i]);
                i--;
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;

        while (!q.empty()) {
            vector<int> level;
            int k = q.size();
            while (k--) {
                TreeNode* node = q.front();
                level.push_back(node->val);
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            cnt += minSwaps(level);
        }
        return cnt;
    }
};