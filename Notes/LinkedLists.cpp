// Linked Lists
#include <bits/stdc++.h>

using namespace std;

class node {
    public:
    int data;
    node* next;

    public:
    node() {}
    node(int val) { data = val; next = nullptr; }
    node(int val, node* ptr) { data = val; next = ptr; }
};

void printingLinkedList(node* head);
node* arraytoLinkedList(int arr[], int n);
int linearSearchLinkedList(node* head, int target);

int main(void) {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(4);
    node* fourth = new node(3);

    // Linking all nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
  
    //printingLinkedList(head);

    int arr[4] = {1, 2, 4, 3};
    node* headofnewList = arraytoLinkedList(arr, 4);
    printingLinkedList(headofnewList);
    cout << endl;

    int result = linearSearchLinkedList(headofnewList, 3);
    
    if (result == 1) cout << "element found" << endl;
    else cout << "element not found" << endl;
}

void printingLinkedList(node* head) {
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }    
}

int linearSearchLinkedList(node* head, int target) {
    while (head != nullptr) {
        if (head->data == target) {
            return 1;
        }
        else head = head->next;
    }
    return 0;
}

node* arraytoLinkedList(int arr[], int n) {
    node* head = new node(arr[0]);
    node* mover = head;

    for (int i = 1; i < n; i++) {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}