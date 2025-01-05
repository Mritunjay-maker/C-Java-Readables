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
int main() {

    Node *head = new Node(56);
    createLLfromArray(head,5);
    printList(head);
    cout << endl;
    cout << length(head);
    cout << endl;
    cout << search(head,1);
    
}