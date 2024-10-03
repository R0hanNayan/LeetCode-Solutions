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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)   return NULL;

        ListNode* even = new ListNode();
        ListNode* odd = new ListNode();

        ListNode* curr = head;
        ListNode* curr1 = even, *curr2 = odd;
        int i = 1;
        while(curr){
            if(i % 2 == 1){
                curr2->next = curr;
                curr2 = curr2->next;
            }else{
                curr1->next = curr;
                curr1 = curr1->next;
            }
            curr = curr->next;
            i++;
        }
        curr1->next = NULL;
        curr2->next = even->next;
        return odd->next; 
    }
};