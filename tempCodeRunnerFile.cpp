Node* nextNode=temp->next;
        while(nextNode!=nullptr && nextNode->data==temp->data){
            Node* todelete=nextNode;
            nextNode=nextNode->next;
            delete todelete;
        }
        temp->next=nextNode;
        if(nextNode!=nullptr){
            nextNode->prev=temp;
        }
        temp=temp->next;