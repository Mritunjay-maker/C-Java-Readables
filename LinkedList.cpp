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
    Node *prev = NULL;
    while(i < position - 1 && curr != NULL){
        
        curr = curr->next;
        i++;
    }
    cout << prev->data << endl;
    curr->next = curr->next->next;
    return head;
}
Node *insertAtPos(Node *head, int position, int data) {
  int i = 1;
  Node *temp = new Node(data);
  // if (position > findLength(head)) {
  //   cout << " Not Possible!";
  //   return head;
  // }
  if (position == 1) {
    temp->next = head;
    return temp;
  }
  // if(position == findLength(head)){
  //   Node *itr = head;
  //   while(itr->next != NULL){
  //     itr = itr->next;
  //   }
  //   itr->next = temp;
  //   temp->next = NULL;
  // }
  Node *curr = head;
  while (i < position - 1 && curr != NULL) {
    curr = curr->next;
    i++;
  }
  temp->next = curr->next;
  curr->next = temp;

  return head;
}

Node *deleteWithValue(Node *head, int element) {

    if(head->data == element) {
        head = head->next;
        return head;
    }
    
    Node *curr = head;
    // while(curr->next->data != element && curr->next !=NULL) {
    //     curr = curr->next;
    // }
    for(curr; curr->next != NULL; curr = curr->next){
        if(curr->next->data == element) {
            curr->next = curr->next->next;
            break;
        }
    }
    
    return head;

}

Node *insertNext(Node *head, int position, int element) {
    Node *temp = new Node(position);
    if(head ==  NULL) {
        return head;
    }
    if(head->data == element) {
        temp->next = head;
        return temp;
    }
    bool flag = false;
    
    Node *curr = head;
    // while(curr->next->data != element) {
    //     curr = curr->next;
        
    // }
    while(curr->next != NULL){
        if(curr->next->data == element) {
            temp->next = curr->next;
            curr->next = temp;
            flag = true;
            break;
        }
        curr = curr->next;
    }
    

    if(flag == false) {
        cout << "element in not there" << endl;
    }
    return head;
}
Node *removeFromEnd(Node *head, int position) {
    int size = length(head);
    if(head == NULL) {
        return head;

    }
    if(position >= size) {
        cout << "Operation not possible" << endl;
        return head;
    }
    if(size == position) {
        head = head->next;
        return head;
    }
    if(size == 1 && position == 1) {
        return NULL;
    }
    int itr = size - position;
    Node *curr = head;
    int i = 0;
    while(i < itr - 1) {
        curr = curr->next;
        i++;
    }
    curr->next = curr->next->next;

    return head;

}
Node *evenOdd(Node *head) {
    if(head == NULL) {
        return NULL;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;
    while(even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
void segregate(int arr[], int n) {
    int i =0;
    int j = n;
    int start = 0;
    int end = n-1;

    while(i != j) {
        if(arr[i] == 0) {
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else if(arr[i] == 1){
            i++;
        }
        else{
            swap(arr[i], arr[end]);
                j--;
                end--;
                
            
        }
    }
}
Node *segregateList(Node *head) {
    Node *zero = new Node(-1);
    

    Node *one = new Node(-1);
    Node *two = new Node(-1);
    Node *zeroHead = zero;
    Node *oneHead = one;
    Node *twoHead = two;
    

    Node *curr = head;
    while(curr != NULL) {
        if(curr->data == 0){
            zero->next = curr;
            zero = curr;
        

        }
        if(curr->data == 1) {
            one->next = curr;
            one = curr;

        }
        if(curr->data == 2){
            two->next = curr;
            two = curr;
        

        }
        curr = curr->next;
    }
    // if(curr->data == 0) {
    //     zero->next = curr;
    // }
    // if(curr->data == 1) {
    //     one->next = curr;
    // }
    // else{
    //     two->next = curr;
    // }
    
    zero->next = oneHead->next;
    oneHead->next = twoHead->next;
    return zeroHead;
}

Node *reverseList(Node *head){
    
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL) {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

int main() {

    Node *head = new Node(0);
    createLLfromArray(head,5);

    head = reverseList(head);
    
    printList(head);
    
    
    
   
    
    
}