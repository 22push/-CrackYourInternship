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
        int carry =0;
        ListNode* first = l1;
        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;
        ListNode* second = l2;
        while(first!=NULL && second!=NULL){
            int sum = first->val+second->val+carry;
            carry = sum/10;
            first->val = sum%10;
            prev1 = first;
            prev2 = second;
            first = first->next;
            second = second->next;
        }
        if(second!=NULL){
            prev1->next = prev2->next;
            prev2->next =NULL;
            first = prev1->next;
        }
        while(first!=NULL){
            int sum = first->val+carry;
            carry = sum/10;
            first->val = sum%10;
            prev1 = first;
            first = first->next;
        }
        if(carry !=0){
            ListNode* car = new ListNode(carry);
            prev1->next = car;
            car->next = NULL;
        }
        
        return l1;
    }
};