#include <iostream>
using namespace std;

struct ListNode
{
	/* data */
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
	//Solution(arguments);
	//~Solution();
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
		if(l1==NULL && l2==NULL) return l1;
		if(l1==NULL) return l2;
		if(l2==NULL) return l1;   //Special first
		if(l1->val > l2->val){
			ListNode* temp=l1;
			l1 = l2;
			l2 = temp;
		}   //Using this to make things easier
		ListNode* p=l1;
		for(;p->next!=NULL;){
			if(l2 == NULL)
				break;
			if((p->next->val) > (l2->val)){
				ListNode* temp = p->next;
				p->next = l2;
				l2 = l2->next;
				p = p->next;
				p->next = temp;
			}
			else
				p = p->next;
		}
		if(l2 != NULL) p->next = l2;
		return l1;
	}
	/* data */
};
