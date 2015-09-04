#include <iostream>
#include "../common/listNode.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* result = l1;
        ListNode* pre_l1;   
        int carry=0;
        while(l1!= NULL && l2!= NULL) {
            l1->val = l1->val + l2->val + carry;
            carry  = l1->val>9? 1:0;
            l1->val = l1->val % 10;
            pre_l1 = l1;
            l1 = l1->next;
            l2 = l2->next; 
        }
        if(l1== NULL){
            pre_l1->next = l2;
            l1 = l2;
        }
        while(l1 != NULL){
            l1->val = l1->val+carry;
            carry = l1->val > 9? 1:0;
            l1->val = l1->val %10;
            pre_l1 = l1;
            l1 = l1->next;
        }
        if(carry == 1){
            ListNode* q = new ListNode(carry);
            pre_l1->next = q; 
        }
        return result;
    }
};



int main(){
    Solution s;
    List l1,l2,result;
    l1.buildList();
    l2.buildList();
    
    result.assignList(s.addTwoNumbers(l1.readList(), l2.readList()));
    result.printList();
    return 1;
}
