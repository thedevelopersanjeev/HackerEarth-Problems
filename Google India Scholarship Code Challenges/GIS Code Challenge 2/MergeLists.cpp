SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* answer = NULL;
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    if(head1->data <= head2->data){
        answer = head1;
        answer->next = mergeLists(head1->next, head2);
    }
    else{
        answer = head2;
        answer->next = mergeLists(head1, head2->next);
    }
    return answer;
}