
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;
        int prevCriticalPos = 0;
        int firstCriticalPos = 0;

        int minDist = INT_MAX;

        while(curr->next != NULL){

            if((curr->val < prev->val && curr->val < curr->next->val) ||
            (curr->val > prev->val && curr->val > curr->next->val)){

                if(prevCriticalPos == 0){
                    prevCriticalPos = i;
                    firstCriticalPos = i;

                   } else {
                        minDist = min(minDist, i - prevCriticalPos);
                        prevCriticalPos = i;
                    }
                }

                i++;
                prev = curr;
                curr = curr->next;
            }

            if(minDist == INT_MAX){
                return {-1, -1};
            }

            return {minDist, prevCriticalPos - firstCriticalPos};
    }
};