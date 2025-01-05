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
   while(curr->next != NULL){
    cout << curr->data <<"->";
    curr = curr->next;
   }     
   cout <<"NULL";

}

void createLLfromArray(Node *head, int noOfElements){
    Node *curr = head;
    int element;
    for(int i = 0; i <= noOfElements; i++) {
        cin >> element;
        curr->next = new Node(element);
        curr = curr->next;
    }

    
}
int main() {

    Node *head = new Node(56);
    createLLfromArray(head,5);
    printList(head);
    
}