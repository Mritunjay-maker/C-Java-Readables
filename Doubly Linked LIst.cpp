#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *createList( int arr[], int n) {
    Node *head = new Node(arr[0]);

    Node *curr = head;
    for(int i = 1; i < n; i++) {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;

        curr = curr->next;
    }
    return head;
    
}
void print(Node *head) {
    if(head == NULL){
        return;
    }
    Node *curr = head;
    while(curr != NULL){
        cout << curr->data <<"<->";
        curr = curr->next;
    }
    //cout << curr->prev->prev->data;

}
Node *deleteHead(Node *head){
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next =NULL;
    free(temp);
    return head;

}
Node *deleteTail(Node *head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    Node *temp = curr->prev;
    temp->next = NULL;
    curr->prev = NULL;
   
    free(curr);
    return head;


    return head;
}
Node *deletePos(Node *head, int position) {
    if(head == NULL) {
        return NULL;
    }
    Node *curr = head;
    int cnt = 0;
    while(cnt < position - 1 && curr != NULL) {
        curr = curr->next;
        cnt++;
    }
    Node *back = curr->prev;
    Node *front = curr->next;
    if(back == NULL && front == NULL){
        return NULL;
    }
    if(back == NULL) {
        return deleteHead(head);
    }
    if(front == NULL) {
        return deleteTail(head);
    }
    back->next = front;
    front->prev = back;
    curr->prev = NULL;
    curr->next = NULL;
    free(curr);
   
    return head;
}
Node *insertHead(Node *head, int data) {
    Node *temp = new Node(data);
    if(head == NULL) {
        return temp;
    }
    temp->next = head;
    head->prev = temp;
    return temp;
}
Node *insertTail(Node *head, int data) {
    Node *temp = new Node(data);
    if(head == NULL) {
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}
int main() {
    

    int arr[] = {2,3,4,5,6,7,8};
    Node *head = createList(arr,7);
    head = insertTail(head,1);

    print(head);

}