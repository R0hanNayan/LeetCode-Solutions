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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int val = front.first;
            ListNode* node = front.second;
            if(node->next)  pq.push({node->next->val, node->next});

            ListNode* newNode = new ListNode(val);
            temp->next = newNode;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};