#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
    ListNode(): next(NULL) {}
};
/*
 * If List is empty, it contains a new ListNode without val(will be 0 by default).
 * Otherwise(it means buildList() ), the List has no head node.
 * */
class List{
private:
    ListNode* l;
public:
    List(){
        l = new ListNode();
    }
    void buildList(){
        int n;
        ListNode* p=l;
        cout<< "Input List: "<<endl;
        while(cin>>n){
            ListNode* q = new ListNode(n);
            p->next = q;
            p = q;
        }
        l = l->next;
        cin.clear();
        cout<< "Input Completed"<<endl;
    }

    void printList(){
        ListNode* p= l;
        while(p!=NULL){
            cout<< p->val << " ";
            p = p->next;
        }
        cout<<endl;
    }

    void assignList(ListNode* l1) {
        l = l1;
    }
    ListNode* readList() {
        return l;
    }
};
