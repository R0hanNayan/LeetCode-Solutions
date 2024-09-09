/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n , -1));
        ListNode* curr = head;
        if(!head)   return mat;
        int top = 0, bottom = m-1, left = 0, right = n-1;

        while(curr){
            for (int i = left; i <= right && curr; i++) {
                mat[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for (int i = top; i <= bottom && curr; i++) {
                mat[i][right] = curr->val;
                curr = curr->next;
            }
            right--;

            if (top <= bottom) { 
                for (int i = right; i >= left && curr; i--) {
                    mat[bottom][i] = curr->val;
                    curr = curr->next;
                }
                bottom--; 
            }

            if (left <= right) { 
                for (int i = bottom; i >= top && curr; i--) {
                    mat[i][left] = curr->val;
                    curr = curr->next;
                }
                left++;
            }
        }
        return mat;
    }
};