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

	/* data */
	ListNode* removeNthFromEnd(ListNode* head, int n){
		ListNode* p=head;
		ListNode* q=head;
		int i=0;
		for(; p!=NULL; i++){
			p = p->next;
			if(i>=n+1) q = q->next;   //Find q is the frontier of the node to be deleted
		}
		if(q->next == NULL)  return NULL;  // If there is only one node
		if(i == n) return head->next;
		q->next = q->next->next;

		return head;
	}
};