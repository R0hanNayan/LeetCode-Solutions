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
    ListNode* findMid(ListNode* head) {
        if(!head)   return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)   return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        ListNode* left = head;
        
        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};