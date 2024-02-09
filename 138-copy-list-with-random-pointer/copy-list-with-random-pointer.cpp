/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>hash;
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copy=new Node(temp->val);
            hash[temp]=copy;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            Node *copiedNode=hash[temp];
            copiedNode->next=hash[temp->next];
            copiedNode->random=hash[temp->random];
            temp=temp->next;
        }
        return hash[head];
    }
};