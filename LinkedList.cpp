#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    public:
    Node(int data){
        this->data = data;
        next = NULL;
    }
    
};
void printList(Node* head){
   Node *curr = head;
   while(curr != NULL){
    cout << curr->data <<"->";
    curr = curr->next;
   }     
   cout <<"NULL";

}

void createLLfromArray(Node *head, int noOfElements){
    Node *curr = head;
    int element;
    for(int i = 0; i < noOfElements; i++) {
        cin >> element;
        curr->next = new Node(element);
        curr = curr->next;
    }

    
}
int length(Node *head){
    int count = 0;
    Node* curr = head;
    while(curr != NULL) {
        
        curr = curr->next;
        count++;
    }
    return count;
}
int search(Node *head, int key){
    Node* curr = head;
    int count = 0;
    while(curr != NULL) {
        if(curr->data == key) {
            return count;
        }
        count++;
        curr = curr->next;
    }
    return -1;

}
Node *insertNodeAtFront(Node *head, int data){
    Node *temp = new Node(data);
    temp->next=head;
    return temp;


}
Node *insertAtEnd(Node *head, int data){
    Node *temp = new Node(data);
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = NULL;
    return head;
}

Node *deleteAtFront(Node *head){
    if(head == NULL){
        return NULL;
    }
    head = head->next;
    return head;
}
Node *deleteAtEnd(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}
Node *deleteNodeAtPosition(Node *head, int position) {
    if(head == NULL) {
        return NULL;
    }
    int lenOfList = length(head);
    if(position > lenOfList) {
        cout << "Size Exceeds!";
        return head;
    }
    if(position == 1){
        head = deleteAtFront(head);
        return head;
    }
    if(position == lenOfList) {
        head = deleteAtEnd(head);
        return head;
    }
    Node *curr = head;
    int i = 1;
    while(i < position - 1 && curr != NULL){
        curr = curr->next;
        i++;
    }
    cout << curr->data << endl;
    curr->next = curr->next->next;
    return head;
}
int main() {

    Node *head = new Node(56);
    createLLfromArray(head,5);
    
    cout << endl;
   
    cout << endl;
    
    head = insertNodeAtFront(head, 80);
    head = insertNodeAtFront(head, 90);
    head = insertAtEnd(head, 97);
    cout<< length(head) << endl;
    printList(head);
    cout << endl;
    head = deleteNodeAtPosition(head,5);
    printList(head);
    cout << endl;
    cout << length(head);
    
    
}