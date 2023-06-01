// Leetcode 2nd problem
// 2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* ans = new ListNode(-1);
        ListNode* it = ans;
        int carry = 0;
        while((l1 != NULL || l2 != NULL) || (carry != 0) )
        {
            int sum = 0;
            if (l1 != NULL && l2 != NULL)
            {
                sum = l1->val + l2->val;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                sum = l2->val;
            }
            else if (l2 == NULL && l1 != NULL)
            {
                sum = l1->val;
            }
            else if (l1 == NULL && l2 == NULL)
            {
                sum = carry;
                carry = 0;
            }
            
            if(carry > 0)
            {
                sum = sum + carry;
                carry = 0;
            }
            if(sum > 9)
            {
                sum = sum%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            // cout << "sum " << sum << endl;
            // cout << "carry " << carry << endl;
            ListNode* node = new ListNode(sum);
            it->next = node ;
            it = it->next;
            if(l1 != NULL && l2 != NULL)
            {
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                l1 = l1->next;
            }
            else if(l2 != NULL && l1 == NULL)
            {
                l2 = l2->next;
            }
            
        }
        ans = ans->next;
        
        return ans; 
    }
};
