#include<stddef.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* merlist = &dummy;
    while(list1 && list2){
        if(list1->val<list2->val){
            merlist->next=list1;
            list1=list1->next;
        }else{
            merlist->next=list2;
            list2=list2->next;
        }
        merlist=merlist->next;
    }
    if(list1!=NULL){
        merlist->next=list1;
    }else{
        merlist->next=list2;
    }
    return dummy.next;
}