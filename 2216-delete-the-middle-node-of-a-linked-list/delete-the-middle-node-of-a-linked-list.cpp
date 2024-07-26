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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        int len = 0;
        ListNode*curr = head;
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
        int position = len/2;

        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < position; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // Delete the middle node
        prev->next = curr->next;
        delete curr;
        
        return head;
    }
};