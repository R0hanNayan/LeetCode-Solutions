class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next == nullptr){
            delete(node);
        }
        node->val = node->next->val;
        node->next = node->next->next;
    }
};