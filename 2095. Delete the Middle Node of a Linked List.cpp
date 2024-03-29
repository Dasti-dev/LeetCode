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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return NULL;
        ListNode* curr = getMiddle(head);        
        ListNode* temp = head;
        while(temp -> next != curr){
            temp = temp -> next;
        }
        temp -> next = curr -> next;
        return head;
    }
};
