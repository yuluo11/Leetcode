struct ListNode {
    int val;
    struct ListNode *next;
 };
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummpy;
    dummpy.next=head;
    struct ListNode* l=&dummpy;
    struct ListNode* temp;
    while(head){
        
        if(head->val==val){
            temp=head;
            l->next=head->next;
            head=head->next;
            free(temp);
        }else{
            l=head;
            head=head->next;
        }
    }
    return dummpy.next;
}