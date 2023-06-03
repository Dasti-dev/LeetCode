// LEETCODE
// 19. Remove Nth Node From End of List
// check for boundary conditions
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        return NULL;
        if(head->next==NULL&&n==1)
        return NULL;
        ListNode* first = head ; 
        ListNode* curr = head ;
        ListNode* c = head ;
        
        long long int count = 0;
        while(c != NULL)
        {
            count++;
            c = c -> next;
        }
        long long int start = count - n ;
        int i = 1;
        if(count == n)
        {
            first = first -> next;
            return first;
        }
        while(i<start)
        {
            curr = curr -> next;
            i++;
        }
        ListNode* tmp = curr->next ;
        curr -> next = tmp -> next;
        tmp -> next = NULL;
        delete tmp;
    return first;
    }
};
