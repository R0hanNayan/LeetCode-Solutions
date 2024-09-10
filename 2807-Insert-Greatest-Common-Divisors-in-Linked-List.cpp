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
    int gcd(int a, int b){
        for(int i = min(a, b); i >= 1; i--){
            if(a % i == 0 && b % i == 0){
                return i;
            }
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)    return head;
        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* temp = curr->next;
            int GCD = gcd(curr->val, curr->next->val);
            ListNode* node = new ListNode(GCD);

            curr->next = node;
            node->next = temp;

            curr = curr->next->next;
        }
        return head;
    }
};