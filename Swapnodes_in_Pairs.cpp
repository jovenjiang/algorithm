//ven a linked list, swap every two adjacent nodes and return its head.

//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space. You may not modify
// the values in the list, only nodes itself can be changed.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* h=new ListNode(0);
        h->next=head;
        ListNode* cur=h;
        while(cur->next && cur->next->next){
            ListNode* first=cur->next;
            ListNode* second=cur->next->next;
            first->next=second->next;
            cur->next=second;
            second->next=first;
            cur=cur->next->next;
        }
        return h->next;
    }
};
