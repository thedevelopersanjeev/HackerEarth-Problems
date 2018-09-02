static int getNode(SinglyLinkedListNode head, int positionFromTail) {
    int a = 0;
    SinglyLinkedListNode c = head, r = head;
        while(c != null){
        c = c.next;
        if(a++ > positionFromTail)
            r = r.next;
    }
    return r.data;
}